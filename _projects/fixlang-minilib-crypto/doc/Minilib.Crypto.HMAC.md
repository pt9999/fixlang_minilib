# `module Minilib.Crypto.HMAC`

The Keyed-Hash Message Authentication Code (HMAC)

Implemented from specification of FIPS 198-1:
https://nvlpubs.nist.gov/nistpubs/FIPS/NIST.FIPS.198-1.pdf
https://doi.org/10.6028/NIST.FIPS.198-1

# Types and aliases

## `namespace Minilib.Crypto.HMAC`

### `type HMAC = unbox struct { ...fields... }`

A type that generates a message authentication code.

#### field `h : Std::Array Std::U8 -> Std::Array Std::U8`

#### field `input_block_size : Std::I64`

#### field `output_block_size : Std::I64`

# Traits and aliases

# Trait implementations

# Values

## `namespace Minilib.Crypto.HMAC::HMAC`

### `@h : Minilib.Crypto.HMAC::HMAC -> Std::Array Std::U8 -> Std::Array Std::U8`

Retrieves the field `h` from a value of `HMAC`.

### `@input_block_size : Minilib.Crypto.HMAC::HMAC -> Std::I64`

Retrieves the field `input_block_size` from a value of `HMAC`.

### `@output_block_size : Minilib.Crypto.HMAC::HMAC -> Std::I64`

Retrieves the field `output_block_size` from a value of `HMAC`.

### `_hash : Std::Array Std::U8 -> Minilib.Crypto.HMAC::HMAC -> Std::Array Std::U8`

### `act_h : [f : Std::Functor] ((Std::Array Std::U8 -> Std::Array Std::U8) -> f (Std::Array Std::U8 -> Std::Array Std::U8)) -> Minilib.Crypto.HMAC::HMAC -> f Minilib.Crypto.HMAC::HMAC`

Updates a value of `HMAC` by applying a functorial action to field `h`.

### `act_input_block_size : [f : Std::Functor] (Std::I64 -> f Std::I64) -> Minilib.Crypto.HMAC::HMAC -> f Minilib.Crypto.HMAC::HMAC`

Updates a value of `HMAC` by applying a functorial action to field `input_block_size`.

### `act_output_block_size : [f : Std::Functor] (Std::I64 -> f Std::I64) -> Minilib.Crypto.HMAC::HMAC -> f Minilib.Crypto.HMAC::HMAC`

Updates a value of `HMAC` by applying a functorial action to field `output_block_size`.

### `digest : Std::Array Std::U8 -> Std::Array Std::U8 -> Minilib.Crypto.HMAC::HMAC -> Std::Array Std::U8`

`hmac.digest(key, text)` creates a message authentication code from `key` and `text`.

### `make : (Std::Array Std::U8 -> Std::Array Std::U8) -> Std::I64 -> Std::I64 -> Minilib.Crypto.HMAC::HMAC`

`HMAC::make(h,b,l)` creates an HMAC instance.
`h` is a secure hash function, such as MD5::digest or SHA1::digest.
`b` is the input block size of `h`.
`l` is the output block size of `h`.
`l` must be less than or equal to `b`.

### `mod_h : ((Std::Array Std::U8 -> Std::Array Std::U8) -> Std::Array Std::U8 -> Std::Array Std::U8) -> Minilib.Crypto.HMAC::HMAC -> Minilib.Crypto.HMAC::HMAC`

Updates a value of `HMAC` by applying a function to field `h`.

### `mod_input_block_size : (Std::I64 -> Std::I64) -> Minilib.Crypto.HMAC::HMAC -> Minilib.Crypto.HMAC::HMAC`

Updates a value of `HMAC` by applying a function to field `input_block_size`.

### `mod_output_block_size : (Std::I64 -> Std::I64) -> Minilib.Crypto.HMAC::HMAC -> Minilib.Crypto.HMAC::HMAC`

Updates a value of `HMAC` by applying a function to field `output_block_size`.

### `set_h : (Std::Array Std::U8 -> Std::Array Std::U8) -> Minilib.Crypto.HMAC::HMAC -> Minilib.Crypto.HMAC::HMAC`

Updates a value of `HMAC` by setting field `h` to a specified one.

### `set_input_block_size : Std::I64 -> Minilib.Crypto.HMAC::HMAC -> Minilib.Crypto.HMAC::HMAC`

Updates a value of `HMAC` by setting field `input_block_size` to a specified one.

### `set_output_block_size : Std::I64 -> Minilib.Crypto.HMAC::HMAC -> Minilib.Crypto.HMAC::HMAC`

Updates a value of `HMAC` by setting field `output_block_size` to a specified one.