
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(GeoIP2_Database_Reader) {

	ZEPHIR_REGISTER_CLASS(GeoIP2\\Database, Reader, geoip2, database_reader, geoip2_database_reader_method_entry, 0);

	zend_declare_property_null(geoip2_database_reader_ce, SL("dbReader"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(geoip2_database_reader_ce, SL("locales"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(geoip2_database_reader_ce, SL("metadata"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_class_implements(geoip2_database_reader_ce TSRMLS_CC, 1, geoip2_providerinterface_ce);
	return SUCCESS;

}

/**
 * Constructor.
 *
 * @param string $filename the path to the GeoIP2 database file
 * @param array  $locales  list of locale codes to use in name property
 *                         from most preferred to least preferred
 *
 * @throws \GeoIP2\Exception\InvalidDatabaseException  if the database
 *                                                     is corrupt or invalid
 */
PHP_METHOD(GeoIP2_Database_Reader, __construct) {

	zval _1$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *filename_param = NULL, *locales = NULL, locales_sub, _0;
	zval filename;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filename);
	ZVAL_UNDEF(&locales_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &filename_param, &locales);

	zephir_get_strval(&filename, filename_param);
	if (!locales) {
		locales = &locales_sub;
		ZEPHIR_INIT_VAR(locales);
		ZVAL_STRING(locales, "");
	}


	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, geoip2_maxmind_db_reader_ce);
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 13, &filename);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("dbReader"), &_0);
	if (Z_TYPE_P(locales) == IS_ARRAY) {
		zephir_update_property_zval(this_ptr, SL("locales"), locales);
	} else if (Z_TYPE_P(locales) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_1$$4);
		zephir_create_array(&_1$$4, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(&_1$$4, locales);
		zephir_update_property_zval(this_ptr, SL("locales"), &_1$$4);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * This method returns a GeoIP2 City model.
 *
 * @param string $ipAddress an IPv4 or IPv6 address as a string
 *
 * @throws \GeoIP2\Exception\AddressNotFoundException  if the address is
 *                                                     not in the database
 * @throws \GeoIP2\Exception\InvalidDatabaseException  if the database
 *                                                     is corrupt or invalid
 *
 * @return \GeoIP2\Model\City
 */
PHP_METHOD(GeoIP2_Database_Reader, city) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *ipAddress_param = NULL, _0, _1;
	zval ipAddress;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ipAddress);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &ipAddress_param);

	zephir_get_strval(&ipAddress, ipAddress_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "City");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "City");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "modelfor", NULL, 14, &_0, &_1, &ipAddress);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * This method returns a GeoIP2 Country model.
 *
 * @param string $ipAddress an IPv4 or IPv6 address as a string
 *
 * @throws \GeoIP2\Exception\AddressNotFoundException  if the address is
 *                                                     not in the database
 * @throws \GeoIP2\Exception\InvalidDatabaseException  if the database
 *                                                     is corrupt or invalid
 *
 * @return \GeoIP2\Model\Country
 */
PHP_METHOD(GeoIP2_Database_Reader, country) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *ipAddress_param = NULL, _0, _1;
	zval ipAddress;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ipAddress);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &ipAddress_param);

	zephir_get_strval(&ipAddress, ipAddress_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Country");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Country");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "modelfor", NULL, 14, &_0, &_1, &ipAddress);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * This method returns a GeoIP2 Anonymous IP model.
 *
 * @param string $ipAddress an IPv4 or IPv6 address as a string
 *
 * @throws \GeoIP2\Exception\AddressNotFoundException  if the address is
 *                                                     not in the database
 * @throws \GeoIP2\Exception\InvalidDatabaseException  if the database
 *                                                     is corrupt or invalid
 *
 * @return \GeoIP2\Model\AnonymousIp
 */
PHP_METHOD(GeoIP2_Database_Reader, anonymousIp) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *ipAddress_param = NULL, _0, _1;
	zval ipAddress;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ipAddress);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &ipAddress_param);

	zephir_get_strval(&ipAddress, ipAddress_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "AnonymousIp");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "GeoIP2-Anonymous-IP");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "flatmodelfor", NULL, 15, &_0, &_1, &ipAddress);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * This method returns a GeoLite2 ASN model.
 *
 * @param string $ipAddress an IPv4 or IPv6 address as a string
 *
 * @throws \GeoIP2\Exception\AddressNotFoundException  if the address is
 *                                                     not in the database
 * @throws \GeoIP2\Exception\InvalidDatabaseException  if the database
 *                                                     is corrupt or invalid
 *
 * @return \GeoIP2\Model\Asn
 */
PHP_METHOD(GeoIP2_Database_Reader, asn) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *ipAddress_param = NULL, _0, _1;
	zval ipAddress;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ipAddress);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &ipAddress_param);

	zephir_get_strval(&ipAddress, ipAddress_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Asn");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "GeoLite2-ASN");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "flatmodelfor", NULL, 15, &_0, &_1, &ipAddress);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * This method returns a GeoIP2 Connection Type model.
 *
 * @param string $ipAddress an IPv4 or IPv6 address as a string
 *
 * @throws \GeoIP2\Exception\AddressNotFoundException  if the address is
 *                                                     not in the database
 * @throws \GeoIP2\Exception\InvalidDatabaseException  if the database
 *                                                     is corrupt or invalid
 *
 * @return \GeoIP2\Model\ConnectionType
 */
PHP_METHOD(GeoIP2_Database_Reader, connectionType) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *ipAddress_param = NULL, _0, _1;
	zval ipAddress;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ipAddress);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &ipAddress_param);

	zephir_get_strval(&ipAddress, ipAddress_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "ConnectionType");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "GeoIP2-Connection-Type");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "flatmodelfor", NULL, 15, &_0, &_1, &ipAddress);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * This method returns a GeoIP2 Domain model.
 *
 * @param string $ipAddress an IPv4 or IPv6 address as a string
 *
 * @throws \GeoIP2\Exception\AddressNotFoundException  if the address is
 *                                                     not in the database
 * @throws \GeoIP2\Exception\InvalidDatabaseException  if the database
 *                                                     is corrupt or invalid
 *
 * @return \GeoIP2\Model\Domain
 */
PHP_METHOD(GeoIP2_Database_Reader, domain) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *ipAddress_param = NULL, _0, _1;
	zval ipAddress;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ipAddress);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &ipAddress_param);

	zephir_get_strval(&ipAddress, ipAddress_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Domain");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "GeoIP2-Domain");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "flatmodelfor", NULL, 15, &_0, &_1, &ipAddress);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * This method returns a GeoIP2 Enterprise model.
 *
 * @param string $ipAddress an IPv4 or IPv6 address as a string
 *
 * @throws \GeoIP2\Exception\AddressNotFoundException  if the address is
 *                                                     not in the database
 * @throws \GeoIP2\Exception\InvalidDatabaseException  if the database
 *                                                     is corrupt or invalid
 *
 * @return \GeoIP2\Model\Enterprise
 */
PHP_METHOD(GeoIP2_Database_Reader, enterprise) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *ipAddress_param = NULL, _0, _1;
	zval ipAddress;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ipAddress);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &ipAddress_param);

	zephir_get_strval(&ipAddress, ipAddress_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Enterprise");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Enterprise");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "modelfor", NULL, 14, &_0, &_1, &ipAddress);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * This method returns a GeoIP2 ISP model.
 *
 * @param string $ipAddress an IPv4 or IPv6 address as a string
 *
 * @throws \GeoIP2\Exception\AddressNotFoundException  if the address is
 *                                                     not in the database
 * @throws \GeoIP2\Exception\InvalidDatabaseException  if the database
 *                                                     is corrupt or invalid
 *
 * @return \GeoIP2\Model\Isp
 */
PHP_METHOD(GeoIP2_Database_Reader, isp) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *ipAddress_param = NULL, _0, _1;
	zval ipAddress;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ipAddress);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &ipAddress_param);

	zephir_get_strval(&ipAddress, ipAddress_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Isp");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "GeoIP2-ISP");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "flatmodelfor", NULL, 15, &_0, &_1, &ipAddress);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(GeoIP2_Database_Reader, custom) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *ipAddress_param = NULL, _0, _1;
	zval ipAddress;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ipAddress);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &ipAddress_param);

	zephir_get_strval(&ipAddress, ipAddress_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Custom");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Custom");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "flatmodelfor", NULL, 15, &_0, &_1, &ipAddress);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(GeoIP2_Database_Reader, modelFor) {

	zend_class_entry *_2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *className_param = NULL, *type_param = NULL, *ipAddress_param = NULL, record, _1$$3, _3$$3;
	zval className, type, ipAddress, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&ipAddress);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&record);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &className_param, &type_param, &ipAddress_param);

	zephir_get_strval(&className, className_param);
	zephir_get_strval(&type, type_param);
	zephir_get_strval(&ipAddress, ipAddress_param);


	ZEPHIR_CALL_METHOD(&record, this_ptr, "getrecord", NULL, 16, &className, &type, &ipAddress);
	zephir_check_call_status();
	zephir_array_update_multi(&record, &ipAddress TSRMLS_CC, SL("ss"), 4, SL("traits"), SL("ip_address"));
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_SV(&_0, "GeoIP2\\Model\\", &className);
	ZEPHIR_CPY_WRT(&className, &_0);
	if (zephir_class_exists(&className, 1 TSRMLS_CC)) {
		zephir_fetch_safe_class(&_1$$3, &className);
		_2$$3 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_1$$3), Z_STRLEN_P(&_1$$3), ZEND_FETCH_CLASS_AUTO);
		if(!_2$$3) {
			RETURN_MM_NULL();
		}
		object_init_ex(return_value, _2$$3);
		if (zephir_has_constructor(return_value TSRMLS_CC)) {
			zephir_read_property(&_3$$3, this_ptr, SL("locales"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &record, &_3$$3);
			zephir_check_call_status();
		}
		RETURN_MM();
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(geoip2_exception_geoip2exception_ce, "Unknown record type", "geoip2/Database/Reader.zep", 205);
	return;

}

PHP_METHOD(GeoIP2_Database_Reader, flatModelFor) {

	zend_class_entry *_2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *className_param = NULL, *type_param = NULL, *ipAddress_param = NULL, record, _1;
	zval className, type, ipAddress, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&ipAddress);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&record);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &className_param, &type_param, &ipAddress_param);

	zephir_get_strval(&className, className_param);
	zephir_get_strval(&type, type_param);
	zephir_get_strval(&ipAddress, ipAddress_param);


	ZEPHIR_CALL_METHOD(&record, this_ptr, "getrecord", NULL, 16, &className, &type, &ipAddress);
	zephir_check_call_status();
	zephir_array_update_string(&record, SL("ip_address"), &ipAddress, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_SV(&_0, "GeoIP2\\Model\\", &className);
	ZEPHIR_CPY_WRT(&className, &_0);
	zephir_fetch_safe_class(&_1, &className);
	_2 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_1), Z_STRLEN_P(&_1), ZEND_FETCH_CLASS_AUTO);
	if(!_2) {
		RETURN_MM_NULL();
	}
	object_init_ex(return_value, _2);
	if (zephir_has_constructor(return_value TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &record);
		zephir_check_call_status();
	}
	RETURN_MM();

}

PHP_METHOD(GeoIP2_Database_Reader, getRecord) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *className_param = NULL, *type_param = NULL, *ipAddress_param = NULL, record, _0, _1$$3, _3$$4, _4$$4, _5$$4;
	zval className, type, ipAddress, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&ipAddress);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&record);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &className_param, &type_param, &ipAddress_param);

	zephir_get_strval(&className, className_param);
	zephir_get_strval(&type, type_param);
	zephir_get_strval(&ipAddress, ipAddress_param);


	zephir_read_property(&_0, this_ptr, SL("dbReader"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&record, &_0, "get", NULL, 0, &ipAddress);
	zephir_check_call_status();
	if (Z_TYPE_P(&record) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, geoip2_exception_addressnotfoundexception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SVS(&_2$$3, "The address ", &ipAddress, " is not in the database.");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 17, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "geoip2/Database/Reader.zep", 222 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(&record) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_3$$4);
		object_init_ex(&_3$$4, geoip2_exception_invaliddatabaseexception_ce);
		ZEPHIR_INIT_VAR(&_4$$4);
		zephir_gettype(&_4$$4, &record TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_5$$4);
		ZEPHIR_CONCAT_SVSV(&_5$$4, "Expected an array when looking up ", &ipAddress, " but received: ", &_4$$4);
		ZEPHIR_CALL_METHOD(NULL, &_3$$4, "__construct", NULL, 17, &_5$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$4, "geoip2/Database/Reader.zep", 235 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(&record);

}

/**
 * @throws \InvalidArgumentException if arguments are passed to the method
 * @throws \BadMethodCallException   if the database has been closed
 *
 * @return \GeoIP2\MaxMind\Db\Reader\Metadata object for the database
 */
PHP_METHOD(GeoIP2_Database_Reader, metadata) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("dbReader"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "metadata", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Closes the GeoIP2 database and returns the resources to the system.
 */
PHP_METHOD(GeoIP2_Database_Reader, close) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("dbReader"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "close", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

