
extern zend_class_entry *geoip2_model_abstractmodel_ce;

ZEPHIR_INIT_CLASS(GeoIP2_Model_AbstractModel);

PHP_METHOD(GeoIP2_Model_AbstractModel, __construct);
PHP_METHOD(GeoIP2_Model_AbstractModel, get);
PHP_METHOD(GeoIP2_Model_AbstractModel, __get);
PHP_METHOD(GeoIP2_Model_AbstractModel, __isset);
PHP_METHOD(GeoIP2_Model_AbstractModel, jsonSerialize);
PHP_METHOD(GeoIP2_Model_AbstractModel, json);

ZEND_BEGIN_ARG_INFO_EX(arginfo_geoip2_model_abstractmodel___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, raw)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_geoip2_model_abstractmodel_get, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, field, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, field)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_geoip2_model_abstractmodel___get, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, attr, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, attr)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_geoip2_model_abstractmodel___isset, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, attr, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, attr)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_geoip2_model_abstractmodel_json, 0, 0, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, options, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, options)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(geoip2_model_abstractmodel_method_entry) {
	PHP_ME(GeoIP2_Model_AbstractModel, __construct, arginfo_geoip2_model_abstractmodel___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(GeoIP2_Model_AbstractModel, get, arginfo_geoip2_model_abstractmodel_get, ZEND_ACC_PROTECTED)
	PHP_ME(GeoIP2_Model_AbstractModel, __get, arginfo_geoip2_model_abstractmodel___get, ZEND_ACC_PUBLIC)
	PHP_ME(GeoIP2_Model_AbstractModel, __isset, arginfo_geoip2_model_abstractmodel___isset, ZEND_ACC_PUBLIC)
	PHP_ME(GeoIP2_Model_AbstractModel, jsonSerialize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(GeoIP2_Model_AbstractModel, json, arginfo_geoip2_model_abstractmodel_json, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
