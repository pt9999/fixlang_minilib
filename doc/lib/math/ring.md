# Module Minilib.Math.Ring (ring.fix)

Functions for a ring, for example multiplication or exponent with an integer.

A ring is a mathematical structure which has addition(`add`), subtraction(`sub`),
additive inverse(`neg`), additive unit(`zero`),
multiplication(`mul`), multiplicative unit(`one`).

For details, see [Wikipedia: Ring](https://en.wikipedia.org/wiki/Ring_(mathematics)).

### `repeat_by_U64: (a -> a -> a) -> a -> a -> U64 -> a;`

`repeat_by_U64(op, x, a, n)` calculates `x.op(a).op(a)...` for `n` times.
`op` is an associative binary operation.
This function returns the same result as `Iterator::range(0, n).fold(x, |x, _| x.op(a))`,
but faster.

### `times_by_U64: [a: Add, a: Zero] U64 -> a -> a;`

`a.times_by_U64(n)` calculates `a * n`.

### `pow_by_U64: [a: Mul, a: One] U64 -> a -> a;`

`a.pow_by_U64(n)` calculates `a ^ n`.

