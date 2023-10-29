
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
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/string.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/concat.h"


/**
 * Copyright (c) Sqids maintainers.
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 *
 * @see https://github.com/sqids/sqids-php
 */
ZEPHIR_INIT_CLASS(Sqids_Sqids)
{
	ZEPHIR_REGISTER_CLASS(Sqids, Sqids, sqids, sqids, sqids_sqids_method_entry, 0);

	zend_declare_property_null(sqids_sqids_ce, SL("math"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(sqids_sqids_ce, SL("alphabet"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(sqids_sqids_ce, SL("minLength"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(sqids_sqids_ce, SL("blocklist"), ZEND_ACC_PROTECTED);
	zephir_declare_class_constant_string(sqids_sqids_ce, SL("DEFAULT_ALPHABET"), "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789");

	zend_class_implements(sqids_sqids_ce, 1, sqids_sqidsinterface_ce);
	return SUCCESS;
}

PHP_METHOD(Sqids_Sqids, __construct)
{
	zend_bool _2, _9, _10;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL, *_17 = NULL;
	zval blocklist;
	zend_long minLength, ZEPHIR_LAST_CALL_STATUS;
	zval *alphabet_param = NULL, *minLength_param = NULL, *blocklist_param = NULL, minLengthLimit, filteredBlocklist, alphabetChars, word, wordLowercased, wordChars, intersection, _3, _4, _5, _7, _8, _13, *_14, _15, _21, _22, _0$$3, _1$$3, _11$$8, _12$$8, _16$$10, _18$$11, _19$$13, _20$$14;
	zval alphabet;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&alphabet);
	ZVAL_UNDEF(&minLengthLimit);
	ZVAL_UNDEF(&filteredBlocklist);
	ZVAL_UNDEF(&alphabetChars);
	ZVAL_UNDEF(&word);
	ZVAL_UNDEF(&wordLowercased);
	ZVAL_UNDEF(&wordChars);
	ZVAL_UNDEF(&intersection);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_16$$10);
	ZVAL_UNDEF(&_18$$11);
	ZVAL_UNDEF(&_19$$13);
	ZVAL_UNDEF(&_20$$14);
	ZVAL_UNDEF(&blocklist);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 3)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(alphabet)
		Z_PARAM_LONG(minLength)
		Z_PARAM_ARRAY_OR_NULL(blocklist)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &alphabet_param, &minLength_param, &blocklist_param);
	if (!alphabet_param) {
		ZEPHIR_INIT_VAR(&alphabet);
	} else {
		zephir_get_strval(&alphabet, alphabet_param);
	}
	if (!minLength_param) {
		minLength = 0;
	} else {
		minLength = zephir_get_intval(minLength_param);
	}
	if (!blocklist_param) {
		ZEPHIR_INIT_VAR(&blocklist);
	} else {
		zephir_get_arrval(&blocklist, blocklist_param);
	}


	if (ZEPHIR_IS_NULL(&blocklist)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_create_array(&_0$$3, 563, 0);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "0rgasm");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "1d10t");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "1d1ot");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "1di0t");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "1diot");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "1eccacu10");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "1eccacu1o");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "1eccacul0");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "1eccaculo");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "1mbec11e");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "1mbec1le");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "1mbeci1e");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "1mbecile");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "a11upat0");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "a11upato");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "a1lupat0");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "a1lupato");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "aand");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "ah01e");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "ah0le");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "aho1e");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "ahole");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "al1upat0");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "al1upato");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "allupat0");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "allupato");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "ana1");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "ana1e");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "anal");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "anale");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "anus");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "arrapat0");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "arrapato");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "arsch");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "arse");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "ass");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "b00b");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "b00be");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "b01ata");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "b0ceta");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "b0iata");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "b0ob");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "b0obe");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "b0sta");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "b1tch");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "b1te");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "b1tte");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "ba1atkar");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "balatkar");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "bastard0");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "bastardo");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "batt0na");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "battona");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "bitch");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "bite");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "bitte");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "bo0b");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "bo0be");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "bo1ata");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "boceta");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "boiata");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "boob");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "boobe");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "bosta");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "bran1age");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "bran1er");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "bran1ette");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "bran1eur");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "bran1euse");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "branlage");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "branler");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "branlette");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "branleur");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "branleuse");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "c0ck");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "c0g110ne");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "c0g11one");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "c0g1i0ne");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "c0g1ione");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "c0gl10ne");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "c0gl1one");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "c0gli0ne");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "c0glione");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "c0na");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "c0nnard");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "c0nnasse");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "c0nne");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "c0u111es");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "c0u11les");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "c0u1l1es");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "c0u1lles");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "c0ui11es");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "c0ui1les");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "c0uil1es");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "c0uilles");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "c11t");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "c11t0");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "c11to");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "c1it");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "c1it0");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "c1ito");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "cabr0n");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "cabra0");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "cabrao");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "cabron");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "caca");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "cacca");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "cacete");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "cagante");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "cagar");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "cagare");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "cagna");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "cara1h0");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "cara1ho");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "caracu10");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "caracu1o");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "caracul0");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "caraculo");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "caralh0");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "caralho");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "cazz0");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "cazz1mma");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "cazzata");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "cazzimma");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "cazzo");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "ch00t1a");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "ch00t1ya");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "ch00tia");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "ch00tiya");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "ch0d");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "ch0ot1a");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "ch0ot1ya");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "ch0otia");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "ch0otiya");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "ch1asse");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "ch1avata");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "ch1er");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "ch1ng0");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "ch1ngadaz0s");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "ch1ngadazos");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "ch1ngader1ta");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "ch1ngaderita");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "ch1ngar");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "ch1ngo");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "ch1ngues");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "ch1nk");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "chatte");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "chiasse");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "chiavata");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "chier");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "ching0");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "chingadaz0s");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "chingadazos");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "chingader1ta");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "chingaderita");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "chingar");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "chingo");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "chingues");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "chink");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "cho0t1a");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "cho0t1ya");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "cho0tia");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "cho0tiya");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "chod");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "choot1a");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "choot1ya");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "chootia");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "chootiya");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "cl1t");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "cl1t0");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "cl1to");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "clit");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "clit0");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "clito");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "cock");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "cog110ne");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "cog11one");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "cog1i0ne");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "cog1ione");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "cogl10ne");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "cogl1one");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "cogli0ne");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "coglione");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "cona");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "connard");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "connasse");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "conne");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "cou111es");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "cou11les");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "cou1l1es");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "cou1lles");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "coui11es");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "coui1les");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "couil1es");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "couilles");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "cracker");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "crap");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "cu10");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "cu1att0ne");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "cu1attone");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "cu1er0");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "cu1ero");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "cu1o");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "cul0");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "culatt0ne");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "culattone");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "culer0");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "culero");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "culo");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "cum");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "cunt");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "d11d0");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "d11do");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "d1ck");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "d1ld0");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "d1ldo");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "damn");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "de1ch");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "deich");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "depp");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "di1d0");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "di1do");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "dick");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "dild0");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "dildo");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "dyke");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "encu1e");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "encule");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "enema");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "enf01re");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "enf0ire");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "enfo1re");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "enfoire");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "estup1d0");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "estup1do");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "estupid0");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "estupido");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "etr0n");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "etron");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "f0da");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "f0der");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "f0ttere");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "f0tters1");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "f0ttersi");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "f0tze");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "f0utre");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "f1ca");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "f1cker");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "f1ga");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "fag");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "fica");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "ficker");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "figa");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "foda");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "foder");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "fottere");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "fotters1");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "fottersi");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "fotze");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "foutre");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "fr0c10");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "fr0c1o");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "fr0ci0");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "fr0cio");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "fr0sc10");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "fr0sc1o");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "fr0sci0");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "fr0scio");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "froc10");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "froc1o");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "froci0");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "frocio");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "frosc10");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "frosc1o");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "frosci0");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "froscio");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "fuck");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "g00");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "g0o");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "g0u1ne");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "g0uine");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "gandu");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "go0");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "goo");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "gou1ne");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "gouine");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "gr0gnasse");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "grognasse");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "haram1");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "harami");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "haramzade");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "hund1n");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "hundin");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "id10t");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "id1ot");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "idi0t");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "idiot");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "imbec11e");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "imbec1le");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "imbeci1e");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "imbecile");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "j1zz");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "jerk");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "jizz");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "k1ke");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "kam1ne");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "kamine");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "kike");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "leccacu10");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "leccacu1o");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "leccacul0");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "leccaculo");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "m1erda");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "m1gn0tta");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "m1gnotta");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "m1nch1a");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "m1nchia");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "m1st");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "mam0n");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "mamahuev0");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "mamahuevo");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "mamon");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "masturbat10n");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "masturbat1on");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "masturbate");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "masturbati0n");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "masturbation");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "merd0s0");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "merd0so");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "merda");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "merde");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "merdos0");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "merdoso");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "mierda");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "mign0tta");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "mignotta");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "minch1a");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "minchia");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "mist");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "musch1");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "muschi");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "n1gger");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "neger");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "negr0");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "negre");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "negro");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "nerch1a");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "nerchia");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "nigger");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "orgasm");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "p00p");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "p011a");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "p01la");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "p0l1a");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "p0lla");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "p0mp1n0");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "p0mp1no");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "p0mpin0");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "p0mpino");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "p0op");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "p0rca");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "p0rn");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "p0rra");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "p0uff1asse");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "p0uffiasse");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "p1p1");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "p1pi");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "p1r1a");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "p1rla");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "p1sc10");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "p1sc1o");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "p1sci0");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "p1scio");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "p1sser");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "pa11e");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "pa1le");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "pal1e");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "palle");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "pane1e1r0");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "pane1e1ro");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "pane1eir0");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "pane1eiro");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "panele1r0");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "panele1ro");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "paneleir0");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "paneleiro");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "patakha");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "pec0r1na");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "pec0rina");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "pecor1na");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "pecorina");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "pen1s");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "pendej0");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "pendejo");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "penis");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "pip1");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "pipi");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "pir1a");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "pirla");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "pisc10");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "pisc1o");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "pisci0");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "piscio");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "pisser");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "po0p");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "po11a");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "po1la");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "pol1a");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "polla");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "pomp1n0");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "pomp1no");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "pompin0");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "pompino");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "poop");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "porca");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "porn");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "porra");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "pouff1asse");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "pouffiasse");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "pr1ck");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "prick");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "pussy");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "put1za");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "puta");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "puta1n");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "putain");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "pute");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "putiza");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "puttana");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "queca");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "r0mp1ba11e");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "r0mp1ba1le");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "r0mp1bal1e");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "r0mp1balle");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "r0mpiba11e");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "r0mpiba1le");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "r0mpibal1e");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "r0mpiballe");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "rand1");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "randi");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "rape");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "recch10ne");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "recch1one");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "recchi0ne");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "recchione");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "retard");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "romp1ba11e");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "romp1ba1le");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "romp1bal1e");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "romp1balle");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "rompiba11e");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "rompiba1le");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "rompibal1e");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "rompiballe");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "ruff1an0");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "ruff1ano");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "ruffian0");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "ruffiano");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "s1ut");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "sa10pe");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "sa1aud");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "sa1ope");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "sacanagem");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "sal0pe");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "salaud");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "salope");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "saugnapf");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "sb0rr0ne");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "sb0rra");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "sb0rrone");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "sbattere");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "sbatters1");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "sbattersi");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "sborr0ne");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "sborra");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "sborrone");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "sc0pare");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "sc0pata");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "sch1ampe");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "sche1se");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "sche1sse");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "scheise");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "scheisse");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "schlampe");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "schwachs1nn1g");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "schwachs1nnig");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "schwachsinn1g");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "schwachsinnig");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "schwanz");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "scopare");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "scopata");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "sexy");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "sh1t");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "shit");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "slut");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "sp0mp1nare");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "sp0mpinare");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "spomp1nare");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "spompinare");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "str0nz0");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "str0nza");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "str0nzo");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "stronz0");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "stronza");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "stronzo");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "stup1d");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "stupid");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "succh1am1");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "succh1ami");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "succhiam1");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "succhiami");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "sucker");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "t0pa");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "tapette");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "test1c1e");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "test1cle");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "testic1e");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "testicle");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "tette");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "topa");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "tr01a");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "tr0ia");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "tr0mbare");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "tr1ng1er");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "tr1ngler");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "tring1er");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "tringler");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "tro1a");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "troia");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "trombare");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "turd");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "twat");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "vaffancu10");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "vaffancu1o");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "vaffancul0");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "vaffanculo");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "vag1na");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "vagina");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "verdammt");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "verga");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "w1chsen");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "wank");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "wichsen");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "x0ch0ta");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "x0chota");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "xana");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "xoch0ta");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "xochota");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "z0cc01a");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "z0cc0la");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "z0cco1a");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "z0ccola");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "z1z1");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "z1zi");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "ziz1");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "zizi");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "zocc01a");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "zocc0la");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "zocco1a");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "zoccola");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_CPY_WRT(&blocklist, &_0$$3);
	}
	_2 = ZEPHIR_IS_NULL(&alphabet);
	if (!(_2)) {
		_2 = ZEPHIR_IS_STRING(&alphabet, "");
	}
	if (_2) {
		ZEPHIR_INIT_NVAR(&alphabet);
		ZVAL_STRING(&alphabet, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789");
	}
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getmathextension", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("math"), &_3);
	ZEPHIR_CALL_FUNCTION(&_4, "mb_strlen", NULL, 14, &alphabet);
	zephir_check_call_status();
	if (!ZEPHIR_IS_LONG(&_4, zephir_fast_strlen_ev(&alphabet))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Alphabet cannot contain multibyte characters", "sqids/Sqids.zep", 43);
		return;
	}
	if (zephir_fast_strlen_ev(&alphabet) < 3) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Alphabet length must be at least 3", "sqids/Sqids.zep", 47);
		return;
	}
	ZEPHIR_CALL_FUNCTION(&_5, "str_split", &_6, 15, &alphabet);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_7, "array_unique", NULL, 16, &_5);
	zephir_check_call_status();
	if (zephir_fast_count_int(&_7) != zephir_fast_strlen_ev(&alphabet)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Alphabet must contain unique characters", "sqids/Sqids.zep", 51);
		return;
	}
	ZEPHIR_INIT_VAR(&minLengthLimit);
	ZVAL_LONG(&minLengthLimit, 255);
	ZVAL_LONG(&_8, minLength);
	_9 = !(Z_TYPE_P(&_8) == IS_LONG);
	if (!(_9)) {
		_9 = minLength < 0;
	}
	_10 = _9;
	if (!(_10)) {
		_10 = ZEPHIR_LT_LONG(&minLengthLimit, minLength);
	}
	if (_10) {
		ZEPHIR_INIT_VAR(&_11$$8);
		object_init_ex(&_11$$8, spl_ce_InvalidArgumentException);
		ZEPHIR_INIT_VAR(&_12$$8);
		ZEPHIR_CONCAT_SV(&_12$$8, "Minimum length has to be between 0 and ", &minLengthLimit);
		ZEPHIR_CALL_METHOD(NULL, &_11$$8, "__construct", NULL, 17, &_12$$8);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_11$$8, "sqids/Sqids.zep", 56);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&filteredBlocklist);
	array_init(&filteredBlocklist);
	ZEPHIR_INIT_VAR(&_13);
	zephir_fast_strtolower(&_13, &alphabet);
	ZEPHIR_CALL_FUNCTION(&alphabetChars, "str_split", &_6, 15, &_13);
	zephir_check_call_status();
	zephir_is_iterable(&blocklist, 0, "sqids/Sqids.zep", 76);
	if (Z_TYPE_P(&blocklist) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&blocklist), _14)
		{
			ZEPHIR_INIT_NVAR(&word);
			ZVAL_COPY(&word, _14);
			if (zephir_fast_strlen_ev(&word) >= 3) {
				ZEPHIR_INIT_NVAR(&wordLowercased);
				zephir_fast_strtolower(&wordLowercased, &word);
				ZEPHIR_CALL_FUNCTION(&wordChars, "str_split", &_6, 15, &wordLowercased);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_16$$10);
				ZEPHIR_INIT_NVAR(&_16$$10);
				zephir_create_closure_ex(&_16$$10, NULL, sqids_0__closure_ce, SL("__invoke"));
				zephir_update_static_property_ce(sqids_0__closure_ce, ZEND_STRL("alphabetChars"), &alphabetChars);
				ZEPHIR_CALL_FUNCTION(&intersection, "array_filter", &_17, 18, &wordChars, &_16$$10);
				zephir_check_call_status();
				if (zephir_fast_count_int(&intersection) == zephir_fast_count_int(&wordChars)) {
					ZEPHIR_INIT_NVAR(&_18$$11);
					zephir_fast_strtolower(&_18$$11, &wordLowercased);
					zephir_array_append(&filteredBlocklist, &_18$$11, PH_SEPARATE, "sqids/Sqids.zep", 71);
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &blocklist, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_15, &blocklist, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_15)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&word, &blocklist, "current", NULL, 0);
			zephir_check_call_status();
				if (zephir_fast_strlen_ev(&word) >= 3) {
					ZEPHIR_INIT_NVAR(&wordLowercased);
					zephir_fast_strtolower(&wordLowercased, &word);
					ZEPHIR_CALL_FUNCTION(&wordChars, "str_split", &_6, 15, &wordLowercased);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_19$$13);
					ZEPHIR_INIT_NVAR(&_19$$13);
					zephir_create_closure_ex(&_19$$13, NULL, sqids_1__closure_ce, SL("__invoke"));
					zephir_update_static_property_ce(sqids_1__closure_ce, ZEND_STRL("alphabetChars"), &alphabetChars);
					ZEPHIR_CALL_FUNCTION(&intersection, "array_filter", &_17, 18, &wordChars, &_19$$13);
					zephir_check_call_status();
					if (zephir_fast_count_int(&intersection) == zephir_fast_count_int(&wordChars)) {
						ZEPHIR_INIT_NVAR(&_20$$14);
						zephir_fast_strtolower(&_20$$14, &wordLowercased);
						zephir_array_append(&filteredBlocklist, &_20$$14, PH_SEPARATE, "sqids/Sqids.zep", 71);
					}
				}
			ZEPHIR_CALL_METHOD(NULL, &blocklist, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&word);
	ZEPHIR_CALL_METHOD(&_21, this_ptr, "shuffle", NULL, 0, &alphabet);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("alphabet"), &_21);
	ZEPHIR_INIT_ZVAL_NREF(_22);
	ZVAL_LONG(&_22, minLength);
	zephir_update_property_zval(this_ptr, ZEND_STRL("minLength"), &_22);
	zephir_update_property_zval(this_ptr, ZEND_STRL("blocklist"), &filteredBlocklist);
	ZEPHIR_MM_RESTORE();
}

/**
 * Encodes an array of unsigned integers into an ID
 *
 * These are the cases where encoding might fail:
 * - One of the numbers passed is smaller than 0 or greater than `maxValue()`
 * - An n-number of attempts has been made to re-generated the ID, where n is alphabet length + 1
 *
 * @param array<int> $numbers Non-negative integers to encode into an ID
 * @return string Generated ID
 */
PHP_METHOD(Sqids_Sqids, encode)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *numbers_param = NULL, inRangeNumbers, _0, _1$$4, _2$$4, _3$$4;
	zval numbers;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&numbers);
	ZVAL_UNDEF(&inRangeNumbers);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(numbers)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &numbers_param);
	zephir_get_arrval(&numbers, numbers_param);


	if (zephir_fast_count_int(&numbers) == 0) {
		RETURN_MM_STRING("");
	}
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, sqids_2__closure_ce, SL("__invoke"));
	ZEPHIR_CALL_FUNCTION(&inRangeNumbers, "array_filter", NULL, 18, &numbers, &_0);
	zephir_check_call_status();
	if (zephir_fast_count_int(&inRangeNumbers) != zephir_fast_count_int(&numbers)) {
		ZEPHIR_INIT_VAR(&_1$$4);
		object_init_ex(&_1$$4, spl_ce_InvalidArgumentException);
		ZEPHIR_INIT_VAR(&_2$$4);
		ZEPHIR_GET_CONSTANT(&_2$$4, "PHP_INT_MAX");
		ZEPHIR_INIT_VAR(&_3$$4);
		ZEPHIR_CONCAT_SV(&_3$$4, "Encoding supports numbers between 0 and ", &_2$$4);
		ZEPHIR_CALL_METHOD(NULL, &_1$$4, "__construct", NULL, 17, &_3$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$4, "sqids/Sqids.zep", 103);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "encodenumbers", NULL, 0, &numbers);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Internal function that encodes an array of unsigned integers into an ID
 *
 * @param array<int> $numbers Non-negative integers to encode into an ID
 * @param int $increment An internal number used to modify the `offset` variable in order to re-generate the ID
 * @return string Generated ID
 */
PHP_METHOD(Sqids_Sqids, encodeNumbers)
{
	double _19, _21;
	zend_string *_4, *_33;
	zend_ulong _3, _32;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_10 = NULL, *_37 = NULL, *_42 = NULL, *_59 = NULL;
	zend_long increment, ZEPHIR_LAST_CALL_STATUS;
	zval *numbers_param = NULL, *increment_param = NULL, offset, prefix, ret, id, alphabet, i, v, z, num, numbersCount, _0, *_1, _2, _18, _20, _22, _23, _24, _25, _26, _27, _28, _29, *_30, _31, _50, _5$$4, _6$$4, _7$$4, _8$$4, _9$$4, _11$$4, _12$$5, _13$$5, _14$$5, _15$$5, _16$$5, _17$$5, _34$$6, _35$$6, _36$$6, _38$$7, _39$$7, _40$$7, _41$$7, _43$$8, _44$$8, _45$$8, _46$$9, _47$$9, _48$$9, _49$$9, _51$$10, _52$$10, _53$$10, _54$$10, _55$$11, _56$$11, _57$$11, _58$$11, _60$$11, _61$$12;
	zval numbers;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&numbers);
	ZVAL_UNDEF(&offset);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&ret);
	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&alphabet);
	ZVAL_UNDEF(&i);
	ZVAL_UNDEF(&v);
	ZVAL_UNDEF(&z);
	ZVAL_UNDEF(&num);
	ZVAL_UNDEF(&numbersCount);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_25);
	ZVAL_UNDEF(&_26);
	ZVAL_UNDEF(&_27);
	ZVAL_UNDEF(&_28);
	ZVAL_UNDEF(&_29);
	ZVAL_UNDEF(&_31);
	ZVAL_UNDEF(&_50);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&_17$$5);
	ZVAL_UNDEF(&_34$$6);
	ZVAL_UNDEF(&_35$$6);
	ZVAL_UNDEF(&_36$$6);
	ZVAL_UNDEF(&_38$$7);
	ZVAL_UNDEF(&_39$$7);
	ZVAL_UNDEF(&_40$$7);
	ZVAL_UNDEF(&_41$$7);
	ZVAL_UNDEF(&_43$$8);
	ZVAL_UNDEF(&_44$$8);
	ZVAL_UNDEF(&_45$$8);
	ZVAL_UNDEF(&_46$$9);
	ZVAL_UNDEF(&_47$$9);
	ZVAL_UNDEF(&_48$$9);
	ZVAL_UNDEF(&_49$$9);
	ZVAL_UNDEF(&_51$$10);
	ZVAL_UNDEF(&_52$$10);
	ZVAL_UNDEF(&_53$$10);
	ZVAL_UNDEF(&_54$$10);
	ZVAL_UNDEF(&_55$$11);
	ZVAL_UNDEF(&_56$$11);
	ZVAL_UNDEF(&_57$$11);
	ZVAL_UNDEF(&_58$$11);
	ZVAL_UNDEF(&_60$$11);
	ZVAL_UNDEF(&_61$$12);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ARRAY(numbers)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(increment)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &numbers_param, &increment_param);
	zephir_get_arrval(&numbers, numbers_param);
	if (!increment_param) {
		increment = 0;
	} else {
		increment = zephir_get_intval(increment_param);
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("alphabet"), PH_NOISY_CC | PH_READONLY);
	if (increment > zephir_fast_strlen_ev(&_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Reached max attempts to re-generate the ID", "sqids/Sqids.zep", 121);
		return;
	}
	ZEPHIR_INIT_VAR(&offset);
	ZVAL_LONG(&offset, zephir_fast_count_int(&numbers));
	zephir_is_iterable(&numbers, 0, "sqids/Sqids.zep", 129);
	if (Z_TYPE_P(&numbers) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&numbers), _3, _4, _1)
		{
			ZEPHIR_INIT_NVAR(&i);
			if (_4 != NULL) { 
				ZVAL_STR_COPY(&i, _4);
			} else {
				ZVAL_LONG(&i, _3);
			}
			ZEPHIR_INIT_NVAR(&v);
			ZVAL_COPY(&v, _1);
			zephir_read_property(&_5$$4, this_ptr, ZEND_STRL("alphabet"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_NVAR(&z);
			ZVAL_LONG(&z, (int) (zephir_safe_mod_zval_long(&v, zephir_fast_strlen_ev(&_5$$4))));
			zephir_read_property(&_6$$4, this_ptr, ZEND_STRL("alphabet"), PH_NOISY_CC | PH_READONLY);
			ZVAL_LONG(&_7$$4, 1);
			ZEPHIR_INIT_NVAR(&_8$$4);
			zephir_substr(&_8$$4, &_6$$4, zephir_get_intval(&z), 1 , 0);
			ZEPHIR_CALL_FUNCTION(&_9$$4, "ord", &_10, 19, &_8$$4);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_11$$4);
			zephir_add_function(&_11$$4, &_9$$4, &i);
			ZEPHIR_ADD_ASSIGN(&offset, &_11$$4);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &numbers, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &numbers, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&i, &numbers, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&v, &numbers, "current", NULL, 0);
			zephir_check_call_status();
				zephir_read_property(&_12$$5, this_ptr, ZEND_STRL("alphabet"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_NVAR(&z);
				ZVAL_LONG(&z, (int) (zephir_safe_mod_zval_long(&v, zephir_fast_strlen_ev(&_12$$5))));
				zephir_read_property(&_13$$5, this_ptr, ZEND_STRL("alphabet"), PH_NOISY_CC | PH_READONLY);
				ZVAL_LONG(&_14$$5, 1);
				ZEPHIR_INIT_NVAR(&_15$$5);
				zephir_substr(&_15$$5, &_13$$5, zephir_get_intval(&z), 1 , 0);
				ZEPHIR_CALL_FUNCTION(&_16$$5, "ord", &_10, 19, &_15$$5);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_17$$5);
				zephir_add_function(&_17$$5, &_16$$5, &i);
				ZEPHIR_ADD_ASSIGN(&offset, &_17$$5);
			ZEPHIR_CALL_METHOD(NULL, &numbers, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&v);
	ZEPHIR_INIT_NVAR(&i);
	zephir_read_property(&_18, this_ptr, ZEND_STRL("alphabet"), PH_NOISY_CC | PH_READONLY);
	_19 = zephir_safe_mod_zval_long(&offset, zephir_fast_strlen_ev(&_18));
	ZEPHIR_INIT_NVAR(&offset);
	ZVAL_DOUBLE(&offset, _19);
	zephir_read_property(&_20, this_ptr, ZEND_STRL("alphabet"), PH_NOISY_CC | PH_READONLY);
	_21 = zephir_safe_mod_long_long(((zephir_get_numberval(&offset) + increment)), zephir_fast_strlen_ev(&_20));
	ZEPHIR_INIT_NVAR(&offset);
	ZVAL_DOUBLE(&offset, _21);
	zephir_read_property(&_22, this_ptr, ZEND_STRL("alphabet"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_23);
	zephir_substr(&_23, &_22, zephir_get_intval(&offset), 0, ZEPHIR_SUBSTR_NO_LENGTH);
	zephir_read_property(&_24, this_ptr, ZEND_STRL("alphabet"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_25, 0);
	ZEPHIR_INIT_VAR(&_26);
	zephir_substr(&_26, &_24, 0 , zephir_get_intval(&offset), 0);
	ZEPHIR_INIT_VAR(&alphabet);
	ZEPHIR_CONCAT_VV(&alphabet, &_23, &_26);
	ZVAL_LONG(&_27, 0);
	ZVAL_LONG(&_28, 1);
	ZEPHIR_INIT_VAR(&prefix);
	zephir_substr(&prefix, &alphabet, 0 , 1 , 0);
	ZEPHIR_CALL_FUNCTION(&_29, "strrev", NULL, 20, &alphabet);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&alphabet, &_29);
	ZEPHIR_INIT_VAR(&ret);
	zephir_create_array(&ret, 1, 0);
	zephir_array_fast_append(&ret, &prefix);
	ZEPHIR_INIT_VAR(&numbersCount);
	ZVAL_LONG(&numbersCount, zephir_fast_count_int(&numbers));
	zephir_is_iterable(&numbers, 0, "sqids/Sqids.zep", 145);
	if (Z_TYPE_P(&numbers) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&numbers), _32, _33, _30)
		{
			ZEPHIR_INIT_NVAR(&i);
			if (_33 != NULL) { 
				ZVAL_STR_COPY(&i, _33);
			} else {
				ZVAL_LONG(&i, _32);
			}
			ZEPHIR_INIT_NVAR(&num);
			ZVAL_COPY(&num, _30);
			ZVAL_LONG(&_35$$6, 1);
			ZEPHIR_INIT_NVAR(&_36$$6);
			zephir_substr(&_36$$6, &alphabet, 1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
			ZEPHIR_CALL_METHOD(&_34$$6, this_ptr, "toid", &_37, 0, &num, &_36$$6);
			zephir_check_call_status();
			zephir_array_append(&ret, &_34$$6, PH_SEPARATE, "sqids/Sqids.zep", 138);
			if (ZEPHIR_LT_LONG(&i, (zephir_get_numberval(&numbersCount) - 1))) {
				ZVAL_LONG(&_38$$7, 0);
				ZVAL_LONG(&_39$$7, 1);
				ZEPHIR_INIT_NVAR(&_40$$7);
				zephir_substr(&_40$$7, &alphabet, 0 , 1 , 0);
				zephir_array_append(&ret, &_40$$7, PH_SEPARATE, "sqids/Sqids.zep", 140);
				ZEPHIR_CALL_METHOD(&_41$$7, this_ptr, "shuffle", &_42, 0, &alphabet);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&alphabet, &_41$$7);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &numbers, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_31, &numbers, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_31)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&i, &numbers, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&num, &numbers, "current", NULL, 0);
			zephir_check_call_status();
				ZVAL_LONG(&_44$$8, 1);
				ZEPHIR_INIT_NVAR(&_45$$8);
				zephir_substr(&_45$$8, &alphabet, 1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
				ZEPHIR_CALL_METHOD(&_43$$8, this_ptr, "toid", &_37, 0, &num, &_45$$8);
				zephir_check_call_status();
				zephir_array_append(&ret, &_43$$8, PH_SEPARATE, "sqids/Sqids.zep", 138);
				if (ZEPHIR_LT_LONG(&i, (zephir_get_numberval(&numbersCount) - 1))) {
					ZVAL_LONG(&_46$$9, 0);
					ZVAL_LONG(&_47$$9, 1);
					ZEPHIR_INIT_NVAR(&_48$$9);
					zephir_substr(&_48$$9, &alphabet, 0 , 1 , 0);
					zephir_array_append(&ret, &_48$$9, PH_SEPARATE, "sqids/Sqids.zep", 140);
					ZEPHIR_CALL_METHOD(&_49$$9, this_ptr, "shuffle", &_42, 0, &alphabet);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&alphabet, &_49$$9);
				}
			ZEPHIR_CALL_METHOD(NULL, &numbers, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&num);
	ZEPHIR_INIT_NVAR(&i);
	ZEPHIR_INIT_VAR(&id);
	zephir_fast_join_str(&id, SL(""), &ret);
	zephir_read_property(&_50, this_ptr, ZEND_STRL("minLength"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_GT_LONG(&_50, zephir_fast_strlen_ev(&id))) {
		ZVAL_LONG(&_51$$10, 0);
		ZVAL_LONG(&_52$$10, 1);
		ZEPHIR_INIT_VAR(&_53$$10);
		zephir_substr(&_53$$10, &alphabet, 0 , 1 , 0);
		zephir_concat_self(&id, &_53$$10);
		while (1) {
			zephir_read_property(&_54$$10, this_ptr, ZEND_STRL("minLength"), PH_NOISY_CC | PH_READONLY);
			if (!((zephir_get_numberval(&_54$$10) - zephir_fast_strlen_ev(&id)) > 0)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&_55$$11, this_ptr, "shuffle", &_42, 0, &alphabet);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&alphabet, &_55$$11);
			zephir_read_property(&_56$$11, this_ptr, ZEND_STRL("minLength"), PH_NOISY_CC | PH_READONLY);
			ZVAL_LONG(&_57$$11, (zephir_get_numberval(&_56$$11) - zephir_fast_strlen_ev(&id)));
			ZVAL_LONG(&_58$$11, zephir_fast_strlen_ev(&alphabet));
			ZEPHIR_CALL_FUNCTION(&_55$$11, "min", &_59, 21, &_57$$11, &_58$$11);
			zephir_check_call_status();
			ZVAL_LONG(&_57$$11, 0);
			ZEPHIR_INIT_NVAR(&_60$$11);
			zephir_substr(&_60$$11, &alphabet, 0 , zephir_get_intval(&_55$$11), 0);
			zephir_concat_self(&id, &_60$$11);
		}
	}
	ZEPHIR_CALL_METHOD(&_29, this_ptr, "isblockedid", NULL, 0, &id);
	zephir_check_call_status();
	if (zephir_is_true(&_29)) {
		ZVAL_LONG(&_61$$12, (increment + 1));
		ZEPHIR_CALL_METHOD(&id, this_ptr, "encodenumbers", NULL, 22, &numbers, &_61$$12);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&id);
}

/**
 * Decodes an ID back into an array of unsigned integers
 *
 * These are the cases where the return value might be an empty array:
 * - Empty ID / empty string
 * - Non-alphabet character is found within the ID
 *
 * @param string $id Encoded ID
 * @return array<int> Array of unsigned integers
 */
PHP_METHOD(Sqids_Sqids, decode)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_23 = NULL, *_25 = NULL;
	zval id, *id_param = NULL, alphabetChars, c, prefix, offset, alphabet, separator, chunks, ret, _0, _2, *_3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16$$8, _17$$8, _18$$9, _19$$9, _20$$9, _21$$9, _22$$9, _24$$11;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&alphabetChars);
	ZVAL_UNDEF(&c);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&offset);
	ZVAL_UNDEF(&alphabet);
	ZVAL_UNDEF(&separator);
	ZVAL_UNDEF(&chunks);
	ZVAL_UNDEF(&ret);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16$$8);
	ZVAL_UNDEF(&_17$$8);
	ZVAL_UNDEF(&_18$$9);
	ZVAL_UNDEF(&_19$$9);
	ZVAL_UNDEF(&_20$$9);
	ZVAL_UNDEF(&_21$$9);
	ZVAL_UNDEF(&_22$$9);
	ZVAL_UNDEF(&_24$$11);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(id)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id_param);
	zephir_get_strval(&id, id_param);


	ZEPHIR_INIT_VAR(&ret);
	array_init(&ret);
	if (ZEPHIR_IS_STRING(&id, "")) {
		RETURN_CCTOR(&ret);
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("alphabet"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&alphabetChars, "str_split", &_1, 15, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_2, "str_split", &_1, 15, &id);
	zephir_check_call_status();
	zephir_is_iterable(&_2, 0, "sqids/Sqids.zep", 187);
	if (Z_TYPE_P(&_2) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_2), _3)
		{
			ZEPHIR_INIT_NVAR(&c);
			ZVAL_COPY(&c, _3);
			if (!(zephir_fast_in_array(&c, &alphabetChars))) {
				RETURN_CCTOR(&ret);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_2, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_4, &_2, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_4)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&c, &_2, "current", NULL, 0);
			zephir_check_call_status();
				if (!(zephir_fast_in_array(&c, &alphabetChars))) {
					RETURN_CCTOR(&ret);
				}
			ZEPHIR_CALL_METHOD(NULL, &_2, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&c);
	ZVAL_LONG(&_5, 0);
	ZVAL_LONG(&_6, 1);
	ZEPHIR_INIT_VAR(&prefix);
	zephir_substr(&prefix, &id, 0 , 1 , 0);
	zephir_read_property(&_7, this_ptr, ZEND_STRL("alphabet"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&offset);
	zephir_fast_strpos(&offset, &_7, &prefix, 0 );
	zephir_read_property(&_8, this_ptr, ZEND_STRL("alphabet"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_9);
	zephir_substr(&_9, &_8, zephir_get_intval(&offset), 0, ZEPHIR_SUBSTR_NO_LENGTH);
	zephir_read_property(&_10, this_ptr, ZEND_STRL("alphabet"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_11, 0);
	ZEPHIR_INIT_VAR(&_12);
	zephir_substr(&_12, &_10, 0 , zephir_get_intval(&offset), 0);
	ZEPHIR_INIT_VAR(&alphabet);
	ZEPHIR_CONCAT_VV(&alphabet, &_9, &_12);
	ZEPHIR_CALL_FUNCTION(&_13, "strrev", NULL, 20, &alphabet);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&alphabet, &_13);
	ZVAL_LONG(&_14, 1);
	ZEPHIR_INIT_VAR(&_15);
	zephir_substr(&_15, &id, 1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
	ZEPHIR_CPY_WRT(&id, &_15);
	while (1) {
		if (!(zephir_fast_strlen_ev(&id) > 0)) {
			break;
		}
		ZVAL_LONG(&_16$$8, 0);
		ZVAL_LONG(&_17$$8, 1);
		ZEPHIR_INIT_NVAR(&separator);
		zephir_substr(&separator, &alphabet, 0 , 1 , 0);
		ZEPHIR_INIT_NVAR(&chunks);
		zephir_fast_explode(&chunks, &separator, &id, 2 );
		if (zephir_is_true(&chunks)) {
			zephir_array_fetch_long(&_18$$9, &chunks, 0, PH_NOISY | PH_READONLY, "sqids/Sqids.zep", 197);
			if (ZEPHIR_IS_STRING(&_18$$9, "")) {
				RETURN_CCTOR(&ret);
			}
			zephir_array_fetch_long(&_20$$9, &chunks, 0, PH_NOISY | PH_READONLY, "sqids/Sqids.zep", 200);
			ZVAL_LONG(&_21$$9, 1);
			ZEPHIR_INIT_NVAR(&_22$$9);
			zephir_substr(&_22$$9, &alphabet, 1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
			ZEPHIR_CALL_METHOD(&_19$$9, this_ptr, "tonumber", &_23, 0, &_20$$9, &_22$$9);
			zephir_check_call_status();
			zephir_array_append(&ret, &_19$$9, PH_SEPARATE, "sqids/Sqids.zep", 200);
			if (zephir_fast_count_int(&chunks) > 1) {
				ZEPHIR_CALL_METHOD(&_24$$11, this_ptr, "shuffle", &_25, 0, &alphabet);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&alphabet, &_24$$11);
			}
		}
		if (zephir_array_isset_long(&chunks, 1)) {
			ZEPHIR_OBS_NVAR(&id);
			zephir_array_fetch_long(&id, &chunks, 1, PH_NOISY, "sqids/Sqids.zep", 205);
		} else {
			ZEPHIR_INIT_NVAR(&id);
			ZVAL_STRING(&id, "");
		}
	}
	RETURN_CCTOR(&ret);
}

PHP_METHOD(Sqids_Sqids, shuffle)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *alphabet_param = NULL, i, j, r, temp, chars, numChars, indices, _0, _1, *_2, _3, _4$$3, _5$$3, _6$$3, _7$$3, _9$$3, _10$$3, _11$$3, _12$$3, _13$$5, _14$$5, _15$$5, _16$$5, _17$$5, _18$$5, _19$$5, _20$$5;
	zval alphabet;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&alphabet);
	ZVAL_UNDEF(&i);
	ZVAL_UNDEF(&j);
	ZVAL_UNDEF(&r);
	ZVAL_UNDEF(&temp);
	ZVAL_UNDEF(&chars);
	ZVAL_UNDEF(&numChars);
	ZVAL_UNDEF(&indices);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&_17$$5);
	ZVAL_UNDEF(&_18$$5);
	ZVAL_UNDEF(&_19$$5);
	ZVAL_UNDEF(&_20$$5);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(alphabet)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &alphabet_param);
	zephir_get_strval(&alphabet, alphabet_param);


	ZEPHIR_CALL_FUNCTION(&chars, "str_split", NULL, 15, &alphabet);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&numChars);
	ZVAL_LONG(&numChars, zephir_fast_strlen_ev(&alphabet));
	ZVAL_LONG(&_0, 0);
	ZVAL_LONG(&_1, (zephir_get_numberval(&numChars) - 1));
	ZEPHIR_CALL_FUNCTION(&indices, "range", NULL, 23, &_0, &_1);
	zephir_check_call_status();
	zephir_is_iterable(&indices, 0, "sqids/Sqids.zep", 230);
	if (Z_TYPE_P(&indices) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&indices), _2)
		{
			ZEPHIR_INIT_NVAR(&i);
			ZVAL_COPY(&i, _2);
			if (ZEPHIR_GE_LONG(&i, (zephir_get_numberval(&numChars) - 1))) {
				break;
			}
			ZEPHIR_OBS_NVAR(&j);
			ZEPHIR_INIT_NVAR(&_4$$3);
			zephir_sub_function(&_4$$3, &numChars, &i);
			zephir_array_fetch_long(&j, &indices, (zephir_get_numberval(&_4$$3) - 1), PH_NOISY, "sqids/Sqids.zep", 223);
			ZEPHIR_INIT_NVAR(&_5$$3);
			mul_function(&_5$$3, &i, &j);
			zephir_array_fetch(&_6$$3, &chars, &i, PH_NOISY | PH_READONLY, "sqids/Sqids.zep", 224);
			ZEPHIR_CALL_FUNCTION(&_7$$3, "ord", &_8, 19, &_6$$3);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_9$$3);
			zephir_add_function(&_9$$3, &_5$$3, &_7$$3);
			zephir_array_fetch(&_10$$3, &chars, &j, PH_NOISY | PH_READONLY, "sqids/Sqids.zep", 224);
			ZEPHIR_CALL_FUNCTION(&_7$$3, "ord", &_8, 19, &_10$$3);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_11$$3);
			zephir_add_function(&_11$$3, &_9$$3, &_7$$3);
			ZEPHIR_INIT_NVAR(&r);
			mod_function(&r, &_11$$3, &numChars);
			ZEPHIR_OBS_NVAR(&temp);
			zephir_array_fetch(&temp, &chars, &i, PH_NOISY, "sqids/Sqids.zep", 225);
			zephir_array_fetch(&_12$$3, &chars, &r, PH_NOISY | PH_READONLY, "sqids/Sqids.zep", 226);
			zephir_array_update_zval(&chars, &i, &_12$$3, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&chars, &r, &temp, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &indices, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_3, &indices, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&i, &indices, "current", NULL, 0);
			zephir_check_call_status();
				if (ZEPHIR_GE_LONG(&i, (zephir_get_numberval(&numChars) - 1))) {
					break;
				}
				ZEPHIR_OBS_NVAR(&j);
				ZEPHIR_INIT_NVAR(&_13$$5);
				zephir_sub_function(&_13$$5, &numChars, &i);
				zephir_array_fetch_long(&j, &indices, (zephir_get_numberval(&_13$$5) - 1), PH_NOISY, "sqids/Sqids.zep", 223);
				ZEPHIR_INIT_NVAR(&_14$$5);
				mul_function(&_14$$5, &i, &j);
				zephir_array_fetch(&_15$$5, &chars, &i, PH_NOISY | PH_READONLY, "sqids/Sqids.zep", 224);
				ZEPHIR_CALL_FUNCTION(&_16$$5, "ord", &_8, 19, &_15$$5);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_17$$5);
				zephir_add_function(&_17$$5, &_14$$5, &_16$$5);
				zephir_array_fetch(&_18$$5, &chars, &j, PH_NOISY | PH_READONLY, "sqids/Sqids.zep", 224);
				ZEPHIR_CALL_FUNCTION(&_16$$5, "ord", &_8, 19, &_18$$5);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_19$$5);
				zephir_add_function(&_19$$5, &_17$$5, &_16$$5);
				ZEPHIR_INIT_NVAR(&r);
				mod_function(&r, &_19$$5, &numChars);
				ZEPHIR_OBS_NVAR(&temp);
				zephir_array_fetch(&temp, &chars, &i, PH_NOISY, "sqids/Sqids.zep", 225);
				zephir_array_fetch(&_20$$5, &chars, &r, PH_NOISY | PH_READONLY, "sqids/Sqids.zep", 226);
				zephir_array_update_zval(&chars, &i, &_20$$5, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&chars, &r, &temp, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &indices, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&i);
	zephir_fast_join_str(return_value, SL(""), &chars);
	RETURN_MM();
}

PHP_METHOD(Sqids_Sqids, toId)
{
	zval idParts;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval alphabet;
	zval *num_param = NULL, *alphabet_param = NULL, chars, numberOfChars, result, index, _6, _7, _8, _9, _0$$3, _1$$3, _2$$3, _3$$3, _4$$3, _5$$3;
	zend_long num, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&chars);
	ZVAL_UNDEF(&numberOfChars);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&alphabet);
	ZVAL_UNDEF(&idParts);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(num)
		Z_PARAM_STR(alphabet)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &num_param, &alphabet_param);
	num = zephir_get_intval(num_param);
	zephir_get_strval(&alphabet, alphabet_param);


	ZEPHIR_CALL_FUNCTION(&chars, "str_split", NULL, 15, &alphabet);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&numberOfChars);
	ZVAL_LONG(&numberOfChars, zephir_fast_count_int(&chars));
	ZEPHIR_INIT_VAR(&result);
	ZVAL_LONG(&result, num);
	ZEPHIR_INIT_VAR(&idParts);
	array_init(&idParts);
	do {
		zephir_read_property(&_0$$3, this_ptr, ZEND_STRL("math"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("math"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_2$$3, &_1$$3, "mod", NULL, 0, &result, &numberOfChars);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&index, &_0$$3, "intval", NULL, 0, &_2$$3);
		zephir_check_call_status();
		zephir_array_fetch(&_3$$3, &chars, &index, PH_NOISY | PH_READONLY, "sqids/Sqids.zep", 247);
		zephir_array_append(&idParts, &_3$$3, PH_SEPARATE, "sqids/Sqids.zep", 247);
		zephir_read_property(&_4$$3, this_ptr, ZEND_STRL("math"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_5$$3, &_4$$3, "divide", NULL, 0, &result, &numberOfChars);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&result, &_5$$3);
		zephir_read_property(&_6, this_ptr, ZEND_STRL("math"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_8, 0);
		ZEPHIR_CALL_METHOD(&_7, &_6, "greaterthan", NULL, 0, &result, &_8);
		zephir_check_call_status();
	} while (zephir_is_true(&_7));
	ZEPHIR_CALL_FUNCTION(&_9, "array_reverse", NULL, 24, &idParts);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&idParts, &_9);
	zephir_fast_join_str(return_value, SL(""), &idParts);
	RETURN_MM();
}

PHP_METHOD(Sqids_Sqids, toNumber)
{
	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, _2, _3;
	zephir_fcall_cache_entry *_0 = NULL, *_7 = NULL;
	zval *id_param = NULL, *alphabet_param = NULL, chars, idArray, result, i, v, number, _8, _4$$3, _5$$3, _6$$3;
	zval id, alphabet;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&alphabet);
	ZVAL_UNDEF(&chars);
	ZVAL_UNDEF(&idArray);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&i);
	ZVAL_UNDEF(&v);
	ZVAL_UNDEF(&number);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(id)
		Z_PARAM_STR(alphabet)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &id_param, &alphabet_param);
	zephir_get_strval(&id, id_param);
	zephir_get_strval(&alphabet, alphabet_param);


	ZEPHIR_CALL_FUNCTION(&chars, "str_split", &_0, 15, &alphabet);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&idArray, "str_split", &_0, 15, &id);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&result);
	ZVAL_LONG(&result, 0);
	_3 = (zephir_fast_count_int(&idArray) - 1);
	_2 = 0;
	_1 = 0;
	if (_2 <= _3) {
		while (1) {
			if (_1) {
				_2++;
				if (!(_2 <= _3)) {
					break;
				}
			} else {
				_1 = 1;
			}
			ZEPHIR_INIT_NVAR(&i);
			ZVAL_LONG(&i, _2);
			ZEPHIR_OBS_NVAR(&v);
			zephir_array_fetch(&v, &idArray, &i, PH_NOISY, "sqids/Sqids.zep", 267);
			zephir_read_property(&_4$$3, this_ptr, ZEND_STRL("math"), PH_NOISY_CC | PH_READONLY);
			ZVAL_LONG(&_5$$3, zephir_fast_count_int(&chars));
			ZEPHIR_CALL_METHOD(&number, &_4$$3, "multiply", NULL, 0, &result, &_5$$3);
			zephir_check_call_status();
			zephir_read_property(&_5$$3, this_ptr, ZEND_STRL("math"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_FUNCTION(&_6$$3, "array_search", &_7, 25, &v, &chars);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&result, &_5$$3, "add", NULL, 0, &number, &_6$$3);
			zephir_check_call_status();
		}
	}
	zephir_read_property(&_8, this_ptr, ZEND_STRL("math"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_8, "intval", NULL, 0, &result);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Sqids_Sqids, isBlockedId)
{
	zend_bool _4$$3, _6$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *id_param = NULL, word, idLower, pos, _0, *_1, _2, _3$$3, _5$$6;
	zval id;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&word);
	ZVAL_UNDEF(&idLower);
	ZVAL_UNDEF(&pos);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$6);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(id)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id_param);
	zephir_get_strval(&id, id_param);


	ZEPHIR_INIT_VAR(&idLower);
	zephir_fast_strtolower(&idLower, &id);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("blocklist"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "sqids/Sqids.zep", 292);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _1)
		{
			ZEPHIR_INIT_NVAR(&word);
			ZVAL_COPY(&word, _1);
			ZEPHIR_INIT_NVAR(&_3$$3);
			zephir_fast_strtolower(&_3$$3, &word);
			ZEPHIR_CPY_WRT(&word, &_3$$3);
			_4$$3 = zephir_start_with(&idLower, &word, NULL);
			if (!(_4$$3)) {
				_4$$3 = zephir_end_with(&idLower, &word, NULL);
			}
			if (_4$$3) {
				RETURN_MM_BOOL(1);
			}
			ZEPHIR_INIT_NVAR(&pos);
			zephir_fast_strpos(&pos, &idLower, &word, 0 );
			if (!ZEPHIR_IS_FALSE_IDENTICAL(&pos)) {
				RETURN_MM_BOOL(1);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_0, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &_0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&word, &_0, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_5$$6);
				zephir_fast_strtolower(&_5$$6, &word);
				ZEPHIR_CPY_WRT(&word, &_5$$6);
				_6$$6 = zephir_start_with(&idLower, &word, NULL);
				if (!(_6$$6)) {
					_6$$6 = zephir_end_with(&idLower, &word, NULL);
				}
				if (_6$$6) {
					RETURN_MM_BOOL(1);
				}
				ZEPHIR_INIT_NVAR(&pos);
				zephir_fast_strpos(&pos, &idLower, &word, 0 );
				if (!ZEPHIR_IS_FALSE_IDENTICAL(&pos)) {
					RETURN_MM_BOOL(1);
				}
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&word);
	RETURN_MM_BOOL(0);
}

/**
 * Get BC Math or GMP extension.
 * @throws \RuntimeException
 */
PHP_METHOD(Sqids_Sqids, getMathExtension)
{
	zval _0, _1, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "gmp");
	ZEPHIR_CALL_FUNCTION(&_1, "extension_loaded", &_2, 26, &_0);
	zephir_check_call_status();
	if (zephir_is_true(&_1)) {
		object_init_ex(return_value, sqids_math_gmp_ce);
		if (zephir_has_constructor(return_value)) {
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0);
			zephir_check_call_status();
		}

		RETURN_MM();
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "bcmath");
	ZEPHIR_CALL_FUNCTION(&_3, "extension_loaded", &_2, 26, &_0);
	zephir_check_call_status();
	if (zephir_is_true(&_3)) {
		object_init_ex(return_value, sqids_math_bcmath_ce);
		if (zephir_has_constructor(return_value)) {
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0);
			zephir_check_call_status();
		}

		RETURN_MM();
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Missing math extension for Sqids, install either bcmath or gmp.", "sqids/Sqids.zep", 309);
	return;
}

