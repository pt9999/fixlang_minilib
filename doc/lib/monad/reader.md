# reader.fix

## module Minilib.Monad.Reader

Reader monad.

For details, see [blog post: The Reader and Writer Monads and Comonads](https://www.olivierverdier.com/posts/2014/12/31/reader-writer-monad-comonad/).

### type ReaderT

Reader monad wraps a function from an environment to a value.
`e` is a type of an environment.
`m` is a type of an underlyind monad.
`a` is a type of a value.

```
type [m: * -> *] ReaderT e m a = unbox struct {
    data: e -> m a
};
```
### type Reader

```
type Reader e a = ReaderT e Identity a;
```
### namespace Reader

#### reader_t: [m: Monad] (e -> m a) -> ReaderT e m a;

Creates a generic reader monad from a function.

#### reader: (e -> a) -> Reader e a;

Creates a reader monad from a function.

#### run_reader_t: [m: Monad] e -> ReaderT e m a -> m a;

Runs a generic reader monad with the supplied environment.

#### run_reader: e -> Reader e a -> a;

Runs a reader monad with the supplied environment.

#### read: [m: Monad] ReaderT e m e;

A reader monad that returns the environment as a value.

#### `impl [m: Monad] ReaderT e m: Functor`

#### `impl [m: Monad] ReaderT e m: Monad`

