
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/object.h"


/**
 * This class provides the GeoIP2 Domain model.
 *
 * @property-read string|null domain The second level domain associated with the
 *     IP address. This will be something like "example.com" or
 *     "example.co.uk", not "foo.example.com".
 * @property-read string ipAddress The IP address that the data in the model is
 *     for.
 */
ZEPHIR_INIT_CLASS(GeoIP2_Model_Domain) {

	ZEPHIR_REGISTER_CLASS_EX(GeoIP2\\Model, Domain, geoip2, model_domain, geoip2_model_abstractmodel_ce, geoip2_model_domain_method_entry, 0);

	zend_declare_property_null(geoip2_model_domain_ce, SL("domain"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(geoip2_model_domain_ce, SL("ipAddress"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * @ignore
 *
 * @param mixed raw
 */
PHP_METHOD(GeoIP2_Model_Domain, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *raw, raw_sub, _1, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&raw_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &raw);



	ZEPHIR_CALL_PARENT(NULL, geoip2_model_domain_ce, getThis(), "__construct", &_0, 0, raw);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "domain");
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "get", NULL, 0, &_2);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("domain"), &_1);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "ip_address");
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "get", NULL, 0, &_2);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("ipAddress"), &_3);
	ZEPHIR_MM_RESTORE();

}

