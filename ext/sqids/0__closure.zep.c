
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(sqids_0__closure)
{
	ZEPHIR_REGISTER_CLASS(sqids, 0__closure, sqids, 0__closure, sqids_0__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	zend_declare_property_null(sqids_0__closure_ce, SL("alphabetChars"), ZEND_ACC_PUBLIC|ZEND_ACC_STATIC);
	return SUCCESS;
}

PHP_METHOD(sqids_0__closure, __invoke)
{
	zval alphabetChars, *c, c_sub;

	ZVAL_UNDEF(&alphabetChars);
	ZVAL_UNDEF(&c_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(c)
	ZEND_PARSE_PARAMETERS_END();
	zephir_read_static_property_ce(&alphabetChars, sqids_0__closure_ce, SL("alphabetChars"), PH_NOISY_CC);
	zephir_fetch_params_without_memory_grow(1, 0, &c);
	RETURN_BOOL(zephir_fast_in_array(c, &alphabetChars));
}

