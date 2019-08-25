
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
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(GeoIP2_Record_AbstractRecord) {

	ZEPHIR_REGISTER_CLASS(GeoIP2\\Record, AbstractRecord, geoip2, record_abstractrecord, geoip2_record_abstractrecord_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(geoip2_record_abstractrecord_ce, SL("validAttributes"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(geoip2_record_abstractrecord_ce, SL("record"), ZEND_ACC_PROTECTED TSRMLS_CC);

	geoip2_record_abstractrecord_ce->create_object = zephir_init_properties_GeoIP2_Record_AbstractRecord;

	zend_class_implements(geoip2_record_abstractrecord_ce TSRMLS_CC, 1, zephir_get_internal_ce(SL("jsonserializable")));
	return SUCCESS;

}

/**
 * @ignore
 *
 * @param mixed $record
 */
PHP_METHOD(GeoIP2_Record_AbstractRecord, __construct) {

	zval *record, record_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&record_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &record);



	if (!(ZEPHIR_IS_EMPTY(record))) {
		zephir_update_property_zval(this_ptr, SL("record"), record);
	}

}

/**
 * @ignore
 *
 * @param mixed $attr
 */
PHP_METHOD(GeoIP2_Record_AbstractRecord, __get) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *attr_param = NULL, key, _0, _1, _8, _2$$3, _3$$3, _4$$4, _5$$4, _6$$4, _7$$4;
	zval attr, _9;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attr);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attr_param);

	zephir_get_strval(&attr, attr_param);


	ZEPHIR_CALL_METHOD(&key, this_ptr, "attributetokey", NULL, 3, &attr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "__isset", NULL, 0, &attr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "validattribute", NULL, 4, &attr);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		zephir_read_property(&_2$$3, this_ptr, SL("record"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_3$$3, &_2$$3, &key, PH_NOISY | PH_READONLY, "geoip2/Record/AbstractRecord.zep", 29 TSRMLS_CC);
		RETURN_CTOR(&_3$$3);
	} else if (zephir_is_true(&_1)) {
		ZEPHIR_INIT_VAR(&_4$$4);
		ZEPHIR_INIT_VAR(&_5$$4);
		ZVAL_STRING(&_5$$4, "/^is_/");
		ZEPHIR_INIT_VAR(&_6$$4);
		ZEPHIR_INIT_VAR(&_7$$4);
		ZVAL_STRING(&_7$$4, "/^is_/");
		zephir_preg_match(&_6$$4, &_7$$4, &key, &_4$$4, 0, 0 , 0  TSRMLS_CC);
		if (zephir_is_true(&_6$$4)) {
			RETURN_MM_BOOL(0);
		}
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(&_8);
	object_init_ex(&_8, spl_ce_RuntimeException);
	ZEPHIR_INIT_VAR(&_9);
	ZEPHIR_CONCAT_SV(&_9, "Unknown attribute: ", &attr);
	ZEPHIR_CALL_METHOD(NULL, &_8, "__construct", NULL, 2, &_9);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_8, "geoip2/Record/AbstractRecord.zep", 36 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

PHP_METHOD(GeoIP2_Record_AbstractRecord, getName) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *name_param = NULL, _0, _1, _2$$3, _3$$3, _4$$3;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	zephir_read_property(&_0, this_ptr, SL("record"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_1, &_0, SL("names"), PH_READONLY, "geoip2/Record/AbstractRecord.zep", 49 TSRMLS_CC);
	if (zephir_array_isset(&_1, &name)) {
		zephir_read_property(&_2$$3, this_ptr, SL("record"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_3$$3, &_2$$3, SL("names"), PH_NOISY | PH_READONLY, "geoip2/Record/AbstractRecord.zep", 50 TSRMLS_CC);
		zephir_array_fetch(&_4$$3, &_3$$3, &name, PH_NOISY | PH_READONLY, "geoip2/Record/AbstractRecord.zep", 50 TSRMLS_CC);
		RETURN_CTOR(&_4$$3);
	}
	RETURN_MM_NULL();

}

PHP_METHOD(GeoIP2_Record_AbstractRecord, __isset) {

	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *attr_param = NULL, _0, _2, _3;
	zval attr;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attr);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attr_param);

	zephir_get_strval(&attr, attr_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "validattribute", NULL, 4, &attr);
	zephir_check_call_status();
	_1 = zephir_is_true(&_0);
	if (_1) {
		zephir_read_property(&_2, this_ptr, SL("record"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_3, this_ptr, "attributetokey", NULL, 3, &attr);
		zephir_check_call_status();
		_1 = zephir_array_isset(&_2, &_3);
	}
	RETURN_MM_BOOL(_1);

}

PHP_METHOD(GeoIP2_Record_AbstractRecord, attributeToKey) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *attr_param = NULL, v, _0, _1;
	zval attr;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attr);
	ZVAL_UNDEF(&v);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attr_param);

	zephir_get_strval(&attr, attr_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "/([A-Z])/");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "_\\1");
	ZEPHIR_CALL_FUNCTION(&v, "preg_replace", NULL, 5, &_0, &_1, &attr);
	zephir_check_call_status();
	zephir_fast_strtolower(return_value, &v);
	RETURN_MM();

}

PHP_METHOD(GeoIP2_Record_AbstractRecord, validAttribute) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *attr_param = NULL, __$true, _0;
	zval attr;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attr);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attr_param);

	zephir_get_strval(&attr, attr_param);


	zephir_read_property(&_0, this_ptr, SL("validAttributes"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_FUNCTION("in_array", NULL, 6, &attr, &_0, &__$true);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(GeoIP2_Record_AbstractRecord, jsonSerialize) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "record");

}

PHP_METHOD(GeoIP2_Record_AbstractRecord, json) {

	zval *options_param = NULL, _0, _1;
	zend_long options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	zephir_fetch_params_without_memory_grow(0, 1, &options_param);

	if (!options_param) {
		options = 0;
	} else {
		options = zephir_get_intval(options_param);
	}


	zephir_read_property(&_0, this_ptr, SL("record"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_1, options);
	zephir_json_encode(return_value, &_0, zephir_get_intval(&_1) );
	return;

}

zend_object *zephir_init_properties_GeoIP2_Record_AbstractRecord(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("record"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("record"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

