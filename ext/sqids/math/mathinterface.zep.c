
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Copyright (c) Sqids maintainers.
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 *
 * @see https://github.com/sqids/sqids-php
 */
ZEPHIR_INIT_CLASS(Sqids_Math_MathInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Sqids\\Math, MathInterface, sqids, math_mathinterface, sqids_math_mathinterface_method_entry);

	return SUCCESS;
}

/**
 * Add two arbitrary-length integers.
 * @param string $a
 * @param string $b
 * @return string
 */
ZEPHIR_DOC_METHOD(Sqids_Math_MathInterface, add);
/**
 * Multiply two arbitrary-length integers.
 * @param string $a
 * @param string $b
 * @return string
 */
ZEPHIR_DOC_METHOD(Sqids_Math_MathInterface, multiply);
/**
 * Divide two arbitrary-length integers.
 * @param string $a
 * @param string $b
 * @return string
 */
ZEPHIR_DOC_METHOD(Sqids_Math_MathInterface, divide);
/**
 * Compute arbitrary-length integer modulo.
 * @param string $n
 * @param string $d
 * @return string
 */
ZEPHIR_DOC_METHOD(Sqids_Math_MathInterface, mod);
/**
 * Compares two arbitrary-length integers.
 * @param string $a
 * @param string $b
 * @return bool
 */
ZEPHIR_DOC_METHOD(Sqids_Math_MathInterface, greaterThan);
/**
 * Converts arbitrary-length integer to PHP integer.
 * @param string $a
 * @return int
 */
ZEPHIR_DOC_METHOD(Sqids_Math_MathInterface, intval);
/**
 * Converts arbitrary-length integer to PHP string.
 * @param string $a
 * @return string
 */
ZEPHIR_DOC_METHOD(Sqids_Math_MathInterface, strval);
/**
 * Converts PHP integer to arbitrary-length integer.
 * @param int $a
 * @return string
 */
ZEPHIR_DOC_METHOD(Sqids_Math_MathInterface, get);
