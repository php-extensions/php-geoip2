
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


/**
 * This class represents an error returned by MaxMind's GeoIP2
 * web service.
 */
ZEPHIR_INIT_CLASS(GeoIP2_Exception_InvalidRequestException) {

	ZEPHIR_REGISTER_CLASS_EX(GeoIP2\\Exception, InvalidRequestException, geoip2, exception_invalidrequestexception, geoip2_exception_httpexception_ce, geoip2_exception_invalidrequestexception_method_entry, 0);

	/**
	 * The code returned by the MaxMind web service.
	 */
	zend_declare_property_null(geoip2_exception_invalidrequestexception_ce, SL("error"), ZEND_ACC_PUBLIC TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(GeoIP2_Exception_InvalidRequestException, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_0 = NULL;
	zend_long httpStatus, ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, *error_param = NULL, *httpStatus_param = NULL, *uri_param = NULL, *previous, previous_sub, _1;
	zval message, error, uri;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&error);
	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&previous_sub);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 5, 0, &message_param, &error_param, &httpStatus_param, &uri_param, &previous);

	zephir_get_strval(&message, message_param);
	zephir_get_strval(&error, error_param);
	httpStatus = zephir_get_intval(httpStatus_param);
	zephir_get_strval(&uri, uri_param);


	zephir_update_property_zval(this_ptr, SL("error"), &error);
	ZVAL_LONG(&_1, httpStatus);
	ZEPHIR_CALL_PARENT(NULL, geoip2_exception_invalidrequestexception_ce, getThis(), "__construct", &_0, 0, &message, &_1, &uri, previous);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

