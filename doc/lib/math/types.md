# types.fix

## module Minilib.Math.Types

Type definitions for mathematical concepts.

### trait Monoid = Zero + Add;

[Monoid](https://en.wikipedia.org/wiki/Monoid)

### trait AdditiveGroup = Zero + Neg + Add + Sub;

[Additive group](https://en.wikipedia.org/wiki/Additive_group)

### trait Ring = AdditiveGroup + Mul;

[Ring](https://en.wikipedia.org/wiki/Ring_(mathematics))

### trait Field = Ring + Div;

[Field](https://en.wikipedia.org/wiki/Field_(mathematics))

### trait Ordered = Eq + LessThan + LessThanOrEq;

[Total order](https://en.wikipedia.org/wiki/Total_order)

### trait OrderedField = Ordered + Field;

[Ordered field](https://en.wikipedia.org/wiki/Ordered_field)

