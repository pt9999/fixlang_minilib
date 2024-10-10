# `module Minilib.Math.BigFloat`

Arbitrary-precision floating point number.

A BigFloat is composed from a mantissa and the exponent of base 2.

Each BigFloat has a precision. It is same as the precision of the mantissa,
and determined by the length of the underlying array (= BigNat).

The precision of a BigNat can be changed with `set_prec()`.

For unary operator such as `-a`, the precision of the result is the same as the precision of the operand.

For binary operator such as `a + b`, `a - b`, `a * b`, `a / b`, the precision of the result is the maximum precision of the two operands.

# Types and aliases

## `namespace Minilib.Math.BigFloat`

### `type BigFloat = unbox struct { ...fields... }`

Arbitrary-precision floating point number.
It is interpreted as `mantissa * 2 ^ exponent`.

#### field `int : Minilib.Math.BigInt::BigInt`

#### field `exp : Std::I64`

# Traits and aliases

# Trait implementations

### `impl Minilib.Math.BigFloat::BigFloat : Minilib.Math.Types::One`

### `impl Minilib.Math.BigFloat::BigFloat : Std::Add`

### `impl Minilib.Math.BigFloat::BigFloat : Std::Div`

### `impl Minilib.Math.BigFloat::BigFloat : Std::Eq`

### `impl Minilib.Math.BigFloat::BigFloat : Std::FromString`

### `impl Minilib.Math.BigFloat::BigFloat : Std::LessThan`

### `impl Minilib.Math.BigFloat::BigFloat : Std::LessThanOrEq`

### `impl Minilib.Math.BigFloat::BigFloat : Std::Mul`

### `impl Minilib.Math.BigFloat::BigFloat : Std::Neg`

### `impl Minilib.Math.BigFloat::BigFloat : Std::Sub`

### `impl Minilib.Math.BigFloat::BigFloat : Std::ToString`

### `impl Minilib.Math.BigFloat::BigFloat : Std::Zero`

# Values

## `namespace Minilib.Math.BigFloat`

### `_approx_log2 : Minilib.Math.BigFloat::BigFloat -> Std::I64`

Calculates approximation of `log2(a.abs)`.

### `_from_string : Std::String -> Std::Result Std::String Minilib.Math.BigFloat::BigFloat`

### `_get_num_frac_digits : Minilib.Math.BigFloat::BigFloat -> Std::I64`

get the preferred number of fractional digits (not same as a.get_prec10).

### `_maximize_precision : Minilib.Math.BigFloat::BigFloat -> Minilib.Math.BigFloat::BigFloat`

Move the topmost 1 to MSB

### `_one : Minilib.Math.BigFloat::BigFloat`

### `_sqrt_inner : Minilib.Math.BigFloat::BigFloat -> Minilib.Math.BigFloat::BigFloat -> Std::I64 -> Minilib.Math.BigFloat::BigFloat`

Returns the square root of `a` using Newton-Raphson method.

### `_ten : Minilib.Math.BigFloat::BigFloat`

### `_to_string_exp_precision : Std::Option Std::I64 -> Minilib.Math.BigFloat::BigFloat -> Std::String`

### `_to_string_rep : Minilib.Math.BigFloat::BigFloat -> Std::String`

Convert a BigFloat to a string of internal representation.

### `_zero : Minilib.Math.BigFloat::BigFloat`

### `abs : Minilib.Math.BigFloat::BigFloat -> Minilib.Math.BigFloat::BigFloat`

Returns the absolute value of `a`.

### `epsilon : Minilib.Math.BigFloat::BigFloat -> Minilib.Math.BigFloat::BigFloat`

Gets a BigInt that represents the smallest change in the mantissa of this BigInt.

### `from_F64 : Std::F64 -> Minilib.Math.BigFloat::BigFloat`

Converts F64 to BigFloat.

### `get_prec : Minilib.Math.BigFloat::BigFloat -> Std::I64`

Gets the precision of a BigFloat in base 2. It is multiple of 32.

### `get_prec10 : Minilib.Math.BigFloat::BigFloat -> Std::I64`

Gets the precision of a BigFloat in base 10.
It calls `get_prec()` and converts the precision from base 2.

### `is_negative : Minilib.Math.BigFloat::BigFloat -> Std::Bool`

Returns true iff the BigFloat is negative.

### `is_positive : Minilib.Math.BigFloat::BigFloat -> Std::Bool`

Returns true iff the BigFloat is positive.

### `is_zero : Minilib.Math.BigFloat::BigFloat -> Std::Bool`

Returns true iff the BigFloat is zero.

### `make : Minilib.Math.BigInt::BigInt -> Std::I64 -> Minilib.Math.BigFloat::BigFloat`

Creates a BigFloat from a BigInt and the exponent of base 2.

### `mul_pow2 : Std::I64 -> Minilib.Math.BigFloat::BigFloat -> Minilib.Math.BigFloat::BigFloat`

Calculates `a * 2^e`.

### `pow_by_U64 : Std::U64 -> Minilib.Math.BigFloat::BigFloat -> Minilib.Math.BigFloat::BigFloat`

Calculates `a^n`.

### `set_prec : Std::I64 -> Minilib.Math.BigFloat::BigFloat -> Minilib.Math.BigFloat::BigFloat`

Set the precision of a BigFloat in base2.
The precision is round-up to multiple of 32, except if `prec == 0` then the precision is set to 32.

### `set_prec10 : Std::I64 -> Minilib.Math.BigFloat::BigFloat -> Minilib.Math.BigFloat::BigFloat`

Sets the precision of a BigFloat in base 10.
It calls `set_prec()` after converting the precision to base 2.

### `sqrt : Minilib.Math.BigFloat::BigFloat -> Minilib.Math.BigFloat::BigFloat`

Returns the square root of `a`.

### `to_F64 : Minilib.Math.BigFloat::BigFloat -> Std::F64`

Converts BigFloat to F64. If BigFloat is out of range of F64, unexpected result is returned.

### `to_string_exp : Minilib.Math.BigFloat::BigFloat -> Std::String`

Convert a BigFloat to a string of exponential form.

### `to_string_exp_precision : Std::I64 -> Minilib.Math.BigFloat::BigFloat -> Std::String`

Convert a BigFloat to a string of exponential form with specified precision (i.e., number of digits after the decimal point).

### `to_string_precision : Std::I64 -> Minilib.Math.BigFloat::BigFloat -> Std::String`

Convert a BigFloat to a string with specified precision (i.e., number of digits after the decimal point).

## `namespace Minilib.Math.BigFloat::BigFloat`

### `@exp : Minilib.Math.BigFloat::BigFloat -> Std::I64`

Retrieves the field `exp` from a value of `BigFloat`.

### `@int : Minilib.Math.BigFloat::BigFloat -> Minilib.Math.BigInt::BigInt`

Retrieves the field `int` from a value of `BigFloat`.

### `act_exp : [f : Std::Functor] (Std::I64 -> f Std::I64) -> Minilib.Math.BigFloat::BigFloat -> f Minilib.Math.BigFloat::BigFloat`

Updates a value of `BigFloat` by applying a functorial action to field `exp`.

### `act_int : [f : Std::Functor] (Minilib.Math.BigInt::BigInt -> f Minilib.Math.BigInt::BigInt) -> Minilib.Math.BigFloat::BigFloat -> f Minilib.Math.BigFloat::BigFloat`

Updates a value of `BigFloat` by applying a functorial action to field `int`.

### `mod_exp : (Std::I64 -> Std::I64) -> Minilib.Math.BigFloat::BigFloat -> Minilib.Math.BigFloat::BigFloat`

Updates a value of `BigFloat` by applying a function to field `exp`.

### `mod_int : (Minilib.Math.BigInt::BigInt -> Minilib.Math.BigInt::BigInt) -> Minilib.Math.BigFloat::BigFloat -> Minilib.Math.BigFloat::BigFloat`

Updates a value of `BigFloat` by applying a function to field `int`.

### `set_exp : Std::I64 -> Minilib.Math.BigFloat::BigFloat -> Minilib.Math.BigFloat::BigFloat`

Updates a value of `BigFloat` by setting field `exp` to a specified one.

### `set_int : Minilib.Math.BigInt::BigInt -> Minilib.Math.BigFloat::BigFloat -> Minilib.Math.BigFloat::BigFloat`

Updates a value of `BigFloat` by setting field `int` to a specified one.