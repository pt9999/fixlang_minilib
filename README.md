## Overview

Minilib is a small library for [FixLang](https://github.com/tttmmmyyyy/fixlang).

This library is still under construction.

## Features

- JSON encoding and decoding
- Simple parsers
- Ordered maps
- String utility, UTF8/UTF16/UTF32 conversion
- TCP/IP Socket
- Unit testing

## How to use

To build the example code, type `make examples`.

To run the test code, type `make test`. It has been tested in the following environment.

- Ubuntu-22.04 on WSL 2
- rustup 1.26.0
- rustc 1.72.1
- llvm 12.0.1
- FixLang 0.1.1

## Directory structure

```
/_sandbox   ... Experimental source code (Not included in the library itself)
/examples   ... Example code using this library
/lib        ... Library code
/tests      ... Test code
```

## Library Reference

See [Reference.md](./Reference.md).
