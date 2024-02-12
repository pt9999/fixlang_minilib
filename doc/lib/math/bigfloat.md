# bigfloat.fix

## module Minilib.Math.BigFloat

Arbitrary-precision floating point number.

A BigFloat is composed from a mantissa and the exponent of base 2.

Each BigFloat has a precision. It is same as the precision of the mantissa,
and determined by the length of the underlying array (= BigNat).

The precision of a BigNat can be changed with `set_prec()`.

For unary operator such as `-a`, the precision of the result is the same as the precision of the operand.

For binary operator such as `a + b`, `a - b`, `a * b`, `a / b`, the precision of the result is the maximum precision of the two operands.


### type BigFloat

Arbitrary-precision floating point number.
It is interpreted as `mantissa * 2 ^ exponent`.

```
type BigFloat = unbox struct {
    int: BigInt,        // the mantissa
                        // NOTE: @int.@nat might have trailing zeros.
    exp: I64            // the exponent of base 2
};
```
#### make: BigInt -> I64 -> BigFloat;

Creates a BigFloat from a BigInt and the exponent of base 2.

#### is_zero: BigFloat -> Bool;

Returns true iff the BigFloat is zero.

#### is_positive: BigFloat -> Bool;

Returns true iff the BigFloat is positive.

#### is_negative: BigFloat -> Bool;

Returns true iff the BigFloat is negative.

#### from_F64: F64 -> BigFloat;

Converts F64 to BigFloat.

#### to_F64: BigFloat -> F64;

Converts BigFloat to F64. If BigFloat is out of range of F64, unexpected result is returned.

#### get_prec10: BigFloat -> I64;

Gets the precision of a BigFloat in base 10.
It calls `get_prec()` and converts the precision from base 2.

#### get_prec: BigFloat -> I64;

Gets the precision of a BigFloat in base 2. It is multiple of 32.

#### set_prec10: I64 -> BigFloat -> BigFloat;

Sets the precision of a BigFloat in base 10.
It calls `set_prec()` after converting the precision to base 2.

#### set_prec: I64 -> BigFloat -> BigFloat;

Set the precision of a BigFloat in base2.
The precision is round-up to multiple of 32, except if `prec == 0` then the precision is set to 32.

#### epsilon: BigFloat -> BigFloat;

Gets a BigInt that represents the smallest change in the mantissa of this BigInt.

#### mul_pow2: I64 -> BigFloat -> BigFloat;

Calculates `a * 2^e`.

#### abs: BigFloat -> BigFloat;

Returns the absolute value of `a`.

#### sqrt: BigFloat -> BigFloat;

Returns the square root of `a`.

#### pow_by_U64: U64 -> BigFloat -> BigFloat;

Calculates `a^n`.

#### to_string_precision: I64 -> BigFloat -> String;

Convert a BigFloat to a string with specified precision (i.e., number of digits after the decimal point).

#### to_string_exp: BigFloat -> String;

Convert a BigFloat to a string of exponential form.

#### to_string_exp_precision: I64 -> BigFloat -> String;

Convert a BigFloat to a string of exponential form with specified precision (i.e., number of digits after the decimal point).

#### `impl BigFloat: FromString`

#### `impl BigFloat: ToString`

#### `impl BigFloat: Eq`

#### `impl BigFloat: LessThan`

#### `impl BigFloat: LessThanOrEq`

#### `impl BigFloat: Zero`

#### `impl BigFloat: Neg`

#### `impl BigFloat: Add`

#### `impl BigFloat: Sub`

#### `impl BigFloat: Mul`

#### `impl BigFloat: Div`

