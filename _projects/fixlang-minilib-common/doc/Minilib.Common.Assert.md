# `module Minilib.Common.Assert`

Assert functions.

# Types and aliases

# Traits and aliases

# Trait implementations

# Values

## `namespace Minilib.Common.Assert`

### `assert_lazy : (() -> Std::String) -> Std::Bool -> (() -> a) -> a`

`assert_lazy(errmsg, value, lazy_func)` asserts that a condition (boolean value) is true.
If the assertion failed, prints a message to the stderr and aborts the program.
If the assertion succeeded, calls a lazy function.

For example, instead of
`eval *assert(|_| "error", a == b); ...` in an IO monad, you can write
`assert_lazy(|_| "error", a == b) $ |_| ...`.