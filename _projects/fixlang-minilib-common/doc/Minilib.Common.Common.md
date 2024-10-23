# `module Minilib.Common.Common`

Common functions such as `id` and `flip`.

# Types and aliases

# Traits and aliases

# Trait implementations

# Values

## `namespace Minilib.Common.Common`

### `apply : a -> (a -> b) -> b`

`apply(a, f)` is equal to `f(a)`.
You can write it as `apply(a) $ f`, `a.apply $ f` or `f.apply(a)`.

### `flip : (a -> b -> c) -> b -> a -> c`

`flip(f)` swaps the first argument and the second argument.

### `id : a -> a`

`id` is an identity function.