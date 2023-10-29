
extern zend_class_entry *sqids_math_mathinterface_ce;

ZEPHIR_INIT_CLASS(Sqids_Math_MathInterface);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sqids_math_mathinterface_add, 0, 2, IS_STRING, 0)
	ZEND_ARG_INFO(0, a)
	ZEND_ARG_INFO(0, b)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sqids_math_mathinterface_multiply, 0, 2, IS_STRING, 0)
	ZEND_ARG_INFO(0, a)
	ZEND_ARG_INFO(0, b)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sqids_math_mathinterface_divide, 0, 2, IS_STRING, 0)
	ZEND_ARG_INFO(0, a)
	ZEND_ARG_INFO(0, b)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sqids_math_mathinterface_mod, 0, 2, IS_STRING, 0)
	ZEND_ARG_INFO(0, n)
	ZEND_ARG_INFO(0, d)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sqids_math_mathinterface_greaterthan, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, a)
	ZEND_ARG_INFO(0, b)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sqids_math_mathinterface_intval, 0, 1, IS_LONG, 0)
	ZEND_ARG_INFO(0, a)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sqids_math_mathinterface_strval, 0, 1, IS_STRING, 0)
	ZEND_ARG_INFO(0, a)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sqids_math_mathinterface_get, 0, 1, IS_STRING, 0)
	ZEND_ARG_INFO(0, a)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(sqids_math_mathinterface_method_entry) {
	PHP_ABSTRACT_ME(Sqids_Math_MathInterface, add, arginfo_sqids_math_mathinterface_add)
	PHP_ABSTRACT_ME(Sqids_Math_MathInterface, multiply, arginfo_sqids_math_mathinterface_multiply)
	PHP_ABSTRACT_ME(Sqids_Math_MathInterface, divide, arginfo_sqids_math_mathinterface_divide)
	PHP_ABSTRACT_ME(Sqids_Math_MathInterface, mod, arginfo_sqids_math_mathinterface_mod)
	PHP_ABSTRACT_ME(Sqids_Math_MathInterface, greaterThan, arginfo_sqids_math_mathinterface_greaterthan)
	PHP_ABSTRACT_ME(Sqids_Math_MathInterface, intval, arginfo_sqids_math_mathinterface_intval)
	PHP_ABSTRACT_ME(Sqids_Math_MathInterface, strval, arginfo_sqids_math_mathinterface_strval)
	PHP_ABSTRACT_ME(Sqids_Math_MathInterface, get, arginfo_sqids_math_mathinterface_get)
	PHP_FE_END
};
