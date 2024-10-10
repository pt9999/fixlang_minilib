# `module Minilib.Monad.Cont`

Continuation Monad.

# Types and aliases

## `namespace Minilib.Monad.Cont`

### `type Cont = Minilib.Monad.Cont::ContT r Minilib.Monad.Identity::Identity a`

A continuation monad whose undelying monad is Identity.

### `type [m : *->*] ContT r m a = unbox struct { ...fields... }`

A continuation monad transformer.
`r` is a type of the result of the continuation function.
`m` is a type of an underlyind monad.
`a` is a type of a value.

#### field `data : (a -> m r) -> m r`

# Traits and aliases

## `namespace Minilib.Monad.Cont`

### `trait [cm : *->*] cm : MonadContIF`

A trait for generic continuation  monads.

#### method `call_cc : ((a -> cm b) -> cm a) -> cm a`

`call_cc(f)` calls `f` with the current continuation, and returns a continuation monad.
`f` takes the current continuation (the exit function) and should return a continuation monad.
For example, `call_cc(|exit| ... if condition { exit(false) }; ... pure(true))`.
The exit function can be passed to another function.

# Trait implementations

### `impl Minilib.Monad.Cont::ContT r : Minilib.Monad.Trans::MonadTrans`

### `impl [m : Std::Monad] Minilib.Monad.Cont::ContT r m : Minilib.Monad.Cont::MonadContIF`

### `impl [m : Std::Monad] Minilib.Monad.Cont::ContT r m : Std::Functor`

### `impl [m : Std::Monad] Minilib.Monad.Cont::ContT r m : Std::Monad`

# Values

## `namespace Minilib.Monad.Cont`

### `cont : ((a -> r) -> r) -> Minilib.Monad.Cont::ContT r Minilib.Monad.Identity::Identity a`

Creates a Cont monad from a function which receives a continuation function and returns the result value.

### `cont_t : [m : Std::Monad] ((a -> m r) -> m r) -> Minilib.Monad.Cont::ContT r m a`

Creates a ContT monad from a function which receives a continuation function and returns the monadic value of the result.

### `lift_cont : [m : Std::Monad] m a -> Minilib.Monad.Cont::ContT r m a`

Lifts an underlying monad to a continuation monad.

### `run_cont : (a -> r) -> Minilib.Monad.Cont::ContT r Minilib.Monad.Identity::Identity a -> r`

Runs a Cont monad with the supplied continuation function.

### `run_cont_t : [m : Std::Monad] (a -> m r) -> Minilib.Monad.Cont::ContT r m a -> m r`

Runs a ContT monad with the supplied continuation function.

## `namespace Minilib.Monad.Cont::ContT`

### `@data : Minilib.Monad.Cont::ContT r m a -> (a -> m r) -> m r`

Retrieves the field `data` from a value of `ContT`.

### `act_data : [f : Std::Functor] (((a -> m r) -> m r) -> f ((a -> m r) -> m r)) -> Minilib.Monad.Cont::ContT r m a -> f (Minilib.Monad.Cont::ContT r m a)`

Updates a value of `ContT` by applying a functorial action to field `data`.

### `mod_data : (((a -> m r) -> m r) -> (a -> m r) -> m r) -> Minilib.Monad.Cont::ContT r m a -> Minilib.Monad.Cont::ContT r m a`

Updates a value of `ContT` by applying a function to field `data`.

### `set_data : ((a -> m r) -> m r) -> Minilib.Monad.Cont::ContT r m a -> Minilib.Monad.Cont::ContT r m a`

Updates a value of `ContT` by setting field `data` to a specified one.

## `namespace Minilib.Monad.Cont::MonadContIF`

### `call_cc : [cm : Minilib.Monad.Cont::MonadContIF] ((a -> cm b) -> cm a) -> cm a`

`call_cc(f)` calls `f` with the current continuation, and returns a continuation monad.
`f` takes the current continuation (the exit function) and should return a continuation monad.
For example, `call_cc(|exit| ... if condition { exit(false) }; ... pure(true))`.
The exit function can be passed to another function.