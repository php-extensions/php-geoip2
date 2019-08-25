
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
 * Contains data for the traits record associated with an IP address.
 *
 * This record is returned by all location services and databases.
 *
 * @property-read int|null $autonomousSystemNumber The
 * {@link * http://en.wikipedia.org/wiki/Autonomous_system_(Internet) autonomous
 * system number} associated with the IP address. This attribute is only
 * available from the City and Insights web service and the GeoIP2
 * Enterprise database.
 * @property-read string|null $autonomousSystemOrganization The organization
 * associated with the registered {@link * http://en.wikipedia.org/wiki/Autonomous_system_(Internet) autonomous
 * system number} for the IP address. This attribute is only available from
 * the City and Insights web service and the GeoIP2 Enterprise
 * database.
 * @property-read string|null $connectionType The connection type may take the
 * following  values: "Dialup", "Cable/DSL", "Corporate", "Cellular".
 * Additional values may be added in the future. This attribute is only
 * available in the GeoIP2 Enterprise database.
 * @property-read string|null $domain The second level domain associated with the
 * IP address. This will be something like "example.com" or "example.co.uk",
 * not "foo.example.com". This attribute is only available from the
 * City and Insights web service and the GeoIP2 Enterprise
 * database.
 * @property-read string $ipAddress The IP address that the data in the model
 * is for. If you performed a "me" lookup against the web service, this
 * will be the externally routable IP address for the system the code is
 * running on. If the system is behind a NAT, this may differ from the IP
 * address locally assigned to it. This attribute is returned by all end
 * points.
 * @property-read bool $isAnonymousProxy *Deprecated.* Please see our
 * {@link * https://www.maxmind.com/en/geoip2-anonymous-ip-database GeoIP2
 * Anonymous IP database} to determine whether the IP address is used by an
 * anonymizing service.
 * @property-read bool $isLegitimateProxy This attribute is true if MaxMind
 * believes this IP address to be a legitimate proxy, such as an internal
 * VPN used by a corporation. This attribute is only available in the GeoIP2
 * Enterprise database.
 * @property-read bool $isSatelliteProvider *Deprecated.* Due to the
 * increased coverage by mobile carriers, very few satellite providers now
 * serve multiple countries. As a result, the output does not provide
 * sufficiently relevant data for us to maintain it.
 * @property-read string|null $isp The name of the ISP associated with the IP
 * address. This attribute is only available from the City and Insights web
 * services and the GeoIP2 Enterprise database.
 * @property-read string|null $organization The name of the organization associated
 * with the IP address. This attribute is only available from the City and
 * Insights web services and the GeoIP2 Enterprise database.
 * @property-read string|null $userType <p>The user type associated with the IP
 *  address. This can be one of the following values:</p>
 *  <ul>
 *    <li>business
 *    <li>cafe
 *    <li>cellular
 *    <li>college
 *    <li>content_delivery_network
 *    <li>dialup
 *    <li>government
 *    <li>hosting
 *    <li>library
 *    <li>military
 *    <li>residential
 *    <li>router
 *    <li>school
 *    <li>search_engine_spider
 *    <li>traveler
 * </ul>
 * <p>
 *   This attribute is only available from the Insights web service and the
 *   GeoIP2 Enterprise database.
 * </p>
 */
ZEPHIR_INIT_CLASS(GeoIP2_Record_Traits) {

	ZEPHIR_REGISTER_CLASS_EX(GeoIP2\\Record, Traits, geoip2, record_traits, geoip2_record_abstractrecord_ce, NULL, 0);

	/**
	 * @ignore
	 */
	zend_declare_property_null(geoip2_record_traits_ce, SL("validAttributes"), ZEND_ACC_PROTECTED TSRMLS_CC);

	geoip2_record_traits_ce->create_object = zephir_init_properties_GeoIP2_Record_Traits;
	return SUCCESS;

}

zend_object *zephir_init_properties_GeoIP2_Record_Traits(zend_class_entry *class_type TSRMLS_DC) {

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
			zephir_create_array(&_3$$4, 11, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_4$$4);
			ZVAL_STRING(&_4$$4, "autonomousSystemNumber");
			zephir_array_fast_append(&_3$$4, &_4$$4);
			ZEPHIR_INIT_NVAR(&_4$$4);
			ZVAL_STRING(&_4$$4, "autonomousSystemOrganization");
			zephir_array_fast_append(&_3$$4, &_4$$4);
			ZEPHIR_INIT_NVAR(&_4$$4);
			ZVAL_STRING(&_4$$4, "connectionType");
			zephir_array_fast_append(&_3$$4, &_4$$4);
			ZEPHIR_INIT_NVAR(&_4$$4);
			ZVAL_STRING(&_4$$4, "domain");
			zephir_array_fast_append(&_3$$4, &_4$$4);
			ZEPHIR_INIT_NVAR(&_4$$4);
			ZVAL_STRING(&_4$$4, "isAnonymousProxy");
			zephir_array_fast_append(&_3$$4, &_4$$4);
			ZEPHIR_INIT_NVAR(&_4$$4);
			ZVAL_STRING(&_4$$4, "isLegitimateProxy");
			zephir_array_fast_append(&_3$$4, &_4$$4);
			ZEPHIR_INIT_NVAR(&_4$$4);
			ZVAL_STRING(&_4$$4, "isSatelliteProvider");
			zephir_array_fast_append(&_3$$4, &_4$$4);
			ZEPHIR_INIT_NVAR(&_4$$4);
			ZVAL_STRING(&_4$$4, "isp");
			zephir_array_fast_append(&_3$$4, &_4$$4);
			ZEPHIR_INIT_NVAR(&_4$$4);
			ZVAL_STRING(&_4$$4, "ipAddress");
			zephir_array_fast_append(&_3$$4, &_4$$4);
			ZEPHIR_INIT_NVAR(&_4$$4);
			ZVAL_STRING(&_4$$4, "organization");
			zephir_array_fast_append(&_3$$4, &_4$$4);
			ZEPHIR_INIT_NVAR(&_4$$4);
			ZVAL_STRING(&_4$$4, "userType");
			zephir_array_fast_append(&_3$$4, &_4$$4);
			zephir_update_property_zval(this_ptr, SL("validAttributes"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

