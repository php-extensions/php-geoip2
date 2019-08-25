
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/array.h"


/**
 * Contains data about your account.
 *
 * This record is returned by all location services and databases.
 *
 * @property-read int|null $queriesRemaining The number of remaining queries you
 * have for the service you are calling.
 */
ZEPHIR_INIT_CLASS(GeoIP2_Record_MaxMind) {

	ZEPHIR_REGISTER_CLASS_EX(GeoIP2\\Record, MaxMind, geoip2, record_maxmind, geoip2_record_abstractrecord_ce, NULL, 0);

	/**
	 * @ignore
	 */
	zend_declare_property_null(geoip2_record_maxmind_ce, SL("validAttributes"), ZEND_ACC_PROTECTED TSRMLS_CC);

	geoip2_record_maxmind_ce->create_object = zephir_init_properties_GeoIP2_Record_MaxMind;
	return SUCCESS;

}

zend_object *zephir_init_properties_GeoIP2_Record_MaxMind(zend_class_entry *class_type TSRMLS_DC) {

		zval _3$$4;
	zval _0, _2, _1$$3, _4$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_3$$4);

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
		zephir_read_property(&_2, this_ptr, SL("validAttributes"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			zephir_create_array(&_3$$4, 1, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_4$$4);
			ZVAL_STRING(&_4$$4, "queriesRemaining");
			zephir_array_fast_append(&_3$$4, &_4$$4);
			zephir_update_property_zval(this_ptr, SL("validAttributes"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

