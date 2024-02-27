# rational.fix

## module Minilib.Math.Rational

Rational number arithmetic, for example `1/2 + 1/3 = 5/6`.

### type Rational

Rational number

```
type Rational a = unbox struct {
    num: a,     // numerator
    den: a      // denominator
};
```
### namespace Rational

#### make: [a: Euclid] a -> a -> Rational a;

`make(num, den)` creates a rational number `(num/den)`.
Aborts if `den` is zero.

#### rational: [a: Euclid] a -> a -> Rational a;

Synonym for `make`.

#### reduce: [a: Euclid] Rational a -> Rational a;

Reduces a rational number.

#### `impl [a: Euclid, a: ToString] Rational a: ToString`

#### `impl [a: Euclid] Rational a: Eq`

#### `impl [a: Euclid, a: One] Rational a: Zero`

#### `impl [a: Euclid, a: One] Rational a: One`

#### `impl [a: Euclid] Rational a: Neg`

#### `impl [a: Euclid] Rational a: Add`

#### `impl [a: Euclid] Rational a: Sub`

#### `impl [a: Euclid] Rational a: Mul`

#### `impl [a: Euclid] Rational a: Div`

