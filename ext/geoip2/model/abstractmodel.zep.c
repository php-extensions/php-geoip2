
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
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/concat.h"


/**
 * @ignore
 */
ZEPHIR_INIT_CLASS(GeoIP2_Model_AbstractModel) {

	ZEPHIR_REGISTER_CLASS(GeoIP2\\Model, AbstractModel, geoip2, model_abstractmodel, geoip2_model_abstractmodel_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(geoip2_model_abstractmodel_ce, SL("attr"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(geoip2_model_abstractmodel_ce, SL("raw"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(geoip2_model_abstractmodel_ce TSRMLS_CC, 1, zephir_get_internal_ce(SL("jsonserializable")));
	return SUCCESS;

}

/**
 * @ignore
 *
 * @param mixed $raw
 */
PHP_METHOD(GeoIP2_Model_AbstractModel, __construct) {

	zval *raw, raw_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&raw_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &raw);



	zephir_update_property_zval(this_ptr, SL("raw"), raw);

}

/**
 * @ignore
 *
 * @param mixed $field
 */
PHP_METHOD(GeoIP2_Model_AbstractModel, get) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *field_param = NULL, _0, _3, _4, _5, _6, _1$$3, _2$$3;
	zval field;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &field_param);

	zephir_get_strval(&field, field_param);


	zephir_read_property(&_0, this_ptr, SL("raw"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_0, &field)) {
		zephir_read_property(&_1$$3, this_ptr, SL("raw"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_2$$3, &_1$$3, &field, PH_NOISY | PH_READONLY, "geoip2/Model/AbstractModel.zep", 26 TSRMLS_CC);
		RETURN_CTOR(&_2$$3);
	}
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "/^is_/");
	ZEPHIR_INIT_VAR(&_5);
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "/^is_/");
	zephir_preg_match(&_5, &_6, &field, &_3, 0, 0 , 0  TSRMLS_CC);
	if (zephir_is_true(&_5)) {
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_NULL();

}

/**
 * @ignore
 *
 * @param mixed $attr
 */
PHP_METHOD(GeoIP2_Model_AbstractModel, __get) {

	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *attr_param = NULL, _1, _3, _2$$3;
	zval attr, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attr);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attr_param);

	zephir_get_strval(&attr, attr_param);


	_0 = !ZEPHIR_IS_STRING(&attr, "instance");
	if (_0) {
		ZEPHIR_CALL_FUNCTION(&_1, "property_exists", NULL, 1, this_ptr, &attr);
		zephir_check_call_status();
		_0 = zephir_is_true(&_1);
	}
	if (_0) {
		ZEPHIR_OBS_VAR(&_2$$3);
		zephir_read_property_zval(&_2$$3, this_ptr, &attr, PH_NOISY_CC);
		RETURN_CCTOR(&_2$$3);
	}
	ZEPHIR_INIT_VAR(&_3);
	object_init_ex(&_3, spl_ce_RuntimeException);
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_SV(&_4, "Unknown attribute: ", &attr);
	ZEPHIR_CALL_METHOD(NULL, &_3, "__construct", NULL, 2, &_4);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_3, "geoip2/Model/AbstractModel.zep", 43 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * @ignore
 *
 * @param mixed $attr
 */
PHP_METHOD(GeoIP2_Model_AbstractModel, __isset) {

	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *attr_param = NULL;
	zval attr;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attr);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attr_param);

	zephir_get_strval(&attr, attr_param);


	_0 = !ZEPHIR_IS_STRING_IDENTICAL(&attr, "instance");
	if (_0) {
		_0 = zephir_isset_property_zval(this_ptr, &attr TSRMLS_CC);
	}
	RETURN_MM_BOOL(_0);

}

PHP_METHOD(GeoIP2_Model_AbstractModel, jsonSerialize) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "raw");

}

PHP_METHOD(GeoIP2_Model_AbstractModel, json) {

	zval *options_param = NULL, _0;
	zend_long options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	zephir_fetch_params_without_memory_grow(0, 1, &options_param);

	if (!options_param) {
		options = 0;
	} else {
		options = zephir_get_intval(options_param);
	}


	ZVAL_LONG(&_0, options);
	zephir_json_encode(return_value, this_ptr, zephir_get_intval(&_0) );
	return;

}

