
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/array.h"


/**
 * Model class for the data returned by GeoIP2 City web service and database.
 *
 * The only difference between the City and Insights model classes is which
 * fields in each record may be populated. See
 * http://dev.maxmind.com/geoip/geoip2/web-services more details.
 *
 * @property-read \GeoIp2\Record\City $city City data for the requested IP
 * address.
 * @property-read \GeoIp2\Record\Continent $continent Continent data for the
 * requested IP address.
 * @property-read \GeoIp2\Record\Country $country Country data for the requested
 * IP address. This object represents the country where MaxMind believes the
 * end user is located.
 * @property-read \GeoIp2\Record\Location $location Location data for the
 * requested IP address.
 * @property-read \GeoIp2\Record\Postal $postal Postal data for the
 * requested IP address.
 * @property-read \GeoIp2\Record\MaxMind $maxmind Data related to your MaxMind
 * account.
 * @property-read \GeoIp2\Record\Country $registeredCountry Registered country
 * data for the requested IP address. This record represents the country
 * where the ISP has registered a given IP block and may differ from the
 * user's country.
 * @property-read \GeoIp2\Record\RepresentedCountry $representedCountry
 * Represented country data for the requested IP address. The represented
 * country is used for things like military bases. It is only present when
 * the represented country differs from the country.
 * @property-read array $subdivisions An array of {@link \GeoIp2\Record\Subdivision}
 * objects representing the country subdivisions for the requested IP
 * address. The number and type of subdivisions varies by country, but a
 * subdivision is typically a state, province, county, etc. Subdivisions
 * are ordered from most general (largest) to most specific (smallest).
 * If the response did not contain any subdivisions, this method returns
 * an empty array.
 * @property-read \GeoIp2\Record\Subdivision $mostSpecificSubdivision An  object
 * representing the most specific subdivision returned. If the response
 * did not contain any subdivisions, this method returns an empty
 * {@link \GeoIp2\Record\Subdivision} object.
 * @property-read \GeoIp2\Record\Traits $traits Data for the traits of the
 * requested IP address.
 */
ZEPHIR_INIT_CLASS(GeoIP2_Model_City) {

	ZEPHIR_REGISTER_CLASS_EX(GeoIP2\\Model, City, geoip2, model_city, geoip2_model_country_ce, geoip2_model_city_method_entry, 0);

	/**
	 * @ignore
	 */
	zend_declare_property_null(geoip2_model_city_ce, SL("city"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @ignore
	 */
	zend_declare_property_null(geoip2_model_city_ce, SL("location"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @ignore
	 */
	zend_declare_property_null(geoip2_model_city_ce, SL("postal"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @ignore
	 */
	zend_declare_property_null(geoip2_model_city_ce, SL("subdivisions"), ZEND_ACC_PROTECTED TSRMLS_CC);

	geoip2_model_city_ce->create_object = zephir_init_properties_GeoIP2_Model_City;
	return SUCCESS;

}

/**
 * @ignore
 *
 * @param mixed $raw
 * @param mixed $locales
 */
PHP_METHOD(GeoIP2_Model_City, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval locales;
	zval *raw, raw_sub, *locales_param = NULL, _1, _2, _3, _4, _5, _6, _7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&raw_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&locales);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &raw, &locales_param);

	if (!locales_param) {
		ZEPHIR_INIT_VAR(&locales);
		array_init(&locales);
	} else {
		zephir_get_arrval(&locales, locales_param);
	}


	ZEPHIR_CALL_PARENT(NULL, geoip2_model_city_ce, getThis(), "__construct", &_0, 0, raw, &locales);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	object_init_ex(&_1, geoip2_record_city_ce);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "city");
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "get", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 9, &_2, &locales);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("city"), &_1);
	ZEPHIR_INIT_NVAR(&_3);
	object_init_ex(&_3, geoip2_record_location_ce);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "location");
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "get", NULL, 0, &_5);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_3, "__construct", NULL, 10, &_4);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("location"), &_3);
	ZEPHIR_INIT_NVAR(&_5);
	object_init_ex(&_5, geoip2_record_postal_ce);
	ZEPHIR_INIT_VAR(&_7);
	ZVAL_STRING(&_7, "postal");
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "get", NULL, 0, &_7);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_5, "__construct", NULL, 10, &_6);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("postal"), &_5);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "createsubdivisions", NULL, 11, raw, &locales);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(GeoIP2_Model_City, createSubdivisions) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval locales;
	zval *raw, raw_sub, *locales_param = NULL, sub, _0, *_1, _2, _3$$4, _5$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&raw_sub);
	ZVAL_UNDEF(&sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&locales);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &raw, &locales_param);

	zephir_get_arrval(&locales, locales_param);


	if (!(zephir_array_isset_string(raw, SL("subdivisions")))) {
		RETURN_MM_NULL();
	}
	zephir_array_fetch_string(&_0, raw, SL("subdivisions"), PH_NOISY | PH_READONLY, "geoip2/Model/City.zep", 84 TSRMLS_CC);
	zephir_is_iterable(&_0, 0, "geoip2/Model/City.zep", 87);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _1)
		{
			ZEPHIR_INIT_NVAR(&sub);
			ZVAL_COPY(&sub, _1);
			ZEPHIR_INIT_NVAR(&_3$$4);
			object_init_ex(&_3$$4, geoip2_record_subdivision_ce);
			ZEPHIR_CALL_METHOD(NULL, &_3$$4, "__construct", &_4, 9, &sub, &locales);
			zephir_check_call_status();
			zephir_update_property_array_append(this_ptr, SL("subdivisions"), &_3$$4);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_0, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &_0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&sub, &_0, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_5$$5);
				object_init_ex(&_5$$5, geoip2_record_subdivision_ce);
				ZEPHIR_CALL_METHOD(NULL, &_5$$5, "__construct", &_4, 9, &sub, &locales);
				zephir_check_call_status();
				zephir_update_property_array_append(this_ptr, SL("subdivisions"), &_5$$5);
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&sub);
	ZEPHIR_MM_RESTORE();

}

/**
 * @ignore
 *
 * @param mixed $attr
 */
PHP_METHOD(GeoIP2_Model_City, __get) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_0 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *attr_param = NULL;
	zval attr;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attr);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attr_param);

	zephir_get_strval(&attr, attr_param);


	if (ZEPHIR_IS_STRING_IDENTICAL(&attr, "mostSpecificSubdivision")) {
		ZEPHIR_RETURN_CALL_METHOD_ZVAL(this_ptr, &attr, NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_RETURN_CALL_PARENT(geoip2_model_city_ce, getThis(), "__get", &_0, 0, &attr);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @ignore
 *
 * @param mixed $attr
 */
PHP_METHOD(GeoIP2_Model_City, __isset) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *attr_param = NULL;
	zval attr;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attr);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attr_param);

	zephir_get_strval(&attr, attr_param);


	if (ZEPHIR_IS_STRING_IDENTICAL(&attr, "mostSpecificSubdivision")) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_RETURN_CALL_PARENT(geoip2_model_city_ce, getThis(), "__isset", &_0, 0, &attr);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(GeoIP2_Model_City, mostSpecificSubdivision) {

	zval _0, _1, _2, _3, _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, SL("subdivisions"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_EMPTY(&_1)) {
		object_init_ex(&_0, geoip2_record_subdivision_ce);
		ZEPHIR_INIT_VAR(&_2);
		array_init(&_2);
		zephir_read_property(&_3, this_ptr, SL("locales"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 9, &_2, &_3);
		zephir_check_call_status();
	} else {
		zephir_read_property(&_4, this_ptr, SL("subdivisions"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_MAKE_REF(&_4);
		ZEPHIR_CALL_FUNCTION(&_0, "end", NULL, 12, &_4);
		ZEPHIR_UNREF(&_4);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&_0);

}

zend_object *zephir_init_properties_GeoIP2_Model_City(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("subdivisions"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("subdivisions"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

