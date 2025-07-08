<?php

// This file provides IDE auto-completion hints only.
// The real functionality lives inside the Sqids extension written in Zephir.

namespace Sqids;

use Sqids\Math\BCMath;
use Sqids\Math\Gmp;
use Sqids\Math\MathInterface;
use InvalidArgumentException;
use RuntimeException;

/**
 * Copyright (c) Sqids maintainers.
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 *
 * @see https://github.com/sqids/sqids-php
 */
class Sqids implements \Sqids\SqidsInterface
{
    const DEFAULT_ALPHABET = 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789';

    protected $math;

    protected $alphabet;

    protected $minLength;

    protected $blocklist;

    /**
     * @param string $alphabet
     * @param int $minLength
     * @param array $blocklist
     */
    public function __construct(string $alphabet = null, int $minLength = 0, array $blocklist = null)
    {
    }

    /**
     * Encodes an array of unsigned integers into an ID
     *
     * These are the cases where encoding might fail:
     * - One of the numbers passed is smaller than 0 or greater than `maxValue()`
     * - An n-number of attempts has been made to re-generated the ID, where n is alphabet length + 1
     *
     * @param array<int> $numbers Non-negative integers to encode into an ID
     * @return string Generated ID
     * @param array $numbers
     */
    public function encode(array $numbers): string
    {
    }

    /**
     * Internal function that encodes an array of unsigned integers into an ID
     *
     * @param array<int> $numbers Non-negative integers to encode into an ID
     * @param int $increment An internal number used to modify the `offset` variable in order to re-generate the ID
     * @return string Generated ID
     * @param array $numbers
     */
    protected function encodeNumbers(array $numbers, int $increment = 0): string
    {
    }

    /**
     * Decodes an ID back into an array of unsigned integers
     *
     * These are the cases where the return value might be an empty array:
     * - Empty ID / empty string
     * - Non-alphabet character is found within the ID
     *
     * @param string $id Encoded ID
     * @return array<int> Array of unsigned integers
     */
    public function decode(string $id): array
    {
    }

    /**
     * @param string $alphabet
     * @return string
     */
    protected function shuffle(string $alphabet): string
    {
    }

    /**
     * @param int $num
     * @param string $alphabet
     * @return string
     */
    protected function toId(int $num, string $alphabet): string
    {
    }

    /**
     * @param string $id
     * @param string $alphabet
     * @return int
     */
    protected function toNumber(string $id, string $alphabet): int
    {
    }

    /**
     * @param string $id
     * @return bool
     */
    protected function isBlockedId(string $id): bool
    {
    }

    /**
     * Get BC Math or GMP extension.
     *
     * @throws \RuntimeException
     * @return MathInterface
     */
    protected function getMathExtension(): MathInterface
    {
    }
}
