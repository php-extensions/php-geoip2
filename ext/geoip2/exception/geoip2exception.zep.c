
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


/**
 * This class represents a generic error.
 */
ZEPHIR_INIT_CLASS(GeoIP2_Exception_GeoIP2Exception) {

	ZEPHIR_REGISTER_CLASS_EX(GeoIP2\\Exception, GeoIP2Exception, geoip2, exception_geoip2exception, zend_exception_get_default(TSRMLS_C), NULL, 0);

	return SUCCESS;

}

