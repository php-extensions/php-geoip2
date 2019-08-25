
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
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(GeoIP2_Record_AbstractPlaceRecord) {

	ZEPHIR_REGISTER_CLASS_EX(GeoIP2\\Record, AbstractPlaceRecord, geoip2, record_abstractplacerecord, geoip2_record_abstractrecord_ce, geoip2_record_abstractplacerecord_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(geoip2_record_abstractplacerecord_ce, SL("locales"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * @ignore
 *
 * @param mixed $record
 * @param mixed $locales
 */
PHP_METHOD(GeoIP2_Record_AbstractPlaceRecord, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval locales;
	zval *record, record_sub, *locales_param = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&record_sub);
	ZVAL_UNDEF(&locales);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &record, &locales_param);

	if (!locales_param) {
		ZEPHIR_INIT_VAR(&locales);
		array_init(&locales);
	} else {
		zephir_get_arrval(&locales, locales_param);
	}


	zephir_update_property_zval(this_ptr, SL("locales"), &locales);
	ZEPHIR_CALL_PARENT(NULL, geoip2_record_abstractplacerecord_ce, getThis(), "__construct", &_0, 0, record);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "filterlocales", NULL, 0, &locales);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(GeoIP2_Record_AbstractPlaceRecord, filterLocales) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *locales_param = NULL, locale, _0, _1$$3, _2$$3, _3$$3, *_5$$3, _6$$3, *_7$$8, _8$$8, _19$$8, _9$$9, _10$$9, _11$$10, _12$$10, _13$$10, _14$$11, _15$$11, _16$$12, _17$$12, _18$$12;
	zval locales, validLocales$$3, _4$$3, _locales$$3, names$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&locales);
	ZVAL_UNDEF(&validLocales$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_locales$$3);
	ZVAL_UNDEF(&names$$8);
	ZVAL_UNDEF(&locale);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_8$$8);
	ZVAL_UNDEF(&_19$$8);
	ZVAL_UNDEF(&_9$$9);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_11$$10);
	ZVAL_UNDEF(&_12$$10);
	ZVAL_UNDEF(&_13$$10);
	ZVAL_UNDEF(&_14$$11);
	ZVAL_UNDEF(&_15$$11);
	ZVAL_UNDEF(&_16$$12);
	ZVAL_UNDEF(&_17$$12);
	ZVAL_UNDEF(&_18$$12);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &locales_param);

	zephir_get_arrval(&locales, locales_param);


	zephir_read_property(&_0, this_ptr, SL("record"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_string(&_0, SL("names"))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_read_property(&_2$$3, this_ptr, SL("record"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_3$$3, &_2$$3, SL("names"), PH_NOISY | PH_READONLY, "geoip2/Record/AbstractPlaceRecord.zep", 24 TSRMLS_CC);
		zephir_array_keys(&_1$$3, &_3$$3 TSRMLS_CC);
		zephir_get_arrval(&_4$$3, &_1$$3);
		ZEPHIR_CPY_WRT(&validLocales$$3, &_4$$3);
		ZEPHIR_INIT_VAR(&_locales$$3);
		array_init(&_locales$$3);
		zephir_is_iterable(&locales, 0, "geoip2/Record/AbstractPlaceRecord.zep", 32);
		if (Z_TYPE_P(&locales) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&locales), _5$$3)
			{
				ZEPHIR_INIT_NVAR(&locale);
				ZVAL_COPY(&locale, _5$$3);
				if (zephir_fast_in_array(&locale, &validLocales$$3 TSRMLS_CC)) {
					zephir_array_append(&_locales$$3, &locale, PH_SEPARATE, "geoip2/Record/AbstractPlaceRecord.zep", 29);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &locales, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_6$$3, &locales, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_6$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&locale, &locales, "current", NULL, 0);
				zephir_check_call_status();
					if (zephir_fast_in_array(&locale, &validLocales$$3 TSRMLS_CC)) {
						zephir_array_append(&_locales$$3, &locale, PH_SEPARATE, "geoip2/Record/AbstractPlaceRecord.zep", 29);
					}
				ZEPHIR_CALL_METHOD(NULL, &locales, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&locale);
		if (!(ZEPHIR_IS_EMPTY(&_locales$$3))) {
			ZEPHIR_CPY_WRT(&locales, &_locales$$3);
			ZEPHIR_INIT_VAR(&names$$8);
			array_init(&names$$8);
			zephir_is_iterable(&locales, 0, "geoip2/Record/AbstractPlaceRecord.zep", 42);
			if (Z_TYPE_P(&locales) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&locales), _7$$8)
				{
					ZEPHIR_INIT_NVAR(&locale);
					ZVAL_COPY(&locale, _7$$8);
					zephir_read_property(&_9$$9, this_ptr, SL("record"), PH_NOISY_CC | PH_READONLY);
					zephir_array_fetch_string(&_10$$9, &_9$$9, SL("names"), PH_READONLY, "geoip2/Record/AbstractPlaceRecord.zep", 38 TSRMLS_CC);
					if (zephir_array_isset(&_10$$9, &locale)) {
						zephir_read_property(&_11$$10, this_ptr, SL("record"), PH_NOISY_CC | PH_READONLY);
						zephir_array_fetch_string(&_12$$10, &_11$$10, SL("names"), PH_NOISY | PH_READONLY, "geoip2/Record/AbstractPlaceRecord.zep", 39 TSRMLS_CC);
						zephir_array_fetch(&_13$$10, &_12$$10, &locale, PH_NOISY | PH_READONLY, "geoip2/Record/AbstractPlaceRecord.zep", 39 TSRMLS_CC);
						zephir_array_update_zval(&names$$8, &locale, &_13$$10, PH_COPY | PH_SEPARATE);
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &locales, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_8$$8, &locales, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_8$$8)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&locale, &locales, "current", NULL, 0);
					zephir_check_call_status();
						zephir_read_property(&_14$$11, this_ptr, SL("record"), PH_NOISY_CC | PH_READONLY);
						zephir_array_fetch_string(&_15$$11, &_14$$11, SL("names"), PH_READONLY, "geoip2/Record/AbstractPlaceRecord.zep", 38 TSRMLS_CC);
						if (zephir_array_isset(&_15$$11, &locale)) {
							zephir_read_property(&_16$$12, this_ptr, SL("record"), PH_NOISY_CC | PH_READONLY);
							zephir_array_fetch_string(&_17$$12, &_16$$12, SL("names"), PH_NOISY | PH_READONLY, "geoip2/Record/AbstractPlaceRecord.zep", 39 TSRMLS_CC);
							zephir_array_fetch(&_18$$12, &_17$$12, &locale, PH_NOISY | PH_READONLY, "geoip2/Record/AbstractPlaceRecord.zep", 39 TSRMLS_CC);
							zephir_array_update_zval(&names$$8, &locale, &_18$$12, PH_COPY | PH_SEPARATE);
						}
					ZEPHIR_CALL_METHOD(NULL, &locales, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&locale);
			ZEPHIR_INIT_VAR(&_19$$8);
			ZVAL_STRING(&_19$$8, "names");
			zephir_update_property_array(this_ptr, SL("record"), &_19$$8, &names$$8);
		} else {
			ZEPHIR_CPY_WRT(&locales, &validLocales$$3);
		}
		zephir_update_property_zval(this_ptr, SL("locales"), &locales);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * @ignore
 *
 * @param mixed $attr
 */
PHP_METHOD(GeoIP2_Record_AbstractPlaceRecord, __get) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *attr_param = NULL, _0$$4;
	zval attr;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attr);
	ZVAL_UNDEF(&_0$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attr_param);

	zephir_get_strval(&attr, attr_param);


	if (ZEPHIR_IS_STRING(&attr, "name")) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "name", NULL, 7);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (ZEPHIR_IS_STRING(&attr, "code")) {
		ZEPHIR_CALL_METHOD(&_0$$4, this_ptr, "__isset", NULL, 0, &attr);
		zephir_check_call_status();
		if (!(zephir_is_true(&_0$$4))) {
			ZEPHIR_INIT_NVAR(&attr);
			ZVAL_STRING(&attr, "isoCode");
		}
	}
	if (ZEPHIR_IS_STRING(&attr, "locales")) {
		RETURN_MM_MEMBER(getThis(), "locales");
	}
	ZEPHIR_RETURN_CALL_PARENT(geoip2_record_abstractplacerecord_ce, getThis(), "__get", &_1, 0, &attr);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @ignore
 *
 * @param mixed $attr
 */
PHP_METHOD(GeoIP2_Record_AbstractPlaceRecord, __isset) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *attr_param = NULL, _0$$3, _1$$3;
	zval attr;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attr);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attr_param);

	zephir_get_strval(&attr, attr_param);


	if (ZEPHIR_IS_STRING_IDENTICAL(&attr, "name")) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZEPHIR_CALL_METHOD(&_1$$3, this_ptr, "firstsetnamelocale", NULL, 8);
		zephir_check_call_status();
		if (Z_TYPE_P(&_1$$3) == IS_NULL) {
			ZVAL_BOOL(&_0$$3, 0);
		} else {
			ZVAL_BOOL(&_0$$3, 1);
		}
		RETURN_CCTOR(&_0$$3);
	}
	ZEPHIR_RETURN_CALL_PARENT(geoip2_record_abstractplacerecord_ce, getThis(), "__isset", &_2, 0, &attr);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(GeoIP2_Record_AbstractPlaceRecord, name) {

	zval locale, _0, _1, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&locale);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&locale, this_ptr, "firstsetnamelocale", NULL, 8);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	if (Z_TYPE_P(&locale) == IS_NULL) {
		ZVAL_NULL(&_0);
	} else {
		zephir_read_property(&_1, this_ptr, SL("record"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_2, &_1, SL("names"), PH_NOISY | PH_READONLY, "geoip2/Record/AbstractPlaceRecord.zep", 86 TSRMLS_CC);
		zephir_array_fetch(&_0, &_2, &locale, PH_NOISY, "geoip2/Record/AbstractPlaceRecord.zep", 86 TSRMLS_CC);
	}
	RETURN_CCTOR(&_0);

}

PHP_METHOD(GeoIP2_Record_AbstractPlaceRecord, firstSetNameLocale) {

	zval locale, _0, _1, _2, *_3, _4, _5$$4, _6$$4, _7$$6, _8$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&locale);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$6);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("locales"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "en");
	if (zephir_fast_in_array(&_1, &_0 TSRMLS_CC)) {
		RETURN_MM_STRING("en");
	}
	zephir_read_property(&_2, this_ptr, SL("locales"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_2, 0, "geoip2/Record/AbstractPlaceRecord.zep", 101);
	if (Z_TYPE_P(&_2) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_2), _3)
		{
			ZEPHIR_INIT_NVAR(&locale);
			ZVAL_COPY(&locale, _3);
			zephir_read_property(&_5$$4, this_ptr, SL("record"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch_string(&_6$$4, &_5$$4, SL("names"), PH_READONLY, "geoip2/Record/AbstractPlaceRecord.zep", 97 TSRMLS_CC);
			if (zephir_array_isset(&_6$$4, &locale)) {
				RETURN_CCTOR(&locale);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_2, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_4, &_2, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_4)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&locale, &_2, "current", NULL, 0);
			zephir_check_call_status();
				zephir_read_property(&_7$$6, this_ptr, SL("record"), PH_NOISY_CC | PH_READONLY);
				zephir_array_fetch_string(&_8$$6, &_7$$6, SL("names"), PH_READONLY, "geoip2/Record/AbstractPlaceRecord.zep", 97 TSRMLS_CC);
				if (zephir_array_isset(&_8$$6, &locale)) {
					RETURN_CCTOR(&locale);
				}
			ZEPHIR_CALL_METHOD(NULL, &_2, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&locale);
	RETURN_MM_NULL();

}

