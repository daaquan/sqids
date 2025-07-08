
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#include "php_ext.h"
#include "sqids.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/globals.h"
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *sqids_math_mathinterface_ce;
zend_class_entry *sqids_sqidsinterface_ce;
zend_class_entry *sqids_0__closure_ce;
zend_class_entry *sqids_1__closure_ce;
zend_class_entry *sqids_2__closure_ce;
zend_class_entry *sqids_math_bcmath_ce;
zend_class_entry *sqids_math_gmp_ce;
zend_class_entry *sqids_sqids_ce;

ZEND_DECLARE_MODULE_GLOBALS(sqids)

PHP_INI_BEGIN()
	
PHP_INI_END()

static PHP_MINIT_FUNCTION(sqids)
{
	REGISTER_INI_ENTRIES();
	zephir_module_init();
	ZEPHIR_INIT(Sqids_Math_MathInterface);
	ZEPHIR_INIT(Sqids_SqidsInterface);
	ZEPHIR_INIT(Sqids_Math_BCMath);
	ZEPHIR_INIT(Sqids_Math_Gmp);
	ZEPHIR_INIT(Sqids_Sqids);
	ZEPHIR_INIT(sqids_0__closure);
	ZEPHIR_INIT(sqids_1__closure);
	ZEPHIR_INIT(sqids_2__closure);
	
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(sqids)
{
	
	zephir_deinitialize_memory();
	UNREGISTER_INI_ENTRIES();
	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_sqids_globals *sqids_globals)
{
	sqids_globals->initialized = 0;

	/* Cache Enabled */
	sqids_globals->cache_enabled = 1;

	/* Recursive Lock */
	sqids_globals->recursive_lock = 0;

	/* Static cache */
	memset(sqids_globals->scache, '\0', sizeof(zephir_fcall_cache_entry*) * ZEPHIR_MAX_CACHE_SLOTS);

	
	
}

/**
 * Initialize globals only on each thread started
 */
static void php_zephir_init_module_globals(zend_sqids_globals *sqids_globals)
{
	
}

static PHP_RINIT_FUNCTION(sqids)
{
	zend_sqids_globals *sqids_globals_ptr;
	sqids_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(sqids_globals_ptr);
	zephir_initialize_memory(sqids_globals_ptr);

	
	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(sqids)
{
	
	zephir_deinitialize_memory();
	return SUCCESS;
}



static PHP_MINFO_FUNCTION(sqids)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_SQIDS_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_SQIDS_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_SQIDS_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_SQIDS_VERSION);
	php_info_print_table_row(2, "Build Date", __DATE__ " " __TIME__ );
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_SQIDS_ZEPVERSION);
	php_info_print_table_end();
	
	DISPLAY_INI_ENTRIES();
}

static PHP_GINIT_FUNCTION(sqids)
{
#if defined(COMPILE_DL_SQIDS) && defined(ZTS)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif

	php_zephir_init_globals(sqids_globals);
	php_zephir_init_module_globals(sqids_globals);
}

static PHP_GSHUTDOWN_FUNCTION(sqids)
{
	
}


zend_function_entry php_sqids_functions[] = {
	ZEND_FE_END

};

static const zend_module_dep php_sqids_deps[] = {
	
	ZEND_MOD_END
};

zend_module_entry sqids_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	php_sqids_deps,
	PHP_SQIDS_EXTNAME,
	php_sqids_functions,
	PHP_MINIT(sqids),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(sqids),
#else
	NULL,
#endif
	PHP_RINIT(sqids),
	PHP_RSHUTDOWN(sqids),
	PHP_MINFO(sqids),
	PHP_SQIDS_VERSION,
	ZEND_MODULE_GLOBALS(sqids),
	PHP_GINIT(sqids),
	PHP_GSHUTDOWN(sqids),
#ifdef ZEPHIR_POST_REQUEST
	PHP_PRSHUTDOWN(sqids),
#else
	NULL,
#endif
	STANDARD_MODULE_PROPERTIES_EX
};

/* implement standard "stub" routine to introduce ourselves to Zend */
#ifdef COMPILE_DL_SQIDS
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(sqids)
#endif
