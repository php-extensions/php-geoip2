<?php

namespace GeoIP2\MaxMind\Db\Reader;

/**
 * @ignore
 *
 * We subtract 1 from the log to protect against precision loss.
 */
class Decoder
{
    /**
     * @ignore
     */
    const _EXTENDED = 0;

    /**
     * @ignore
     */
    const _POINTER = 1;

    /**
     * @ignore
     */
    const _UTF8_STRING = 2;

    /**
     * @ignore
     */
    const _DOUBLE = 3;

    /**
     * @ignore
     */
    const _BYTES = 4;

    /**
     * @ignore
     */
    const _UINT16 = 5;

    /**
     * @ignore
     */
    const _UINT32 = 6;

    /**
     * @ignore
     */
    const _MAP = 7;

    /**
     * @ignore
     */
    const _INT32 = 8;

    /**
     * @ignore
     */
    const _UINT64 = 9;

    /**
     * @ignore
     */
    const _UINT128 = 10;

    /**
     * @ignore
     */
    const _ARRAY = 11;

    /**
     * @ignore
     */
    const _CONTAINER = 12;

    /**
     * @ignore
     */
    const _END_MARKER = 13;

    /**
     * @ignore
     */
    const _BOOLEAN = 14;

    /**
     * @ignore
     */
    const _FLOAT = 15;


    private $fileStream;


    private $pointerBase;


    private $pointerBaseByteSize;


    private $pointerTestHack;


    private $switchByteOrder;


    private $maxmind_max_int_bytes;


    /**
     * @param mixed $fileStream
     * @param mixed $pointerBase
     * @param mixed $pointerTestHack
     */
    public function __construct($fileStream, $pointerBase = 0, $pointerTestHack = false) {}

    /**
     * @param int $offset
     */
    public function decode(int $offset) {}

    /**
     * @param mixed $type
     * @param mixed $offset
     * @param mixed $size
     */
    private function decodeByType($type, $offset, $size) {}

    /**
     * @param mixed $expected
     * @param mixed $actual
     */
    private function verifySize($expected, $actual) {}

    /**
     * @param mixed $size
     * @param mixed $offset
     */
    private function decodeArray($size, $offset) {}

    /**
     * @param mixed $size
     */
    private function decodeBoolean($size) {}

    /**
     * @param mixed $bits
     */
    private function decodeDouble($bits) {}

    /**
     * @param mixed $bits
     */
    private function decodeFloat($bits) {}

    /**
     * @param mixed $bytes
     * @param mixed $size
     */
    private function decodeInt32($bytes, $size) {}

    /**
     * @param mixed $size
     * @param mixed $offset
     */
    private function decodeMap($size, $offset) {}

    /**
     * @param mixed $ctrlByte
     * @param mixed $offset
     */
    private function decodePointer($ctrlByte, $offset) {}

    /**
     * @param mixed $bytes
     * @param mixed $byteLength
     */
    private function decodeUint($bytes, $byteLength) {}

    /**
     * @param mixed $ctrlByte
     * @param mixed $offset
     */
    private function sizeFromCtrlByte($ctrlByte, $offset) {}

    /**
     * @param mixed $bytes
     */
    private function maybeSwitchByteOrder($bytes) {}


    private function isPlatformLittleEndian() {}

}
