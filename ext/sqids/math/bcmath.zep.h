
extern zend_class_entry *sqids_math_bcmath_ce;

ZEPHIR_INIT_CLASS(Sqids_Math_BCMath);

PHP_METHOD(Sqids_Math_BCMath, add);
PHP_METHOD(Sqids_Math_BCMath, multiply);
PHP_METHOD(Sqids_Math_BCMath, divide);
PHP_METHOD(Sqids_Math_BCMath, mod);
PHP_METHOD(Sqids_Math_BCMath, greaterThan);
PHP_METHOD(Sqids_Math_BCMath, intval);
PHP_METHOD(Sqids_Math_BCMath, strval);
PHP_METHOD(Sqids_Math_BCMath, get);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sqids_math_bcmath_add, 0, 2, IS_STRING, 0)
	ZEND_ARG_INFO(0, a)
	ZEND_ARG_INFO(0, b)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sqids_math_bcmath_multiply, 0, 2, IS_STRING, 0)
	ZEND_ARG_INFO(0, a)
	ZEND_ARG_INFO(0, b)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sqids_math_bcmath_divide, 0, 2, IS_STRING, 0)
	ZEND_ARG_INFO(0, a)
	ZEND_ARG_INFO(0, b)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sqids_math_bcmath_mod, 0, 2, IS_STRING, 0)
	ZEND_ARG_INFO(0, n)
	ZEND_ARG_INFO(0, d)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sqids_math_bcmath_greaterthan, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, a)
	ZEND_ARG_INFO(0, b)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sqids_math_bcmath_intval, 0, 1, IS_LONG, 0)
	ZEND_ARG_INFO(0, a)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sqids_math_bcmath_strval, 0, 1, IS_STRING, 0)
	ZEND_ARG_INFO(0, a)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sqids_math_bcmath_get, 0, 1, IS_STRING, 0)
	ZEND_ARG_INFO(0, a)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(sqids_math_bcmath_method_entry) {
	PHP_ME(Sqids_Math_BCMath, add, arginfo_sqids_math_bcmath_add, ZEND_ACC_PUBLIC)
	PHP_ME(Sqids_Math_BCMath, multiply, arginfo_sqids_math_bcmath_multiply, ZEND_ACC_PUBLIC)
	PHP_ME(Sqids_Math_BCMath, divide, arginfo_sqids_math_bcmath_divide, ZEND_ACC_PUBLIC)
	PHP_ME(Sqids_Math_BCMath, mod, arginfo_sqids_math_bcmath_mod, ZEND_ACC_PUBLIC)
	PHP_ME(Sqids_Math_BCMath, greaterThan, arginfo_sqids_math_bcmath_greaterthan, ZEND_ACC_PUBLIC)
	PHP_ME(Sqids_Math_BCMath, intval, arginfo_sqids_math_bcmath_intval, ZEND_ACC_PUBLIC)
	PHP_ME(Sqids_Math_BCMath, strval, arginfo_sqids_math_bcmath_strval, ZEND_ACC_PUBLIC)
	PHP_ME(Sqids_Math_BCMath, get, arginfo_sqids_math_bcmath_get, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
