<?php

// Interface stub for math classes used by the Sqids extension.

namespace Sqids\Math;

/**
 * Copyright (c) Sqids maintainers.
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 *
 * @see https://github.com/sqids/sqids-php
 */
interface MathInterface
{


    /**
     * Add two arbitrary-length integers.
     *
     * @param string $a
     * @param string $b
     * @return string
     */
    public function add($a, $b): string;

    /**
     * Multiply two arbitrary-length integers.
     *
     * @param string $a
     * @param string $b
     * @return string
     */
    public function multiply($a, $b): string;

    /**
     * Divide two arbitrary-length integers.
     *
     * @param string $a
     * @param string $b
     * @return string
     */
    public function divide($a, $b): string;

    /**
     * Compute arbitrary-length integer modulo.
     *
     * @param string $n
     * @param string $d
     * @return string
     */
    public function mod($n, $d): string;

    /**
     * Compares two arbitrary-length integers.
     *
     * @param string $a
     * @param string $b
     * @return bool
     */
    public function greaterThan($a, $b): bool;

    /**
     * Converts arbitrary-length integer to PHP integer.
     *
     * @param string $a
     * @return int
     */
    public function intval($a): int;

    /**
     * Converts arbitrary-length integer to PHP string.
     *
     * @param string $a
     * @return string
     */
    public function strval($a): string;

    /**
     * Converts PHP integer to arbitrary-length integer.
     *
     * @param int $a
     * @return string
     */
    public function get($a): string;
}
