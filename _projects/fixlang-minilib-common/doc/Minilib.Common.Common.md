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

### `assert_lazy : (() -> Std::String) -> Std::Bool -> (() -> a) -> a`

`assert_lazy(errmsg, value, lazy_func)` asserts that a condition (boolean value) is true.
If the assertion failed, prints a message to the stderr and aborts the program.
If the assertion succeeded, calls a lazy function.

For example, instead of
`eval *assert(|_| "error", a == b); ...` in an IO monad, you can write
`assert_lazy(|_| "error", a == b) $ |_| ...`.

### `flip : (a -> b -> c) -> b -> a -> c`

`flip(f)` swaps the first argument and the second argument.

### `id : a -> a`

`id` is an identity function.