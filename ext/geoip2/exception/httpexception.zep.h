
extern zend_class_entry *geoip2_exception_httpexception_ce;

ZEPHIR_INIT_CLASS(GeoIP2_Exception_HttpException);

PHP_METHOD(GeoIP2_Exception_HttpException, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_geoip2_exception_httpexception___construct, 0, 0, 4)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, message)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, httpStatus, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, httpStatus)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, uri, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, uri)
#endif
	ZEND_ARG_INFO(0, previous)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(geoip2_exception_httpexception_method_entry) {
	PHP_ME(GeoIP2_Exception_HttpException, __construct, arginfo_geoip2_exception_httpexception___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
