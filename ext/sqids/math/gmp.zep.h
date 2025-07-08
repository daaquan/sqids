
extern zend_class_entry *sqids_math_gmp_ce;

ZEPHIR_INIT_CLASS(Sqids_Math_Gmp);

PHP_METHOD(Sqids_Math_Gmp, add);
PHP_METHOD(Sqids_Math_Gmp, multiply);
PHP_METHOD(Sqids_Math_Gmp, divide);
PHP_METHOD(Sqids_Math_Gmp, mod);
PHP_METHOD(Sqids_Math_Gmp, greaterThan);
PHP_METHOD(Sqids_Math_Gmp, intval);
PHP_METHOD(Sqids_Math_Gmp, strval);
PHP_METHOD(Sqids_Math_Gmp, get);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sqids_math_gmp_add, 0, 2, IS_STRING, 0)
	ZEND_ARG_INFO(0, a)
	ZEND_ARG_INFO(0, b)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sqids_math_gmp_multiply, 0, 2, IS_STRING, 0)
	ZEND_ARG_INFO(0, a)
	ZEND_ARG_INFO(0, b)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sqids_math_gmp_divide, 0, 2, IS_STRING, 0)
	ZEND_ARG_INFO(0, a)
	ZEND_ARG_INFO(0, b)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sqids_math_gmp_mod, 0, 2, IS_STRING, 0)
	ZEND_ARG_INFO(0, n)
	ZEND_ARG_INFO(0, d)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sqids_math_gmp_greaterthan, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, a)
	ZEND_ARG_INFO(0, b)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sqids_math_gmp_intval, 0, 1, IS_LONG, 0)
	ZEND_ARG_INFO(0, a)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sqids_math_gmp_strval, 0, 1, IS_STRING, 0)
	ZEND_ARG_INFO(0, a)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sqids_math_gmp_get, 0, 1, IS_STRING, 0)
	ZEND_ARG_INFO(0, a)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(sqids_math_gmp_method_entry) {
	PHP_ME(Sqids_Math_Gmp, add, arginfo_sqids_math_gmp_add, ZEND_ACC_PUBLIC)
	PHP_ME(Sqids_Math_Gmp, multiply, arginfo_sqids_math_gmp_multiply, ZEND_ACC_PUBLIC)
	PHP_ME(Sqids_Math_Gmp, divide, arginfo_sqids_math_gmp_divide, ZEND_ACC_PUBLIC)
	PHP_ME(Sqids_Math_Gmp, mod, arginfo_sqids_math_gmp_mod, ZEND_ACC_PUBLIC)
	PHP_ME(Sqids_Math_Gmp, greaterThan, arginfo_sqids_math_gmp_greaterthan, ZEND_ACC_PUBLIC)
	PHP_ME(Sqids_Math_Gmp, intval, arginfo_sqids_math_gmp_intval, ZEND_ACC_PUBLIC)
	PHP_ME(Sqids_Math_Gmp, strval, arginfo_sqids_math_gmp_strval, ZEND_ACC_PUBLIC)
	PHP_ME(Sqids_Math_Gmp, get, arginfo_sqids_math_gmp_get, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
