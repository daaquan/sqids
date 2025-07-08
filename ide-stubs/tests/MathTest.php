<?php

/**
 * Copyright (c) Sqids maintainers.
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 *
 * @see https://github.com/sqids/sqids-php
 */

namespace Sqids\Tests;

use Sqids\Math\BCMath;
use Sqids\Math\Gmp;
use PHPUnit\Framework\TestCase;
use RuntimeException;

class MathTest extends TestCase
{
    public static function mathProvider()
    {
        // Provide math implementation instances depending on available extensions
        $providerCases = [];
        if (extension_loaded('gmp')) {
            $providerCases[] = [new Gmp()];
        }

        if (extension_loaded('bcmath')) {
            $providerCases[] = [new BCMath()];
        }

        if (count($providerCases) > 0) {
            return $providerCases;
        }

        throw new RuntimeException('Missing math extension for Sqids, install either bcmath or gmp.');
    }

    /** @dataProvider mathProvider */
    public function testAdd($math)
    {
        // 1 + 2 = 3
        $this->assertEquals($math->get(3), $math->add(1, 2));
    }

    /** @dataProvider mathProvider */
    public function testMultiply($math)
    {
        // 2 * 6 = 12
        $this->assertEquals($math->get(12), $math->multiply(2, 6));
    }

    /** @dataProvider mathProvider */
    public function testDivide($math)
    {
        // 4 / 2 = 2
        $this->assertEquals($math->get(2), $math->divide(4, 2));
    }

    /** @dataProvider mathProvider */
    public function testGreaterThan($math)
    {
        // Verify comparison of very large numbers
        $this->assertTrue($math->greaterThan('18446744073709551615', '9223372036854775807'));
        $this->assertFalse($math->greaterThan('9223372036854775807', '18446744073709551615'));
        $this->assertFalse($math->greaterThan('9223372036854775807', '9223372036854775807'));
    }

    /** @dataProvider mathProvider */
    public function testMod($math)
    {
        // Large modulo operation
        $this->assertEquals($math->get(15), $math->mod('18446744073709551615', '100'));
    }

    /** @dataProvider mathProvider */
    public function testIntval($math)
    {
        // Convert string to integer
        $this->assertSame(9223372036854775807, $math->intval('9223372036854775807'));
    }

    /** @dataProvider mathProvider */
    public function testStrval($math)
    {
        // Convert math value to string
        $this->assertSame('18446744073709551615', $math->strval($math->add('0', '18446744073709551615')));
    }
}
