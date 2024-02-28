# modular.fix

## module Minilib.Math.Modular

This is an arithmetic with a modulus (modulo), for example `2 * 5 = 10 = 3 (mod 7)`.

For details, see [Wikipedia: Modular Arithmetic](https://en.wikipedia.org/wiki/Modular_arithmetic).

### type Modular

A type that performs Modular Arithmetic.

```
type Modular a = unbox struct {
    value: a,
    modulus: a          // zero if unknown
};
```
#### make: [a: Euclid] a -> a -> Modular a;

`Modular::make(v, m)` creates `v modulo m`.
It is an equivalence class of a quotient ring `Z/mZ`.

#### modulo: [a: Euclid] a -> a -> Modular a;

Synonym for `Modular::make`.

#### nonneg: [a: Euclid, a: LessThan] Modular a -> Modular a;

`x.nonneg` changes `@value` with a equivalent non-negative value.
For example, `modulo(-1, 3)` will be changed to `modulo(2,3)`
because `-1 == 2 mod 3`.

#### `impl [a: ToString] Modular a: ToString`

#### `impl [a: Euclid] Modular a: Eq`

#### `impl [a: Euclid] Modular a: Zero`

#### `impl [a: Euclid] Modular a: One`

#### `impl [a: Euclid] Modular a: Neg`

#### `impl [a: Euclid] Modular a: Add`

#### `impl [a: Euclid] Modular a: Sub`

#### `impl [a: Euclid] Modular a: Mul`

#### `impl [a: Euclid] Modular a: Div`

