
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#include "php_ext.h"
#include "geoip2.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/globals.h"
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *geoip2_providerinterface_ce;
zend_class_entry *geoip2_model_abstractmodel_ce;
zend_class_entry *geoip2_record_abstractrecord_ce;
zend_class_entry *geoip2_exception_geoip2exception_ce;
zend_class_entry *geoip2_record_abstractplacerecord_ce;
zend_class_entry *geoip2_model_country_ce;
zend_class_entry *geoip2_model_city_ce;
zend_class_entry *geoip2_exception_httpexception_ce;
zend_class_entry *geoip2_record_country_ce;
zend_class_entry *geoip2_database_reader_ce;
zend_class_entry *geoip2_database_reader_metadata_ce;
zend_class_entry *geoip2_exception_addressnotfoundexception_ce;
zend_class_entry *geoip2_exception_authenticationexception_ce;
zend_class_entry *geoip2_exception_invaliddatabaseexception_ce;
zend_class_entry *geoip2_exception_invalidrequestexception_ce;
zend_class_entry *geoip2_exception_outofqueriesexception_ce;
zend_class_entry *geoip2_maxmind_db_reader_ce;
zend_class_entry *geoip2_maxmind_db_reader_decoder_ce;
zend_class_entry *geoip2_maxmind_db_reader_invaliddatabaseexception_ce;
zend_class_entry *geoip2_maxmind_db_reader_metadata_ce;
zend_class_entry *geoip2_maxmind_db_reader_util_ce;
zend_class_entry *geoip2_model_anonymousip_ce;
zend_class_entry *geoip2_model_asn_ce;
zend_class_entry *geoip2_model_connectiontype_ce;
zend_class_entry *geoip2_model_custom_ce;
zend_class_entry *geoip2_model_domain_ce;
zend_class_entry *geoip2_model_enterprise_ce;
zend_class_entry *geoip2_model_insights_ce;
zend_class_entry *geoip2_model_isp_ce;
zend_class_entry *geoip2_record_city_ce;
zend_class_entry *geoip2_record_continent_ce;
zend_class_entry *geoip2_record_location_ce;
zend_class_entry *geoip2_record_maxmind_ce;
zend_class_entry *geoip2_record_postal_ce;
zend_class_entry *geoip2_record_representedcountry_ce;
zend_class_entry *geoip2_record_subdivision_ce;
zend_class_entry *geoip2_record_traits_ce;

ZEND_DECLARE_MODULE_GLOBALS(geoip2)

PHP_INI_BEGIN()
	
PHP_INI_END()

static PHP_MINIT_FUNCTION(geoip2)
{
	REGISTER_INI_ENTRIES();
	zephir_module_init();
	ZEPHIR_INIT(GeoIP2_ProviderInterface);
	ZEPHIR_INIT(GeoIP2_Model_AbstractModel);
	ZEPHIR_INIT(GeoIP2_Record_AbstractRecord);
	ZEPHIR_INIT(GeoIP2_Exception_GeoIP2Exception);
	ZEPHIR_INIT(GeoIP2_Record_AbstractPlaceRecord);
	ZEPHIR_INIT(GeoIP2_Model_Country);
	ZEPHIR_INIT(GeoIP2_Model_City);
	ZEPHIR_INIT(GeoIP2_Exception_HttpException);
	ZEPHIR_INIT(GeoIP2_Record_Country);
	ZEPHIR_INIT(GeoIP2_Database_Reader);
	ZEPHIR_INIT(GeoIP2_Database_Reader_Metadata);
	ZEPHIR_INIT(GeoIP2_Exception_AddressNotFoundException);
	ZEPHIR_INIT(GeoIP2_Exception_AuthenticationException);
	ZEPHIR_INIT(GeoIP2_Exception_InvalidDatabaseException);
	ZEPHIR_INIT(GeoIP2_Exception_InvalidRequestException);
	ZEPHIR_INIT(GeoIP2_Exception_OutOfQueriesException);
	ZEPHIR_INIT(GeoIP2_MaxMind_Db_Reader);
	ZEPHIR_INIT(GeoIP2_MaxMind_Db_Reader_Decoder);
	ZEPHIR_INIT(GeoIP2_MaxMind_Db_Reader_InvalidDatabaseException);
	ZEPHIR_INIT(GeoIP2_MaxMind_Db_Reader_Metadata);
	ZEPHIR_INIT(GeoIP2_MaxMind_Db_Reader_Util);
	ZEPHIR_INIT(GeoIP2_Model_AnonymousIp);
	ZEPHIR_INIT(GeoIP2_Model_Asn);
	ZEPHIR_INIT(GeoIP2_Model_ConnectionType);
	ZEPHIR_INIT(GeoIP2_Model_Custom);
	ZEPHIR_INIT(GeoIP2_Model_Domain);
	ZEPHIR_INIT(GeoIP2_Model_Enterprise);
	ZEPHIR_INIT(GeoIP2_Model_Insights);
	ZEPHIR_INIT(GeoIP2_Model_Isp);
	ZEPHIR_INIT(GeoIP2_Record_City);
	ZEPHIR_INIT(GeoIP2_Record_Continent);
	ZEPHIR_INIT(GeoIP2_Record_Location);
	ZEPHIR_INIT(GeoIP2_Record_MaxMind);
	ZEPHIR_INIT(GeoIP2_Record_Postal);
	ZEPHIR_INIT(GeoIP2_Record_RepresentedCountry);
	ZEPHIR_INIT(GeoIP2_Record_Subdivision);
	ZEPHIR_INIT(GeoIP2_Record_Traits);
	
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(geoip2)
{
	
	zephir_deinitialize_memory(TSRMLS_C);
	UNREGISTER_INI_ENTRIES();
	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_geoip2_globals *geoip2_globals TSRMLS_DC)
{
	geoip2_globals->initialized = 0;

	/* Cache Enabled */
	geoip2_globals->cache_enabled = 1;

	/* Recursive Lock */
	geoip2_globals->recursive_lock = 0;

	/* Static cache */
	memset(geoip2_globals->scache, '\0', sizeof(zephir_fcall_cache_entry*) * ZEPHIR_MAX_CACHE_SLOTS);

	
	
}

/**
 * Initialize globals only on each thread started
 */
static void php_zephir_init_module_globals(zend_geoip2_globals *geoip2_globals TSRMLS_DC)
{
	
}

static PHP_RINIT_FUNCTION(geoip2)
{
	zend_geoip2_globals *geoip2_globals_ptr;
#ifdef ZTS
	tsrm_ls = ts_resource(0);
#endif
	geoip2_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(geoip2_globals_ptr TSRMLS_CC);
	zephir_initialize_memory(geoip2_globals_ptr TSRMLS_CC);

	
	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(geoip2)
{
	
	zephir_deinitialize_memory(TSRMLS_C);
	return SUCCESS;
}



static PHP_MINFO_FUNCTION(geoip2)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_GEOIP2_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_GEOIP2_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_GEOIP2_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_GEOIP2_VERSION);
	php_info_print_table_row(2, "Build Date", __DATE__ " " __TIME__ );
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_GEOIP2_ZEPVERSION);
	php_info_print_table_end();
	
	DISPLAY_INI_ENTRIES();
}

static PHP_GINIT_FUNCTION(geoip2)
{
	php_zephir_init_globals(geoip2_globals TSRMLS_CC);
	php_zephir_init_module_globals(geoip2_globals TSRMLS_CC);
}

static PHP_GSHUTDOWN_FUNCTION(geoip2)
{
	
}


zend_function_entry php_geoip2_functions[] = {
	ZEND_FE_END

};

static const zend_module_dep php_geoip2_deps[] = {
	ZEND_MOD_REQUIRED("json")
	ZEND_MOD_END
};

zend_module_entry geoip2_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	php_geoip2_deps,
	PHP_GEOIP2_EXTNAME,
	php_geoip2_functions,
	PHP_MINIT(geoip2),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(geoip2),
#else
	NULL,
#endif
	PHP_RINIT(geoip2),
	PHP_RSHUTDOWN(geoip2),
	PHP_MINFO(geoip2),
	PHP_GEOIP2_VERSION,
	ZEND_MODULE_GLOBALS(geoip2),
	PHP_GINIT(geoip2),
	PHP_GSHUTDOWN(geoip2),
#ifdef ZEPHIR_POST_REQUEST
	PHP_PRSHUTDOWN(geoip2),
#else
	NULL,
#endif
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_GEOIP2
ZEND_GET_MODULE(geoip2)
#endif
