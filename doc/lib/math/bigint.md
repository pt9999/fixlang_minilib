# bigint.fix

## module Minilib.Math.BigInt

Arbitrary-precision integer.

### type BigInt

Arbitrary-precision integer.

```
type BigInt = unbox struct {
    sign: I64,          // sign
    nat: Array U32      // natural number (>= 0)
};
```
#### make: I64 -> Array U32 -> BigInt;

`BigInt::make(sign, nat)` creates new BigInt object.

#### abs: BigInt -> BigInt;

`a.abs` returns the absolute value of `a`.

#### from_U64: U64 -> BigInt;

`BigInt::from_U64(u64)` creates new BigInt object from `u64`.

#### from_I64: I64 -> BigInt;

`BigInt::from_I64(i64)` creates new BigInt object from `i64`.

#### to_I64: BigInt -> I64;

Converts BigInt to I64. If overflow, it produces unexpected result.

#### cmp: BigInt -> BigInt -> I64;

`BigInt::cmp(a,b)` returns 1 if `a > b`, -1 if `a < b`, 0 if `a == b`.

#### divmod: BigInt -> BigInt -> (BigInt, BigInt);

`BigInt::divmod(a,b)` returns `(a/b, a%b)`.
NOTE: -8 / 3 == -2 and -8 % 3 == -2, as with the Fix language.

#### divmod_by_two: BigInt -> (BigInt, BigInt);

`BigInt::divmod_by_two(a)` returns `(a/2, a%2)`.

#### one: BigInt;

BigInt constant representing 1.

#### two: BigInt;

BigInt constant representing 2.

#### is_zero: BigInt -> Bool;

`a.is_zero` returns true iff `a` is zero.

#### is_positive: BigInt -> Bool;

`a.is_positive` returns true iff `a` is a positive number.

#### is_negative: BigInt -> Bool;

`a.is_negative` returns true iff `a` is a negative number.

#### is_even: BigInt -> Bool;

`a.is_even` returns true iff `a` is an even number.

#### is_odd: BigInt -> Bool;

`a.is_odd` returns true iff `a` is an odd number.

#### `impl BigInt: FromString`

Converts BigInt from a decimal string.

#### `impl BigInt: ToString`

Converts BigInt to a decimal string.

#### `impl BigInt: Eq`

Checks two BigInts are equal.

#### `impl BigInt: LessThan`

Compares two BigInts.

#### `impl BigInt: LessThanOrEq`

Compares two BigInts.

#### `impl BigInt: Zero`

#### `impl BigInt: Neg`

#### `impl BigInt: Add`

#### `impl BigInt: Sub`

#### `impl BigInt: Mul`

#### `impl BigInt: Div`

NOTE: -8 / 3 == -2, as with the Fix language.

#### `impl BigInt: Rem`

NOTE: -8 % 3 == -2, as with the Fix language.

