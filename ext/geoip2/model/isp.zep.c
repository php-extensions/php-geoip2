
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
 * This class provides the GeoIP2 ISP model.
 *
 * @property-read int|null autonomousSystemNumber The autonomous system number
 *     associated with the IP address.
 * @property-read string|null autonomousSystemOrganization The organization
 *     associated with the registered autonomous system number for the IP
 *     address.
 * @property-read string|null isp The name of the ISP associated with the IP
 *     address.
 * @property-read string|null organization The name of the organization associated
 *     with the IP address.
 * @property-read string ipAddress The IP address that the data in the model is
 *     for.
 */
ZEPHIR_INIT_CLASS(GeoIP2_Model_Isp) {

	ZEPHIR_REGISTER_CLASS_EX(GeoIP2\\Model, Isp, geoip2, model_isp, geoip2_model_abstractmodel_ce, geoip2_model_isp_method_entry, 0);

	zend_declare_property_null(geoip2_model_isp_ce, SL("autonomousSystemNumber"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(geoip2_model_isp_ce, SL("autonomousSystemOrganization"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(geoip2_model_isp_ce, SL("isp"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(geoip2_model_isp_ce, SL("organization"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(geoip2_model_isp_ce, SL("ipAddress"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * @ignore
 *
 * @param mixed raw
 */
PHP_METHOD(GeoIP2_Model_Isp, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *raw, raw_sub, _1, _2, _3, _4, _5, _6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&raw_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &raw);



	ZEPHIR_CALL_PARENT(NULL, geoip2_model_isp_ce, getThis(), "__construct", &_0, 0, raw);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "autonomous_system_number");
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "get", NULL, 0, &_2);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("autonomousSystemNumber"), &_1);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "autonomous_system_organization");
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "get", NULL, 0, &_2);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("autonomousSystemOrganization"), &_3);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "isp");
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "get", NULL, 0, &_2);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("isp"), &_4);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "organization");
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "get", NULL, 0, &_2);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("organization"), &_5);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "ip_address");
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "get", NULL, 0, &_2);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("ipAddress"), &_6);
	ZEPHIR_MM_RESTORE();

}

