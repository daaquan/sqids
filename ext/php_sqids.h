
/* This file was generated automatically by Zephir do not modify it! */

#ifndef PHP_SQIDS_H
#define PHP_SQIDS_H 1

#ifdef PHP_WIN32
#define ZEPHIR_RELEASE 1
#endif

#include "kernel/globals.h"

#define PHP_SQIDS_NAME        "sqids"
#define PHP_SQIDS_VERSION     "0.0.1"
#define PHP_SQIDS_EXTNAME     "sqids"
#define PHP_SQIDS_AUTHOR      "Phalcon Team"
#define PHP_SQIDS_ZEPVERSION  "0.19.0-$Id$"
#define PHP_SQIDS_DESCRIPTION ""



ZEND_BEGIN_MODULE_GLOBALS(sqids)

	int initialized;

	/** Function cache */
	HashTable *fcache;

	zephir_fcall_cache_entry *scache[ZEPHIR_MAX_CACHE_SLOTS];

	/* Cache enabled */
	unsigned int cache_enabled;

	/* Max recursion control */
	unsigned int recursive_lock;

	
ZEND_END_MODULE_GLOBALS(sqids)

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_EXTERN_MODULE_GLOBALS(sqids)

#ifdef ZTS
	#define ZEPHIR_GLOBAL(v) ZEND_MODULE_GLOBALS_ACCESSOR(sqids, v)
#else
	#define ZEPHIR_GLOBAL(v) (sqids_globals.v)
#endif

#ifdef ZTS
	ZEND_TSRMLS_CACHE_EXTERN()
	#define ZEPHIR_VGLOBAL ((zend_sqids_globals *) (*((void ***) tsrm_get_ls_cache()))[TSRM_UNSHUFFLE_RSRC_ID(sqids_globals_id)])
#else
	#define ZEPHIR_VGLOBAL &(sqids_globals)
#endif

#define ZEPHIR_API ZEND_API

#define zephir_globals_def sqids_globals
#define zend_zephir_globals_def zend_sqids_globals

extern zend_module_entry sqids_module_entry;
#define phpext_sqids_ptr &sqids_module_entry

#endif
