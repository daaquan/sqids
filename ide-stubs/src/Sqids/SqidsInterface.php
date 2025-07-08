<?php

// Interface stub file for IDE support. Implementation is provided by the Sqids extension.

namespace Sqids;

/**
 * Copyright (c) Sqids maintainers.
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 *
 * @see https://github.com/sqids/sqids-php
 */
interface SqidsInterface
{


    /**
     * Encode integers to generate an ID.
     *
     * @param array<int> $numbers
     * @return string
     * @param array $numbers
     */
    public function encode(array $numbers): string;

    /**
     * Decode an ID back to integers.
     *
     * @param string $id
     * @return array<int>
     */
    public function decode(string $id): array;
}
