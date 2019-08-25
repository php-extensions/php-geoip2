
extern zend_class_entry *geoip2_model_asn_ce;

ZEPHIR_INIT_CLASS(GeoIP2_Model_Asn);

PHP_METHOD(GeoIP2_Model_Asn, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_geoip2_model_asn___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, raw)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(geoip2_model_asn_method_entry) {
	PHP_ME(GeoIP2_Model_Asn, __construct, arginfo_geoip2_model_asn___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
