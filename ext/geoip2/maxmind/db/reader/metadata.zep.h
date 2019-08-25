
extern zend_class_entry *geoip2_maxmind_db_reader_metadata_ce;

ZEPHIR_INIT_CLASS(GeoIP2_MaxMind_Db_Reader_Metadata);

PHP_METHOD(GeoIP2_MaxMind_Db_Reader_Metadata, __construct);
PHP_METHOD(GeoIP2_MaxMind_Db_Reader_Metadata, __get);
PHP_METHOD(GeoIP2_MaxMind_Db_Reader_Metadata, __toArray);

ZEND_BEGIN_ARG_INFO_EX(arginfo_geoip2_maxmind_db_reader_metadata___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, metadata)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_geoip2_maxmind_db_reader_metadata___get, 0, 0, 1)
	ZEND_ARG_INFO(0, v)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(geoip2_maxmind_db_reader_metadata_method_entry) {
	PHP_ME(GeoIP2_MaxMind_Db_Reader_Metadata, __construct, arginfo_geoip2_maxmind_db_reader_metadata___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(GeoIP2_MaxMind_Db_Reader_Metadata, __get, arginfo_geoip2_maxmind_db_reader_metadata___get, ZEND_ACC_PUBLIC)
	PHP_ME(GeoIP2_MaxMind_Db_Reader_Metadata, __toArray, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
