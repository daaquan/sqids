
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(sqids_2__closure)
{
	ZEPHIR_REGISTER_CLASS(sqids, 2__closure, sqids, 2__closure, sqids_2__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;
}

PHP_METHOD(sqids_2__closure, __invoke)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *n, n_sub, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&n_sub);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(n)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &n);


	_0 = ZEPHIR_GE_LONG(n, 0);
	if (_0) {
		ZEPHIR_INIT_VAR(&_1);
		ZEPHIR_GET_CONSTANT(&_1, "PHP_INT_MAX");
		_0 = ZEPHIR_LE(n, &_1);
	}
	RETURN_MM_BOOL(_0);
}

