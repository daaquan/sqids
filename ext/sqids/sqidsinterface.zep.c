
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

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
ZEPHIR_INIT_CLASS(Sqids_SqidsInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Sqids, SqidsInterface, sqids, sqidsinterface, sqids_sqidsinterface_method_entry);

	return SUCCESS;
}

/**
 * Encode integers to generate an ID.
 * @param array<int> $numbers
 * @return string
 */
ZEPHIR_DOC_METHOD(Sqids_SqidsInterface, encode);
/**
 * Decode an ID back to integers.
 * @param string $id
 * @return array<int>
 */
ZEPHIR_DOC_METHOD(Sqids_SqidsInterface, decode);
