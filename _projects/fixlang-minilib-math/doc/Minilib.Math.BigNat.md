# `module Minilib.Math.BigNat`

Arbitrary-precision natural number. This is internal module of BigInt.

# Types and aliases

# Traits and aliases

# Trait implementations

# Values

## `namespace Minilib.Math.BigNat`

### `_add : Std::Array Std::U32 -> Std::Array Std::U32 -> Std::Array Std::U32`

Calculates `a0 + a1`.

### `_add_with_offset1 : Std::Array Std::U32 -> (Std::Array Std::U32, Std::I64) -> Std::Array Std::U32`

Calculates `a0 + a1 * _base ^ offset1`.

### `_base : Std::U64`

The base of BigNat. It must be power of 2.

### `_bit_length : Std::Array Std::U32 -> Std::U64`

Returns the bit length of `a`, ie. one plus the bit position of most significant `1`.
Returns 0 if `a` is zero.

### `_cmp : (Std::Array Std::U32, Std::I64) -> (Std::Array Std::U32, Std::I64) -> Std::I64`

Calculates `sign(a0 * _base ^ offset0 - a1 * _base ^ offset1)`.

### `_divmod : Std::Array Std::U32 -> Std::Array Std::U32 -> (Std::Array Std::U32, Std::Array Std::U32)`

Calculates `(a0 / a1, a0 % a1)`.
Aborts if any error occured.

### `_divmod_base : Std::U64 -> (Std::U64, Std::U64)`

divmod by _base.

### `_divmod_by_power_of_two : Std::Array Std::U32 -> Std::U64 -> (Std::Array Std::U32, Std::Array Std::U32)`

Calculates `(a0 / 2 ^ exp, a0 % 2 ^ exp)`.
Aborts if any error occured.

### `_divmod_by_two : Std::Array Std::U32 -> (Std::Array Std::U32, Std::Array Std::U32)`

Calculates `(a0 / 2, a0 % 2)`.
Aborts if any error occured.

### `_divmod_log2_base : Std::U64 -> (Std::U64, Std::U64)`

divmod by _log2_base.

### `_divmod_u32 : Std::Array Std::U32 -> Std::U32 -> (Std::Array Std::U32, Std::U32)`

Calculates `(a0 / d1, a0 % d1)`.

### `_dummy : ()`

### `_from_string_inner : Std::Array Std::U8 -> Std::I64 -> Std::Array Std::U32 -> Std::Result Std::String (Std::Array Std::U32)`

FromString of BigNat.

### `_from_u64 : Std::U64 -> Std::Array Std::U32`

Converts U64 to BigNat.

### `_generate_bignat : Std::I64 -> Random::Random -> (Random::Random, Std::Array Std::U32)`

### `_generate_bignat_range : Std::Array Std::U32 -> Std::Array Std::U32 -> Random::Random -> (Random::Random, Std::Array Std::U32)`

### `_is_zero : Std::Array Std::U32 -> Std::Bool`

Returns true if BigNat is zero.

### `_log2_base : Std::U64`

log2 of base. It must be power of 2 and `0 <= _log2_base <= 32`.

### `_log2_log2_base : Std::U64`

log2(log2(base)). It must be `0 <= _log2_log2_base <= 5`.

### `_mul : Std::Array Std::U32 -> Std::Array Std::U32 -> Std::Array Std::U32`

Calculates `a0 * a1`.

### `_mul_u32 : Std::U32 -> Std::Array Std::U32 -> Std::Array Std::U32`

Calculates `d0 * a1`.

### `_neg : Std::Array Std::U32 -> Std::Array Std::U32`

Treats `a` as a negative number in two's complement representation and reverses its sign.

### `_one : Std::Array Std::U32`

1 in BigNat.

### `_pow_by_U64 : Std::Array Std::U32 -> Std::U64 -> Std::Array Std::U32`

Calculates `a^n`.

### `_remove_last_zeros : Std::Array Std::U32 -> Std::Array Std::U32`

Removes trailing zeros.

### `_shift_left : Std::U64 -> Std::Array Std::U32 -> Std::Array Std::U32`

### `_shift_right : Std::U64 -> Std::Array Std::U32 -> Std::Array Std::U32`

### `_signed_sub_with_offset : (Std::Array Std::U32, Std::I64) -> (Std::Array Std::U32, Std::I64) -> ((Std::Array Std::U32, Std::I64), Std::I64)`

Calculates `a0 * pow(_base, offset0) - a1 * pow(_base, offset1)`.
returns the result and the sign.

### `_sub : Std::Array Std::U32 -> Std::Array Std::U32 -> Std::Array Std::U32`

Calculates `a0 - a1`.
Aborts if the result is negative.

### `_to_string : Std::Array Std::U32 -> Std::String`

ToString of BigNat.

### `_to_string_hex : Std::Array Std::U32 -> Std::String`

### `_to_string_inner : Std::Array Std::U32 -> Std::Iterator Std::U8 -> Std::Iterator Std::U8`

### `_to_u64 : Std::Array Std::U32 -> Std::U64`

Converts BigNat to U64. If overflow, it produces unexpected result.

### `_two : Std::Array Std::U32`

2 in BigNat.

### `_zero : Std::Array Std::U32`

0 in BigNat.