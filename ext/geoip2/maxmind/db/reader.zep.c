
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/concat.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/file.h"


/**
 * Instances of this class provide a reader for the MaxMind DB format. IP
 * addresses can be looked up using the get method.
 */
ZEPHIR_INIT_CLASS(GeoIP2_MaxMind_Db_Reader) {

	ZEPHIR_REGISTER_CLASS(GeoIP2\\MaxMind\\Db, Reader, geoip2, maxmind_db_reader, geoip2_maxmind_db_reader_method_entry, 0);

	zend_declare_property_long(geoip2_maxmind_db_reader_ce, SL("data_section_separator_size"), 16, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_null(geoip2_maxmind_db_reader_ce, SL("metadata_start_marker"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_long(geoip2_maxmind_db_reader_ce, SL("metadata_start_marker_length"), 14, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_long(geoip2_maxmind_db_reader_ce, SL("metadata_max_size"), 131072, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_null(geoip2_maxmind_db_reader_ce, SL("decoder"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(geoip2_maxmind_db_reader_ce, SL("fileHandle"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(geoip2_maxmind_db_reader_ce, SL("fileSize"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(geoip2_maxmind_db_reader_ce, SL("ipV4Start"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(geoip2_maxmind_db_reader_ce, SL("metadata"), ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

/**
 * Constructs a Reader for the MaxMind DB format. The file passed to it must
 * be a valid MaxMind DB file such as a GeoIp2 database file.
 *
 * @param string database
 *                         the MaxMind DB file to use
 *
 * @throws \InvalidArgumentException                   for invalid database path or unknown arguments
 * @throws \MaxMind\Db\Reader\InvalidDatabaseException
 *                                                     if the database is invalid or there is an error reading
 *                                                     from it
 */
PHP_METHOD(GeoIP2_MaxMind_Db_Reader, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *database_param = NULL, start, metadataDecoder, metadataArray, _0, _1, _2, _3, _4, _5, _6, _7, _8, _10, _11, _12, _13, _14, _15;
	zval database;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&database);
	ZVAL_UNDEF(&start);
	ZVAL_UNDEF(&metadataDecoder);
	ZVAL_UNDEF(&metadataArray);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &database_param);

	zephir_get_strval(&database, database_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "ABCDEF");
	ZEPHIR_CALL_FUNCTION(&_1, "hex2bin", NULL, 18, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_VS(&_2, &_1, "MaxMind.com");
	zend_update_static_property(geoip2_maxmind_db_reader_ce, ZEND_STRL("metadata_start_marker"), &_2);
	if (ZEND_NUM_ARGS() != 1) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "The constructor takes exactly one argument.", "geoip2/MaxMind/Db/Reader.zep", 42);
		return;
	}
	ZEPHIR_CALL_FUNCTION(&_3, "is_readable", NULL, 19, &database);
	zephir_check_call_status();
	if (!(zephir_is_true(&_3))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "The file {database} does not exist or is not readable.", "geoip2/MaxMind/Db/Reader.zep", 47);
		return;
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "rb");
	ZEPHIR_CALL_FUNCTION(&_4, "fopen", NULL, 20, &database, &_0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("fileHandle"), &_4);
	zephir_read_property(&_5, this_ptr, SL("fileHandle"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_5)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Error opening \"database\".", "geoip2/MaxMind/Db/Reader.zep", 54);
		return;
	}
	ZEPHIR_CALL_FUNCTION(&_6, "filesize", NULL, 21, &database);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("fileSize"), &_6);
	zephir_read_property(&_7, this_ptr, SL("fileSize"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_7)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_UnexpectedValueException, "Error determining the size of \"database\".", "geoip2/MaxMind/Db/Reader.zep", 61);
		return;
	}
	ZEPHIR_CALL_METHOD(&start, this_ptr, "findmetadatastart", NULL, 22, &database);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&metadataDecoder);
	object_init_ex(&metadataDecoder, geoip2_maxmind_db_reader_decoder_ce);
	zephir_read_property(&_8, this_ptr, SL("fileHandle"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &metadataDecoder, "__construct", &_9, 23, &_8, &start);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&metadataArray, &metadataDecoder, "decode", NULL, 24, &start);
	zephir_check_call_status();
	zephir_array_fetch_long(&_10, &metadataArray, 0, PH_NOISY | PH_READONLY, "geoip2/MaxMind/Db/Reader.zep", 66 TSRMLS_CC);
	ZEPHIR_CPY_WRT(&metadataArray, &_10);
	ZEPHIR_INIT_NVAR(&_0);
	object_init_ex(&_0, geoip2_maxmind_db_reader_metadata_ce);
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 25, &metadataArray);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("metadata"), &_0);
	ZEPHIR_INIT_VAR(&_11);
	object_init_ex(&_11, geoip2_maxmind_db_reader_decoder_ce);
	zephir_read_property(&_12, this_ptr, SL("fileHandle"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_13, this_ptr, SL("metadata"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_14, &_13, SL("searchTreeSize"), PH_NOISY_CC | PH_READONLY);
	zephir_read_static_property_ce(&_15, geoip2_maxmind_db_reader_ce, SL("data_section_separator_size"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_LNVAR(_2);
	zephir_add_function(&_2, &_14, &_15);
	ZEPHIR_CALL_METHOD(NULL, &_11, "__construct", &_9, 23, &_12, &_2);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("decoder"), &_11);
	ZEPHIR_MM_RESTORE();

}

/**
 * Looks up the address in the MaxMind DB.
 *
 * @param string ipAddress
 *                          the IP address to look up
 *
 * @throws \BadMethodCallException   if this method is called on a closed database
 * @throws \InvalidArgumentException if something other than a single IP address is passed to the method
 * @throws InvalidDatabaseException
 *                                   if the database is invalid or there is an error reading
 *                                   from it
 *
 * @return array the record for the IP address
 */
PHP_METHOD(GeoIP2_MaxMind_Db_Reader, get) {

	zval _8$$6;
	zend_bool _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *ipAddress, ipAddress_sub, pointer, _0, _1, _2, _3, _5, _6, _7$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ipAddress_sub);
	ZVAL_UNDEF(&pointer);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &ipAddress);



	if (ZEND_NUM_ARGS() != 1) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Method takes exactly one argument.", "geoip2/MaxMind/Db/Reader.zep", 93);
		return;
	}
	zephir_read_property(&_0, this_ptr, SL("fileHandle"), PH_NOISY_CC | PH_READONLY);
	if (!(Z_TYPE_P(&_0) == IS_RESOURCE)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_BadMethodCallException, "Attempt to read from a closed MaxMind DB.", "geoip2/MaxMind/Db/Reader.zep", 98);
		return;
	}
	ZVAL_LONG(&_1, 275);
	ZEPHIR_CALL_FUNCTION(&_2, "filter_var", NULL, 26, ipAddress, &_1);
	zephir_check_call_status();
	if (!zephir_is_true(&_2)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "The value \"ipAddress\" is not a valid IP address.", "geoip2/MaxMind/Db/Reader.zep", 103);
		return;
	}
	zephir_read_property(&_1, this_ptr, SL("metadata"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_3, &_1, SL("ipVersion"), PH_NOISY_CC | PH_READONLY);
	_4 = ZEPHIR_IS_LONG_IDENTICAL(&_3, 4);
	if (_4) {
		ZEPHIR_INIT_VAR(&_5);
		ZVAL_STRING(&_5, ":");
		ZEPHIR_CALL_FUNCTION(&_6, "strrpos", NULL, 27, ipAddress, &_5);
		zephir_check_call_status();
		_4 = zephir_is_true(&_6);
	}
	if (_4) {
		ZEPHIR_INIT_VAR(&_7$$6);
		object_init_ex(&_7$$6, spl_ce_InvalidArgumentException);
		ZEPHIR_INIT_VAR(&_8$$6);
		ZEPHIR_CONCAT_SS(&_8$$6, "Error looking up ipAddress. You attempted to look up an", " IPv6 address in an IPv4-only database.");
		ZEPHIR_CALL_METHOD(NULL, &_7$$6, "__construct", NULL, 28, &_8$$6);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_7$$6, "geoip2/MaxMind/Db/Reader.zep", 109 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&pointer, this_ptr, "findaddressintree", NULL, 29, ipAddress);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG_IDENTICAL(&pointer, 0)) {
		RETURN_MM_NULL();
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "resolvedatapointer", NULL, 30, &pointer);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(GeoIP2_MaxMind_Db_Reader, findAddressInTree) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, tempBit = 0, bit = 0, i = 0;
	zval *ipAddress, ipAddress_sub, rawAddress, bitCount, node, _0, _1, _2, _9, _10, _11, _12, _3$$3, _4$$3, _5$$3, _6$$3, _7$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ipAddress_sub);
	ZVAL_UNDEF(&rawAddress);
	ZVAL_UNDEF(&bitCount);
	ZVAL_UNDEF(&node);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &ipAddress);



	ZEPHIR_CALL_FUNCTION(&_0, "inet_pton", NULL, 31, ipAddress);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "C*");
	ZEPHIR_CALL_FUNCTION(&_2, "unpack", NULL, 32, &_1, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&rawAddress, "array_merge", NULL, 33, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&bitCount);
	ZVAL_LONG(&bitCount, (zephir_fast_count_int(&rawAddress TSRMLS_CC) * 8));
	ZEPHIR_CALL_METHOD(&node, this_ptr, "startnode", NULL, 34, &bitCount);
	zephir_check_call_status();
	i = 0;
	while (1) {
		if (!(ZEPHIR_GT_LONG(&bitCount, i))) {
			break;
		}
		zephir_read_property(&_3$$3, this_ptr, SL("metadata"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_4$$3, &_3$$3, SL("nodeCount"), PH_NOISY_CC | PH_READONLY);
		if (ZEPHIR_GE(&node, &_4$$3)) {
			break;
		}
		ZEPHIR_OBS_NVAR(&_5$$3);
		zephir_array_fetch_long(&_5$$3, &rawAddress, (i >> 3), PH_NOISY, "geoip2/MaxMind/Db/Reader.zep", 133 TSRMLS_CC);
		tempBit = (0xFF & zephir_get_intval(&_5$$3));
		bit = (1 & ((tempBit >> (int) (((double) 7 - (zephir_safe_mod_long_long(i, 8 TSRMLS_CC)))))));
		ZVAL_LONG(&_7$$3, bit);
		ZEPHIR_CALL_METHOD(&_6$$3, this_ptr, "readnode", &_8, 35, &node, &_7$$3);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&node, &_6$$3);
		i++;
	}
	zephir_read_property(&_9, this_ptr, SL("metadata"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_10, &_9, SL("nodeCount"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_11, this_ptr, SL("metadata"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_12, &_11, SL("nodeCount"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_IDENTICAL(&node, &_10)) {
		RETURN_MM_LONG(0);
	} else if (ZEPHIR_GT(&node, &_12)) {
		RETURN_CCTOR(&node);
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(geoip2_maxmind_db_reader_invaliddatabaseexception_ce, "Something bad happened", "geoip2/MaxMind/Db/Reader.zep", 145);
	return;

}

PHP_METHOD(GeoIP2_MaxMind_Db_Reader, startNode) {

	zend_bool _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *length, length_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&length_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &length);



	zephir_read_property(&_0, this_ptr, SL("metadata"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, &_0, SL("ipVersion"), PH_NOISY_CC | PH_READONLY);
	_2 = ZEPHIR_IS_LONG_IDENTICAL(&_1, 6);
	if (_2) {
		_2 = ZEPHIR_IS_LONG_IDENTICAL(length, 32);
	}
	if (_2) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "ipv4startnode", NULL, 36);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_LONG(0);

}

PHP_METHOD(GeoIP2_MaxMind_Db_Reader, ipV4StartNode) {

	zend_bool _3;
	zval node, _0, _1, _2, _4, _5, _6$$5, _7$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, i = 0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&node);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("metadata"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, &_0, SL("ipVersion"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_LONG_IDENTICAL(&_1, 4)) {
		RETURN_MM_LONG(0);
	}
	zephir_read_property(&_2, this_ptr, SL("ipV4Start"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_2)) {
		RETURN_MM_MEMBER(getThis(), "ipV4Start");
	}
	ZEPHIR_INIT_VAR(&node);
	ZVAL_LONG(&node, 0);
	i = 0;
	while (1) {
		_3 = i < 96;
		if (_3) {
			zephir_read_property(&_4, this_ptr, SL("metadata"), PH_NOISY_CC | PH_READONLY);
			zephir_read_property(&_5, &_4, SL("nodeCount"), PH_NOISY_CC | PH_READONLY);
			_3 = ZEPHIR_LT(&node, &_5);
		}
		if (!(_3)) {
			break;
		}
		ZVAL_LONG(&_7$$5, 0);
		ZEPHIR_CALL_METHOD(&_6$$5, this_ptr, "readnode", &_8, 35, &node, &_7$$5);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&node, &_6$$5);
		i++;
	}
	zephir_update_property_zval(this_ptr, SL("ipV4Start"), &node);
	RETURN_CCTOR(&node);

}

PHP_METHOD(GeoIP2_MaxMind_Db_Reader, readNode) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, _17$$5, _18$$6;
	zephir_fcall_cache_entry *_3 = NULL, *_10 = NULL;
	zval *nodeNumber, nodeNumber_sub, *index, index_sub, baseOffset, node, middleByte, middle, bytes, _0, _1, _2, _4$$3, _5$$3, _6$$3, _7$$3, _8$$3, _9$$3, _11$$3, _12$$4, _13$$4, _14$$4, _15$$4, _16$$4, _19$$4, _20$$4, _21$$4, _22$$7, _23$$7, _24$$7, _25$$7, _26$$7, _27$$8, _28$$8, _29$$8, _30$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&nodeNumber_sub);
	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&baseOffset);
	ZVAL_UNDEF(&node);
	ZVAL_UNDEF(&middleByte);
	ZVAL_UNDEF(&middle);
	ZVAL_UNDEF(&bytes);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&_14$$4);
	ZVAL_UNDEF(&_15$$4);
	ZVAL_UNDEF(&_16$$4);
	ZVAL_UNDEF(&_19$$4);
	ZVAL_UNDEF(&_20$$4);
	ZVAL_UNDEF(&_21$$4);
	ZVAL_UNDEF(&_22$$7);
	ZVAL_UNDEF(&_23$$7);
	ZVAL_UNDEF(&_24$$7);
	ZVAL_UNDEF(&_25$$7);
	ZVAL_UNDEF(&_26$$7);
	ZVAL_UNDEF(&_27$$8);
	ZVAL_UNDEF(&_28$$8);
	ZVAL_UNDEF(&_29$$8);
	ZVAL_UNDEF(&_30$$8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &nodeNumber, &index);



	zephir_read_property(&_0, this_ptr, SL("metadata"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, &_0, SL("nodeByteSize"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&baseOffset);
	mul_function(&baseOffset, nodeNumber, &_1 TSRMLS_CC);
	zephir_read_property(&_1, this_ptr, SL("metadata"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&_2);
	zephir_read_property(&_2, &_1, SL("recordSize"), PH_NOISY_CC);
	do {
		if (ZEPHIR_IS_LONG(&_2, 24)) {
			zephir_read_property(&_4$$3, this_ptr, SL("fileHandle"), PH_NOISY_CC | PH_READONLY);
			ZVAL_LONG(&_5$$3, (zephir_get_numberval(&baseOffset) + (zephir_get_numberval(index) * 3)));
			ZVAL_LONG(&_6$$3, 3);
			ZEPHIR_CALL_CE_STATIC(&bytes, geoip2_maxmind_db_reader_util_ce, "read", &_3, 0, &_4$$3, &_5$$3, &_6$$3);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_7$$3);
			ZVAL_STRING(&_7$$3, "00");
			ZEPHIR_CALL_FUNCTION(&_8$$3, "hex2bin", NULL, 18, &_7$$3);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_9$$3);
			ZEPHIR_CONCAT_VV(&_9$$3, &_8$$3, &bytes);
			ZEPHIR_INIT_NVAR(&_7$$3);
			ZVAL_STRING(&_7$$3, "N");
			ZEPHIR_CALL_FUNCTION(&node, "unpack", &_10, 32, &_7$$3, &_9$$3);
			zephir_check_call_status();
			zephir_array_fetch_long(&_11$$3, &node, 1, PH_NOISY | PH_READONLY, "geoip2/MaxMind/Db/Reader.zep", 188 TSRMLS_CC);
			ZEPHIR_CPY_WRT(&node, &_11$$3);
			RETURN_CCTOR(&node);
		}
		if (ZEPHIR_IS_LONG(&_2, 28)) {
			zephir_read_property(&_12$$4, this_ptr, SL("fileHandle"), PH_NOISY_CC | PH_READONLY);
			ZVAL_LONG(&_13$$4, (zephir_get_numberval(&baseOffset) + 3));
			ZVAL_LONG(&_14$$4, 1);
			ZEPHIR_CALL_CE_STATIC(&middleByte, geoip2_maxmind_db_reader_util_ce, "read", &_3, 0, &_12$$4, &_13$$4, &_14$$4);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_15$$4);
			ZVAL_STRING(&_15$$4, "C");
			ZEPHIR_CALL_FUNCTION(&middle, "unpack", &_10, 32, &_15$$4, &middleByte);
			zephir_check_call_status();
			zephir_array_fetch_long(&_16$$4, &middle, 1, PH_NOISY | PH_READONLY, "geoip2/MaxMind/Db/Reader.zep", 193 TSRMLS_CC);
			ZEPHIR_CPY_WRT(&middle, &_16$$4);
			ZEPHIR_INIT_NVAR(&middle);
			if (ZEPHIR_IS_LONG_IDENTICAL(index, 0)) {
				_17$$5 = (((0xF0 & zephir_get_intval(&middle))) >> 4);
				ZVAL_LONG(&middle, _17$$5);
			} else {
				_18$$6 = (0x0F & zephir_get_intval(&middle));
				ZVAL_LONG(&middle, _18$$6);
			}
			zephir_read_property(&_13$$4, this_ptr, SL("fileHandle"), PH_NOISY_CC | PH_READONLY);
			ZVAL_LONG(&_14$$4, (zephir_get_numberval(&baseOffset) + (zephir_get_numberval(index) * 4)));
			ZVAL_LONG(&_19$$4, 3);
			ZEPHIR_CALL_CE_STATIC(&bytes, geoip2_maxmind_db_reader_util_ce, "read", &_3, 0, &_13$$4, &_14$$4, &_19$$4);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(&_20$$4, "chr", NULL, 37, &middle);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_21$$4);
			ZEPHIR_CONCAT_VV(&_21$$4, &_20$$4, &bytes);
			ZEPHIR_INIT_NVAR(&_15$$4);
			ZVAL_STRING(&_15$$4, "N");
			ZEPHIR_CALL_FUNCTION(&node, "unpack", &_10, 32, &_15$$4, &_21$$4);
			zephir_check_call_status();
			zephir_array_fetch_long(&_16$$4, &node, 1, PH_NOISY | PH_READONLY, "geoip2/MaxMind/Db/Reader.zep", 201 TSRMLS_CC);
			ZEPHIR_CPY_WRT(&node, &_16$$4);
			RETURN_CCTOR(&node);
		}
		if (ZEPHIR_IS_LONG(&_2, 32)) {
			zephir_read_property(&_22$$7, this_ptr, SL("fileHandle"), PH_NOISY_CC | PH_READONLY);
			ZVAL_LONG(&_23$$7, (zephir_get_numberval(&baseOffset) + (zephir_get_numberval(index) * 4)));
			ZVAL_LONG(&_24$$7, 4);
			ZEPHIR_CALL_CE_STATIC(&bytes, geoip2_maxmind_db_reader_util_ce, "read", &_3, 0, &_22$$7, &_23$$7, &_24$$7);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_25$$7);
			ZVAL_STRING(&_25$$7, "N");
			ZEPHIR_CALL_FUNCTION(&node, "unpack", &_10, 32, &_25$$7, &bytes);
			zephir_check_call_status();
			zephir_array_fetch_long(&_26$$7, &node, 1, PH_NOISY | PH_READONLY, "geoip2/MaxMind/Db/Reader.zep", 206 TSRMLS_CC);
			ZEPHIR_CPY_WRT(&node, &_26$$7);
			RETURN_CCTOR(&node);
		}
		ZEPHIR_INIT_VAR(&_27$$8);
		object_init_ex(&_27$$8, geoip2_maxmind_db_reader_invaliddatabaseexception_ce);
		zephir_read_property(&_28$$8, this_ptr, SL("metadata"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_29$$8, &_28$$8, SL("recordSize"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_30$$8);
		ZEPHIR_CONCAT_SV(&_30$$8, "Unknown record size: ", &_29$$8);
		ZEPHIR_CALL_METHOD(NULL, &_27$$8, "__construct", NULL, 17, &_30$$8);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_27$$8, "geoip2/MaxMind/Db/Reader.zep", 212 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	} while(0);

	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(GeoIP2_MaxMind_Db_Reader, resolveDataPointer) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pointer, pointer_sub, resolved, data, _0, _1, _2, _3, _4, _5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pointer_sub);
	ZVAL_UNDEF(&resolved);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &pointer);



	zephir_read_property(&_0, this_ptr, SL("metadata"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, &_0, SL("nodeCount"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_SINIT_VAR(_2);
	zephir_sub_function(&_2, pointer, &_1);
	zephir_read_property(&_1, this_ptr, SL("metadata"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_3, &_1, SL("searchTreeSize"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&resolved);
	zephir_add_function(&resolved, &_2, &_3);
	zephir_read_property(&_3, this_ptr, SL("fileSize"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_GT(&resolved, &_3)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(geoip2_maxmind_db_reader_invaliddatabaseexception_ce, "The MaxMind DB file's search tree is corrupt", "geoip2/MaxMind/Db/Reader.zep", 223);
		return;
	}
	zephir_read_property(&_4, this_ptr, SL("decoder"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&data, &_4, "decode", NULL, 0, &resolved);
	zephir_check_call_status();
	zephir_array_fetch_long(&_5, &data, 0, PH_NOISY | PH_READONLY, "geoip2/MaxMind/Db/Reader.zep", 226 TSRMLS_CC);
	ZEPHIR_CPY_WRT(&data, &_5);
	RETURN_CCTOR(&data);

}

PHP_METHOD(GeoIP2_MaxMind_Db_Reader, findMetadataStart) {

	zend_bool _continue = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL, *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, i = 0, j = 0;
	zval *filename, filename_sub, handle, fstat, fileSize, marker, markerLength, metadataMaxLengthExcludingMarker, matchBit, _0, _1, _2, _7, _8, _3$$4, _6$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filename_sub);
	ZVAL_UNDEF(&handle);
	ZVAL_UNDEF(&fstat);
	ZVAL_UNDEF(&fileSize);
	ZVAL_UNDEF(&marker);
	ZVAL_UNDEF(&markerLength);
	ZVAL_UNDEF(&metadataMaxLengthExcludingMarker);
	ZVAL_UNDEF(&matchBit);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_6$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &filename);



	ZEPHIR_OBS_VAR(&handle);
	zephir_read_property(&handle, this_ptr, SL("fileHandle"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&fstat, "fstat", NULL, 38, &handle);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&fileSize);
	zephir_array_fetch_string(&fileSize, &fstat, SL("size"), PH_NOISY, "geoip2/MaxMind/Db/Reader.zep", 240 TSRMLS_CC);
	zephir_read_static_property_ce(&_0, geoip2_maxmind_db_reader_ce, SL("metadata_start_marker"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&marker, "str_split", NULL, 39, &_0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&markerLength);
	zephir_read_static_property_ce(&markerLength, geoip2_maxmind_db_reader_ce, SL("metadata_start_marker_length"), PH_NOISY_CC);
	zephir_read_static_property_ce(&_1, geoip2_maxmind_db_reader_ce, SL("metadata_max_size"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&_2, "min", NULL, 40, &_1, &fileSize);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&metadataMaxLengthExcludingMarker);
	zephir_sub_function(&metadataMaxLengthExcludingMarker, &_2, &markerLength);
	i = -1;
	while (1) {
		if (!(ZEPHIR_GE_LONG(&metadataMaxLengthExcludingMarker, i))) {
			break;
		}
		i++;
		_continue = 0;
		j = -1;
		while (1) {
			if (!(j < (zephir_get_numberval(&markerLength) - 1))) {
				break;
			}
			j++;
			ZVAL_LONG(&_3$$4, (((zephir_get_numberval(&fileSize) - i) - j) - 1));
			ZEPHIR_CALL_FUNCTION(NULL, "fseek", &_4, 41, &handle, &_3$$4);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(&matchBit, "fgetc", &_5, 42, &handle);
			zephir_check_call_status();
			zephir_array_fetch_long(&_6$$4, &marker, ((zephir_get_numberval(&markerLength) - j) - 1), PH_NOISY | PH_READONLY, "geoip2/MaxMind/Db/Reader.zep", 254 TSRMLS_CC);
			if (!ZEPHIR_IS_IDENTICAL(&matchBit, &_6$$4)) {
				_continue = 1;
				continue;
			}
		}
		if (_continue) {
			continue;
		}
		RETURN_MM_LONG((zephir_get_numberval(&fileSize) - i));
	}
	ZEPHIR_INIT_VAR(&_7);
	object_init_ex(&_7, geoip2_maxmind_db_reader_invaliddatabaseexception_ce);
	ZEPHIR_INIT_VAR(&_8);
	ZEPHIR_CONCAT_SVSS(&_8, "Error opening database file (", filename, "). ", "Is this a valid MaxMind DB file?");
	ZEPHIR_CALL_METHOD(NULL, &_7, "__construct", NULL, 17, &_8);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_7, "geoip2/MaxMind/Db/Reader.zep", 267 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * @throws \InvalidArgumentException if arguments are passed to the method
 * @throws \BadMethodCallException   if the database has been closed
 *
 * @return Metadata object for the database
 */
PHP_METHOD(GeoIP2_MaxMind_Db_Reader, metadata) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	if (ZEND_NUM_ARGS()) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Method takes no arguments.", "geoip2/MaxMind/Db/Reader.zep", 280);
		return;
	}
	zephir_read_property(&_0, this_ptr, SL("fileHandle"), PH_NOISY_CC | PH_READONLY);
	if (!(Z_TYPE_P(&_0) == IS_RESOURCE)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_BadMethodCallException, "Attempt to read from a closed MaxMind DB.", "geoip2/MaxMind/Db/Reader.zep", 287);
		return;
	}
	RETURN_MEMBER(getThis(), "metadata");

}

/**
 * Closes the MaxMind DB and returns resources to the system.
 *
 * @throws \Exception if an I/O error occurs
 */
PHP_METHOD(GeoIP2_MaxMind_Db_Reader, close) {

	zval _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	zephir_read_property(&_0, this_ptr, SL("fileHandle"), PH_NOISY_CC | PH_READONLY);
	if (!(Z_TYPE_P(&_0) == IS_RESOURCE)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_BadMethodCallException, "Attempt to close a closed MaxMind DB.", "geoip2/MaxMind/Db/Reader.zep", 301);
		return;
	}
	zephir_read_property(&_1, this_ptr, SL("fileHandle"), PH_NOISY_CC | PH_READONLY);
	zephir_fclose(&_1 TSRMLS_CC);

}

