# `module Minilib.Math.Polynomial`

Polynomial of one variable, for example `x^2 + 2x + 1`. The coefficients can be any ring.

# Types and aliases

## `namespace Minilib.Math.Polynomial`

### `type Polynomial a = unbox struct { ...fields... }`

A structure that represents a polynomial over a ring.
The coefficient array is ascending order of degree.
For example, `[1,2,3]` means a polynomial `3x^2 + 2x + 1`.

#### field `coeff : Std::Array a`

# Traits and aliases

# Trait implementations

### `impl [a : Minilib.Math.Types::Ring] Minilib.Math.Polynomial::Polynomial a : Minilib.Math.Types::One`

### `impl [a : Minilib.Math.Types::Ring] Minilib.Math.Polynomial::Polynomial a : Std::Add`

### `impl [a : Minilib.Math.Types::Field] Minilib.Math.Polynomial::Polynomial a : Std::Div`

### `impl [a : Minilib.Math.Types::Ring] Minilib.Math.Polynomial::Polynomial a : Std::Eq`

### `impl [a : Minilib.Math.Types::Ring] Minilib.Math.Polynomial::Polynomial a : Std::Mul`

### `impl [a : Minilib.Math.Types::Ring] Minilib.Math.Polynomial::Polynomial a : Std::Neg`

### `impl [a : Minilib.Math.Types::Field] Minilib.Math.Polynomial::Polynomial a : Std::Rem`

### `impl [a : Minilib.Math.Types::Ring] Minilib.Math.Polynomial::Polynomial a : Std::Sub`

### `impl [a : Minilib.Math.Types::Ring, a : Std::ToString] Minilib.Math.Polynomial::Polynomial a : Std::ToString`

### `impl [a : Minilib.Math.Types::Ring] Minilib.Math.Polynomial::Polynomial a : Std::Zero`

# Values

## `namespace Minilib.Math.Polynomial`

### `_to_string_full : [a : Minilib.Math.Types::Ring, a : Std::ToString] Minilib.Math.Polynomial::Polynomial a -> Std::String`

Converts a polynomial to a string without simplification.

### `_to_string_simple : [a : Minilib.Math.Types::Ring, a : Std::ToString] Minilib.Math.Polynomial::Polynomial a -> Std::String`

Converts a polynomial to a string with simplification.

### `at_degree : [a : Minilib.Math.Types::Ring] Std::I64 -> a -> Minilib.Math.Polynomial::Polynomial a`

`a.at_degree(n)` creates a polynomial `a * x ^ n`.

### `divmod : [a : Minilib.Math.Types::Field] Minilib.Math.Polynomial::Polynomial a -> Minilib.Math.Polynomial::Polynomial a -> (Minilib.Math.Polynomial::Polynomial a, Minilib.Math.Polynomial::Polynomial a)`

`divmod(num, den)` calculates a quotient `quo = num / den`
and a reminder `rem = num % den`.
Returns `(quo, rem)`.
The type of coefficients must be a field.
If the division of the field does not fulfill the requirement
(ie. `forall a b, a == a / b * b`),
this function may return an incorrect result.

### `generate : Std::I64 -> Std::I64 -> Std::Iterator (Minilib.Math.Polynomial::Polynomial (Minilib.Math.Modular::Modular Std::I64))`

`generate(p,m)` generates polynomials of degree `m` or lower in GF(p).

### `generate_primitive_polynomials : Std::I64 -> Std::I64 -> Std::Iterator (Minilib.Math.Polynomial::Polynomial (Minilib.Math.Modular::Modular Std::I64))`

`generate_primitive_polynomials(p, m)` generates primitive polynomials of degree `m` in GF(p).

### `get : [a : Minilib.Math.Types::Ring] Std::I64 -> Minilib.Math.Polynomial::Polynomial a -> a`

`f.get(i)` returns the coefficient of degree `i`.

### `get_degree : Minilib.Math.Polynomial::Polynomial a -> Std::I64`

`f.get_degree` returns the degree of a polynomial `f`.

### `is_primitive : Minilib.Math.Polynomial::Polynomial (Minilib.Math.Modular::Modular Std::I64) -> Std::Bool`

Checks whether it is a primitive polynomial.

### `make : [a : Minilib.Math.Types::Ring] Std::Array a -> Minilib.Math.Polynomial::Polynomial a`

`Polynomial::make(coeff)` creates a polynomial from coefficients.
For example, `Polynomial::make([1,2,3])` makes a polynomial `3x^2 + 2x + 1`.
For polynomials with degree greater than zero, the coefficient array is
truncated so that the coefficient of highest degree is not zero.

### `polynomial : [a : Minilib.Math.Types::Ring] Std::Array a -> Minilib.Math.Polynomial::Polynomial a`

Synonym for `Polynomial::make`.

### `set : [a : Minilib.Math.Types::Ring] Std::I64 -> a -> Minilib.Math.Polynomial::Polynomial a -> Minilib.Math.Polynomial::Polynomial a`

`f.set(i, a)` sets the coefficient of degree `i`.

### `subst : Std::I64 -> Minilib.Math.Polynomial::Polynomial (Minilib.Math.Modular::Modular Std::I64) -> Std::I64`

`f.subst(x)` substitutes the indeterminate of a polynomial with `x`.

## `namespace Minilib.Math.Polynomial::Polynomial`

### `@coeff : Minilib.Math.Polynomial::Polynomial a -> Std::Array a`

Retrieves the field `coeff` from a value of `Polynomial`.

### `act_coeff : [f : Std::Functor] (Std::Array a -> f (Std::Array a)) -> Minilib.Math.Polynomial::Polynomial a -> f (Minilib.Math.Polynomial::Polynomial a)`

Updates a value of `Polynomial` by applying a functorial action to field `coeff`.

### `mod_coeff : (Std::Array a -> Std::Array a) -> Minilib.Math.Polynomial::Polynomial a -> Minilib.Math.Polynomial::Polynomial a`

Updates a value of `Polynomial` by applying a function to field `coeff`.

### `set_coeff : Std::Array a -> Minilib.Math.Polynomial::Polynomial a -> Minilib.Math.Polynomial::Polynomial a`

Updates a value of `Polynomial` by setting field `coeff` to a specified one.