
extern zend_class_entry *geoip2_record_abstractrecord_ce;

ZEPHIR_INIT_CLASS(GeoIP2_Record_AbstractRecord);

PHP_METHOD(GeoIP2_Record_AbstractRecord, __construct);
PHP_METHOD(GeoIP2_Record_AbstractRecord, __get);
PHP_METHOD(GeoIP2_Record_AbstractRecord, getName);
PHP_METHOD(GeoIP2_Record_AbstractRecord, __isset);
PHP_METHOD(GeoIP2_Record_AbstractRecord, attributeToKey);
PHP_METHOD(GeoIP2_Record_AbstractRecord, validAttribute);
PHP_METHOD(GeoIP2_Record_AbstractRecord, jsonSerialize);
PHP_METHOD(GeoIP2_Record_AbstractRecord, json);
zend_object *zephir_init_properties_GeoIP2_Record_AbstractRecord(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_geoip2_record_abstractrecord___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, record)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_geoip2_record_abstractrecord___get, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, attr, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, attr)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_geoip2_record_abstractrecord_getname, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_geoip2_record_abstractrecord___isset, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, attr, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, attr)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_geoip2_record_abstractrecord_attributetokey, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, attr, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, attr)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_geoip2_record_abstractrecord_validattribute, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, attr, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, attr)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_geoip2_record_abstractrecord_json, 0, 0, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, options, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, options)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(geoip2_record_abstractrecord_method_entry) {
	PHP_ME(GeoIP2_Record_AbstractRecord, __construct, arginfo_geoip2_record_abstractrecord___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(GeoIP2_Record_AbstractRecord, __get, arginfo_geoip2_record_abstractrecord___get, ZEND_ACC_PUBLIC)
	PHP_ME(GeoIP2_Record_AbstractRecord, getName, arginfo_geoip2_record_abstractrecord_getname, ZEND_ACC_PUBLIC)
	PHP_ME(GeoIP2_Record_AbstractRecord, __isset, arginfo_geoip2_record_abstractrecord___isset, ZEND_ACC_PUBLIC)
	PHP_ME(GeoIP2_Record_AbstractRecord, attributeToKey, arginfo_geoip2_record_abstractrecord_attributetokey, ZEND_ACC_PRIVATE)
	PHP_ME(GeoIP2_Record_AbstractRecord, validAttribute, arginfo_geoip2_record_abstractrecord_validattribute, ZEND_ACC_PRIVATE)
	PHP_ME(GeoIP2_Record_AbstractRecord, jsonSerialize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(GeoIP2_Record_AbstractRecord, json, arginfo_geoip2_record_abstractrecord_json, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
