/**
 * Copyright (c) Sqids maintainers.
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 *
 * @see https://github.com/sqids/sqids-php
 */
namespace Sqids\Math;

class Gmp implements MathInterface
{
    /**
     * Add two arbitrary-length integers using the gmp_add function.
     */
    public function add(var a, var b) -> string
    {
        return gmp_add(a, b);
    }

    /**
     * Multiply two arbitrary-length integers using gmp_mul.
     */
    public function multiply(var a, var b) -> string
    {
        return gmp_mul(a, b);
    }

    /**
     * Divide two arbitrary-length integers using gmp_div_q.
     */
    public function divide(var a, var b) -> string
    {
        return gmp_div_q(a, b);
    }

    /**
     * Compute the modulo of two arbitrary-length integers.
     */
    public function mod(var n, var d) -> string
    {
        return gmp_mod(n, d);
    }

    /**
     * Compare two arbitrary-length integers using gmp_cmp.
     */
    public function greaterThan(var a, var b) -> bool
    {
        return gmp_cmp(a, b) > 0;
    }

    /**
     * Cast a GMP number to integer.
     */
    public function intval(var a) -> int
    {
        return gmp_intval(a);
    }

    /**
     * Convert a GMP number to string.
     */
    public function strval(var a) -> string
    {
        return gmp_strval(a);
    }

    /**
     * Convert an integer or string to a GMP number.
     */
    public function get(var a) -> string
    {
        return gmp_init(a);
    }

}