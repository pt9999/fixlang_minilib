# Module Minilib.Comonad.Traced (traced.fix)

Traced comonad. (a.k.a CoWriter comonad)

For details, see [blog post: The Reader and Writer Monads and Comonads](https://www.olivierverdier.com/posts/2014/12/31/reader-writer-monad-comonad/).

### `type TracedT`

Traced comonad.
`e` is a type of an environment.
`w` is a type of an underlyind comonad.
`a` is a type of a value.

```
type [w: * -> *] TracedT e w a = unbox struct {
    data: w (e -> a)
};
```
### `type Traced`

```
type Traced e a = TracedT e IdentityC a;
```
## `namespace Traced`

### `traced_t: [w: Comonad] w (e -> a) -> TracedT e w a;`

Creates a generic traced comonad from a function.

### `traced: (e -> a) -> Traced e a;`

Creates a traced comonad from a function.

### `run_traced_t: [w: Comonad] TracedT e w a -> w (e -> a);`

Runs a generic traced commonad with the supplied environment.

### `run_traced: e -> Traced e a -> a;`

Runs a traced commonad with the supplied environment.

### `impl [w: Comonad] TracedT e w: Functor`

### `impl [e: Monoid, w: Comonad] TracedT e w: Comonad`

