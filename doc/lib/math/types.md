# types.fix

## module Minilib.Math.Types

Type definitions for mathematical concepts.

### trait Monoid = Zero + Add;

A trait that represents a [monoid](https://en.wikipedia.org/wiki/Monoid),
where the additive unit is `zero`.

### trait AdditiveGroup = Eq + Zero + Neg + Add + Sub;

A trait that represents an [additive group](https://en.wikipedia.org/wiki/Additive_group),
which has addition(`add`), subtraction(`sub`), additive inverse(`neg`), additive unit(`zero`).

### trait One

A trait that represents a multiplicative unit.

```
trait a: One {
    one: a;
}
```
### trait Ring = AdditiveGroup + One + Mul;

A trait that represents a [ring](https://en.wikipedia.org/wiki/Ring_(mathematics)),
which has addition(`add`), subtraction(`sub`), additive inverse(`neg`), additive unit(`zero`),
multiplication(`mul`), multiplicative unit(`one`).

### trait Euclid = Ring + Div + Rem;

A trait that represents an [Euclidean domain](https://en.wikipedia.org/wiki/Euclidean_domain),
which is a ring with following division-with-remainder.
```
forall a b, a = (a / b) * b + (a % b)
```

### trait Field = Ring + Div;

A trait that represents a [field](https://en.wikipedia.org/wiki/Field_(mathematics)),
which is a ring with division(`div`).

The division must meet following condition.
```
forall a b, a = a * b / b
```

### trait Ordered = Eq + LessThan + LessThanOrEq;

[Total order](https://en.wikipedia.org/wiki/Total_order)

### trait OrderedField = Field + LessThan + LessThanOrEq;

[Ordered field](https://en.wikipedia.org/wiki/Ordered_field)

#### `impl I64: One`

#### `impl F64: One`

