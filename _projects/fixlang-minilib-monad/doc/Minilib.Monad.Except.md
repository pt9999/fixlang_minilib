# `module Minilib.Monad.Except`

Except monad transformer that implements `MonadErrorIF`.

# Types and aliases

## `namespace Minilib.Monad.Except`

### `type [m : *->*] ExceptT e m a = unbox struct { ...fields... }`

Except monad wraps an operation result (success or error).
`e` is a type of an error if the operation fails.
`m` is a type of an underlying monad.
`a` is a type of an operation result if operation is successful.

#### field `data : m (Std::Result e a)`

# Traits and aliases

# Trait implementations

### `impl [m : Std::Monad] Minilib.Monad.Except::ExceptT Std::String m : Minilib.Monad.Error::MonadErrorIF`

### `impl Minilib.Monad.Except::ExceptT e : Minilib.Monad.Trans::MonadTrans`

### `impl [m : Std::Functor] Minilib.Monad.Except::ExceptT e m : Std::Functor`

### `impl [m : Std::Monad] Minilib.Monad.Except::ExceptT e m : Std::Monad`

# Values

## `namespace Minilib.Monad.Except`

### `except_t : m (Std::Result e a) -> Minilib.Monad.Except::ExceptT e m a`

Creates an Except monad from an operation result.

### `lift_except_t : [m : Std::Monad] m a -> Minilib.Monad.Except::ExceptT e m a`

Lifts an underlying monad to an Except monad.

### `map_except_t : (m (Std::Result e a) -> n (Std::Result e1 b)) -> Minilib.Monad.Except::ExceptT e m a -> Minilib.Monad.Except::ExceptT e1 n b`

Maps an underlying monad and an operation result using the specified function.

### `run_except_t : Minilib.Monad.Except::ExceptT e m a -> m (Std::Result e a)`

Gets the operation result.

## `namespace Minilib.Monad.Except::ExceptT`

### `@data : Minilib.Monad.Except::ExceptT e m a -> m (Std::Result e a)`

Retrieves the field `data` from a value of `ExceptT`.

### `act_data : [f : Std::Functor] (m (Std::Result e a) -> f (m (Std::Result e a))) -> Minilib.Monad.Except::ExceptT e m a -> f (Minilib.Monad.Except::ExceptT e m a)`

Updates a value of `ExceptT` by applying a functorial action to field `data`.

### `mod_data : (m (Std::Result e a) -> m (Std::Result e a)) -> Minilib.Monad.Except::ExceptT e m a -> Minilib.Monad.Except::ExceptT e m a`

Updates a value of `ExceptT` by applying a function to field `data`.

### `set_data : m (Std::Result e a) -> Minilib.Monad.Except::ExceptT e m a -> Minilib.Monad.Except::ExceptT e m a`

Updates a value of `ExceptT` by setting field `data` to a specified one.