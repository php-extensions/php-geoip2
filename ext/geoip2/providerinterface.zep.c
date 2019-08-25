
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(GeoIP2_ProviderInterface) {

	ZEPHIR_REGISTER_INTERFACE(GeoIP2, ProviderInterface, geoip2, providerinterface, geoip2_providerinterface_method_entry);

	return SUCCESS;

}

/**
 * @param string $ipAddress an IPv4 or IPv6 address to lookup
 *
 * @return \GeoIp2\Model\Country a Country model for the requested IP address
 */
ZEPHIR_DOC_METHOD(GeoIP2_ProviderInterface, country);

/**
 * @param string $ipAddress an IPv4 or IPv6 address to lookup
 *
 * @return \GeoIp2\Model\City a City model for the requested IP address
 */
ZEPHIR_DOC_METHOD(GeoIP2_ProviderInterface, city);

