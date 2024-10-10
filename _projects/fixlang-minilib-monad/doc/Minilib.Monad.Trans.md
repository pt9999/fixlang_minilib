# `module Minilib.Monad.Trans`

Trait for a monad transformer.

# Types and aliases

# Traits and aliases

## `namespace Minilib.Monad.Trans`

### `trait [t : (*->*)->*->*] t : MonadTrans`

Trait for a monad transformer.

#### method `lift_t : [m : Std::Monad] m a -> t m a`

Lifts an underlying monad to a transformed monad.

# Trait implementations

# Values

## `namespace Minilib.Monad.Trans::MonadTrans`

### `lift_t : [t : Minilib.Monad.Trans::MonadTrans, m : Std::Monad] m a -> t m a`

Lifts an underlying monad to a transformed monad.