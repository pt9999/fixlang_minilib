# ring.fix

## module Minilib.Math.Ring

Utility functions for a [ring](https://en.wikipedia.org/wiki/Ring_(mathematics)),
which has addition(`add`), subtraction(`sub`), additive inverse(`neg`), additive unit(`zero`),
multiplication(`mul`), multiplicative unit(`one`).

#### repeat_by_U64: [a: Ring] (a -> a -> a) -> a -> a -> U64 -> a;

`repeat_by_U64(op, x, a, n)` calculates `x.op(a).op(a)...` for `n` times.
`op` is an associative binary operation.
This function returns the same result as `Iterator::range(0, n).fold(x, |x, _| x.op(a))`,
but faster.

#### times_by_U64: [a: Ring] U64 -> a -> a;

`a.times_by_U64(n)` calculates `a * n`.

#### pow_by_U64: [a: Ring] U64 -> a -> a;

`a.pow_by_U64(n)` calculates `a ^ n`.

