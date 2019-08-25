
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
 * This class represents a generic error.
 */
ZEPHIR_INIT_CLASS(GeoIP2_Exception_HttpException) {

	ZEPHIR_REGISTER_CLASS_EX(GeoIP2\\Exception, HttpException, geoip2, exception_httpexception, geoip2_exception_geoip2exception_ce, geoip2_exception_httpexception_method_entry, 0);

	/**
	 *  This class represents an HTTP transport error.
	 */
	zend_declare_property_null(geoip2_exception_httpexception_ce, SL("uri"), ZEND_ACC_PUBLIC TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(GeoIP2_Exception_HttpException, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long httpStatus, ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, *httpStatus_param = NULL, *uri_param = NULL, *previous, previous_sub, _0;
	zval message, uri;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&previous_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &message_param, &httpStatus_param, &uri_param, &previous);

	zephir_get_strval(&message, message_param);
	httpStatus = zephir_get_intval(httpStatus_param);
	zephir_get_strval(&uri, uri_param);


	zephir_update_property_zval(this_ptr, SL("uri"), &uri);
	ZVAL_LONG(&_0, httpStatus);
	ZEPHIR_CALL_PARENT(NULL, geoip2_exception_httpexception_ce, getThis(), "__construct", NULL, 0, &message, &_0, previous);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

