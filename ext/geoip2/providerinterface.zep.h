
extern zend_class_entry *geoip2_providerinterface_ce;

ZEPHIR_INIT_CLASS(GeoIP2_ProviderInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_geoip2_providerinterface_country, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, ipAddress, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, ipAddress)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_geoip2_providerinterface_city, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, ipAddress, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, ipAddress)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(geoip2_providerinterface_method_entry) {
	PHP_ABSTRACT_ME(GeoIP2_ProviderInterface, country, arginfo_geoip2_providerinterface_country)
	PHP_ABSTRACT_ME(GeoIP2_ProviderInterface, city, arginfo_geoip2_providerinterface_city)
	PHP_FE_END
};
