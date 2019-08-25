
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
 * Contains data for the subdivisions associated with an IP address.
 *
 * This record is returned by all location databases and services besides
 * Country.
 *
 * @property-read int|null $confidence This is a value from 0-100 indicating
 * MaxMind"s confidence that the subdivision is correct. This attribute is
 * only available from the Insights service and the GeoIP2 Enterprise
 * database.
 * @property-read int|null $geonameId This is a GeoName ID for the subdivision.
 * This attribute is returned by all location databases and services besides
 * Country.
 * @property-read string|null $isoCode This is a string up to three characters long
 * contain the subdivision portion of the
 * {@link * http://en.wikipedia.org/wiki/ISO_3166-2 ISO 3166-2 code}. This attribute
 * is returned by all location databases and services except Country.
 * @property-read string|null $name The name of the subdivision based on the
 * locales list passed to the constructor. This attribute is returned by all
 * location databases and services besides Country.
 * @property-read array|null $names An array map where the keys are locale codes
 * and the values are names. This attribute is returned by all location
 * databases and services besides Country.
 */
ZEPHIR_INIT_CLASS(GeoIP2_Record_Subdivision) {

	ZEPHIR_REGISTER_CLASS_EX(GeoIP2\\Record, Subdivision, geoip2, record_subdivision, geoip2_record_abstractplacerecord_ce, NULL, 0);

	/**
	 * @ignore
	 */
	zend_declare_property_null(geoip2_record_subdivision_ce, SL("validAttributes"), ZEND_ACC_PROTECTED TSRMLS_CC);

	geoip2_record_subdivision_ce->create_object = zephir_init_properties_GeoIP2_Record_Subdivision;
	return SUCCESS;

}

zend_object *zephir_init_properties_GeoIP2_Record_Subdivision(zend_class_entry *class_type TSRMLS_DC) {

		zval _1$$3;
	zval _0, _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("validAttributes"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			zephir_create_array(&_1$$3, 4, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_2$$3);
			ZVAL_STRING(&_2$$3, "confidence");
			zephir_array_fast_append(&_1$$3, &_2$$3);
			ZEPHIR_INIT_NVAR(&_2$$3);
			ZVAL_STRING(&_2$$3, "geonameId");
			zephir_array_fast_append(&_1$$3, &_2$$3);
			ZEPHIR_INIT_NVAR(&_2$$3);
			ZVAL_STRING(&_2$$3, "isoCode");
			zephir_array_fast_append(&_1$$3, &_2$$3);
			ZEPHIR_INIT_NVAR(&_2$$3);
			ZVAL_STRING(&_2$$3, "names");
			zephir_array_fast_append(&_1$$3, &_2$$3);
			zephir_update_property_zval(this_ptr, SL("validAttributes"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

