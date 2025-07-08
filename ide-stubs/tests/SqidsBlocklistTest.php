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

class SqidsBlocklistTest extends TestCase
{
    public function testIfNoCustomBlocklistParamUseDefaultBlocklist()
    {
        // Default blocklist should be used when none is provided
        $sqids = new Sqids();

        $this->assertSame([4572721], $sqids->decode('aho1e'));
        $this->assertSame('JExTR', $sqids->encode([4572721]));
    }

    public function testIfEmptyBlocklistParamPassedDontUseAnyBlocklist()
    {
        // An empty array disables blocklist filtering
        $sqids = new Sqids('', 0, []);

        $this->assertSame([4572721], $sqids->decode('aho1e'));
        $this->assertSame('aho1e', $sqids->encode([4572721]));
    }

    public function testIfNonEmptyBlocklistParamPassedUseOnlyThat()
    {
        // Only the provided blocklist words should be filtered
        $sqids = new Sqids('', 0, [
            'ArUO' // originally encoded [100000]
        ]);

        // Make sure we don't use the default blocklist
        $this->assertSame([4572721], $sqids->decode('aho1e'));
        $this->assertSame('aho1e', $sqids->encode([4572721]));

        // Make sure we are using the passed blocklist
        $this->assertSame([100000], $sqids->decode('ArUO'));
        $this->assertSame('QyG4', $sqids->encode([100000]));
        $this->assertSame([100000], $sqids->decode('QyG4'));
    }

    public function testBlocklist()
    {
        // Ensure multiple blocked words are respected during encoding
        $sqids = new Sqids('', 0, [
            'JSwXFaosAN', // normal result of 1st encoding, let's block that word on purpose
            'OCjV9JK64o', // result of 2nd encoding
            'rBHf', // result of 3rd encoding is `4rBHfOiqd3`, let's block a substring
            '79SM', // result of 4th encoding is `dyhgw479SM`, let's block the postfix
            '7tE6', // result of 4th encoding is `7tE6jdAHLe`, let's block the prefix
        ]);

        $this->assertSame('1aYeB7bRUt', $sqids->encode([1_000_000, 2_000_000]));
        $this->assertSame([1_000_000, 2_000_000], $sqids->decode('1aYeB7bRUt'));
    }

    public function testDecodingBlocklistWordsShouldStillWork()
    {
        // Decoding should not fail even if the input is on the blocklist
        $sqids = new Sqids('', 0, ['86Rf07', 'se8ojk', 'ARsz1p', 'Q8AI49', '5sQRZO']);

        $this->assertSame([1, 2, 3], $sqids->decode('86Rf07'));
        $this->assertSame([1, 2, 3], $sqids->decode('se8ojk'));
        $this->assertSame([1, 2, 3], $sqids->decode('ARsz1p'));
        $this->assertSame([1, 2, 3], $sqids->decode('Q8AI49'));
        $this->assertSame([1, 2, 3], $sqids->decode('5sQRZO'));
    }

    public function testMatchAgainstAShortBlocklistWord()
    {
        // Short blocklist words should not cause issues with encoding
        $sqids = new Sqids('', 0, ['pnd']);
        $this->assertSame([1000], $sqids->decode($sqids->encode([1000])));
    }

    public function testBlocklistFilteringInConstructor()
    {
        // Blocklist is normalized according to the provided alphabet
        // lowercase blocklist in only-uppercase alphabet
        $sqids = new Sqids('ABCDEFGHIJKLMNOPQRSTUVWXYZ', 0, ['sxnzkl']);

        $id = $sqids->encode([1, 2, 3]);
        $numbers = $sqids->decode($id);

        $this->assertSame($id, 'IBSHOZ'); // without blocklist, would've been "SXNZKL"
        $this->assertSame($numbers, [1, 2, 3]);
    }

    public function testMaxEncodingAttempts()
    {
        // Throw an exception when all possible shuffled variants are blocked
        $alphabet = 'abc';
        $minLength = 3;
        $blocklist = ['cab', 'abc', 'bca'];

        $sqids = new Sqids($alphabet, $minLength, $blocklist);

        $this->assertSame($minLength, strlen($alphabet));
        $this->assertSame(count($blocklist), strlen($alphabet));

        $this->expectException(InvalidArgumentException::class);
        $sqids->encode([0]);
    }
}
