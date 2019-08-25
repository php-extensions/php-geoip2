
extern zend_class_entry *geoip2_maxmind_db_reader_ce;

ZEPHIR_INIT_CLASS(GeoIP2_MaxMind_Db_Reader);

PHP_METHOD(GeoIP2_MaxMind_Db_Reader, __construct);
PHP_METHOD(GeoIP2_MaxMind_Db_Reader, get);
PHP_METHOD(GeoIP2_MaxMind_Db_Reader, findAddressInTree);
PHP_METHOD(GeoIP2_MaxMind_Db_Reader, startNode);
PHP_METHOD(GeoIP2_MaxMind_Db_Reader, ipV4StartNode);
PHP_METHOD(GeoIP2_MaxMind_Db_Reader, readNode);
PHP_METHOD(GeoIP2_MaxMind_Db_Reader, resolveDataPointer);
PHP_METHOD(GeoIP2_MaxMind_Db_Reader, findMetadataStart);
PHP_METHOD(GeoIP2_MaxMind_Db_Reader, metadata);
PHP_METHOD(GeoIP2_MaxMind_Db_Reader, close);

ZEND_BEGIN_ARG_INFO_EX(arginfo_geoip2_maxmind_db_reader___construct, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, database, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, database)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_geoip2_maxmind_db_reader_get, 0, 0, 1)
	ZEND_ARG_INFO(0, ipAddress)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_geoip2_maxmind_db_reader_findaddressintree, 0, 0, 1)
	ZEND_ARG_INFO(0, ipAddress)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_geoip2_maxmind_db_reader_startnode, 0, 0, 1)
	ZEND_ARG_INFO(0, length)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_geoip2_maxmind_db_reader_readnode, 0, 0, 2)
	ZEND_ARG_INFO(0, nodeNumber)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_geoip2_maxmind_db_reader_resolvedatapointer, 0, 0, 1)
	ZEND_ARG_INFO(0, pointer)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_geoip2_maxmind_db_reader_findmetadatastart, 0, 0, 1)
	ZEND_ARG_INFO(0, filename)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(geoip2_maxmind_db_reader_method_entry) {
	PHP_ME(GeoIP2_MaxMind_Db_Reader, __construct, arginfo_geoip2_maxmind_db_reader___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(GeoIP2_MaxMind_Db_Reader, get, arginfo_geoip2_maxmind_db_reader_get, ZEND_ACC_PUBLIC)
	PHP_ME(GeoIP2_MaxMind_Db_Reader, findAddressInTree, arginfo_geoip2_maxmind_db_reader_findaddressintree, ZEND_ACC_PRIVATE)
	PHP_ME(GeoIP2_MaxMind_Db_Reader, startNode, arginfo_geoip2_maxmind_db_reader_startnode, ZEND_ACC_PRIVATE)
	PHP_ME(GeoIP2_MaxMind_Db_Reader, ipV4StartNode, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(GeoIP2_MaxMind_Db_Reader, readNode, arginfo_geoip2_maxmind_db_reader_readnode, ZEND_ACC_PRIVATE)
	PHP_ME(GeoIP2_MaxMind_Db_Reader, resolveDataPointer, arginfo_geoip2_maxmind_db_reader_resolvedatapointer, ZEND_ACC_PRIVATE)
	PHP_ME(GeoIP2_MaxMind_Db_Reader, findMetadataStart, arginfo_geoip2_maxmind_db_reader_findmetadatastart, ZEND_ACC_PRIVATE)
	PHP_ME(GeoIP2_MaxMind_Db_Reader, metadata, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(GeoIP2_MaxMind_Db_Reader, close, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
