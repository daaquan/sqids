
extern zend_class_entry *sqids_sqidsinterface_ce;

ZEPHIR_INIT_CLASS(Sqids_SqidsInterface);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sqids_sqidsinterface_encode, 0, 1, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, numbers, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sqids_sqidsinterface_decode, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, id, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(sqids_sqidsinterface_method_entry) {
	PHP_ABSTRACT_ME(Sqids_SqidsInterface, encode, arginfo_sqids_sqidsinterface_encode)
	PHP_ABSTRACT_ME(Sqids_SqidsInterface, decode, arginfo_sqids_sqidsinterface_decode)
	PHP_FE_END
};
