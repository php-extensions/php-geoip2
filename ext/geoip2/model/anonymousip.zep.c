
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
 * This class provides the GeoIP2 Anonymous IP model.
 *
 * @property-read bool isAnonymous This is true if the IP address belongs to
 *     any sort of anonymous network.
 * @property-read bool isAnonymousVpn This is true if the IP address belongs to
 *     an anonymous VPN system.
 * @property-read bool isHostingProvider This is true if the IP address belongs
 *     to a hosting provider.
 * @property-read bool isPublicProxy This is true if the IP address belongs to
 *     a public proxy.
 * @property-read bool isTorExitNode This is true if the IP address is a Tor
 *     exit node.
 * @property-read string ipAddress The IP address that the data in the model is
 *     for.
 */
ZEPHIR_INIT_CLASS(GeoIP2_Model_AnonymousIp) {

	ZEPHIR_REGISTER_CLASS_EX(GeoIP2\\Model, AnonymousIp, geoip2, model_anonymousip, geoip2_model_abstractmodel_ce, geoip2_model_anonymousip_method_entry, 0);

	zend_declare_property_null(geoip2_model_anonymousip_ce, SL("isAnonymous"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(geoip2_model_anonymousip_ce, SL("isAnonymousVpn"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(geoip2_model_anonymousip_ce, SL("isHostingProvider"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(geoip2_model_anonymousip_ce, SL("isPublicProxy"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(geoip2_model_anonymousip_ce, SL("isTorExitNode"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(geoip2_model_anonymousip_ce, SL("ipAddress"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * @ignore
 *
 * @param mixed raw
 */
PHP_METHOD(GeoIP2_Model_AnonymousIp, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *raw, raw_sub, _1, _2, _3, _4, _5, _6, _7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&raw_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &raw);



	ZEPHIR_CALL_PARENT(NULL, geoip2_model_anonymousip_ce, getThis(), "__construct", &_0, 0, raw);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "is_anonymous");
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "get", NULL, 0, &_2);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("isAnonymous"), &_1);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "is_anonymous_vpn");
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "get", NULL, 0, &_2);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("isAnonymousVpn"), &_3);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "is_hosting_provider");
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "get", NULL, 0, &_2);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("isHostingProvider"), &_4);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "is_public_proxy");
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "get", NULL, 0, &_2);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("isPublicProxy"), &_5);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "is_tor_exit_node");
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "get", NULL, 0, &_2);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("isTorExitNode"), &_6);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "ip_address");
	ZEPHIR_CALL_METHOD(&_7, this_ptr, "get", NULL, 0, &_2);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("ipAddress"), &_7);
	ZEPHIR_MM_RESTORE();

}

