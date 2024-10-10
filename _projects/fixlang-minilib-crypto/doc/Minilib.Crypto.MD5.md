# `module Minilib.Crypto.MD5`

MD5 secure hash function.

Implemented from specification of RFC 1321:
https://www.rfc-editor.org/rfc/rfc1321.txt

# Types and aliases

## `namespace Minilib.Crypto.MD5`

### `type MD5 = unbox struct { ...fields... }`

MD5 hasher.
Usually it is sufficient to simply call `MD5:digest(bytes)` without using this structure.

#### field `hash : Std::Array Std::U32`

#### field `msglen : Std::U64`

#### field `msgbuf : Std::Array Std::U8`

# Traits and aliases

# Trait implementations

# Values

## `namespace Minilib.Crypto.MD5`

### `_bit_not : Std::U32 -> Std::U32`

bitwise complement

### `_f : Std::U32 -> Std::U32 -> Std::U32 -> Std::U32`

3.4 Step 4. Process Message in 16-Word Blocks

### `_g : Std::U32 -> Std::U32 -> Std::U32 -> Std::U32`

### `_h : Std::U32 -> Std::U32 -> Std::U32 -> Std::U32`

### `_i : Std::U32 -> Std::U32 -> Std::U32 -> Std::U32`

### `_init_hash : Std::Array Std::U32`

3.3 Step 3. Initialize MD Buffer

### `_rotl : Std::U32 -> Std::U32 -> Std::U32`

rotate left

### `_t : Std::Array Std::U32`

### `_update_hash : Std::Array Std::U32 -> Std::Array Std::U32 -> Std::Array Std::U32`

3.4 Step 4. Process Message in 16-Word Blocks

### `_update_inner : Std::Array Std::U8 -> Std::U64 -> Minilib.Crypto.MD5::MD5 -> Minilib.Crypto.MD5::MD5`

`md5._update_inner(input, msglen_inc)` updates the message buffer with input.
And it increments the message length by `msglen_inc`.
When the message buffer is full (64 bytes), it updates hash with the message
and clears the messsage buffer.

### `digest : Std::Array Std::U8 -> Std::Array Std::U8`

`MD5::digest(bytes)` computes MD5 secure hash function of `bytes`.

### `empty : Minilib.Crypto.MD5::MD5`

An empty MD5 hasher.

### `finalize : Minilib.Crypto.MD5::MD5 -> Std::Array Std::U8`

`md5.finalize` retrieves a final MD5 hash value.

### `update : Std::Array Std::U8 -> Minilib.Crypto.MD5::MD5 -> Minilib.Crypto.MD5::MD5`

`md5.update(bytes)` processes `bytes`, and updates its internal state.

## `namespace Minilib.Crypto.MD5::MD5`

### `@hash : Minilib.Crypto.MD5::MD5 -> Std::Array Std::U32`

Retrieves the field `hash` from a value of `MD5`.

### `@msgbuf : Minilib.Crypto.MD5::MD5 -> Std::Array Std::U8`

Retrieves the field `msgbuf` from a value of `MD5`.

### `@msglen : Minilib.Crypto.MD5::MD5 -> Std::U64`

Retrieves the field `msglen` from a value of `MD5`.

### `act_hash : [f : Std::Functor] (Std::Array Std::U32 -> f (Std::Array Std::U32)) -> Minilib.Crypto.MD5::MD5 -> f Minilib.Crypto.MD5::MD5`

Updates a value of `MD5` by applying a functorial action to field `hash`.

### `act_msgbuf : [f : Std::Functor] (Std::Array Std::U8 -> f (Std::Array Std::U8)) -> Minilib.Crypto.MD5::MD5 -> f Minilib.Crypto.MD5::MD5`

Updates a value of `MD5` by applying a functorial action to field `msgbuf`.

### `act_msglen : [f : Std::Functor] (Std::U64 -> f Std::U64) -> Minilib.Crypto.MD5::MD5 -> f Minilib.Crypto.MD5::MD5`

Updates a value of `MD5` by applying a functorial action to field `msglen`.

### `mod_hash : (Std::Array Std::U32 -> Std::Array Std::U32) -> Minilib.Crypto.MD5::MD5 -> Minilib.Crypto.MD5::MD5`

Updates a value of `MD5` by applying a function to field `hash`.

### `mod_msgbuf : (Std::Array Std::U8 -> Std::Array Std::U8) -> Minilib.Crypto.MD5::MD5 -> Minilib.Crypto.MD5::MD5`

Updates a value of `MD5` by applying a function to field `msgbuf`.

### `mod_msglen : (Std::U64 -> Std::U64) -> Minilib.Crypto.MD5::MD5 -> Minilib.Crypto.MD5::MD5`

Updates a value of `MD5` by applying a function to field `msglen`.

### `set_hash : Std::Array Std::U32 -> Minilib.Crypto.MD5::MD5 -> Minilib.Crypto.MD5::MD5`

Updates a value of `MD5` by setting field `hash` to a specified one.

### `set_msgbuf : Std::Array Std::U8 -> Minilib.Crypto.MD5::MD5 -> Minilib.Crypto.MD5::MD5`

Updates a value of `MD5` by setting field `msgbuf` to a specified one.

### `set_msglen : Std::U64 -> Minilib.Crypto.MD5::MD5 -> Minilib.Crypto.MD5::MD5`

Updates a value of `MD5` by setting field `msglen` to a specified one.