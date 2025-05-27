
extern zend_class_entry *sqids_sqids_ce;

ZEPHIR_INIT_CLASS(Sqids_Sqids);

PHP_METHOD(Sqids_Sqids, __construct);
PHP_METHOD(Sqids_Sqids, encode);
PHP_METHOD(Sqids_Sqids, encodeNumbers);
PHP_METHOD(Sqids_Sqids, decode);
PHP_METHOD(Sqids_Sqids, shuffle);
PHP_METHOD(Sqids_Sqids, toId);
PHP_METHOD(Sqids_Sqids, toNumber);
PHP_METHOD(Sqids_Sqids, isBlockedId);
PHP_METHOD(Sqids_Sqids, getMathExtension);

ZEND_BEGIN_ARG_INFO_EX(arginfo_sqids_sqids___construct, 0, 0, 0)
	ZEND_ARG_TYPE_INFO(0, alphabet, IS_STRING, 1)
	ZEND_ARG_TYPE_INFO(0, minLength, IS_LONG, 0)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, blocklist, IS_ARRAY, 1, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sqids_sqids_encode, 0, 1, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, numbers, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sqids_sqids_encodenumbers, 0, 1, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, numbers, 0)
	ZEND_ARG_TYPE_INFO(0, increment, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sqids_sqids_decode, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, id, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sqids_sqids_shuffle, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, alphabet, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sqids_sqids_toid, 0, 2, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, num, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, alphabet, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sqids_sqids_tonumber, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, id, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, alphabet, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sqids_sqids_isblockedid, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, id, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_sqids_sqids_getmathextension, 0, 0, Sqids\\Math\\MathInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(sqids_sqids_method_entry) {
	PHP_ME(Sqids_Sqids, __construct, arginfo_sqids_sqids___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Sqids_Sqids, encode, arginfo_sqids_sqids_encode, ZEND_ACC_PUBLIC)
	PHP_ME(Sqids_Sqids, encodeNumbers, arginfo_sqids_sqids_encodenumbers, ZEND_ACC_PROTECTED)
	PHP_ME(Sqids_Sqids, decode, arginfo_sqids_sqids_decode, ZEND_ACC_PUBLIC)
	PHP_ME(Sqids_Sqids, shuffle, arginfo_sqids_sqids_shuffle, ZEND_ACC_PROTECTED)
	PHP_ME(Sqids_Sqids, toId, arginfo_sqids_sqids_toid, ZEND_ACC_PROTECTED)
	PHP_ME(Sqids_Sqids, toNumber, arginfo_sqids_sqids_tonumber, ZEND_ACC_PROTECTED)
	PHP_ME(Sqids_Sqids, isBlockedId, arginfo_sqids_sqids_isblockedid, ZEND_ACC_PROTECTED)
	PHP_ME(Sqids_Sqids, getMathExtension, arginfo_sqids_sqids_getmathextension, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
