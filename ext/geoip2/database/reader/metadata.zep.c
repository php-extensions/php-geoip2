
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
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


/**
 * This class provides the metadata for the MaxMind DB file.
 *
 * @property int nodeCount This is an unsigned 32-bit integer indicating
 * the number of nodes in the search tree.
 * @property int recordSize This is an unsigned 16-bit integer. It
 * indicates the number of bits in a record in the search tree. Note that each
 * node consists of two records.
 * @property int ipVersion This is an unsigned 16-bit integer which is
 * always 4 or 6. It indicates whether the database contains IPv4 or IPv6
 * address data.
 * @property string databaseType This is a string that indicates the structure
 * of each data record associated with an IP address. The actual definition of
 * these structures is left up to the database creator.
 * @property array languages An array of strings, each of which is a language
 * code. A given record may contain data items that have been localized to
 * some or all of these languages. This may be undefined.
 * @property int binaryFormatMajorVersion This is an unsigned 16-bit
 * integer indicating the major version number for the database's binary
 * format.
 * @property int binaryFormatMinorVersion This is an unsigned 16-bit
 * integer indicating the minor version number for the database's binary format.
 * @property int buildEpoch This is an unsigned 64-bit integer that
 * contains the database build timestamp as a Unix epoch value.
 * @property array description This key will always point to a map
 * (associative array). The keys of that map will be language codes, and the
 * values will be a description in that language as a UTF-8 string. May be
 * undefined for some databases.
 */
ZEPHIR_INIT_CLASS(GeoIP2_Database_Reader_Metadata) {

	ZEPHIR_REGISTER_CLASS(GeoIP2\\Database\\Reader, Metadata, geoip2, database_reader_metadata, geoip2_database_reader_metadata_method_entry, 0);

	zend_declare_property_null(geoip2_database_reader_metadata_ce, SL("binaryFormatMajorVersion"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(geoip2_database_reader_metadata_ce, SL("binaryFormatMinorVersion"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(geoip2_database_reader_metadata_ce, SL("buildEpoch"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(geoip2_database_reader_metadata_ce, SL("databaseType"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(geoip2_database_reader_metadata_ce, SL("description"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(geoip2_database_reader_metadata_ce, SL("ipVersion"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(geoip2_database_reader_metadata_ce, SL("languages"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(geoip2_database_reader_metadata_ce, SL("nodeByteSize"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(geoip2_database_reader_metadata_ce, SL("nodeCount"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(geoip2_database_reader_metadata_ce, SL("recordSize"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(geoip2_database_reader_metadata_ce, SL("searchTreeSize"), ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(GeoIP2_Database_Reader_Metadata, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *metadata, metadata_sub, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&metadata_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &metadata);



	zephir_array_fetch_string(&_0, metadata, SL("binary_format_major_version"), PH_NOISY | PH_READONLY, "geoip2/Database/Reader/Metadata.zep", 48 TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("binaryFormatMajorVersion"), &_0);
	zephir_array_fetch_string(&_1, metadata, SL("binary_format_minor_version"), PH_NOISY | PH_READONLY, "geoip2/Database/Reader/Metadata.zep", 50 TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("binaryFormatMinorVersion"), &_1);
	zephir_array_fetch_string(&_2, metadata, SL("build_epoch"), PH_NOISY | PH_READONLY, "geoip2/Database/Reader/Metadata.zep", 51 TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("buildEpoch"), &_2);
	zephir_array_fetch_string(&_3, metadata, SL("database_type"), PH_NOISY | PH_READONLY, "geoip2/Database/Reader/Metadata.zep", 52 TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("databaseType"), &_3);
	zephir_array_fetch_string(&_4, metadata, SL("languages"), PH_NOISY | PH_READONLY, "geoip2/Database/Reader/Metadata.zep", 53 TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("languages"), &_4);
	zephir_array_fetch_string(&_5, metadata, SL("description"), PH_NOISY | PH_READONLY, "geoip2/Database/Reader/Metadata.zep", 54 TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("description"), &_5);
	zephir_array_fetch_string(&_6, metadata, SL("ip_version"), PH_NOISY | PH_READONLY, "geoip2/Database/Reader/Metadata.zep", 55 TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("ipVersion"), &_6);
	zephir_array_fetch_string(&_7, metadata, SL("node_count"), PH_NOISY | PH_READONLY, "geoip2/Database/Reader/Metadata.zep", 56 TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("nodeCount"), &_7);
	zephir_array_fetch_string(&_8, metadata, SL("record_size"), PH_NOISY | PH_READONLY, "geoip2/Database/Reader/Metadata.zep", 57 TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("recordSize"), &_8);
	zephir_read_property(&_9, this_ptr, SL("recordSize"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_ZVAL_NREF(_10);
	ZVAL_DOUBLE(&_10, zephir_safe_div_zval_long(&_9, 4 TSRMLS_CC));
	zephir_update_property_zval(this_ptr, SL("nodeByteSize"), &_10);
	zephir_read_property(&_10, this_ptr, SL("nodeCount"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_11, this_ptr, SL("nodeByteSize"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_12);
	mul_function(&_12, &_10, &_11 TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("searchTreeSize"), &_12);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(GeoIP2_Database_Reader_Metadata, __get) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *v, v_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&v_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &v);



	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property_zval(&_0, this_ptr, v, PH_NOISY_CC);
	RETURN_CCTOR(&_0);

}

