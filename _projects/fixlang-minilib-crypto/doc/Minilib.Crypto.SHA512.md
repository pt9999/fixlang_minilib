# `module Minilib.Crypto.SHA512`

SHA-512 secure hash function.

Implemented from specification of FIPS PUB 180-4:
https://csrc.nist.gov/files/pubs/fips/180-4/final/docs/fips180-4.pdf

NOTE: FIPS 180-4 (2012) is superseded by FIPS 180-4 (2015), with the only change being
made in the Applicability Clause. There are no changes to the technical specifications.
FIPS 180-4 (2015):
http://dx.doi.org/10.6028/NIST.FIPS.180-4

# Types and aliases

## `namespace Minilib.Crypto.SHA512`

### `type SHA512 = unbox struct { ...fields... }`

SHA-512 hasher.
Usually it is sufficient to simply call `SHA512:digest(bytes)` without using this structure.

#### field `hash : Std::Array Std::U64`

#### field `msglen : Std::U64`

#### field `msgbuf : Std::Array Std::U8`

# Traits and aliases

# Trait implementations

# Values

## `namespace Minilib.Crypto.SHA512`

### `_bit_not : Std::U64 -> Std::U64`

2.2.2 Symbols and Operations
bitwise complement

### `_ch : Std::U64 -> Std::U64 -> Std::U64 -> Std::U64`

4.1.3 SHA-384, SHA-512, SHA-512/224 and SHA-512/256 Functions

### `_init_hash_sha384 : Std::Array Std::U64`

5.3 Setting the Initial Hash Value (H(0))
5.3.4 SHA-384

### `_init_hash_sha512 : Std::Array Std::U64`

5.3.5 SHA-512

### `_k : Std::Array Std::U64`

### `_large_sigma_0 : Std::U64 -> Std::U64`

### `_large_sigma_1 : Std::U64 -> Std::U64`

### `_maj : Std::U64 -> Std::U64 -> Std::U64 -> Std::U64`

### `_rotl : Std::U64 -> Std::U64 -> Std::U64`

rotate left

### `_rotr : Std::U64 -> Std::U64 -> Std::U64`

rotate right

### `_shr : Std::U64 -> Std::U64 -> Std::U64`

shift right

### `_small_sigma_0 : Std::U64 -> Std::U64`

### `_small_sigma_1 : Std::U64 -> Std::U64`

### `_update_hash : Std::Array Std::U64 -> Std::Array Std::U64 -> Std::Array Std::U64`

6.2.2 SHA-512 Hash Computation

### `_update_inner : Std::Array Std::U8 -> Std::U64 -> Minilib.Crypto.SHA512::SHA512 -> Minilib.Crypto.SHA512::SHA512`

`sha512._update_inner(input, msglen_inc)` updates the message buffer with input.
And it increments the message length by `msglen_inc`.
When the message buffer is full (128 bytes), it updates hash with the message
and clears the messsage buffer.

### `digest : Std::Array Std::U8 -> Std::Array Std::U8`

`SHA512::digest(bytes)` computes SHA-512 secure hash function of `bytes`.

### `empty : Minilib.Crypto.SHA512::SHA512`

An empty SHA-512 hasher.

### `finalize : Minilib.Crypto.SHA512::SHA512 -> Std::Array Std::U8`

`sha512.finalize` retrieves a final SHA-512 hash value.

### `update : Std::Array Std::U8 -> Minilib.Crypto.SHA512::SHA512 -> Minilib.Crypto.SHA512::SHA512`

`sha512.update(bytes)` processes `bytes`, and updates its internal state.

## `namespace Minilib.Crypto.SHA512::SHA384`

### `digest : Std::Array Std::U8 -> Std::Array Std::U8`

`SHA384::digest(bytes)` computes SHA-384 secure hash function of `bytes`.

## `namespace Minilib.Crypto.SHA512::SHA512`

### `@hash : Minilib.Crypto.SHA512::SHA512 -> Std::Array Std::U64`

Retrieves the field `hash` from a value of `SHA512`.

### `@msgbuf : Minilib.Crypto.SHA512::SHA512 -> Std::Array Std::U8`

Retrieves the field `msgbuf` from a value of `SHA512`.

### `@msglen : Minilib.Crypto.SHA512::SHA512 -> Std::U64`

Retrieves the field `msglen` from a value of `SHA512`.

### `act_hash : [f : Std::Functor] (Std::Array Std::U64 -> f (Std::Array Std::U64)) -> Minilib.Crypto.SHA512::SHA512 -> f Minilib.Crypto.SHA512::SHA512`

Updates a value of `SHA512` by applying a functorial action to field `hash`.

### `act_msgbuf : [f : Std::Functor] (Std::Array Std::U8 -> f (Std::Array Std::U8)) -> Minilib.Crypto.SHA512::SHA512 -> f Minilib.Crypto.SHA512::SHA512`

Updates a value of `SHA512` by applying a functorial action to field `msgbuf`.

### `act_msglen : [f : Std::Functor] (Std::U64 -> f Std::U64) -> Minilib.Crypto.SHA512::SHA512 -> f Minilib.Crypto.SHA512::SHA512`

Updates a value of `SHA512` by applying a functorial action to field `msglen`.

### `mod_hash : (Std::Array Std::U64 -> Std::Array Std::U64) -> Minilib.Crypto.SHA512::SHA512 -> Minilib.Crypto.SHA512::SHA512`

Updates a value of `SHA512` by applying a function to field `hash`.

### `mod_msgbuf : (Std::Array Std::U8 -> Std::Array Std::U8) -> Minilib.Crypto.SHA512::SHA512 -> Minilib.Crypto.SHA512::SHA512`

Updates a value of `SHA512` by applying a function to field `msgbuf`.

### `mod_msglen : (Std::U64 -> Std::U64) -> Minilib.Crypto.SHA512::SHA512 -> Minilib.Crypto.SHA512::SHA512`

Updates a value of `SHA512` by applying a function to field `msglen`.

### `set_hash : Std::Array Std::U64 -> Minilib.Crypto.SHA512::SHA512 -> Minilib.Crypto.SHA512::SHA512`

Updates a value of `SHA512` by setting field `hash` to a specified one.

### `set_msgbuf : Std::Array Std::U8 -> Minilib.Crypto.SHA512::SHA512 -> Minilib.Crypto.SHA512::SHA512`

Updates a value of `SHA512` by setting field `msgbuf` to a specified one.

### `set_msglen : Std::U64 -> Minilib.Crypto.SHA512::SHA512 -> Minilib.Crypto.SHA512::SHA512`

Updates a value of `SHA512` by setting field `msglen` to a specified one.