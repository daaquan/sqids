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

use Sqids\Sqids;
use InvalidArgumentException;
use PHPUnit\Framework\TestCase;

class SqidsAlphabetTest extends TestCase
{
    public function testSimple()
    {
        // Basic encoding and decoding with a custom alphabet
        $sqids = new Sqids('0123456789abcdef');

        $numbers = [1, 2, 3];
        $id = '489158';

        $this->assertSame($id, $sqids->encode($numbers));
        $this->assertSame($numbers, $sqids->decode($id));
    }

    public function testShortAlphabet()
    {
        // Alphabet with a minimal acceptable length
        $sqids = new Sqids('abc');

        $numbers = [1, 2, 3];
        $this->assertSame($numbers, $sqids->decode($sqids->encode($numbers)));
    }

    public function testLongAlphabet()
    {
        // Very long alphabet containing many symbols
        $sqids = new Sqids('abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()-_+|{}[];:\'"/?.>,<`~');

        $numbers = [1, 2, 3];
        $this->assertSame($numbers, $sqids->decode($sqids->encode($numbers)));
    }

    public function testMultibyteCharacters()
    {
        // Non-ASCII characters are not allowed in the alphabet
        $this->expectException(InvalidArgumentException::class);
        new Sqids('ë1092');
    }

    public function testRepeatingAlphabetCharacters()
    {
        // The alphabet must not contain repeating characters
        $this->expectException(InvalidArgumentException::class);
        new Sqids('aabcdefg');
    }

    public function testTooShortAlphabet()
    {
        // The alphabet needs at least three unique characters
        $this->expectException(InvalidArgumentException::class);
        new Sqids('ab');
    }
}
