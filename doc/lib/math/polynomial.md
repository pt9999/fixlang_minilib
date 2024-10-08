# Module Minilib.Math.Polynomial (polynomial.fix)

Polynomial of one variable, for example `x^2 + 2x + 1`. The coefficients can be any ring.

### `type Polynomial`

A structure that represents a polynomial over a ring.
The coefficient array is ascending order of degree.
For example, `[1,2,3]` means a polynomial `3x^2 + 2x + 1`.

```
type Polynomial a = unbox struct {
    coeff: Array a      // The coefficient array
};
```
### `make: [a: Ring] Array a -> Polynomial a;`

`Polynomial::make(coeff)` creates a polynomial from coefficients.
For example, `Polynomial::make([1,2,3])` makes a polynomial `3x^2 + 2x + 1`.
For polynomials with degree greater than zero, the coefficient array is
truncated so that the coefficient of highest degree is not zero.

### `polynomial: [a: Ring] Array a -> Polynomial a;`

Synonym for `Polynomial::make`.

### `at_degree: [a: Ring] I64 -> a -> Polynomial a;`

`a.at_degree(n)` creates a polynomial `a * x ^ n`.

### `get: [a: Ring] I64 -> Polynomial a -> a;`

`f.get(i)` returns the coefficient of degree `i`.

### `set: [a: Ring] I64 -> a -> Polynomial a -> Polynomial a;`

`f.set(i, a)` sets the coefficient of degree `i`.

### `get_degree: Polynomial a -> I64;`

`f.get_degree` returns the degree of a polynomial `f`.

### `divmod: [a: Field] Polynomial a -> Polynomial a -> (Polynomial a, Polynomial a);`

`divmod(num, den)` calculates a quotient `quo = num / den`
and a reminder `rem = num % den`.
Returns `(quo, rem)`.
The type of coefficients must be a field.
If the division of the field does not fulfill the requirement
(ie. `forall a b, a == a / b * b`),
this function may return an incorrect result.

### `impl [a: Ring, a: ToString] Polynomial a: ToString`

### `impl [a: Ring] Polynomial a: Eq`

### `impl [a: Ring] Polynomial a: Zero`

### `impl [a: Ring] Polynomial a: One`

### `impl [a: Ring] Polynomial a: Neg`

### `impl [a: Ring] Polynomial a: Add`

### `impl [a: Ring] Polynomial a: Sub`

### `impl [a: Ring] Polynomial a: Mul`

### `impl [a: Field] Polynomial a: Div`

### `impl [a: Field] Polynomial a: Rem`

### `is_primitive: Polynomial (Modular I64) -> Bool;`

Checks whether it is a primitive polynomial.

### `generate: I64 -> I64 -> Iterator (Polynomial (Modular I64));`

`generate(p,m)` generates polynomials of degree `m` or lower in GF(p).

### `generate_primitive_polynomials: I64 -> I64 -> Iterator (Polynomial (Modular I64));`

`generate_primitive_polynomials(p, m)` generates primitive polynomials of degree `m` in GF(p).

### `subst: I64 -> Polynomial (Modular I64) -> I64;`

`f.subst(x)` substitutes the indeterminate of a polynomial with `x`.

