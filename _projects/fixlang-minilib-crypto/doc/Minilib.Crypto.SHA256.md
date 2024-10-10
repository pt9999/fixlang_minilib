# `module Minilib.Crypto.SHA256`

SHA-256 secure hash function.

Implemented from specification of FIPS PUB 180-4:
https://csrc.nist.gov/files/pubs/fips/180-4/final/docs/fips180-4.pdf

NOTE: FIPS 180-4 (2012) is superseded by FIPS 180-4 (2015), with the only change being
made in the Applicability Clause. There are no changes to the technical specifications.
FIPS 180-4 (2015):
http://dx.doi.org/10.6028/NIST.FIPS.180-4

# Types and aliases

## `namespace Minilib.Crypto.SHA256`

### `type SHA256 = unbox struct { ...fields... }`

SHA-256 hasher.
Usually it is sufficient to simply call `SHA256:digest(bytes)` without using this structure.

#### field `hash : Std::Array Std::U32`

#### field `msglen : Std::U64`

#### field `msgbuf : Std::Array Std::U8`

# Traits and aliases

# Trait implementations

# Values

## `namespace Minilib.Crypto.SHA256`

### `_bit_not : Std::U32 -> Std::U32`

2.2.2 Symbols and Operations
bitwise complement

### `_ch : Std::U32 -> Std::U32 -> Std::U32 -> Std::U32`

4.1.2 SHA-224 and SHA-256 Functions

### `_init_hash : Std::Array Std::U32`

5.3 Setting the Initial Hash Value (H(0))
5.3.3 SHA-256

### `_k : Std::Array Std::U32`

### `_large_sigma_0 : Std::U32 -> Std::U32`

### `_large_sigma_1 : Std::U32 -> Std::U32`

### `_maj : Std::U32 -> Std::U32 -> Std::U32 -> Std::U32`

### `_rotl : Std::U32 -> Std::U32 -> Std::U32`

rotate left

### `_rotr : Std::U32 -> Std::U32 -> Std::U32`

rotate right

### `_shr : Std::U32 -> Std::U32 -> Std::U32`

shift right

### `_small_sigma_0 : Std::U32 -> Std::U32`

### `_small_sigma_1 : Std::U32 -> Std::U32`

### `_update_hash : Std::Array Std::U32 -> Std::Array Std::U32 -> Std::Array Std::U32`

6.2.2 SHA-256 Hash Computation

### `_update_inner : Std::Array Std::U8 -> Std::U64 -> Minilib.Crypto.SHA256::SHA256 -> Minilib.Crypto.SHA256::SHA256`

`sha256._update_inner(input, msglen_inc)` updates the message buffer with input.
And it increments the message length by `msglen_inc`.
When the message buffer is full (64 bytes), it updates hash with the message
and clears the messsage buffer.

### `digest : Std::Array Std::U8 -> Std::Array Std::U8`

`SHA256::digest(bytes)` computes SHA-256 secure hash function of `bytes`.

### `empty : Minilib.Crypto.SHA256::SHA256`

An empty SHA-256 hasher.

### `finalize : Minilib.Crypto.SHA256::SHA256 -> Std::Array Std::U8`

`sha256.finalize` retrieves a final SHA-256 hash value.

### `update : Std::Array Std::U8 -> Minilib.Crypto.SHA256::SHA256 -> Minilib.Crypto.SHA256::SHA256`

`sha256.update(bytes)` processes `bytes`, and updates its internal state.

## `namespace Minilib.Crypto.SHA256::SHA256`

### `@hash : Minilib.Crypto.SHA256::SHA256 -> Std::Array Std::U32`

Retrieves the field `hash` from a value of `SHA256`.

### `@msgbuf : Minilib.Crypto.SHA256::SHA256 -> Std::Array Std::U8`

Retrieves the field `msgbuf` from a value of `SHA256`.

### `@msglen : Minilib.Crypto.SHA256::SHA256 -> Std::U64`

Retrieves the field `msglen` from a value of `SHA256`.

### `act_hash : [f : Std::Functor] (Std::Array Std::U32 -> f (Std::Array Std::U32)) -> Minilib.Crypto.SHA256::SHA256 -> f Minilib.Crypto.SHA256::SHA256`

Updates a value of `SHA256` by applying a functorial action to field `hash`.

### `act_msgbuf : [f : Std::Functor] (Std::Array Std::U8 -> f (Std::Array Std::U8)) -> Minilib.Crypto.SHA256::SHA256 -> f Minilib.Crypto.SHA256::SHA256`

Updates a value of `SHA256` by applying a functorial action to field `msgbuf`.

### `act_msglen : [f : Std::Functor] (Std::U64 -> f Std::U64) -> Minilib.Crypto.SHA256::SHA256 -> f Minilib.Crypto.SHA256::SHA256`

Updates a value of `SHA256` by applying a functorial action to field `msglen`.

### `mod_hash : (Std::Array Std::U32 -> Std::Array Std::U32) -> Minilib.Crypto.SHA256::SHA256 -> Minilib.Crypto.SHA256::SHA256`

Updates a value of `SHA256` by applying a function to field `hash`.

### `mod_msgbuf : (Std::Array Std::U8 -> Std::Array Std::U8) -> Minilib.Crypto.SHA256::SHA256 -> Minilib.Crypto.SHA256::SHA256`

Updates a value of `SHA256` by applying a function to field `msgbuf`.

### `mod_msglen : (Std::U64 -> Std::U64) -> Minilib.Crypto.SHA256::SHA256 -> Minilib.Crypto.SHA256::SHA256`

Updates a value of `SHA256` by applying a function to field `msglen`.

### `set_hash : Std::Array Std::U32 -> Minilib.Crypto.SHA256::SHA256 -> Minilib.Crypto.SHA256::SHA256`

Updates a value of `SHA256` by setting field `hash` to a specified one.

### `set_msgbuf : Std::Array Std::U8 -> Minilib.Crypto.SHA256::SHA256 -> Minilib.Crypto.SHA256::SHA256`

Updates a value of `SHA256` by setting field `msgbuf` to a specified one.

### `set_msglen : Std::U64 -> Minilib.Crypto.SHA256::SHA256 -> Minilib.Crypto.SHA256::SHA256`

Updates a value of `SHA256` by setting field `msglen` to a specified one.