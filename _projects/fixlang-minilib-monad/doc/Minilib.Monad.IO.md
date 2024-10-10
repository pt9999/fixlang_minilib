# `module Minilib.Monad.IO`

Monadic traits which can lift IO and IOFail monad.

# Types and aliases

# Traits and aliases

## `namespace Minilib.Monad.IO`

### `trait [m : *->*] m : MonadIOFailIF`

An interface of a monadic trait which can lift IOFail monad.

#### method `lift_iofail : Std::IO::IOFail a -> m a`

### `trait [m : *->*] m : MonadIOIF`

An interface of a monadic trait which can lift IO monad.

#### method `lift_io : Std::IO a -> m a`

# Trait implementations

### `impl Std::IO : Minilib.Monad.IO::MonadIOIF`

### `impl Std::IO::IOFail : Minilib.Monad.IO::MonadIOFailIF`

### `impl Std::IO::IOFail : Minilib.Monad.IO::MonadIOIF`

# Values

## `namespace Minilib.Monad.IO::MonadIOFailIF`

### `lift_iofail : [m : Minilib.Monad.IO::MonadIOFailIF] Std::IO::IOFail a -> m a`

## `namespace Minilib.Monad.IO::MonadIOIF`

### `lift_io : [m : Minilib.Monad.IO::MonadIOIF] Std::IO a -> m a`