## Overview

Minilib is a small library for [FixLang](https://github.com/tttmmmyyyy/fixlang).

This library is still in alpha stage.

NOTE: This library is currently undergoing major changes. 

## Tested Platform

- x86_64-linux-gnu
- aarch64-linux-gnu
- NOTE: Currently MacOS is not supported.

It has been mainly tested in the following environment.

- Ubuntu-22.04 on WSL 2
- gcc 11.4.0
- GNU make 4.3
- rustup 1.26.0
- rustc 1.72.1
- llvm 12.0.1
- latest Fix program (2024/10/24)

## Subprojects

Minilib is split to several FixLang subprojects with whose name starts with `minilib-`.

Each subproject is managed under other GitHub repository. For example, `minilib-common` is managed under
https://github.com/pt9999/fixlang-minilib-common repository.

### List of subprojects

| Name   | Description |
|--------|-------------|
|[minilib-common](https://github.com/pt9999/fixlang-minilib-common)| Common modules (StringEx, UnitTest etc.)|
|[minilib-text](https://github.com/pt9999/fixlang-minilib-text)| Text handling (SimpleParser, Unicode etc.)|
|[minilib-binary](https://github.com/pt9999/fixlang-minilib-binary)| Binary handling|
|[minilib-io](https://github.com/pt9999/fixlang-minilib-io)| IO operations (File System, Platform Info)|
|[minilib-collections](https://github.com/pt9999/fixlang-minilib-collections)| Collections  (Red-Black tree, Double-ended queue etc.)|
|[minilib-monad](https://github.com/pt9999/fixlang-minilib-monad)| Monads (State/Reader/Writer monad, Monad transformer etc.)|
|[minilib-comonad](https://github.com/pt9999/fixlang-minilib-comonad)| Comonads (Env/Traced comonad etc.)|
|[minilib-thread](https://github.com/pt9999/fixlang-minilib-thread)| Multithreading (Task pool etc.) |
|[minilib-net](https://github.com/pt9999/fixlang-minilib-net)| Networks (TCP/IP, HTTP etc.) |
|[minilib-math](https://github.com/pt9999/fixlang-minilib-math)| Math (Complex number, BigInt, BigFloat, Algebra etc.)|
|[minilib-crypto](https://github.com/pt9999/fixlang-minilib-crypto)| Cryptography  (AES, SHA-1, SHA-256, HMAC etc.)|
|[minilib-app](https://github.com/pt9999/fixlang-minilib-app)| Application Support (CommandLine parser etc.) |
|[minilib-media](https://github.com/pt9999/fixlang-minilib-media)| Multimedia (PNG image etc.) |
|[minilib-json](https://github.com/pt9999/fixlang-minilib-json)| JSON encoder/decoder |
|[minilib-xml](https://github.com/pt9999/fixlang-minilib-xml)| XML encoder/decoder |
|--------|-------------|
|[minilib-examples](https://github.com/pt9999/fixlang-minilib-examples)| Example programs|

### Project dependencies

![Project dependencies](_projects/dependencies.png)

### Registy File

You might want to add [registry.toml](registry.toml) to your `${HOME}/.fixproj.toml`.
For example:
```
registries = [
    "https://raw.githubusercontent.com/pt9999/fixlang_minilib/refs/heads/main/registry.toml"
]
```

Then, you can specify the names of subprojects in `fix deps add` command.
For example:
```
$ fix deps add minilib-common minilib-binary
```

## Directory structure

```
/_projects  ... Git submodules are stored here
/_sandbox   ... Experimental source code (Not included in the library itself)
/tools      ... Tools code
```

## Git submodules

The subprojects are referenced as Git submodules.

To update Git submodules, run the commands below. They are cloned from GitHub repositories, and stored under `_projects` directory.
```
$ git submodule init
$ git submodule update
```

To run test codes and build example programs, type `cd _projects && make test`.


### Library Reference

See `_projects/fixlang-minilib-*/doc` directory.

### Example programs

See [_projects/fixlang-minilib-examples/README.md](_projects/fixlang-minilib-examples/README.md).
