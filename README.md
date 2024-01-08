## Overview

Minilib is a small library for [FixLang](https://github.com/tttmmmyyyy/fixlang).

This library is still work in progress.

## Tested Platform
- x86_64-linux-gnu
- aarch64-linux-gnu
- NOTE: Currently not tested on MacOS.

## Features

- Application support
  - Clap (Command Line Argument Parser)
- Collections
  - Ordered maps
  - Deque (double-ended queue)
- File format
  - JSON encoding and decoding
- Text handling
  - Regular expressions
  - Simple parsers
  - String utility
  - UTF8/UTF16/UTF32 conversion
- Networking
  - TCP/IP Socket (WARNING: IPv6 is not supported yet)
  - URL, URI
  - Simple HTTP Server
- Unit testing

## How to use

To build example programs, type `make examples`.

To run test codes, type `make test`. It has been tested in the following environment.

- Ubuntu-22.04 on WSL 2
- rustup 1.26.0
- rustc 1.72.1
- llvm 12.0.1
- FixLang 0.1.1

## Directory structure

```
/_sandbox   ... Experimental source code (Not included in the library itself)
/doc        ... Library Reference documentation
/examples   ... Example code using this library
/lib        ... Library code
/tests      ... Test code
```

## Library Reference

See [Library Reference](doc/index.md). (work in progress)
