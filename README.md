# Sqids PHP Extension

This repository contains a PHP extension built with **Zephir** that implements the [Sqids](https://sqids.org) algorithm. Sqids generates short, unique and seemingly random IDs from arrays of integers.

## About Zephir

[Zephir](https://docs.zephir-lang.com/0.12/en/welcome) is an open source language designed to make it easy to create and maintain PHP extensions.

## About Sqids

Sqids is a tiny library for generating short unique IDs from numbers. Think of it as base conversion with additional features.

See the [FAQ](https://sqids.org/faq) for more details.

### When to use Sqids

- Link shorteners
- Unique event IDs in logs
- Short codes for text messages
- Generating friend codes

Sqids is **not** meant for sensitive data because the IDs can be decoded back to the original numbers.

## Building and Installing

1. Build the extension from source using `phpize` and `make` (Zephir is only required when regenerating the C sources):

```bash
phpize
./configure --enable-sqids
make
sudo make install
```

2. Enable the extension by adding the following line to your `php.ini` or using a dedicated `.ini` file:

```ini
extension=sqids.so
```

## Usage

```php
<?php
$sqids = new \Sqids\Sqids();
$id = $sqids->encode([1, 2, 3]); // "86Rf07"
$numbers = $sqids->decode($id); // [1, 2, 3]
```

## Running Tests

Install the development dependencies with Composer and execute PHPUnit:

```bash
composer install
./vendor/bin/phpunit ide-stubs/tests
```

All tests should pass and verify the behaviour of the extension.

## Documentation

More documentation and API details are available at <https://sqids.org/php>.
