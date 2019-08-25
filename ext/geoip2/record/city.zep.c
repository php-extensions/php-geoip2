
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
 * City-level data associated with an IP address.
 *
 * This record is returned by all location services and databases besides
 * Country.
 *
 * @property-read int|null $confidence A value from 0-100 indicating MaxMind"s
 * confidence that the city is correct. This attribute is only available
 * from the Insights service and the GeoIP2 Enterprise database.
 * @property-read int|null $geonameId The GeoName ID for the city. This attribute
 * is returned by all location services and databases.
 * @property-read string|null $name The name of the city based on the locales list
 * passed to the constructor. This attribute is returned by all location
 * services and databases.
 * @property-read array|null $names A array map where the keys are locale codes
 * and the values are names. This attribute is returned by all location
 * services and databases.
 */
ZEPHIR_INIT_CLASS(GeoIP2_Record_City) {

	ZEPHIR_REGISTER_CLASS_EX(GeoIP2\\Record, City, geoip2, record_city, geoip2_record_abstractplacerecord_ce, NULL, 0);

	/**
	 * @ignore
	 */
	zend_declare_property_null(geoip2_record_city_ce, SL("validAttributes"), ZEND_ACC_PROTECTED TSRMLS_CC);

	geoip2_record_city_ce->create_object = zephir_init_properties_GeoIP2_Record_City;
	return SUCCESS;

}

zend_object *zephir_init_properties_GeoIP2_Record_City(zend_class_entry *class_type TSRMLS_DC) {

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
			zephir_create_array(&_1$$3, 3, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_2$$3);
			ZVAL_STRING(&_2$$3, "confidence");
			zephir_array_fast_append(&_1$$3, &_2$$3);
			ZEPHIR_INIT_NVAR(&_2$$3);
			ZVAL_STRING(&_2$$3, "geonameId");
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

