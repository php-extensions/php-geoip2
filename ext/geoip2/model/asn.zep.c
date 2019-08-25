
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
 * This class provides the GeoLite2 ASN model.
 *
 * @property-read int|null autonomousSystemNumber The autonomous system number
 *     associated with the IP address.
 * @property-read string|null autonomousSystemOrganization The organization
 *     associated with the registered autonomous system number for the IP
 *     address.
 * @property-read string ipAddress The IP address that the data in the model is
 *     for.
 */
ZEPHIR_INIT_CLASS(GeoIP2_Model_Asn) {

	ZEPHIR_REGISTER_CLASS_EX(GeoIP2\\Model, Asn, geoip2, model_asn, geoip2_model_abstractmodel_ce, geoip2_model_asn_method_entry, 0);

	zend_declare_property_null(geoip2_model_asn_ce, SL("autonomousSystemNumber"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(geoip2_model_asn_ce, SL("autonomousSystemOrganization"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(geoip2_model_asn_ce, SL("ipAddress"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * @ignore
 *
 * @param mixed raw
 */
PHP_METHOD(GeoIP2_Model_Asn, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *raw, raw_sub, _1, _2, _3, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&raw_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &raw);



	ZEPHIR_CALL_PARENT(NULL, geoip2_model_asn_ce, getThis(), "__construct", &_0, 0, raw);
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
	ZVAL_STRING(&_2, "ip_address");
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "get", NULL, 0, &_2);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("ipAddress"), &_4);
	ZEPHIR_MM_RESTORE();

}

