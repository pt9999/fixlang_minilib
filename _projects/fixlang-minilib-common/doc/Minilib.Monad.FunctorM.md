# `module Minilib.Monad.FunctorM`

`map_m`, `foreach_m` for Array and Iterator.

# Types and aliases

# Traits and aliases

## `namespace Minilib.Monad.FunctorM`

### `trait [f : *->*] f : FunctorM`

#### method `map_m : [m : Std::Monad] (a -> m b) -> f a -> m (f b)`

#### method `foreach_m : [m : Std::Monad] (a -> m ()) -> f a -> m ()`

# Trait implementations

### `impl Std::Array : Minilib.Monad.FunctorM::FunctorM`

### `impl Std::Iterator : Minilib.Monad.FunctorM::FunctorM`

# Values

## `namespace Minilib.Monad.FunctorM::FunctorM`

### `foreach_m : [f : Minilib.Monad.FunctorM::FunctorM, m : Std::Monad] (a -> m ()) -> f a -> m ()`

### `map_m : [f : Minilib.Monad.FunctorM::FunctorM, m : Std::Monad] (a -> m b) -> f a -> m (f b)`