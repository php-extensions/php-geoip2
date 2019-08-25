
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
 * Contains data for the location record associated with an IP address.
 *
 * This record is returned by all location services and databases besides
 * Country.
 *
 * @property-read int|null $averageIncome The average income in US dollars
 * associated with the requested IP address. This attribute is only available
 * from the Insights service.
 * @property-read int|null $accuracyRadius The approximate accuracy radius in
 * kilometers around the latitude and longitude for the IP address. This is
 * the radius where we have a 67% confidence that the device using the IP
 * address resides within the circle centered at the latitude and longitude
 * with the provided radius.
 * @property-read float|null $latitude The approximate latitude of the location
 * associated with the IP address. This value is not precise and should not be
 * used to identify a particular address or household.
 * @property-read float|null $longitude The approximate longitude of the location
 * associated with the IP address. This value is not precise and should not be
 * used to identify a particular address or household.
 * @property-read int|null $populationDensity The estimated population per square
 * kilometer associated with the IP address. This attribute is only available
 * from the Insights service.
 * @property-read int|null $metroCode The metro code of the location if the location
 * is in the US. MaxMind returns the same metro codes as the
 * {@link * https://developers.google.com/adwords/api/docs/appendix/cities-DMAregions
 * Google AdWords API}.
 * @property-read string|null $timeZone The time zone associated with location, as
 * specified by the {@link http://www.iana.org/time-zones IANA Time Zone
 * Database}, e.g., "America/New_York".
 */
ZEPHIR_INIT_CLASS(GeoIP2_Record_Location) {

	ZEPHIR_REGISTER_CLASS_EX(GeoIP2\\Record, Location, geoip2, record_location, geoip2_record_abstractrecord_ce, NULL, 0);

	/**
	 * @ignore
	 */
	zend_declare_property_null(geoip2_record_location_ce, SL("validAttributes"), ZEND_ACC_PROTECTED TSRMLS_CC);

	geoip2_record_location_ce->create_object = zephir_init_properties_GeoIP2_Record_Location;
	return SUCCESS;

}

zend_object *zephir_init_properties_GeoIP2_Record_Location(zend_class_entry *class_type TSRMLS_DC) {

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
			zephir_create_array(&_3$$4, 9, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_4$$4);
			ZVAL_STRING(&_4$$4, "averageIncome");
			zephir_array_fast_append(&_3$$4, &_4$$4);
			ZEPHIR_INIT_NVAR(&_4$$4);
			ZVAL_STRING(&_4$$4, "accuracyRadius");
			zephir_array_fast_append(&_3$$4, &_4$$4);
			ZEPHIR_INIT_NVAR(&_4$$4);
			ZVAL_STRING(&_4$$4, "latitude");
			zephir_array_fast_append(&_3$$4, &_4$$4);
			ZEPHIR_INIT_NVAR(&_4$$4);
			ZVAL_STRING(&_4$$4, "longitude");
			zephir_array_fast_append(&_3$$4, &_4$$4);
			ZEPHIR_INIT_NVAR(&_4$$4);
			ZVAL_STRING(&_4$$4, "metroCode");
			zephir_array_fast_append(&_3$$4, &_4$$4);
			ZEPHIR_INIT_NVAR(&_4$$4);
			ZVAL_STRING(&_4$$4, "populationDensity");
			zephir_array_fast_append(&_3$$4, &_4$$4);
			ZEPHIR_INIT_NVAR(&_4$$4);
			ZVAL_STRING(&_4$$4, "postalCode");
			zephir_array_fast_append(&_3$$4, &_4$$4);
			ZEPHIR_INIT_NVAR(&_4$$4);
			ZVAL_STRING(&_4$$4, "postalConfidence");
			zephir_array_fast_append(&_3$$4, &_4$$4);
			ZEPHIR_INIT_NVAR(&_4$$4);
			ZVAL_STRING(&_4$$4, "timeZone");
			zephir_array_fast_append(&_3$$4, &_4$$4);
			zephir_update_property_zval(this_ptr, SL("validAttributes"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

