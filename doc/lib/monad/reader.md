# reader.fix

## module Minilib.Monad.Reader

Reader monad.

For details, see [blog post: The Reader and Writer Monads and Comonads](https://www.olivierverdier.com/posts/2014/12/31/reader-writer-monad-comonad/).

### trait MonadReader = Monad + MonadReaderIF;

A trait for the interface of generic reader monads.

### trait MonadReaderIF

A trait for generic reader monads that manages the internal environment.

```
trait [rm: * -> *] rm: MonadReaderIF {
    // The type of the internal environment.
    type EnvType rm;
    // A monad that returns the internal environment as a value.
    ask: rm (EnvType rm);
    // `rm.local(f)` creates a reader monad with an environment modified by `f`.
    local: (EnvType rm -> EnvType rm) -> rm a -> rm a;
}
```
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

#### map_reader_t: [m: Monad, n: Monad] (m a -> n b) -> ReaderT e m a -> ReaderT e n b;

Maps an underlying monad and a value using the specified function.

#### with_reader_t: [m: Monad] (e1 -> e) -> ReaderT e m a -> ReaderT e1 m a;

Creates a reader monad with the modified environment.

#### lift_reader: [m: Monad] m a -> ReaderT e m a;

Lifts an underlying monad to a reader monad.

#### `impl [m: Monad] ReaderT e m: Functor`

#### `impl [m: Monad] ReaderT e m: Monad`

#### `impl [m: Monad] ReaderT e m: MonadReaderIF`

#### `impl ReaderT e: MonadTrans`

#### `impl [m: MonadError] ReaderT e m: MonadErrorIF`

#### `impl [m: MonadIO] ReaderT e m: MonadIOIF`

#### `impl [m: MonadIOFail] ReaderT e m: MonadIOFailIF`

