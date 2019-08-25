
extern zend_class_entry *geoip2_maxmind_db_reader_util_ce;

ZEPHIR_INIT_CLASS(GeoIP2_MaxMind_Db_Reader_Util);

PHP_METHOD(GeoIP2_MaxMind_Db_Reader_Util, read);

ZEND_BEGIN_ARG_INFO_EX(arginfo_geoip2_maxmind_db_reader_util_read, 0, 0, 3)
	ZEND_ARG_INFO(0, stream)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, offset, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, offset)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, numberOfBytes, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, numberOfBytes)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(geoip2_maxmind_db_reader_util_method_entry) {
	PHP_ME(GeoIP2_MaxMind_Db_Reader_Util, read, arginfo_geoip2_maxmind_db_reader_util_read, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
