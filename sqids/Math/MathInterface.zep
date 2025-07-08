/**
 * Copyright (c) Sqids maintainers.
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 *
 * @see https://github.com/sqids/sqids-php
 */
namespace Sqids\Math;

interface MathInterface
{
    /**
     * Add two arbitrary-length integers.
     * @param string $a
     * @param string $b
     * @return string
     */
    public function add(var a, var b) -> string;

    /**
     * Multiply two arbitrary-length integers.
     * @param string $a
     * @param string $b
     * @return string
     */
    public function multiply(var a, var b) -> string;

    /**
     * Divide two arbitrary-length integers.
     * @param string $a
     * @param string $b
     * @return string
     */
    public function divide(var a, var b) -> string;

    /**
     * Compute arbitrary-length integer modulo.
     * @param string $n
     * @param string $d
     * @return string
     */
    public function mod(var n, var d) -> string;

    /**
     * Compares two arbitrary-length integers.
     * @param string $a
     * @param string $b
     * @return bool
     */
    public function greaterThan(var a, var b) -> bool;

    /**
     * Converts arbitrary-length integer to PHP integer.
     * @param string $a
     * @return int
     */
    public function intval(var a) -> int;

    /**
     * Converts arbitrary-length integer to PHP string.
     * @param string $a
     * @return string
     */
    public function strval(var a) -> string;

    /**
     * Converts PHP integer to arbitrary-length integer.
     * @param int $a
     * @return string
     */
    public function get(var a) -> string;

}