# Module Minilib.Common.Common (common.fix)

Common functions such as `id` and `flip`.

### `id: a -> a;`

`id` is an identity function.

### `flip: (a -> b -> c) -> (b -> a -> c);`

`flip(f)` swaps the first argument and the second argument.

### `apply: a -> (a -> b) -> b;`

`apply(a, f)` is equal to `f(a)`.
You can write it as `apply(a) $ f`, `a.apply $ f` or `f.apply(a)`.

