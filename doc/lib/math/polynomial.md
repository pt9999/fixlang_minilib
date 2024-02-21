# polynomial.fix

## module Minilib.Math.Polynomial

### type Polynomial

Polynomial

```
type Polynomial a = unbox struct {
    coeff: Array a      // coefficients
};
```
#### make: [a: Ring] Array a -> Polynomial a;

`Polynomial::make(coeff)` creates a polynomial from coefficients.

#### polynomial: [a: Ring] Array a -> Polynomial a;

Synonym for `Polynomial::make`.

#### of_power: [a: Ring] a -> I64 -> Polynomial a;

#### get: [a: Ring] I64 -> Polynomial a -> a;

`f.get(i)` returns the coefficient of degree `i`.

#### get_degree: Polynomial a -> I64;

#### map_coeff: [a: Ring] (a -> a) -> Polynomial a -> Polynomial a;

#### divmod: [a: Field] Polynomial a -> Polynomial a -> (Polynomial a, Polynomial a);

`divmod(num, den)` calculates a quotient `quo = num / den`
and a reminder `rem = num % den`.
Returns `(quo, rem)`.

#### `impl [a: Ring, a: ToString] Polynomial a: ToString`

#### `impl [a: Ring] Polynomial a: Eq`

#### `impl [a: Ring] Polynomial a: Zero`

#### `impl [a: Ring] Polynomial a: One`

#### `impl [a: Ring] Polynomial a: Neg`

#### `impl [a: Ring] Polynomial a: Add`

#### `impl [a: Ring] Polynomial a: Sub`

#### `impl [a: Ring] Polynomial a: Mul`

#### `impl [a: Field] Polynomial a: Div`

#### `impl [a: Field] Polynomial a: Rem`

#### is_primitive: Polynomial (Modular I64) -> Bool;

Checks whether it is a primitive polynomial.

#### generate: I64 -> I64 -> Iterator (Polynomial (Modular I64));

`generate(p,m)` generates polynomials of degree `m` or lower in GF(p).

#### generate_primitive_polynomials: I64 -> I64 -> Iterator (Polynomial (Modular I64));

`generate_primitive_polynomials(p, m)` generates primitive polynomials of degree `m` in GF(p).

#### subst: I64 -> Polynomial (Modular I64) -> I64;

`f.subst(x)` substitutes the indeterminate of a polynomial with `x`.

