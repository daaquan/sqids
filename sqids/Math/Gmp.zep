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
    public function add(var a, var b) -> string
    {
        return gmp_add(a, b);
    }

    public function multiply(var a, var b) -> string
    {
        return gmp_mul(a, b);
    }

    public function divide(var a, var b) -> string
    {
        return gmp_div_q(a, b);
    }

    public function mod(var n, var d) -> string
    {
        return gmp_mod(n, d);
    }

    public function greaterThan(var a, var b) -> bool
    {
        return gmp_cmp(a, b) > 0;
    }

    public function intval(var a) -> int
    {
        return gmp_intval(a);
    }

    public function strval(var a) -> string
    {
        return gmp_strval(a);
    }

    public function get(var a) -> string
    {
        return gmp_init(a);
    }

}