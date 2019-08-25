
extern zend_class_entry *geoip2_database_reader_ce;

ZEPHIR_INIT_CLASS(GeoIP2_Database_Reader);

PHP_METHOD(GeoIP2_Database_Reader, __construct);
PHP_METHOD(GeoIP2_Database_Reader, city);
PHP_METHOD(GeoIP2_Database_Reader, country);
PHP_METHOD(GeoIP2_Database_Reader, anonymousIp);
PHP_METHOD(GeoIP2_Database_Reader, asn);
PHP_METHOD(GeoIP2_Database_Reader, connectionType);
PHP_METHOD(GeoIP2_Database_Reader, domain);
PHP_METHOD(GeoIP2_Database_Reader, enterprise);
PHP_METHOD(GeoIP2_Database_Reader, isp);
PHP_METHOD(GeoIP2_Database_Reader, custom);
PHP_METHOD(GeoIP2_Database_Reader, modelFor);
PHP_METHOD(GeoIP2_Database_Reader, flatModelFor);
PHP_METHOD(GeoIP2_Database_Reader, getRecord);
PHP_METHOD(GeoIP2_Database_Reader, metadata);
PHP_METHOD(GeoIP2_Database_Reader, close);

ZEND_BEGIN_ARG_INFO_EX(arginfo_geoip2_database_reader___construct, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, filename)
#endif
	ZEND_ARG_INFO(0, locales)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_geoip2_database_reader_city, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, ipAddress, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, ipAddress)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_geoip2_database_reader_country, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, ipAddress, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, ipAddress)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_geoip2_database_reader_anonymousip, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, ipAddress, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, ipAddress)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_geoip2_database_reader_asn, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, ipAddress, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, ipAddress)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_geoip2_database_reader_connectiontype, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, ipAddress, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, ipAddress)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_geoip2_database_reader_domain, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, ipAddress, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, ipAddress)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_geoip2_database_reader_enterprise, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, ipAddress, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, ipAddress)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_geoip2_database_reader_isp, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, ipAddress, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, ipAddress)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_geoip2_database_reader_custom, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, ipAddress, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, ipAddress)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_geoip2_database_reader_modelfor, 0, 0, 3)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, className, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, className)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, type)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, ipAddress, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, ipAddress)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_geoip2_database_reader_flatmodelfor, 0, 0, 3)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, className, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, className)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, type)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, ipAddress, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, ipAddress)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_geoip2_database_reader_getrecord, 0, 0, 3)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, className, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, className)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, type)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, ipAddress, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, ipAddress)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(geoip2_database_reader_method_entry) {
	PHP_ME(GeoIP2_Database_Reader, __construct, arginfo_geoip2_database_reader___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(GeoIP2_Database_Reader, city, arginfo_geoip2_database_reader_city, ZEND_ACC_PUBLIC)
	PHP_ME(GeoIP2_Database_Reader, country, arginfo_geoip2_database_reader_country, ZEND_ACC_PUBLIC)
	PHP_ME(GeoIP2_Database_Reader, anonymousIp, arginfo_geoip2_database_reader_anonymousip, ZEND_ACC_PUBLIC)
	PHP_ME(GeoIP2_Database_Reader, asn, arginfo_geoip2_database_reader_asn, ZEND_ACC_PUBLIC)
	PHP_ME(GeoIP2_Database_Reader, connectionType, arginfo_geoip2_database_reader_connectiontype, ZEND_ACC_PUBLIC)
	PHP_ME(GeoIP2_Database_Reader, domain, arginfo_geoip2_database_reader_domain, ZEND_ACC_PUBLIC)
	PHP_ME(GeoIP2_Database_Reader, enterprise, arginfo_geoip2_database_reader_enterprise, ZEND_ACC_PUBLIC)
	PHP_ME(GeoIP2_Database_Reader, isp, arginfo_geoip2_database_reader_isp, ZEND_ACC_PUBLIC)
	PHP_ME(GeoIP2_Database_Reader, custom, arginfo_geoip2_database_reader_custom, ZEND_ACC_PUBLIC)
	PHP_ME(GeoIP2_Database_Reader, modelFor, arginfo_geoip2_database_reader_modelfor, ZEND_ACC_PRIVATE)
	PHP_ME(GeoIP2_Database_Reader, flatModelFor, arginfo_geoip2_database_reader_flatmodelfor, ZEND_ACC_PRIVATE)
	PHP_ME(GeoIP2_Database_Reader, getRecord, arginfo_geoip2_database_reader_getrecord, ZEND_ACC_PRIVATE)
	PHP_ME(GeoIP2_Database_Reader, metadata, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(GeoIP2_Database_Reader, close, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
