# reader.fix

## module Minilib.Monad.Reader

Reader monad. (a.k.a Traced, CoWriter comonad)

For details, see [blog post: The Reader and Writer Monads and Comonads](https://www.olivierverdier.com/posts/2014/12/31/reader-writer-monad-comonad/).

### type Reader

Reader monad wraps a function from an environment to a value.
`e` is a type of an environment.
`a` is a type of a value.

```
type Reader e a = unbox struct {
    data: e -> a
};
```
### namespace Reader

#### reader: (e -> a) -> Reader e a;

Creates a reader monad from a function.

#### run_reader: e -> Reader e a -> a;

Runs a reader monad with the supplied environment.

#### read: Reader e e;

A reader monad that returns the environment as a value.

### type Traced

Traced comonad. This is same as a reader monad.

```
type Traced e a = Reader e a;
```
### namespace Traced

#### traced: (e -> a) -> Traced e a;

Creates a traced comonad from a function.

#### run_traced: e -> Traced e a -> a;

Runs a traced commonad with the supplied environment.

#### `impl Reader e: Functor`

#### `impl Reader e: Monad`

#### `impl [e: Monoid] Reader e: Comonad`

