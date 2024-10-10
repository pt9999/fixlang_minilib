# `module Minilib.Crypto.SHA1`

SHA-1 secure hash function.

Implemented from specification of FIPS PUB 180-4:
https://csrc.nist.gov/files/pubs/fips/180-4/final/docs/fips180-4.pdf

NOTE: FIPS 180-4 (2012) is superseded by FIPS 180-4 (2015), with the only change being
made in the Applicability Clause. There are no changes to the technical specifications.
FIPS 180-4 (2015):
http://dx.doi.org/10.6028/NIST.FIPS.180-4

# Types and aliases

## `namespace Minilib.Crypto.SHA1`

### `type SHA1 = unbox struct { ...fields... }`

SHA-1 hasher.
Usually it is sufficient to simply call `SHA1:digest(bytes)` without using this structure.

#### field `hash : Std::Array Std::U32`

#### field `msglen : Std::U64`

#### field `msgbuf : Std::Array Std::U8`

# Traits and aliases

# Trait implementations

# Values

## `namespace Minilib.Crypto.SHA1`

### `_bit_not : Std::U32 -> Std::U32`

2.2.2 Symbols and Operations
bitwise complement

### `_f : Std::I64 -> Std::U32 -> Std::U32 -> Std::U32 -> Std::U32`

4.1.1 SHA-1 Functions

### `_init_hash : Std::Array Std::U32`

5.3 Setting the Initial Hash Value (H(0))
5.3.1 SHA-1

### `_k : Std::I64 -> Std::U32`

4.2.1 SHA-1 Constants

### `_rotl : Std::U32 -> Std::U32 -> Std::U32`

rotate left

### `_rotr : Std::U32 -> Std::U32 -> Std::U32`

rotate right

### `_shr : Std::U32 -> Std::U32 -> Std::U32`

shift right

### `_update_hash : Std::Array Std::U32 -> Std::Array Std::U32 -> Std::Array Std::U32`

6.1.2 SHA-1 Hash Computation

### `_update_inner : Std::Array Std::U8 -> Std::U64 -> Minilib.Crypto.SHA1::SHA1 -> Minilib.Crypto.SHA1::SHA1`

`sha1._update_inner(input, msglen_inc)` updates the message buffer with input.
And it increments the message length by `msglen_inc`.
When the message buffer is full (64 bytes), it updates hash with the message
and clears the messsage buffer.

### `digest : Std::Array Std::U8 -> Std::Array Std::U8`

`SHA1::digest(bytes)` computes SHA-1 secure hash function of `bytes`.

### `empty : Minilib.Crypto.SHA1::SHA1`

An empty SHA-1 hasher.

### `finalize : Minilib.Crypto.SHA1::SHA1 -> Std::Array Std::U8`

`sha1.finalize` retrieves a final SHA-1 hash value.

### `update : Std::Array Std::U8 -> Minilib.Crypto.SHA1::SHA1 -> Minilib.Crypto.SHA1::SHA1`

`sha1.update(bytes)` processes `bytes`, and updates its internal state.

## `namespace Minilib.Crypto.SHA1::SHA1`

### `@hash : Minilib.Crypto.SHA1::SHA1 -> Std::Array Std::U32`

Retrieves the field `hash` from a value of `SHA1`.

### `@msgbuf : Minilib.Crypto.SHA1::SHA1 -> Std::Array Std::U8`

Retrieves the field `msgbuf` from a value of `SHA1`.

### `@msglen : Minilib.Crypto.SHA1::SHA1 -> Std::U64`

Retrieves the field `msglen` from a value of `SHA1`.

### `act_hash : [f : Std::Functor] (Std::Array Std::U32 -> f (Std::Array Std::U32)) -> Minilib.Crypto.SHA1::SHA1 -> f Minilib.Crypto.SHA1::SHA1`

Updates a value of `SHA1` by applying a functorial action to field `hash`.

### `act_msgbuf : [f : Std::Functor] (Std::Array Std::U8 -> f (Std::Array Std::U8)) -> Minilib.Crypto.SHA1::SHA1 -> f Minilib.Crypto.SHA1::SHA1`

Updates a value of `SHA1` by applying a functorial action to field `msgbuf`.

### `act_msglen : [f : Std::Functor] (Std::U64 -> f Std::U64) -> Minilib.Crypto.SHA1::SHA1 -> f Minilib.Crypto.SHA1::SHA1`

Updates a value of `SHA1` by applying a functorial action to field `msglen`.

### `mod_hash : (Std::Array Std::U32 -> Std::Array Std::U32) -> Minilib.Crypto.SHA1::SHA1 -> Minilib.Crypto.SHA1::SHA1`

Updates a value of `SHA1` by applying a function to field `hash`.

### `mod_msgbuf : (Std::Array Std::U8 -> Std::Array Std::U8) -> Minilib.Crypto.SHA1::SHA1 -> Minilib.Crypto.SHA1::SHA1`

Updates a value of `SHA1` by applying a function to field `msgbuf`.

### `mod_msglen : (Std::U64 -> Std::U64) -> Minilib.Crypto.SHA1::SHA1 -> Minilib.Crypto.SHA1::SHA1`

Updates a value of `SHA1` by applying a function to field `msglen`.

### `set_hash : Std::Array Std::U32 -> Minilib.Crypto.SHA1::SHA1 -> Minilib.Crypto.SHA1::SHA1`

Updates a value of `SHA1` by setting field `hash` to a specified one.

### `set_msgbuf : Std::Array Std::U8 -> Minilib.Crypto.SHA1::SHA1 -> Minilib.Crypto.SHA1::SHA1`

Updates a value of `SHA1` by setting field `msgbuf` to a specified one.

### `set_msglen : Std::U64 -> Minilib.Crypto.SHA1::SHA1 -> Minilib.Crypto.SHA1::SHA1`

Updates a value of `SHA1` by setting field `msglen` to a specified one.