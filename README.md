## Overview

Minilib is a small library for [FixLang](https://github.com/tttmmmyyyy/fixlang).

This library is still in alpha stage.

## Tested Platform
- x86_64-linux-gnu
- aarch64-linux-gnu
- NOTE: Currently MacOS is not supported.

## Features

- Application
  - Command Line Argument Parser
- Collections
  - Ordered map
  - Double-ended queue
  - Tree map
  - Tree set
  - Red-Black tree
- Cryptography
  - Secure hash function (MD5/SHA-1/SHA-256)
- Encoding
  - Binary
  - JSON
- IO
  - File system
  - Platform information
  - Channel
- Math
  - Complex number
  - BigInt
  - BigFloat (currently not well tested)
  - Prime generator using BigInt
  - Rational number
  - Algebra (Ring, Field, Euclid, Modular, Polynomial)
- Monad
  - State / Reader / Writer Monad
  - Functor for Monad (map_m, foreach_m)
- Networking
  - TCP/IP Socket (IPv4 only)
  - URL, URI
  - Simple HTTP Server
- Testing
  - Unit test
  - Time
- Text
  - Simple parser
  - String extension
  - Regular expression
  - Unicode (UTF8/UTF16/UTF32) conversion
- Thread
  - Task Pool
  - Future
- Trait
  - Semigroup
  - Monoid
  - Comonad

## How to use

To build example programs, type `make examples`.

To run test codes, type `make test`. It has been mainly tested in the following environment.

- Ubuntu-22.04 on WSL 2
- rustup 1.26.0
- rustc 1.72.1
- llvm 12.0.1
- FixLang 0.1.1

## Directory structure

```
/_sandbox   ... Experimental source code (Not included in the library itself)
/bin        ... Tools executable
/doc        ... Library Reference documentation
/examples   ... Example code using this library
/lib        ... Library code
/tests      ... Test code
/tools      ... Tools code
```

## Library Reference

See [Library Reference](doc/index.md).

## Example programs

See [examples/README.md](examples/README.md).
