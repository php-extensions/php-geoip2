
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


/**
 * Model class for the data returned by GeoIP2 Country web service and database.
 *
 * The only difference between the City and Insights model classes is which
 * fields in each record may be populated. See
 * http://dev.maxmind.com/geoip/geoip2/web-services more details.
 *
 * @property-read \GeoIp2\Record\Continent $continent Continent data for the
 * requested IP address.
 * @property-read \GeoIp2\Record\Country $country Country data for the requested
 * IP address. This object represents the country where MaxMind believes the
 * end user is located.
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
 * @property-read \GeoIp2\Record\Traits $traits Data for the traits of the
 * requested IP address.
 */
ZEPHIR_INIT_CLASS(GeoIP2_Model_Country) {

	ZEPHIR_REGISTER_CLASS_EX(GeoIP2\\Model, Country, geoip2, model_country, geoip2_model_abstractmodel_ce, geoip2_model_country_method_entry, 0);

	zend_declare_property_null(geoip2_model_country_ce, SL("continent"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(geoip2_model_country_ce, SL("country"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(geoip2_model_country_ce, SL("locales"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(geoip2_model_country_ce, SL("registeredCountry"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(geoip2_model_country_ce, SL("representedCountry"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(geoip2_model_country_ce, SL("traits"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * @ignore
 *
 * @param mixed $raw
 * @param mixed $locales
 */
PHP_METHOD(GeoIP2_Model_Country, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval locales;
	zval *raw, raw_sub, *locales_param = NULL, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&raw_sub);
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
	ZVAL_UNDEF(&locales);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &raw, &locales_param);

	if (!locales_param) {
		ZEPHIR_INIT_VAR(&locales);
		array_init(&locales);
	} else {
		zephir_get_arrval(&locales, locales_param);
	}


	ZEPHIR_CALL_PARENT(NULL, geoip2_model_country_ce, getThis(), "__construct", &_0, 0, raw);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	object_init_ex(&_1, geoip2_record_continent_ce);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "continent");
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "get", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 9, &_2, &locales);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("continent"), &_1);
	ZEPHIR_INIT_NVAR(&_3);
	object_init_ex(&_3, geoip2_record_country_ce);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "country");
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "get", NULL, 0, &_5);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_3, "__construct", NULL, 9, &_4, &locales);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("country"), &_3);
	ZEPHIR_INIT_NVAR(&_5);
	object_init_ex(&_5, geoip2_record_country_ce);
	ZEPHIR_INIT_VAR(&_7);
	ZVAL_STRING(&_7, "registered_country");
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "get", NULL, 0, &_7);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_5, "__construct", NULL, 9, &_6, &locales);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("registeredCountry"), &_5);
	ZEPHIR_INIT_NVAR(&_7);
	object_init_ex(&_7, geoip2_record_representedcountry_ce);
	ZEPHIR_INIT_VAR(&_9);
	ZVAL_STRING(&_9, "represented_country");
	ZEPHIR_CALL_METHOD(&_8, this_ptr, "get", NULL, 0, &_9);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_7, "__construct", NULL, 9, &_8, &locales);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("representedCountry"), &_7);
	ZEPHIR_INIT_NVAR(&_9);
	object_init_ex(&_9, geoip2_record_traits_ce);
	ZEPHIR_INIT_VAR(&_11);
	ZVAL_STRING(&_11, "traits");
	ZEPHIR_CALL_METHOD(&_10, this_ptr, "get", NULL, 0, &_11);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_9, "__construct", NULL, 10, &_10);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("traits"), &_9);
	zephir_update_property_zval(this_ptr, SL("locales"), &locales);
	ZEPHIR_MM_RESTORE();

}

