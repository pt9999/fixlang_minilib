# `module Minilib.Math.Ring`

Functions for a ring, for example multiplication or exponent with an integer.

A ring is a mathematical structure which has addition(`add`), subtraction(`sub`),
additive inverse(`neg`), additive unit(`zero`),
multiplication(`mul`), multiplicative unit(`one`).

For details, see [Wikipedia: Ring](https://en.wikipedia.org/wiki/Ring_(mathematics)).

# Types and aliases

# Traits and aliases

# Trait implementations

# Values

## `namespace Minilib.Math.Ring`

### `pow_by_U64 : [a : Std::Mul, a : Minilib.Math.Types::One] Std::U64 -> a -> a`

`a.pow_by_U64(n)` calculates `a ^ n`.

### `repeat_by_U64 : (a -> a -> a) -> a -> a -> Std::U64 -> a`

`repeat_by_U64(op, x, a, n)` calculates `x.op(a).op(a)...` for `n` times.
`op` is an associative binary operation.
This function returns the same result as `Iterator::range(0, n).fold(x, |x, _| x.op(a))`,
but faster.

### `times_by_U64 : [a : Std::Add, a : Std::Zero] Std::U64 -> a -> a`

`a.times_by_U64(n)` calculates `a * n`.