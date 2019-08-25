
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"


/**
 * This class should be thrown when unexpected data is found in the database.
 */
ZEPHIR_INIT_CLASS(GeoIP2_MaxMind_Db_Reader_InvalidDatabaseException) {

	ZEPHIR_REGISTER_CLASS_EX(GeoIP2\\MaxMind\\Db\\Reader, InvalidDatabaseException, geoip2, maxmind_db_reader_invaliddatabaseexception, zend_exception_get_default(TSRMLS_C), NULL, 0);

	return SUCCESS;

}

