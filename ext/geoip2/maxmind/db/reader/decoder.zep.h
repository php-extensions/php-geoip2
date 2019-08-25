
extern zend_class_entry *geoip2_maxmind_db_reader_decoder_ce;

ZEPHIR_INIT_CLASS(GeoIP2_MaxMind_Db_Reader_Decoder);

PHP_METHOD(GeoIP2_MaxMind_Db_Reader_Decoder, __construct);
PHP_METHOD(GeoIP2_MaxMind_Db_Reader_Decoder, decode);
PHP_METHOD(GeoIP2_MaxMind_Db_Reader_Decoder, decodeByType);
PHP_METHOD(GeoIP2_MaxMind_Db_Reader_Decoder, verifySize);
PHP_METHOD(GeoIP2_MaxMind_Db_Reader_Decoder, decodeArray);
PHP_METHOD(GeoIP2_MaxMind_Db_Reader_Decoder, decodeBoolean);
PHP_METHOD(GeoIP2_MaxMind_Db_Reader_Decoder, decodeDouble);
PHP_METHOD(GeoIP2_MaxMind_Db_Reader_Decoder, decodeFloat);
PHP_METHOD(GeoIP2_MaxMind_Db_Reader_Decoder, decodeInt32);
PHP_METHOD(GeoIP2_MaxMind_Db_Reader_Decoder, decodeMap);
PHP_METHOD(GeoIP2_MaxMind_Db_Reader_Decoder, decodePointer);
PHP_METHOD(GeoIP2_MaxMind_Db_Reader_Decoder, decodeUint);
PHP_METHOD(GeoIP2_MaxMind_Db_Reader_Decoder, sizeFromCtrlByte);
PHP_METHOD(GeoIP2_MaxMind_Db_Reader_Decoder, maybeSwitchByteOrder);
PHP_METHOD(GeoIP2_MaxMind_Db_Reader_Decoder, isPlatformLittleEndian);

ZEND_BEGIN_ARG_INFO_EX(arginfo_geoip2_maxmind_db_reader_decoder___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, fileStream)
	ZEND_ARG_INFO(0, pointerBase)
	ZEND_ARG_INFO(0, pointerTestHack)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_geoip2_maxmind_db_reader_decoder_decode, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, offset, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, offset)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_geoip2_maxmind_db_reader_decoder_decodebytype, 0, 0, 3)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, offset)
	ZEND_ARG_INFO(0, size)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_geoip2_maxmind_db_reader_decoder_verifysize, 0, 0, 2)
	ZEND_ARG_INFO(0, expected)
	ZEND_ARG_INFO(0, actual)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_geoip2_maxmind_db_reader_decoder_decodearray, 0, 0, 2)
	ZEND_ARG_INFO(0, size)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_geoip2_maxmind_db_reader_decoder_decodeboolean, 0, 0, 1)
	ZEND_ARG_INFO(0, size)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_geoip2_maxmind_db_reader_decoder_decodedouble, 0, 0, 1)
	ZEND_ARG_INFO(0, bits)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_geoip2_maxmind_db_reader_decoder_decodefloat, 0, 0, 1)
	ZEND_ARG_INFO(0, bits)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_geoip2_maxmind_db_reader_decoder_decodeint32, 0, 0, 2)
	ZEND_ARG_INFO(0, bytes)
	ZEND_ARG_INFO(0, size)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_geoip2_maxmind_db_reader_decoder_decodemap, 0, 0, 2)
	ZEND_ARG_INFO(0, size)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_geoip2_maxmind_db_reader_decoder_decodepointer, 0, 0, 2)
	ZEND_ARG_INFO(0, ctrlByte)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_geoip2_maxmind_db_reader_decoder_decodeuint, 0, 0, 2)
	ZEND_ARG_INFO(0, bytes)
	ZEND_ARG_INFO(0, byteLength)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_geoip2_maxmind_db_reader_decoder_sizefromctrlbyte, 0, 0, 2)
	ZEND_ARG_INFO(0, ctrlByte)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_geoip2_maxmind_db_reader_decoder_maybeswitchbyteorder, 0, 0, 1)
	ZEND_ARG_INFO(0, bytes)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(geoip2_maxmind_db_reader_decoder_method_entry) {
	PHP_ME(GeoIP2_MaxMind_Db_Reader_Decoder, __construct, arginfo_geoip2_maxmind_db_reader_decoder___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(GeoIP2_MaxMind_Db_Reader_Decoder, decode, arginfo_geoip2_maxmind_db_reader_decoder_decode, ZEND_ACC_PUBLIC)
	PHP_ME(GeoIP2_MaxMind_Db_Reader_Decoder, decodeByType, arginfo_geoip2_maxmind_db_reader_decoder_decodebytype, ZEND_ACC_PRIVATE)
	PHP_ME(GeoIP2_MaxMind_Db_Reader_Decoder, verifySize, arginfo_geoip2_maxmind_db_reader_decoder_verifysize, ZEND_ACC_PRIVATE)
	PHP_ME(GeoIP2_MaxMind_Db_Reader_Decoder, decodeArray, arginfo_geoip2_maxmind_db_reader_decoder_decodearray, ZEND_ACC_PRIVATE)
	PHP_ME(GeoIP2_MaxMind_Db_Reader_Decoder, decodeBoolean, arginfo_geoip2_maxmind_db_reader_decoder_decodeboolean, ZEND_ACC_PRIVATE)
	PHP_ME(GeoIP2_MaxMind_Db_Reader_Decoder, decodeDouble, arginfo_geoip2_maxmind_db_reader_decoder_decodedouble, ZEND_ACC_PRIVATE)
	PHP_ME(GeoIP2_MaxMind_Db_Reader_Decoder, decodeFloat, arginfo_geoip2_maxmind_db_reader_decoder_decodefloat, ZEND_ACC_PRIVATE)
	PHP_ME(GeoIP2_MaxMind_Db_Reader_Decoder, decodeInt32, arginfo_geoip2_maxmind_db_reader_decoder_decodeint32, ZEND_ACC_PRIVATE)
	PHP_ME(GeoIP2_MaxMind_Db_Reader_Decoder, decodeMap, arginfo_geoip2_maxmind_db_reader_decoder_decodemap, ZEND_ACC_PRIVATE)
	PHP_ME(GeoIP2_MaxMind_Db_Reader_Decoder, decodePointer, arginfo_geoip2_maxmind_db_reader_decoder_decodepointer, ZEND_ACC_PRIVATE)
	PHP_ME(GeoIP2_MaxMind_Db_Reader_Decoder, decodeUint, arginfo_geoip2_maxmind_db_reader_decoder_decodeuint, ZEND_ACC_PRIVATE)
	PHP_ME(GeoIP2_MaxMind_Db_Reader_Decoder, sizeFromCtrlByte, arginfo_geoip2_maxmind_db_reader_decoder_sizefromctrlbyte, ZEND_ACC_PRIVATE)
	PHP_ME(GeoIP2_MaxMind_Db_Reader_Decoder, maybeSwitchByteOrder, arginfo_geoip2_maxmind_db_reader_decoder_maybeswitchbyteorder, ZEND_ACC_PRIVATE)
	PHP_ME(GeoIP2_MaxMind_Db_Reader_Decoder, isPlatformLittleEndian, NULL, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
