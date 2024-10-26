## Overview

Minilib is a small library for [FixLang](https://github.com/tttmmmyyyy/fixlang).

This library is still in alpha stage.

NOTE: This library is currently undergoing major changes. 

## Tested Platform
- x86_64-linux-gnu
- aarch64-linux-gnu
- NOTE: Currently MacOS is not supported.

## Subprojects

Minilib is split to several subprojects.
They are referenced as Git submodules under `_projects` directory.

For details, see `_projects/fixlang-minilib-*`.

![Project dependencies](_projects/dependencies.png)

| Name   | Description |
|--------|-------------|
|minilib-common| Common modules (StringEx, UnitTest etc.)|
|minilib-text| Text handling (SimpleParser, Unicode etc.)|
|minilib-binary| Binary handling|
|minilib-io| IO operations (File System, Platform Info)|
|minilib-collections| Collections  (Red-Black tree, Double-ended queue etc.)|
|minilib-monad| Monads (State/Reader/Writer monad, Monad transformer etc.)|
|minilib-comonad| Comonads (Env/Traced comonad etc.)|
|minilib-thread| Multithreading (Task pool etc.) |
|minilib-net| Networks (TCP/IP, HTTP etc.) |
|minilib-math| Math (Complex number, BigInt, BigFloat, Algebra etc.)|
|minilib-crypto| Cryptography  (AES, SHA-1, SHA-256, HMAC etc.)|
|minilib-app| Application Support (CommandLine parser etc.) |
|minilib-media| Multimedia (PNG image etc.) |
|minilib-json| JSON encoder/decoder |
|minilib-xml| XML encoder/decoder |
|--------|-------------|
|minilib-examples| Example programs|

## How to use

To run test codes and build example programs, type `cd _projects && make test`.

It has been mainly tested in the following environment.

- Ubuntu-22.04 on WSL 2
- gcc 11.4.0
- GNU make 4.3
- rustup 1.26.0
- rustc 1.72.1
- llvm 12.0.1
- FixLang 0.1.1

## Directory structure

```
/_projects  ... Subprojects
/_sandbox   ... Experimental source code (Not included in the library itself)
/tools      ... Tools code
```

## Library Reference

See `_projects/fixlang-minilib-*/doc` directory.

## Example programs

See [_projects/fixlang-minilib-examples/README.md](_projects/fixlang-minilib-examples/README.md).
