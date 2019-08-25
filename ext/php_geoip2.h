
/* This file was generated automatically by Zephir do not modify it! */

#ifndef PHP_GEOIP2_H
#define PHP_GEOIP2_H 1

#ifdef PHP_WIN32
#define ZEPHIR_RELEASE 1
#endif

#include "kernel/globals.h"

#define PHP_GEOIP2_NAME        "geoip2"
#define PHP_GEOIP2_VERSION     "0.9.2"
#define PHP_GEOIP2_EXTNAME     "geoip2"
#define PHP_GEOIP2_AUTHOR      "github.com/php-extensions"
#define PHP_GEOIP2_ZEPVERSION  "0.12.2-$Id$"
#define PHP_GEOIP2_DESCRIPTION "GeoIP2 PHP API"



ZEND_BEGIN_MODULE_GLOBALS(geoip2)

	int initialized;

	/** Function cache */
	HashTable *fcache;

	zephir_fcall_cache_entry *scache[ZEPHIR_MAX_CACHE_SLOTS];

	/* Cache enabled */
	unsigned int cache_enabled;

	/* Max recursion control */
	unsigned int recursive_lock;

	
ZEND_END_MODULE_GLOBALS(geoip2)

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_EXTERN_MODULE_GLOBALS(geoip2)

#ifdef ZTS
	#define ZEPHIR_GLOBAL(v) ZEND_MODULE_GLOBALS_ACCESSOR(geoip2, v)
#else
	#define ZEPHIR_GLOBAL(v) (geoip2_globals.v)
#endif

#ifdef ZTS
	void ***tsrm_ls;
	#define ZEPHIR_VGLOBAL ((zend_geoip2_globals *) (*((void ***) tsrm_get_ls_cache()))[TSRM_UNSHUFFLE_RSRC_ID(geoip2_globals_id)])
#else
	#define ZEPHIR_VGLOBAL &(geoip2_globals)
#endif

#define ZEPHIR_API ZEND_API

#define zephir_globals_def geoip2_globals
#define zend_zephir_globals_def zend_geoip2_globals

extern zend_module_entry geoip2_module_entry;
#define phpext_geoip2_ptr &geoip2_module_entry

#endif
