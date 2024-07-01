# io.fix

## module Minilib.Monad.IO

Monadic traits which can lift IO and IOFail monad.

### trait MonadIO = Monad + MonadIOIF;

A monadic trait which can lift IO monad.

### trait MonadIOIF

An interface of a monadic trait which can lift IO monad.

```
trait [m: * -> *] m: MonadIOIF {
    lift_io: IO a -> m a;
}
```
### trait MonadIOFail = Monad + MonadIOIF + MonadIOFailIF;

A monadic trait which can lift IO and IOFail monad.

### trait MonadIOFailIF

An interface of a monadic trait which can lift IOFail monad.

```
trait [m: * -> *] m: MonadIOFailIF {
    lift_iofail: IOFail a -> m a;
}
```
#### `impl IO: MonadIOIF`

#### `impl IOFail: MonadIOIF`

#### `impl IOFail: MonadIOFailIF`

