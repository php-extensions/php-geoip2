
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"


ZEPHIR_INIT_CLASS(GeoIP2_MaxMind_Db_Reader_Decoder) {

	ZEPHIR_REGISTER_CLASS(GeoIP2\\MaxMind\\Db\\Reader, Decoder, geoip2, maxmind_db_reader_decoder, geoip2_maxmind_db_reader_decoder_method_entry, 0);

	zend_declare_property_null(geoip2_maxmind_db_reader_decoder_ce, SL("fileStream"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(geoip2_maxmind_db_reader_decoder_ce, SL("pointerBase"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(geoip2_maxmind_db_reader_decoder_ce, SL("pointerBaseByteSize"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(geoip2_maxmind_db_reader_decoder_ce, SL("pointerTestHack"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(geoip2_maxmind_db_reader_decoder_ce, SL("switchByteOrder"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(geoip2_maxmind_db_reader_decoder_ce, SL("maxIntBytes"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zephir_declare_class_constant_long(geoip2_maxmind_db_reader_decoder_ce, SL("_EXTENDED"), 0);

	zephir_declare_class_constant_long(geoip2_maxmind_db_reader_decoder_ce, SL("_POINTER"), 1);

	zephir_declare_class_constant_long(geoip2_maxmind_db_reader_decoder_ce, SL("_UTF8_STRING"), 2);

	zephir_declare_class_constant_long(geoip2_maxmind_db_reader_decoder_ce, SL("_DOUBLE"), 3);

	zephir_declare_class_constant_long(geoip2_maxmind_db_reader_decoder_ce, SL("_BYTES"), 4);

	zephir_declare_class_constant_long(geoip2_maxmind_db_reader_decoder_ce, SL("_UINT16"), 5);

	zephir_declare_class_constant_long(geoip2_maxmind_db_reader_decoder_ce, SL("_UINT32"), 6);

	zephir_declare_class_constant_long(geoip2_maxmind_db_reader_decoder_ce, SL("_MAP"), 7);

	zephir_declare_class_constant_long(geoip2_maxmind_db_reader_decoder_ce, SL("_INT32"), 8);

	zephir_declare_class_constant_long(geoip2_maxmind_db_reader_decoder_ce, SL("_UINT64"), 9);

	zephir_declare_class_constant_long(geoip2_maxmind_db_reader_decoder_ce, SL("_UINT128"), 10);

	zephir_declare_class_constant_long(geoip2_maxmind_db_reader_decoder_ce, SL("_ARRAY"), 11);

	zephir_declare_class_constant_long(geoip2_maxmind_db_reader_decoder_ce, SL("_CONTAINER"), 12);

	zephir_declare_class_constant_long(geoip2_maxmind_db_reader_decoder_ce, SL("_END_MARKER"), 13);

	zephir_declare_class_constant_long(geoip2_maxmind_db_reader_decoder_ce, SL("_BOOLEAN"), 14);

	zephir_declare_class_constant_long(geoip2_maxmind_db_reader_decoder_ce, SL("_FLOAT"), 15);

	return SUCCESS;

}

PHP_METHOD(GeoIP2_MaxMind_Db_Reader_Decoder, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_3 = NULL;
	zval *fileStream, fileStream_sub, *pointerBase = NULL, pointerBase_sub, *pointerTestHack = NULL, pointerTestHack_sub, __$false, _0, _1, _2, _4, _5, _6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&fileStream_sub);
	ZVAL_UNDEF(&pointerBase_sub);
	ZVAL_UNDEF(&pointerTestHack_sub);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &fileStream, &pointerBase, &pointerTestHack);

	if (!pointerBase) {
		pointerBase = &pointerBase_sub;
		ZEPHIR_INIT_VAR(pointerBase);
		ZVAL_LONG(pointerBase, 0);
	}
	if (!pointerTestHack) {
		pointerTestHack = &pointerTestHack_sub;
		pointerTestHack = &__$false;
	}


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_MM_GET_CONSTANT(&_0, "PHP_INT_MAX");
	ZVAL_LONG(&_1, 2);
	ZEPHIR_CALL_FUNCTION(&_2, "log", &_3, 43, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_DOUBLE(&_1, zephir_safe_div_long_long((zephir_get_numberval(&_2) - 1), 8 TSRMLS_CC));
	zephir_update_property_zval(this_ptr, SL("maxIntBytes"), &_1);
	zephir_update_property_zval(this_ptr, SL("fileStream"), fileStream);
	zephir_update_property_zval(this_ptr, SL("pointerBase"), pointerBase);
	ZEPHIR_INIT_VAR(&_4);
	if (ZEPHIR_GT_LONG(pointerBase, 0)) {
		ZVAL_LONG(&_1, 2);
		ZEPHIR_CALL_FUNCTION(&_5, "log", &_3, 43, pointerBase, &_1);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_4);
		ZVAL_DOUBLE(&_4, zephir_safe_div_zval_long(&_5, 8 TSRMLS_CC));
	} else {
		ZEPHIR_INIT_NVAR(&_4);
		ZVAL_LONG(&_4, 0);
	}
	zephir_update_property_zval(this_ptr, SL("pointerBaseByteSize"), &_4);
	zephir_update_property_zval(this_ptr, SL("pointerTestHack"), pointerTestHack);
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "isplatformlittleendian", NULL, 44);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("switchByteOrder"), &_6);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(GeoIP2_MaxMind_Db_Reader_Decoder, decode) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_1 = NULL, *_6 = NULL;
	zval *offset_param = NULL, ctrlByte, type, pointer, pointerOffset, result, nextByte, sizeOffset, _0, _2, _3, _4, _5, _7, _20, _8$$3, _9$$3, _10$$3, _11$$3, _12$$5, _13$$5, _14$$5, _15$$5, _16$$5, _17$$5, _18$$6, _19$$6;
	zend_long offset, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ctrlByte);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&pointer);
	ZVAL_UNDEF(&pointerOffset);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&nextByte);
	ZVAL_UNDEF(&sizeOffset);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&_17$$5);
	ZVAL_UNDEF(&_18$$6);
	ZVAL_UNDEF(&_19$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &offset_param);

	offset = zephir_get_intval(offset_param);


	zephir_read_property(&_2, this_ptr, SL("fileStream"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_3, offset);
	ZVAL_LONG(&_4, 1);
	ZEPHIR_CALL_CE_STATIC(&_0, geoip2_maxmind_db_reader_util_ce, "read", &_1, 0, &_2, &_3, &_4);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "C");
	ZEPHIR_CALL_FUNCTION(&ctrlByte, "unpack", &_6, 32, &_5, &_0);
	zephir_check_call_status();
	zephir_array_fetch_long(&_7, &ctrlByte, 1, PH_NOISY | PH_READONLY, "geoip2/MaxMind/Db/Reader/Decoder.zep", 50 TSRMLS_CC);
	ZEPHIR_CPY_WRT(&ctrlByte, &_7);
	offset++;
	ZEPHIR_INIT_VAR(&type);
	ZVAL_LONG(&type, ((int) (zephir_get_numberval(&ctrlByte)) >> 5));
	if (ZEPHIR_IS_LONG_IDENTICAL(&type, 1)) {
		ZVAL_LONG(&_8$$3, offset);
		ZEPHIR_CALL_METHOD(&pointerOffset, this_ptr, "decodepointer", NULL, 45, &ctrlByte, &_8$$3);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(&pointer);
		zephir_array_fetch_long(&pointer, &pointerOffset, 0, PH_NOISY, "geoip2/MaxMind/Db/Reader/Decoder.zep", 58 TSRMLS_CC);
		ZEPHIR_OBS_VAR(&_9$$3);
		zephir_array_fetch_long(&_9$$3, &pointerOffset, 1, PH_NOISY, "geoip2/MaxMind/Db/Reader/Decoder.zep", 59 TSRMLS_CC);
		offset = zephir_get_intval(&_9$$3);
		zephir_read_property(&_8$$3, this_ptr, SL("pointerTestHack"), PH_NOISY_CC | PH_READONLY);
		if (zephir_is_true(&_8$$3)) {
			zephir_create_array(return_value, 1, 0 TSRMLS_CC);
			zephir_array_fast_append(return_value, &pointer);
			RETURN_MM();
		}
		ZEPHIR_CALL_METHOD(&result, this_ptr, "decode", NULL, 24, &pointer);
		zephir_check_call_status();
		zephir_create_array(return_value, 2, 0 TSRMLS_CC);
		ZEPHIR_OBS_VAR(&_10$$3);
		zephir_array_fetch_long(&_10$$3, &result, 0, PH_NOISY, "geoip2/MaxMind/Db/Reader/Decoder.zep", 65 TSRMLS_CC);
		zephir_array_fast_append(return_value, &_10$$3);
		ZEPHIR_INIT_VAR(&_11$$3);
		ZVAL_LONG(&_11$$3, offset);
		zephir_array_fast_append(return_value, &_11$$3);
		RETURN_MM();
	}
	if (ZEPHIR_IS_LONG_IDENTICAL(&type, 0)) {
		zephir_read_property(&_13$$5, this_ptr, SL("fileStream"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_14$$5, offset);
		ZVAL_LONG(&_15$$5, 1);
		ZEPHIR_CALL_CE_STATIC(&_12$$5, geoip2_maxmind_db_reader_util_ce, "read", &_1, 0, &_13$$5, &_14$$5, &_15$$5);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_16$$5);
		ZVAL_STRING(&_16$$5, "C");
		ZEPHIR_CALL_FUNCTION(&nextByte, "unpack", &_6, 32, &_16$$5, &_12$$5);
		zephir_check_call_status();
		zephir_array_fetch_long(&_17$$5, &nextByte, 1, PH_NOISY | PH_READONLY, "geoip2/MaxMind/Db/Reader/Decoder.zep", 72 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(&type);
		ZVAL_LONG(&type, (zephir_get_numberval(&_17$$5) + 7));
		if (ZEPHIR_LT_LONG(&type, 8)) {
			ZEPHIR_INIT_VAR(&_18$$6);
			object_init_ex(&_18$$6, geoip2_maxmind_db_reader_invaliddatabaseexception_ce);
			ZEPHIR_INIT_VAR(&_19$$6);
			ZEPHIR_CONCAT_SSVS(&_19$$6, "Something went horribly wrong in the decoder. An extended type ", "resolved to a type number < 8 (", &type, ")");
			ZEPHIR_CALL_METHOD(NULL, &_18$$6, "__construct", NULL, 17, &_19$$6);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_18$$6, "geoip2/MaxMind/Db/Reader/Decoder.zep", 79 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		offset++;
	}
	ZVAL_LONG(&_3, offset);
	ZEPHIR_CALL_METHOD(&sizeOffset, this_ptr, "sizefromctrlbyte", NULL, 46, &ctrlByte, &_3);
	zephir_check_call_status();
	zephir_array_fetch_long(&_7, &sizeOffset, 1, PH_NOISY | PH_READONLY, "geoip2/MaxMind/Db/Reader/Decoder.zep", 84 TSRMLS_CC);
	zephir_array_fetch_long(&_20, &sizeOffset, 0, PH_NOISY | PH_READONLY, "geoip2/MaxMind/Db/Reader/Decoder.zep", 84 TSRMLS_CC);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "decodebytype", NULL, 47, &type, &_7, &_20);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(GeoIP2_MaxMind_Db_Reader_Decoder, decodeByType) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL, *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, newOffset = 0;
	zval *type, type_sub, *offset, offset_sub, *size, size_sub, bytes, _1, _3, _0$$5, _4$$6, _5$$7, _7$$7, _8$$7, _9$$8, _10$$8, _11$$8, _12$$9, _13$$9, _14$$10, _15$$10, _16$$11, _17$$11;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type_sub);
	ZVAL_UNDEF(&offset_sub);
	ZVAL_UNDEF(&size_sub);
	ZVAL_UNDEF(&bytes);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_0$$5);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_12$$9);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_14$$10);
	ZVAL_UNDEF(&_15$$10);
	ZVAL_UNDEF(&_16$$11);
	ZVAL_UNDEF(&_17$$11);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &type, &offset, &size);



	do {
		if (ZEPHIR_IS_LONG(type, 7)) {
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "decodemap", NULL, 48, size, offset);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(type, 11)) {
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "decodearray", NULL, 49, size, offset);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(type, 14)) {
			zephir_create_array(return_value, 2, 0 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_0$$5, this_ptr, "decodeboolean", NULL, 50, size);
			zephir_check_call_status();
			zephir_array_fast_append(return_value, &_0$$5);
			zephir_array_fast_append(return_value, offset);
			RETURN_MM();
		}
	} while(0);

	ZEPHIR_INIT_VAR(&_1);
	zephir_add_function(&_1, offset, size);
	newOffset = zephir_get_numberval(&_1);
	zephir_read_property(&_3, this_ptr, SL("fileStream"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_CE_STATIC(&bytes, geoip2_maxmind_db_reader_util_ce, "read", &_2, 0, &_3, offset, size);
	zephir_check_call_status();
	do {
		if (ZEPHIR_IS_LONG(type, 4) || ZEPHIR_IS_LONG(type, 2)) {
			zephir_create_array(return_value, 2, 0 TSRMLS_CC);
			zephir_array_fast_append(return_value, &bytes);
			ZEPHIR_INIT_VAR(&_4$$6);
			ZVAL_LONG(&_4$$6, newOffset);
			zephir_array_fast_append(return_value, &_4$$6);
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(type, 3)) {
			ZVAL_LONG(&_5$$7, 8);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "verifysize", &_6, 51, &_5$$7, size);
			zephir_check_call_status();
			zephir_create_array(return_value, 2, 0 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_7$$7, this_ptr, "decodedouble", NULL, 52, &bytes);
			zephir_check_call_status();
			zephir_array_fast_append(return_value, &_7$$7);
			ZEPHIR_INIT_VAR(&_8$$7);
			ZVAL_LONG(&_8$$7, newOffset);
			zephir_array_fast_append(return_value, &_8$$7);
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(type, 15)) {
			ZVAL_LONG(&_9$$8, 4);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "verifysize", &_6, 51, &_9$$8, size);
			zephir_check_call_status();
			zephir_create_array(return_value, 2, 0 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_10$$8, this_ptr, "decodefloat", NULL, 53, &bytes);
			zephir_check_call_status();
			zephir_array_fast_append(return_value, &_10$$8);
			ZEPHIR_INIT_VAR(&_11$$8);
			ZVAL_LONG(&_11$$8, newOffset);
			zephir_array_fast_append(return_value, &_11$$8);
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(type, 8)) {
			zephir_create_array(return_value, 2, 0 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_12$$9, this_ptr, "decodeint32", NULL, 54, &bytes, size);
			zephir_check_call_status();
			zephir_array_fast_append(return_value, &_12$$9);
			ZEPHIR_INIT_VAR(&_13$$9);
			ZVAL_LONG(&_13$$9, newOffset);
			zephir_array_fast_append(return_value, &_13$$9);
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(type, 5) || ZEPHIR_IS_LONG(type, 6) || ZEPHIR_IS_LONG(type, 9) || ZEPHIR_IS_LONG(type, 10)) {
			zephir_create_array(return_value, 2, 0 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_14$$10, this_ptr, "decodeuint", NULL, 55, &bytes, size);
			zephir_check_call_status();
			zephir_array_fast_append(return_value, &_14$$10);
			ZEPHIR_INIT_VAR(&_15$$10);
			ZVAL_LONG(&_15$$10, newOffset);
			zephir_array_fast_append(return_value, &_15$$10);
			RETURN_MM();
		}
		ZEPHIR_INIT_VAR(&_16$$11);
		object_init_ex(&_16$$11, geoip2_maxmind_db_reader_invaliddatabaseexception_ce);
		ZEPHIR_INIT_VAR(&_17$$11);
		ZEPHIR_CONCAT_SV(&_17$$11, "Unknown or unexpected type: ", type);
		ZEPHIR_CALL_METHOD(NULL, &_16$$11, "__construct", NULL, 17, &_17$$11);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_16$$11, "geoip2/MaxMind/Db/Reader/Decoder.zep", 122 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	} while(0);

	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(GeoIP2_MaxMind_Db_Reader_Decoder, verifySize) {

	zval *expected, expected_sub, *actual, actual_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expected_sub);
	ZVAL_UNDEF(&actual_sub);

	zephir_fetch_params_without_memory_grow(2, 0, &expected, &actual);



	if (!ZEPHIR_IS_IDENTICAL(expected, actual)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(geoip2_maxmind_db_reader_invaliddatabaseexception_ce, "The MaxMind DB file's data section contains bad data (unknown data type or corrupt data)", "geoip2/MaxMind/Db/Reader/Decoder.zep", 130);
		return;
	}

}

PHP_METHOD(GeoIP2_MaxMind_Db_Reader_Decoder, decodeArray) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_0 = NULL, *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, i = 0;
	zval *size, size_sub, *offset = NULL, offset_sub, _array, value_offset, value;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&size_sub);
	ZVAL_UNDEF(&offset_sub);
	ZVAL_UNDEF(&_array);
	ZVAL_UNDEF(&value_offset);
	ZVAL_UNDEF(&value);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &size, &offset);

	ZEPHIR_SEPARATE_PARAM(offset);


	ZEPHIR_INIT_VAR(&_array);
	array_init(&_array);
	i = 0;
	while (1) {
		if (!(ZEPHIR_GT_LONG(size, i))) {
			break;
		}
		ZEPHIR_CALL_METHOD(&value_offset, this_ptr, "decode", &_0, 0, offset);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(&value);
		zephir_array_fetch_long(&value, &value_offset, 0, PH_NOISY, "geoip2/MaxMind/Db/Reader/Decoder.zep", 140 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(offset);
		zephir_array_fetch_long(offset, &value_offset, 1, PH_NOISY, "geoip2/MaxMind/Db/Reader/Decoder.zep", 141 TSRMLS_CC);
		ZEPHIR_MAKE_REF(&_array);
		ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_1, 56, &_array, &value);
		ZEPHIR_UNREF(&_array);
		zephir_check_call_status();
		i++;
	}
	zephir_create_array(return_value, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(return_value, &_array);
	zephir_array_fast_append(return_value, offset);
	RETURN_MM();

}

PHP_METHOD(GeoIP2_MaxMind_Db_Reader_Decoder, decodeBoolean) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *size, size_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&size_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &size);



	ZEPHIR_INIT_VAR(&_0);
	if (ZEPHIR_IS_LONG_IDENTICAL(size, 0)) {
		ZVAL_BOOL(&_0, 0);
	} else {
		ZVAL_BOOL(&_0, 1);
	}
	RETURN_CCTOR(&_0);

}

PHP_METHOD(GeoIP2_MaxMind_Db_Reader_Decoder, decodeDouble) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *bits, bits_sub, _double, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&bits_sub);
	ZVAL_UNDEF(&_double);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &bits);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "maybeswitchbyteorder", NULL, 57, bits);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "d");
	ZEPHIR_CALL_FUNCTION(&_double, "unpack", NULL, 32, &_1, &_0);
	zephir_check_call_status();
	zephir_array_fetch_long(&_2, &_double, 1, PH_NOISY | PH_READONLY, "geoip2/MaxMind/Db/Reader/Decoder.zep", 161 TSRMLS_CC);
	ZEPHIR_CPY_WRT(&_double, &_2);
	RETURN_CCTOR(&_double);

}

PHP_METHOD(GeoIP2_MaxMind_Db_Reader_Decoder, decodeFloat) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *bits, bits_sub, _float, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&bits_sub);
	ZVAL_UNDEF(&_float);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &bits);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "maybeswitchbyteorder", NULL, 57, bits);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "f");
	ZEPHIR_CALL_FUNCTION(&_float, "unpack", NULL, 32, &_1, &_0);
	zephir_check_call_status();
	zephir_array_fetch_long(&_2, &_float, 1, PH_NOISY | PH_READONLY, "geoip2/MaxMind/Db/Reader/Decoder.zep", 174 TSRMLS_CC);
	ZEPHIR_CPY_WRT(&_float, &_2);
	RETURN_CCTOR(&_float);

}

PHP_METHOD(GeoIP2_MaxMind_Db_Reader_Decoder, decodeInt32) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *bytes = NULL, bytes_sub, *size, size_sub, _int, _5, _6, _7, _0$$4, _1$$4, _2$$4, _3$$4, _4$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&bytes_sub);
	ZVAL_UNDEF(&size_sub);
	ZVAL_UNDEF(&_int);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &bytes, &size);

	ZEPHIR_SEPARATE_PARAM(bytes);


	do {
		if (ZEPHIR_IS_LONG(size, 0)) {
			RETURN_MM_LONG(0);
		}
		if (ZEPHIR_IS_LONG(size, 1) || ZEPHIR_IS_LONG(size, 2) || ZEPHIR_IS_LONG(size, 3)) {
			ZEPHIR_INIT_VAR(&_0$$4);
			ZVAL_STRING(&_0$$4, "00");
			ZEPHIR_CALL_FUNCTION(&_1$$4, "hex2bin", NULL, 18, &_0$$4);
			zephir_check_call_status();
			ZVAL_LONG(&_2$$4, 4);
			ZVAL_LONG(&_3$$4, 0);
			ZEPHIR_CALL_FUNCTION(&_4$$4, "str_pad", NULL, 58, bytes, &_2$$4, &_1$$4, &_3$$4);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(bytes, &_4$$4);
			break;
		}
		if (ZEPHIR_IS_LONG(size, 4)) {
			break;
		}
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(geoip2_maxmind_db_reader_invaliddatabaseexception_ce, "The MaxMind DB file's data section contains bad data (unknown data type or corrupt data)", "geoip2/MaxMind/Db/Reader/Decoder.zep", 193);
		return;
	} while(0);

	ZEPHIR_CALL_METHOD(&_5, this_ptr, "maybeswitchbyteorder", NULL, 57, bytes);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "l");
	ZEPHIR_CALL_FUNCTION(&_int, "unpack", NULL, 32, &_6, &_5);
	zephir_check_call_status();
	zephir_array_fetch_long(&_7, &_int, 1, PH_NOISY | PH_READONLY, "geoip2/MaxMind/Db/Reader/Decoder.zep", 196 TSRMLS_CC);
	ZEPHIR_CPY_WRT(&_int, &_7);
	RETURN_CCTOR(&_int);

}

PHP_METHOD(GeoIP2_MaxMind_Db_Reader_Decoder, decodeMap) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_0 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, i = 0;
	zval *size, size_sub, *offset = NULL, offset_sub, map, key_offset, key, value_offset, value;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&size_sub);
	ZVAL_UNDEF(&offset_sub);
	ZVAL_UNDEF(&map);
	ZVAL_UNDEF(&key_offset);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value_offset);
	ZVAL_UNDEF(&value);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &size, &offset);

	ZEPHIR_SEPARATE_PARAM(offset);


	ZEPHIR_INIT_VAR(&map);
	array_init(&map);
	i = 0;
	while (1) {
		if (!(ZEPHIR_GT_LONG(size, i))) {
			break;
		}
		ZEPHIR_CALL_METHOD(&key_offset, this_ptr, "decode", &_0, 0, offset);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(&key);
		zephir_array_fetch_long(&key, &key_offset, 0, PH_NOISY, "geoip2/MaxMind/Db/Reader/Decoder.zep", 206 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(offset);
		zephir_array_fetch_long(offset, &key_offset, 1, PH_NOISY, "geoip2/MaxMind/Db/Reader/Decoder.zep", 207 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&value_offset, this_ptr, "decode", &_0, 24, offset);
		zephir_check_call_status();
		zephir_array_fetch_long(&value, &value_offset, 0, PH_NOISY | PH_READONLY, "geoip2/MaxMind/Db/Reader/Decoder.zep", 209 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(offset);
		zephir_array_fetch_long(offset, &value_offset, 1, PH_NOISY, "geoip2/MaxMind/Db/Reader/Decoder.zep", 210 TSRMLS_CC);
		zephir_array_update_zval(&map, &key, &value, PH_COPY | PH_SEPARATE);
		i++;
	}
	zephir_create_array(return_value, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(return_value, &map);
	zephir_array_fast_append(return_value, offset);
	RETURN_MM();

}

PHP_METHOD(GeoIP2_MaxMind_Db_Reader_Decoder, decodePointer) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, pointerSize = 0, pointer = 0, pointerOffset = 0, byteLength = 0, _3;
	zephir_fcall_cache_entry *_0 = NULL, *_7 = NULL, *_8 = NULL;
	zval *ctrlByte, ctrlByte_sub, *offset = NULL, offset_sub, buffer, packed, _pointer, _1, _2, _33, _4$$3, _5$$3, _6$$3, _9$$3, _10$$4, _11$$4, _12$$4, _13$$4, _14$$4, _15$$5, _16$$5, _17$$5, _18$$5, _19$$6, _20$$6, _21$$6, _22$$6, _23$$6, _24$$6, _25$$7, _26$$8, _27$$8, _28$$8, _29$$8, _30$$9, _31$$9, _32$$9;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ctrlByte_sub);
	ZVAL_UNDEF(&offset_sub);
	ZVAL_UNDEF(&buffer);
	ZVAL_UNDEF(&packed);
	ZVAL_UNDEF(&_pointer);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_33);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&_14$$4);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&_17$$5);
	ZVAL_UNDEF(&_18$$5);
	ZVAL_UNDEF(&_19$$6);
	ZVAL_UNDEF(&_20$$6);
	ZVAL_UNDEF(&_21$$6);
	ZVAL_UNDEF(&_22$$6);
	ZVAL_UNDEF(&_23$$6);
	ZVAL_UNDEF(&_24$$6);
	ZVAL_UNDEF(&_25$$7);
	ZVAL_UNDEF(&_26$$8);
	ZVAL_UNDEF(&_27$$8);
	ZVAL_UNDEF(&_28$$8);
	ZVAL_UNDEF(&_29$$8);
	ZVAL_UNDEF(&_30$$9);
	ZVAL_UNDEF(&_31$$9);
	ZVAL_UNDEF(&_32$$9);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &ctrlByte, &offset);

	ZEPHIR_SEPARATE_PARAM(offset);


	pointerSize = ((((((int) (zephir_get_numberval(ctrlByte)) >> 3)) & 0x3)) + 1);
	zephir_read_property(&_1, this_ptr, SL("fileStream"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_2, pointerSize);
	ZEPHIR_CALL_CE_STATIC(&buffer, geoip2_maxmind_db_reader_util_ce, "read", &_0, 0, &_1, offset, &_2);
	zephir_check_call_status();
	_3 = (zephir_get_numberval(offset) + pointerSize);
	ZEPHIR_INIT_NVAR(offset);
	ZVAL_LONG(offset, _3);
	do {
		if (pointerSize == 1) {
			ZEPHIR_INIT_VAR(&_4$$3);
			ZVAL_STRING(&_4$$3, "C");
			ZVAL_LONG(&_5$$3, ((int) (zephir_get_numberval(ctrlByte)) & 0x7));
			ZEPHIR_CALL_FUNCTION(&_6$$3, "pack", &_7, 59, &_4$$3, &_5$$3);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&packed);
			ZEPHIR_CONCAT_VV(&packed, &_6$$3, &buffer);
			ZEPHIR_INIT_NVAR(&_4$$3);
			ZVAL_STRING(&_4$$3, "n");
			ZEPHIR_CALL_FUNCTION(&_pointer, "unpack", &_8, 32, &_4$$3, &packed);
			zephir_check_call_status();
			ZEPHIR_OBS_VAR(&_9$$3);
			zephir_array_fetch_long(&_9$$3, &_pointer, 1, PH_NOISY, "geoip2/MaxMind/Db/Reader/Decoder.zep", 228 TSRMLS_CC);
			pointer = zephir_get_intval(&_9$$3);
			zephir_read_property(&_5$$3, this_ptr, SL("pointerBase"), PH_NOISY_CC | PH_READONLY);
			pointer += zephir_get_numberval(&_5$$3);
			break;
		}
		if (pointerSize == 2) {
			ZEPHIR_INIT_VAR(&_10$$4);
			ZVAL_STRING(&_10$$4, "00");
			ZEPHIR_CALL_FUNCTION(&_11$$4, "hex2bin", NULL, 18, &_10$$4);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_10$$4);
			ZVAL_STRING(&_10$$4, "C");
			ZVAL_LONG(&_12$$4, ((int) (zephir_get_numberval(ctrlByte)) & 0x7));
			ZEPHIR_CALL_FUNCTION(&_13$$4, "pack", &_7, 59, &_10$$4, &_12$$4);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&packed);
			ZEPHIR_CONCAT_VVV(&packed, &_11$$4, &_13$$4, &buffer);
			ZEPHIR_INIT_NVAR(&_10$$4);
			ZVAL_STRING(&_10$$4, "N");
			ZEPHIR_CALL_FUNCTION(&_pointer, "unpack", &_8, 32, &_10$$4, &packed);
			zephir_check_call_status();
			ZEPHIR_OBS_VAR(&_14$$4);
			zephir_array_fetch_long(&_14$$4, &_pointer, 1, PH_NOISY, "geoip2/MaxMind/Db/Reader/Decoder.zep", 234 TSRMLS_CC);
			pointer = zephir_get_intval(&_14$$4);
			zephir_read_property(&_12$$4, this_ptr, SL("pointerBase"), PH_NOISY_CC | PH_READONLY);
			pointer += (zephir_get_numberval(&_12$$4) + 2048);
			break;
		}
		if (pointerSize == 3) {
			ZEPHIR_INIT_VAR(&_15$$5);
			ZVAL_STRING(&_15$$5, "C");
			ZVAL_LONG(&_16$$5, ((int) (zephir_get_numberval(ctrlByte)) & 0x7));
			ZEPHIR_CALL_FUNCTION(&_17$$5, "pack", &_7, 59, &_15$$5, &_16$$5);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&packed);
			ZEPHIR_CONCAT_VV(&packed, &_17$$5, &buffer);
			ZEPHIR_INIT_NVAR(&_15$$5);
			ZVAL_STRING(&_15$$5, "N");
			ZEPHIR_CALL_FUNCTION(&_pointer, "unpack", &_8, 32, &_15$$5, &packed);
			zephir_check_call_status();
			ZEPHIR_OBS_VAR(&_18$$5);
			zephir_array_fetch_long(&_18$$5, &_pointer, 1, PH_NOISY, "geoip2/MaxMind/Db/Reader/Decoder.zep", 242 TSRMLS_CC);
			pointer = zephir_get_intval(&_18$$5);
			zephir_read_property(&_16$$5, this_ptr, SL("pointerBase"), PH_NOISY_CC | PH_READONLY);
			pointer += (zephir_get_numberval(&_16$$5) + 526336);
			break;
		}
		if (pointerSize == 4) {
			ZVAL_LONG(&_20$$6, pointerSize);
			ZEPHIR_CALL_METHOD(&_19$$6, this_ptr, "decodeuint", NULL, 55, &buffer, &_20$$6);
			zephir_check_call_status();
			pointerOffset = zephir_get_intval(&_19$$6);
			zephir_read_property(&_20$$6, this_ptr, SL("pointerBaseByteSize"), PH_NOISY_CC | PH_READONLY);
			byteLength = (pointerSize + zephir_get_numberval(&_20$$6));
			zephir_read_property(&_21$$6, this_ptr, SL("maxIntBytes"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_22$$6);
			ZVAL_STRING(&_22$$6, "gmp");
			ZEPHIR_CALL_FUNCTION(&_23$$6, "extension_loaded", NULL, 60, &_22$$6);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_22$$6);
			ZVAL_STRING(&_22$$6, "bcmath");
			ZEPHIR_CALL_FUNCTION(&_24$$6, "extension_loaded", NULL, 60, &_22$$6);
			zephir_check_call_status();
			if (ZEPHIR_GE_LONG(&_21$$6, byteLength)) {
				zephir_read_property(&_25$$7, this_ptr, SL("pointerBase"), PH_NOISY_CC | PH_READONLY);
				pointer = (pointerOffset + zephir_get_numberval(&_25$$7));
			} else if (zephir_is_true(&_23$$6)) {
				zephir_read_property(&_26$$8, this_ptr, SL("pointerBase"), PH_NOISY_CC | PH_READONLY);
				ZVAL_LONG(&_27$$8, pointerOffset);
				ZEPHIR_CALL_FUNCTION(&_28$$8, "gmp_add", NULL, 61, &_27$$8, &_26$$8);
				zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(&_29$$8, "gmp_strval", NULL, 62, &_28$$8);
				zephir_check_call_status();
				pointer = zephir_get_intval(&_29$$8);
			} else if (zephir_is_true(&_24$$6)) {
				zephir_read_property(&_30$$9, this_ptr, SL("pointerBase"), PH_NOISY_CC | PH_READONLY);
				ZVAL_LONG(&_31$$9, pointerOffset);
				ZEPHIR_CALL_FUNCTION(&_32$$9, "bcadd", NULL, 63, &_31$$9, &_30$$9);
				zephir_check_call_status();
				pointer = zephir_get_intval(&_32$$9);
			} else {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "The gmp or bcmath extension must be installed to read this database.", "geoip2/MaxMind/Db/Reader/Decoder.zep", 259);
				return;
			}
		}
	} while(0);

	zephir_create_array(return_value, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_33);
	ZVAL_LONG(&_33, pointer);
	zephir_array_fast_append(return_value, &_33);
	zephir_array_fast_append(return_value, offset);
	RETURN_MM();

}

PHP_METHOD(GeoIP2_MaxMind_Db_Reader_Decoder, decodeUint) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_1 = NULL, *_5 = NULL, *_10 = NULL, *_12 = NULL, *_13 = NULL, *_16 = NULL, *_17 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, i = 0, _7$$5;
	zval *bytes, bytes_sub, *byteLength, byteLength_sub, _integer, part, _bytes, _0$$4, _2$$4, _3$$4, _4$$4, _6$$4, _8$$6, _9$$6, _11$$6, _14$$7, _15$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&bytes_sub);
	ZVAL_UNDEF(&byteLength_sub);
	ZVAL_UNDEF(&_integer);
	ZVAL_UNDEF(&part);
	ZVAL_UNDEF(&_bytes);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_15$$7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &bytes, &byteLength);



	if (ZEPHIR_IS_LONG_IDENTICAL(byteLength, 0)) {
		RETURN_MM_LONG(0);
	}
	ZEPHIR_CALL_FUNCTION(&_bytes, "str_split", NULL, 39, bytes);
	zephir_check_call_status();
	i = 0;
	while (1) {
		if (!(ZEPHIR_GT_LONG(byteLength, i))) {
			break;
		}
		zephir_array_fetch_long(&_0$$4, &_bytes, i, PH_NOISY | PH_READONLY, "geoip2/MaxMind/Db/Reader/Decoder.zep", 274 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&part, "ord", &_1, 64, &_0$$4);
		zephir_check_call_status();
		zephir_read_property(&_2$$4, this_ptr, SL("maxIntBytes"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&_3$$4);
		ZVAL_STRING(&_3$$4, "gmp");
		ZEPHIR_CALL_FUNCTION(&_4$$4, "extension_loaded", &_5, 60, &_3$$4);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_3$$4);
		ZVAL_STRING(&_3$$4, "bcmath");
		ZEPHIR_CALL_FUNCTION(&_6$$4, "extension_loaded", &_5, 60, &_3$$4);
		zephir_check_call_status();
		if (ZEPHIR_LE(byteLength, &_2$$4)) {
			_7$$5 = ((((int) (zephir_get_numberval(&_integer)) << 8)) + zephir_get_numberval(&part));
			ZEPHIR_INIT_NVAR(&_integer);
			ZVAL_LONG(&_integer, _7$$5);
		} else if (zephir_is_true(&_4$$4)) {
			ZVAL_LONG(&_8$$6, 256);
			ZEPHIR_CALL_FUNCTION(&_9$$6, "gmp_mul", &_10, 65, &_integer, &_8$$6);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(&_11$$6, "gmp_add", &_12, 61, &_9$$6, &part);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(&_integer, "gmp_strval", &_13, 62, &_11$$6);
			zephir_check_call_status();
		} else if (zephir_is_true(&_6$$4)) {
			ZVAL_LONG(&_14$$7, 256);
			ZEPHIR_CALL_FUNCTION(&_15$$7, "bcmul", &_16, 66, &_integer, &_14$$7);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(&_integer, "bcadd", &_17, 63, &_15$$7, &part);
			zephir_check_call_status();
		} else {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "The gmp or bcmath extension must be installed to read this database.", "geoip2/MaxMind/Db/Reader/Decoder.zep", 285);
			return;
		}
		i++;
	}
	RETURN_CCTOR(&_integer);

}

PHP_METHOD(GeoIP2_MaxMind_Db_Reader_Decoder, sizeFromCtrlByte) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, size = 0, bytesToRead = 0, adjust = 0;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *ctrlByte, ctrlByte_sub, *offset, offset_sub, bytes, _adjust, _2, _3, _11, _0$$3, _4$$4, _5$$5, _6$$5, _7$$6, _8$$6, _9$$6, _10$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ctrlByte_sub);
	ZVAL_UNDEF(&offset_sub);
	ZVAL_UNDEF(&bytes);
	ZVAL_UNDEF(&_adjust);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &ctrlByte, &offset);



	size = ((int) (zephir_get_numberval(ctrlByte)) & 0x1f);
	if (size < 29) {
		zephir_create_array(return_value, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_0$$3);
		ZVAL_LONG(&_0$$3, size);
		zephir_array_fast_append(return_value, &_0$$3);
		zephir_array_fast_append(return_value, offset);
		RETURN_MM();
	}
	bytesToRead = (size - 28);
	zephir_read_property(&_2, this_ptr, SL("fileStream"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_3, bytesToRead);
	ZEPHIR_CALL_CE_STATIC(&bytes, geoip2_maxmind_db_reader_util_ce, "read", &_1, 0, &_2, offset, &_3);
	zephir_check_call_status();
	if (size == 29) {
		ZEPHIR_CALL_FUNCTION(&_4$$4, "ord", NULL, 64, &bytes);
		zephir_check_call_status();
		size = (29 + zephir_get_numberval(&_4$$4));
	} else if (size == 30) {
		ZEPHIR_INIT_VAR(&_5$$5);
		ZVAL_STRING(&_5$$5, "n");
		ZEPHIR_CALL_FUNCTION(&_adjust, "unpack", NULL, 32, &_5$$5, &bytes);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(&_6$$5);
		zephir_array_fetch_long(&_6$$5, &_adjust, 1, PH_NOISY, "geoip2/MaxMind/Db/Reader/Decoder.zep", 306 TSRMLS_CC);
		adjust = zephir_get_intval(&_6$$5);
		size = (285 + adjust);
	} else if (size > 30) {
		ZEPHIR_INIT_VAR(&_7$$6);
		ZVAL_STRING(&_7$$6, "00");
		ZEPHIR_CALL_FUNCTION(&_8$$6, "hex2bin", NULL, 18, &_7$$6);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_9$$6);
		ZEPHIR_CONCAT_VV(&_9$$6, &_8$$6, &bytes);
		ZEPHIR_INIT_NVAR(&_7$$6);
		ZVAL_STRING(&_7$$6, "N");
		ZEPHIR_CALL_FUNCTION(&_adjust, "unpack", NULL, 32, &_7$$6, &_9$$6);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(&_10$$6);
		zephir_array_fetch_long(&_10$$6, &_adjust, 1, PH_NOISY, "geoip2/MaxMind/Db/Reader/Decoder.zep", 310 TSRMLS_CC);
		adjust = zephir_get_intval(&_10$$6);
		size = (((adjust & ((0x0FFFFFFF >> ((32 - ((8 * bytesToRead)))))))) + 65821);
	}
	zephir_create_array(return_value, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_11);
	ZVAL_LONG(&_11, size);
	zephir_array_fast_append(return_value, &_11);
	ZEPHIR_INIT_NVAR(&_11);
	ZVAL_LONG(&_11, (zephir_get_numberval(offset) + bytesToRead));
	zephir_array_fast_append(return_value, &_11);
	RETURN_MM();

}

PHP_METHOD(GeoIP2_MaxMind_Db_Reader_Decoder, maybeSwitchByteOrder) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *bytes, bytes_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&bytes_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &bytes);



	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, SL("switchByteOrder"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_1)) {
		ZEPHIR_CALL_FUNCTION(&_0, "strrev", NULL, 67, bytes);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&_0, bytes);
	}
	RETURN_CCTOR(&_0);

}

PHP_METHOD(GeoIP2_MaxMind_Db_Reader_Decoder, isPlatformLittleEndian) {

	zval packed, _0, _1, _2, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, testint = 0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&packed);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();

	testint = 0x00FF;
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "S");
	ZVAL_LONG(&_1, testint);
	ZEPHIR_CALL_FUNCTION(&packed, "pack", NULL, 59, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "v");
	ZEPHIR_CALL_FUNCTION(&_2, "unpack", NULL, 32, &_0, &packed);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_3, "current", NULL, 68, &_2);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_LONG_IDENTICAL(&_3, testint));

}

