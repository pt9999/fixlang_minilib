# bigint.fix

## module Minilib.Math.BigInt

Arbitrary-precision integer.

### namespace BigNat

### type BigInt

Arbitrary-precision integer.

```
type BigInt = unbox struct {
    sign: I64,          // sign
    nat: Array U32      // natural number (>= 0)
};
```
### namespace BigInt

#### make: I64 -> Array U32 -> BigInt;

`BigInt::make(sign, nat)` creates new BigInt object.

#### from_U64: U64 -> BigInt;

`BigInt::from_U64(u64)` creates new BigInt object from `u64`.

#### from_I64: I64 -> BigInt;

`BigInt::from_I64(i64)` creates new BigInt object from `i64`.

#### cmp: BigInt -> BigInt -> I64;

`BigInt::cmp(a,b)` returns 1 if `a > b`, -1 if `a < b`, 0 if `a == b`.

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

