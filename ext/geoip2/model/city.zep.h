
extern zend_class_entry *geoip2_model_city_ce;

ZEPHIR_INIT_CLASS(GeoIP2_Model_City);

PHP_METHOD(GeoIP2_Model_City, __construct);
PHP_METHOD(GeoIP2_Model_City, createSubdivisions);
PHP_METHOD(GeoIP2_Model_City, __get);
PHP_METHOD(GeoIP2_Model_City, __isset);
PHP_METHOD(GeoIP2_Model_City, mostSpecificSubdivision);
zend_object *zephir_init_properties_GeoIP2_Model_City(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_geoip2_model_city___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, raw)
	ZEND_ARG_ARRAY_INFO(0, locales, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_geoip2_model_city_createsubdivisions, 0, 0, 2)
	ZEND_ARG_INFO(0, raw)
	ZEND_ARG_ARRAY_INFO(0, locales, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_geoip2_model_city___get, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, attr, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, attr)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_geoip2_model_city___isset, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, attr, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, attr)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(geoip2_model_city_method_entry) {
	PHP_ME(GeoIP2_Model_City, __construct, arginfo_geoip2_model_city___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(GeoIP2_Model_City, createSubdivisions, arginfo_geoip2_model_city_createsubdivisions, ZEND_ACC_PRIVATE)
	PHP_ME(GeoIP2_Model_City, __get, arginfo_geoip2_model_city___get, ZEND_ACC_PUBLIC)
	PHP_ME(GeoIP2_Model_City, __isset, arginfo_geoip2_model_city___isset, ZEND_ACC_PUBLIC)
	PHP_ME(GeoIP2_Model_City, mostSpecificSubdivision, NULL, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
