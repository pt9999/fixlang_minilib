# `module Minilib.Crypto.SecureRandom`

Secure random number generator.

Currently only Linux is supported, because it uses `/dev/urandom` as a secure random source.

# Types and aliases

## `namespace Minilib.Crypto.SecureRandom`

### `type SecureRandom = unbox struct { ...fields... }`

#### field `data : Std::FFI::Destructor Std::IO::IOHandle`

# Traits and aliases

# Trait implementations

# Values

## `namespace Minilib.Crypto.SecureRandom::SecureRandom`

### `@data : Minilib.Crypto.SecureRandom::SecureRandom -> Std::FFI::Destructor Std::IO::IOHandle`

Retrieves the field `data` from a value of `SecureRandom`.

### `act_data : [f : Std::Functor] (Std::FFI::Destructor Std::IO::IOHandle -> f (Std::FFI::Destructor Std::IO::IOHandle)) -> Minilib.Crypto.SecureRandom::SecureRandom -> f Minilib.Crypto.SecureRandom::SecureRandom`

Updates a value of `SecureRandom` by applying a functorial action to field `data`.

### `generate_bytes : Std::I64 -> Minilib.Crypto.SecureRandom::SecureRandom -> Std::IO::IOFail (Minilib.Crypto.SecureRandom::SecureRandom, Std::Array Std::U8)`

Generates a random byte array with specified size.

### `make : Std::IO::IOFail Minilib.Crypto.SecureRandom::SecureRandom`

Creates a SecureRandom instance.

### `mod_data : (Std::FFI::Destructor Std::IO::IOHandle -> Std::FFI::Destructor Std::IO::IOHandle) -> Minilib.Crypto.SecureRandom::SecureRandom -> Minilib.Crypto.SecureRandom::SecureRandom`

Updates a value of `SecureRandom` by applying a function to field `data`.

### `set_data : Std::FFI::Destructor Std::IO::IOHandle -> Minilib.Crypto.SecureRandom::SecureRandom -> Minilib.Crypto.SecureRandom::SecureRandom`

Updates a value of `SecureRandom` by setting field `data` to a specified one.