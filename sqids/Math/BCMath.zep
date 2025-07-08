/**
 * Copyright (c) Sqids maintainers.
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 *
 * @see https://github.com/sqids/sqids-php
 */
namespace Sqids\Math;

class BCMath implements MathInterface
{
    /**
     * Add two arbitrary-length integers using the bcadd function.
     */
    public function add(var a, var b) -> string
    {
        return bcadd(a, b, 0);
    }

    /**
     * Multiply two arbitrary-length integers using the bcmul function.
     */
    public function multiply(var a, var b) -> string
    {
        return bcmul(a, b, 0);
    }

    /**
     * Divide two arbitrary-length integers using bcdiv.
     */
    public function divide(var a, var b) -> string
    {
        return bcdiv(a, b, 0);
    }

    /**
     * Compute the modulo of two arbitrary-length integers.
     */
    public function mod(var n, var d) -> string
    {
        return bcmod(n, d);
    }

    /**
     * Compare two arbitrary-length integers.
     */
    public function greaterThan(var a, var b) -> bool
    {
        return bccomp(a, b, 0) > 0;
    }

    /**
     * Cast a bc value to integer.
     */
    public function intval(var a) -> int
    {
        return intval(a);
    }

    /**
     * Cast a bc value to string.
     */
    public function strval(var a) -> string
    {
        return a;
    }

    /**
     * Return the given value as a string for bc math operations.
     */
    public function get(var a) -> string
    {
        return a;
    }

}