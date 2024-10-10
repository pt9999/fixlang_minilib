# `module Minilib.Math.Modular`

This is an arithmetic with a modulus (modulo), for example `2 * 5 = 10 = 3 (mod 7)`.

For details, see [Wikipedia: Modular Arithmetic](https://en.wikipedia.org/wiki/Modular_arithmetic).

# Types and aliases

## `namespace Minilib.Math.Modular`

### `type Modular a = unbox struct { ...fields... }`

A type that performs Modular Arithmetic.

#### field `value : a`

#### field `modulus : a`

# Traits and aliases

# Trait implementations

### `impl [a : Minilib.Math.Types::Euclid] Minilib.Math.Modular::Modular a : Minilib.Math.Types::One`

### `impl [a : Minilib.Math.Types::Euclid] Minilib.Math.Modular::Modular a : Std::Add`

### `impl [a : Minilib.Math.Types::Euclid] Minilib.Math.Modular::Modular a : Std::Div`

### `impl [a : Minilib.Math.Types::Euclid] Minilib.Math.Modular::Modular a : Std::Eq`

### `impl [a : Minilib.Math.Types::Euclid] Minilib.Math.Modular::Modular a : Std::Mul`

### `impl [a : Minilib.Math.Types::Euclid] Minilib.Math.Modular::Modular a : Std::Neg`

### `impl [a : Minilib.Math.Types::Euclid] Minilib.Math.Modular::Modular a : Std::Sub`

### `impl [a : Std::ToString] Minilib.Math.Modular::Modular a : Std::ToString`

### `impl [a : Minilib.Math.Types::Euclid] Minilib.Math.Modular::Modular a : Std::Zero`

# Values

## `namespace Minilib.Math.Modular`

### `_get_modulus : [a : Minilib.Math.Types::Euclid] Minilib.Math.Modular::Modular a -> Minilib.Math.Modular::Modular a -> a`

Returns modulus of either `x` or `y`.

### `make : [a : Minilib.Math.Types::Euclid] a -> a -> Minilib.Math.Modular::Modular a`

`Modular::make(v, m)` creates `v modulo m`.
It is an equivalence class of a quotient ring `Z/mZ`.

### `modulo : [a : Minilib.Math.Types::Euclid] a -> a -> Minilib.Math.Modular::Modular a`

Synonym for `Modular::make`.

### `nonneg : [a : Minilib.Math.Types::Euclid, a : Std::LessThan] Minilib.Math.Modular::Modular a -> Minilib.Math.Modular::Modular a`

`x.nonneg` changes `@value` with a equivalent non-negative value.
For example, `modulo(-1, 3)` will be changed to `modulo(2,3)`
because `-1 == 2 mod 3`.

## `namespace Minilib.Math.Modular::Modular`

### `@modulus : Minilib.Math.Modular::Modular a -> a`

Retrieves the field `modulus` from a value of `Modular`.

### `@value : Minilib.Math.Modular::Modular a -> a`

Retrieves the field `value` from a value of `Modular`.

### `act_modulus : [f : Std::Functor] (a -> f a) -> Minilib.Math.Modular::Modular a -> f (Minilib.Math.Modular::Modular a)`

Updates a value of `Modular` by applying a functorial action to field `modulus`.

### `act_value : [f : Std::Functor] (a -> f a) -> Minilib.Math.Modular::Modular a -> f (Minilib.Math.Modular::Modular a)`

Updates a value of `Modular` by applying a functorial action to field `value`.

### `mod_modulus : (a -> a) -> Minilib.Math.Modular::Modular a -> Minilib.Math.Modular::Modular a`

Updates a value of `Modular` by applying a function to field `modulus`.

### `mod_value : (a -> a) -> Minilib.Math.Modular::Modular a -> Minilib.Math.Modular::Modular a`

Updates a value of `Modular` by applying a function to field `value`.

### `set_modulus : a -> Minilib.Math.Modular::Modular a -> Minilib.Math.Modular::Modular a`

Updates a value of `Modular` by setting field `modulus` to a specified one.

### `set_value : a -> Minilib.Math.Modular::Modular a -> Minilib.Math.Modular::Modular a`

Updates a value of `Modular` by setting field `value` to a specified one.