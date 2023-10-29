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
    public function add(var a, var b) -> string
    {
        return bcadd(a, b, 0);
    }

    public function multiply(var a, var b) -> string
    {
        return bcmul(a, b, 0);
    }

    public function divide(var a, var b) -> string
    {
        return bcdiv(a, b, 0);
    }

    public function mod(var n, var d) -> string
    {
        return bcmod(n, d);
    }

    public function greaterThan(var a, var b) -> bool
    {
        return bccomp(a, b, 0) > 0;
    }

    public function intval(var a) -> int
    {
        return intval(a);
    }

    public function strval(var a) -> string
    {
        return a;
    }

    public function get(var a) -> string
    {
        return a;
    }

}