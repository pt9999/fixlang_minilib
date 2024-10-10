# `module Minilib.Monad.Reader`

Reader monad.

For details, see [blog post: The Reader and Writer Monads and Comonads](https://www.olivierverdier.com/posts/2014/12/31/reader-writer-monad-comonad/).

# Types and aliases

## `namespace Minilib.Monad.Reader`

### `type Reader = Minilib.Monad.Reader::ReaderT e Minilib.Monad.Identity::Identity a`

### `type [m : *->*] ReaderT e m a = unbox struct { ...fields... }`

Reader monad wraps a function from an environment to a value.
`e` is a type of an environment.
`m` is a type of an underlyind monad.
`a` is a type of a value.

#### field `data : e -> m a`

# Traits and aliases

## `namespace Minilib.Monad.Reader`

### `trait [rm : *->*] rm : MonadReaderIF`

A trait for generic reader monads that manages the internal environment.

#### method `ask : rm (Minilib.Monad.Reader::MonadReaderIF::EnvType rm)`

A monad that returns the internal environment as a value.

#### method `local : (Minilib.Monad.Reader::MonadReaderIF::EnvType rm -> Minilib.Monad.Reader::MonadReaderIF::EnvType rm) -> rm a -> rm a`

`rm.local(f)` creates a reader monad with an environment modified by `f`.

# Trait implementations

### `impl Minilib.Monad.Reader::ReaderT e : Minilib.Monad.Trans::MonadTrans`

### `impl [m : Minilib.Monad.Error::MonadError] Minilib.Monad.Reader::ReaderT e m : Minilib.Monad.Error::MonadErrorIF`

### `impl [m : Minilib.Monad.IO::MonadIOFail] Minilib.Monad.Reader::ReaderT e m : Minilib.Monad.IO::MonadIOFailIF`

### `impl [m : Minilib.Monad.IO::MonadIO] Minilib.Monad.Reader::ReaderT e m : Minilib.Monad.IO::MonadIOIF`

### `impl [m : Std::Monad] Minilib.Monad.Reader::ReaderT e m : Minilib.Monad.Reader::MonadReaderIF`

### `impl [m : Std::Monad] Minilib.Monad.Reader::ReaderT e m : Std::Functor`

### `impl [m : Std::Monad] Minilib.Monad.Reader::ReaderT e m : Std::Monad`

# Values

## `namespace Minilib.Monad.Reader`

### `lift_reader : [m : Std::Monad] m a -> Minilib.Monad.Reader::ReaderT e m a`

Lifts an underlying monad to a reader monad.

### `map_reader_t : [m : Std::Monad, n : Std::Monad] (m a -> n b) -> Minilib.Monad.Reader::ReaderT e m a -> Minilib.Monad.Reader::ReaderT e n b`

Maps an underlying monad and a value using the specified function.

### `read : [m : Std::Monad] Minilib.Monad.Reader::ReaderT e m e`

A reader monad that returns the environment as a value.

### `reader : (e -> a) -> Minilib.Monad.Reader::ReaderT e Minilib.Monad.Identity::Identity a`

Creates a reader monad from a function.

### `reader_t : [m : Std::Monad] (e -> m a) -> Minilib.Monad.Reader::ReaderT e m a`

Creates a generic reader monad from a function.

### `run_reader : e -> Minilib.Monad.Reader::ReaderT e Minilib.Monad.Identity::Identity a -> a`

Runs a reader monad with the supplied environment.

### `run_reader_t : [m : Std::Monad] e -> Minilib.Monad.Reader::ReaderT e m a -> m a`

Runs a generic reader monad with the supplied environment.

### `with_reader_t : [m : Std::Monad] (e1 -> e) -> Minilib.Monad.Reader::ReaderT e m a -> Minilib.Monad.Reader::ReaderT e1 m a`

Creates a reader monad with the modified environment.

## `namespace Minilib.Monad.Reader::MonadReaderIF`

### `ask : [rm : Minilib.Monad.Reader::MonadReaderIF] rm (Minilib.Monad.Reader::MonadReaderIF::EnvType rm)`

A monad that returns the internal environment as a value.

### `local : [rm : Minilib.Monad.Reader::MonadReaderIF] (Minilib.Monad.Reader::MonadReaderIF::EnvType rm -> Minilib.Monad.Reader::MonadReaderIF::EnvType rm) -> rm a -> rm a`

`rm.local(f)` creates a reader monad with an environment modified by `f`.

## `namespace Minilib.Monad.Reader::ReaderT`

### `@data : Minilib.Monad.Reader::ReaderT e m a -> e -> m a`

Retrieves the field `data` from a value of `ReaderT`.

### `act_data : [f : Std::Functor] ((e -> m a) -> f (e -> m a)) -> Minilib.Monad.Reader::ReaderT e m a -> f (Minilib.Monad.Reader::ReaderT e m a)`

Updates a value of `ReaderT` by applying a functorial action to field `data`.

### `mod_data : ((e -> m a) -> e -> m a) -> Minilib.Monad.Reader::ReaderT e m a -> Minilib.Monad.Reader::ReaderT e m a`

Updates a value of `ReaderT` by applying a function to field `data`.

### `set_data : (e -> m a) -> Minilib.Monad.Reader::ReaderT e m a -> Minilib.Monad.Reader::ReaderT e m a`

Updates a value of `ReaderT` by setting field `data` to a specified one.