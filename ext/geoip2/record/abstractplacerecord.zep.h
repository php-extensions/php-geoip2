
extern zend_class_entry *geoip2_record_abstractplacerecord_ce;

ZEPHIR_INIT_CLASS(GeoIP2_Record_AbstractPlaceRecord);

PHP_METHOD(GeoIP2_Record_AbstractPlaceRecord, __construct);
PHP_METHOD(GeoIP2_Record_AbstractPlaceRecord, filterLocales);
PHP_METHOD(GeoIP2_Record_AbstractPlaceRecord, __get);
PHP_METHOD(GeoIP2_Record_AbstractPlaceRecord, __isset);
PHP_METHOD(GeoIP2_Record_AbstractPlaceRecord, name);
PHP_METHOD(GeoIP2_Record_AbstractPlaceRecord, firstSetNameLocale);

ZEND_BEGIN_ARG_INFO_EX(arginfo_geoip2_record_abstractplacerecord___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, record)
	ZEND_ARG_ARRAY_INFO(0, locales, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_geoip2_record_abstractplacerecord_filterlocales, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, locales, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_geoip2_record_abstractplacerecord___get, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, attr, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, attr)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_geoip2_record_abstractplacerecord___isset, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, attr, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, attr)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(geoip2_record_abstractplacerecord_method_entry) {
	PHP_ME(GeoIP2_Record_AbstractPlaceRecord, __construct, arginfo_geoip2_record_abstractplacerecord___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(GeoIP2_Record_AbstractPlaceRecord, filterLocales, arginfo_geoip2_record_abstractplacerecord_filterlocales, ZEND_ACC_PROTECTED)
	PHP_ME(GeoIP2_Record_AbstractPlaceRecord, __get, arginfo_geoip2_record_abstractplacerecord___get, ZEND_ACC_PUBLIC)
	PHP_ME(GeoIP2_Record_AbstractPlaceRecord, __isset, arginfo_geoip2_record_abstractplacerecord___isset, ZEND_ACC_PUBLIC)
	PHP_ME(GeoIP2_Record_AbstractPlaceRecord, name, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(GeoIP2_Record_AbstractPlaceRecord, firstSetNameLocale, NULL, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
