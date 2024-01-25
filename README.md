## Overview

Minilib is a small library for [FixLang](https://github.com/tttmmmyyyy/fixlang).

This library is still work in progress.

NOTE: I am currently undergoing a major restructuring.

## Tested Platform
- x86_64-linux-gnu
- aarch64-linux-gnu
- NOTE: Currently MacOS is not supported.

## Features

- Application
  - Clap (Command Line Argument Parser)
- Collections
  - Ordered map
  - Deque (double-ended queue)
  - Tree map
  - Tree set
  - Red-Black tree
- Cryptography
  - Secure hash function (SHA-1, SHA-256)
- Encoding
  - Binary (byte order, byte buffer)
  - JSON
- IO
  - IO extension
- Networking
  - TCP/IP Socket (IPv4 only)
  - URL, URI
  - Simple HTTP Server
- Testing
  - Unit test
- Text
  - Simple parser
  - String extension
  - Regular expression
  - Unicode (UTF8/UTF16/UTF32 conversion)

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
/doc        ... Library Reference documentation
/examples   ... Example code using this library
/lib        ... Library code
/tests      ... Test code
```

## Library Reference

See [Library Reference](doc/index.md). (work in progress)
