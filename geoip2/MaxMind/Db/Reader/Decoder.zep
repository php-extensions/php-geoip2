namespace GeoIP2\MaxMind\Db\Reader;

class Decoder
{
    private fileStream;
    private pointerBase;
    private pointerBaseByteSize;
    // This is only used for unit testing
    private pointerTestHack;
    private switchByteOrder;
    private maxIntBytes;

    const _EXTENDED = 0;
    const _POINTER = 1;
    const _UTF8_STRING = 2;
    const _DOUBLE = 3;
    const _BYTES = 4;
    const _UINT16 = 5;
    const _UINT32 = 6;
    const _MAP = 7;
    const _INT32 = 8;
    const _UINT64 = 9;
    const _UINT128 = 10;
    const _ARRAY = 11;
    const _CONTAINER = 12;
    const _END_MARKER = 13;
    const _BOOLEAN = 14;
    const _FLOAT = 15;

    public function __construct(
        fileStream,
        pointerBase = 0,
        pointerTestHack = false
    ) {
        let this->maxIntBytes = (log(PHP_INT_MAX, 2) - 1) / 8;
        let this->fileStream = fileStream;
        let this->pointerBase = pointerBase;
        let this->pointerBaseByteSize = pointerBase > 0 ? log(pointerBase, 2) / 8 : 0;
        let this->pointerTestHack = pointerTestHack;
        let this->switchByteOrder = this->isPlatformLittleEndian();
    }

    public function decode(int offset)
    {
        var ctrlByte, type, pointer, pointerOffset, result, nextByte, sizeOffset;
        let ctrlByte = unpack(
            "C",
            Util::read(this->fileStream, offset, 1)
        );
        let ctrlByte = ctrlByte[1];
        let offset++;
        let type = ctrlByte >> 5;
        // Pointers are a special case, we don't read the next size bytes, we
        // use the size to determine the length of the pointer and then follow
        // it.
        if (type === self::_POINTER) {
            let pointerOffset = this->decodePointer(ctrlByte, offset);
            let pointer = pointerOffset[0];
            let offset = (int)pointerOffset[1];
            // for unit testing
            if (this->pointerTestHack) {
                return [pointer];
            }
            let result = this->decode(pointer);
            return [result[0], offset];
        }
        if (type === self::_EXTENDED) {
            let nextByte = unpack(
                "C",
                Util::read(this->fileStream, offset, 1)
            );
            let type = nextByte[1] + 7;
            if (type < 8) {
                throw new InvalidDatabaseException(
                    "Something went horribly wrong in the decoder. An extended type "
                    . "resolved to a type number < 8 ("
                    . type
                    . ")"
                );
            }
            let offset++;
        }
        let sizeOffset = this->sizeFromCtrlByte(ctrlByte, offset);
        return this->decodeByType(type, sizeOffset[1], sizeOffset[0]);
    }


    private function decodeByType(type, offset, size)
    {
        int newOffset;
        var bytes;
        switch (type) {
            case self::_MAP:
                return this->decodeMap(size, offset);
            case self::_ARRAY:
                return this->decodeArray(size, offset);
            case self::_BOOLEAN:
                return [this->decodeBoolean(size), offset];
        }
        let newOffset = offset + size;
        let bytes = Util::read(this->fileStream, offset, size);
        switch (type) {
            case self::_BYTES:
            case self::_UTF8_STRING:
                return [bytes, newOffset];
            case self::_DOUBLE:
                this->verifySize(8, size);
                return [this->decodeDouble(bytes), newOffset];
            case self::_FLOAT:
                this->verifySize(4, size);
                return [this->decodeFloat(bytes), newOffset];
            case self::_INT32:
                return [this->decodeInt32(bytes, size), newOffset];
            case self::_UINT16:
            case self::_UINT32:
            case self::_UINT64:
            case self::_UINT128:
                return [this->decodeUint(bytes, size), newOffset];
            default:
                throw new InvalidDatabaseException(
                    "Unknown or unexpected type: " . type
                );
        }
    }
    private function verifySize(expected, actual)
    {
        if (expected !== actual) {
            throw new InvalidDatabaseException(
                "The MaxMind DB file's data section contains bad data (unknown data type or corrupt data)"
            );
        }
    }
    private function decodeArray(size, offset)
    {
        var _array, i, value_offset, value;
        let _array = [];
        let i = 0;
        while (i < size) {
            let value_offset = this->decode(offset);
            let value = value_offset[0];
            let offset = value_offset[1];
            array_push(_array, value);
            let i++;
        }
        return [_array, offset];
    }
    private function decodeBoolean(size)
    {
        return size === 0 ? false : true;
    }
    private function decodeDouble(bits)
    {
        var _double;
        // This assumes IEEE 754 doubles, but most (all?) modern platforms
        // use them.
        //
        // We are not using the "E" format as that was only added in
        // 7.0.15 and 7.1.1. As such, we must switch byte order on
        // little endian machines.
        let _double = unpack("d", this->maybeSwitchByteOrder(bits));
        let _double = _double[1];
        return _double;
    }
    private function decodeFloat(bits)
    {
    var _float;
        // This assumes IEEE 754 floats, but most (all?) modern platforms
        // use them.
        //
        // We are not using the "G" format as that was only added in
        // 7.0.15 and 7.1.1. As such, we must switch byte order on
        // little endian machines.
        let _float = unpack("f", this->maybeSwitchByteOrder(bits));
        let _float = _float[1];
        return _float;
    }
    private function decodeInt32(bytes, size)
    {
        var _int;
        switch (size) {
            case 0:
                return 0;
            case 1:
            case 2:
            case 3:
                let bytes = str_pad(bytes, 4, hex2bin("00"), STR_PAD_LEFT);
                break;
            case 4:
                break;
            default:
                throw new InvalidDatabaseException(
                    "The MaxMind DB file's data section contains bad data (unknown data type or corrupt data)"
                );
        }
        let _int = unpack("l", this->maybeSwitchByteOrder(bytes));
        let _int = _int[1];
        return _int;
    }
    private function decodeMap(size, offset)
    {
        var map, i, key_offset, key, value_offset, value;
        let map = [];
        let i = 0;
        while (i < size) {
            let key_offset = this->decode(offset);
            let key = key_offset[0];
            let offset = key_offset[1];
            let value_offset = this->decode(offset);
            let value = value_offset[0];
            let offset = value_offset[1];
            let map[key] = value;
            let i++;
        }
        return [map, offset];
    }

    private function decodePointer(ctrlByte, offset)
    {
        int pointerSize, pointer, pointerOffset, byteLength;
        var buffer, packed, _pointer;
        let pointerSize = ((ctrlByte >> 3) & 0x3) + 1;
        let buffer = Util::read(this->fileStream, offset, pointerSize);
        let offset = offset + pointerSize;
        switch (pointerSize) {
            case 1:
                let packed = (pack("C", ctrlByte & 0x7)) . buffer;
                let _pointer = unpack("n", packed);
                let pointer = (int)_pointer[1];
                let pointer += this->pointerBase;
                break;
            case 2:
                let packed = hex2bin("00") . (pack("C", ctrlByte & 0x7)) . buffer;
                let _pointer = unpack("N", packed);
                let pointer = (int)_pointer[1];
                let pointer += this->pointerBase + 2048;
                break;
            case 3:
                let packed = (pack("C", ctrlByte & 0x7)) . buffer;
                // It is safe to use 'N' here, even on 32 bit machines as the
                // first bit is 0.
                let _pointer = unpack("N", packed);
                let pointer = (int)_pointer[1];
                let pointer += this->pointerBase + 526336;
                break;
            case 4:
                // We cannot use unpack here as we might overflow on 32 bit
                // machines
                let pointerOffset = (int)this->decodeUint(buffer, pointerSize);
                let byteLength = pointerSize + this->pointerBaseByteSize;
                if (byteLength <= this->maxIntBytes) {
                    let pointer = pointerOffset + this->pointerBase;
                } elseif (extension_loaded("gmp")) {
                    let pointer = (int)gmp_strval(gmp_add(pointerOffset, this->pointerBase));
                } elseif (extension_loaded("bcmath")) {
                    let pointer = (int)bcadd(pointerOffset, this->pointerBase);
                } else {
                    throw new \RuntimeException(
                        "The gmp or bcmath extension must be installed to read this database."
                    );
                }
        }
        return [pointer, offset];
    }

    private function decodeUint(bytes, byteLength)
    {
        var _integer, i, part, _bytes;
        if (byteLength === 0) {
            return 0;
        }
        let _bytes = str_split(bytes);
        let i = 0;
        while (i < byteLength) {
            let part = ord(_bytes[i]);
            // We only use gmp or bcmath if the final value is too big
            if (byteLength <= this->maxIntBytes) {
                let _integer = (_integer << 8) + part;
            } elseif (extension_loaded("gmp")) {
                let _integer = gmp_strval(gmp_add(gmp_mul(_integer, 256), part));
            } elseif (extension_loaded("bcmath")) {
                let _integer = bcadd(bcmul(_integer, 256), part);
            } else {
                throw new \RuntimeException(
                    "The gmp or bcmath extension must be installed to read this database."
                );
            }
            let i++;
        }
        return _integer;
    }

    private function sizeFromCtrlByte(ctrlByte, offset)
    {
        int size, bytesToRead, adjust;
        var bytes, _adjust;
        let size = ctrlByte & 0x1f;
        if (size < 29) {
            return [size, offset];
        }
        let bytesToRead = size - 28;
        let bytes = Util::read(this->fileStream, offset, bytesToRead);
        if (size === 29) {
            let size = 29 + ord(bytes);
        } elseif (size === 30) {
            let _adjust = unpack("n", bytes);
            let adjust = (int)_adjust[1];
            let size = 285 + adjust;
        } elseif (size > 30) {
            let _adjust = unpack("N", hex2bin("00") . bytes);
            let adjust = (int)_adjust[1];
            let size = (adjust & (0x0FFFFFFF >> (32 - (8 * bytesToRead))))
                + 65821;
        }
        return [size, offset + bytesToRead];
    }

    private function maybeSwitchByteOrder(bytes)
    {
        return this->switchByteOrder ? strrev(bytes) : bytes;
    }
    private function isPlatformLittleEndian()
    {
        var testint, packed;
        let testint = 0x00FF;
        let packed = pack("S", testint);
        return testint === current(unpack("v", packed));
    }
}