
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
#include "kernel/exception.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(GeoIP2_MaxMind_Db_Reader_Util) {

	ZEPHIR_REGISTER_CLASS(GeoIP2\\MaxMind\\Db\\Reader, Util, geoip2, maxmind_db_reader_util, geoip2_maxmind_db_reader_util_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(GeoIP2_MaxMind_Db_Reader_Util, read) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long offset, numberOfBytes, ZEPHIR_LAST_CALL_STATUS;
	zval *stream, stream_sub, *offset_param = NULL, *numberOfBytes_param = NULL, value, _0, _1, _2$$4, _3$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&stream_sub);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &stream, &offset_param, &numberOfBytes_param);

	offset = zephir_get_intval(offset_param);
	numberOfBytes = zephir_get_intval(numberOfBytes_param);


	if (numberOfBytes == 0) {
		RETURN_MM_STRING("");
	}
	ZVAL_LONG(&_0, offset);
	ZEPHIR_CALL_FUNCTION(&_1, "fseek", NULL, 41, stream, &_0);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG_IDENTICAL(&_1, 0)) {
		ZVAL_LONG(&_2$$4, numberOfBytes);
		ZEPHIR_CALL_FUNCTION(&value, "fread", NULL, 70, stream, &_2$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_3$$4, "ftell", NULL, 71, stream);
		zephir_check_call_status();
		if ((zephir_get_numberval(&_3$$4) - offset) == numberOfBytes) {
			RETURN_CCTOR(&value);
		}
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(geoip2_maxmind_db_reader_invaliddatabaseexception_ce, "The MaxMind DB file contains bad data", "geoip2/MaxMind/Db/Reader/Util.zep", 22);
	return;

}

