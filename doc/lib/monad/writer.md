# writer.fix

## module Minilib.Monad.Writer

Writer monad.

For details, see [blog post: The Reader and Writer Monads and Comonads](https://www.olivierverdier.com/posts/2014/12/31/reader-writer-monad-comonad/).

### trait MonadWriter = Monad + MonadWriterIF;

A trait for the interface of generic writer monads.

### trait MonadWriterIF

A trait for generic writer monads that manages the internal environment.

```
trait [wm: * -> *] wm: MonadWriterIF {
    // The type of the environment.
    type EnvType wm;
    // Tells specified value to the internal environment.
    tell: EnvType wm -> wm ();
    // Listens the internal environment.
    listen: wm a -> wm (EnvType wm, a);
    // Provide a writer transformer which changes internals of the written object.
    pass: wm (EnvType wm -> EnvType wm, a) -> wm a;
}
```
### type WriterT

Writer monad wraps a pair of an environment and a value.
`e` is a type of an environment.
`m` is a type of an underlyind monad.
`a` is a type of a value.

```
type [m: * -> *] WriterT e m a = unbox struct {
    data: m (e, a)
};
```
### type Writer

```
type Writer e a = WriterT e Identity a;
```
#### writer_t: [m: Monad] m (e, a) -> WriterT e m a;

Creates a generic writer monad from an enviroment and a value.

#### writer: e -> a -> Writer e a;

Creates a writer monad from an enviroment and a value.

#### run_writer_t: [m: Monad] WriterT e m a -> m (e, a);

Runs a generic writer monad to get an enviroment and a value.

#### run_writer: Writer e a -> (e, a);

Runs a writer monad to get an enviroment and a value.

#### write: [e: Monoid, m: Monad] e -> WriterT e m ();

Creates a writer monad that appends to the environment.

#### get_env_t: [m: Monad] WriterT e m a -> m e;

Gets the envirionment from a generic writer monad.

#### get_env: Writer e a -> e;

Gets the envirionment from a writer monad.

#### get_value_t: [m: Monad] WriterT e m a -> m a;

Gets the value from a generic writer monad.

#### get_value: Writer e a -> a;

Gets the value from a writer monad.

#### map_writer_t: [m: Monad, n: Monad] (m (e, a) -> n (e1, b)) -> WriterT e m a -> WriterT e1 n b;

Maps an underlying monad and a value using the specified function.

#### lift_writer: [e: Monoid, m: Monad] m a -> WriterT e m a;

Lifts an underlyind monad to a writer monad.

#### `impl [m: Monad] WriterT e m: Functor`

#### `impl [e: Monoid, m: Monad] WriterT e m: Monad`

#### `impl [e: Monoid, m: Monad] WriterT e m: MonadWriterIF`

#### `impl [e: Monoid] WriterT e: MonadTrans`

#### `impl [e: Monoid, m: MonadError] WriterT e m: MonadErrorIF`

