
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


ZEPHIR_INIT_CLASS(GeoIP2_Model_Custom) {

	ZEPHIR_REGISTER_CLASS_EX(GeoIP2\\Model, Custom, geoip2, model_custom, geoip2_model_abstractmodel_ce, NULL, 0);

	return SUCCESS;

}

