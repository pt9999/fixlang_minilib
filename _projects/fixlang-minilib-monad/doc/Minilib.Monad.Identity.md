# `module Minilib.Monad.Identity`

Identity monad

# Types and aliases

## `namespace Minilib.Monad.Identity`

### `type Identity a = unbox struct { ...fields... }`

Identity monad

#### field `data : a`

# Traits and aliases

# Trait implementations

### `impl Minilib.Monad.Identity::Identity : Std::Functor`

### `impl Minilib.Monad.Identity::Identity : Std::Monad`

# Values

## `namespace Minilib.Monad.Identity`

### `get : Minilib.Monad.Identity::Identity a -> a`

Gets a value from an identity monad.

### `make : a -> Minilib.Monad.Identity::Identity a`

Creates an identity monad from a value.

## `namespace Minilib.Monad.Identity::Identity`

### `@data : Minilib.Monad.Identity::Identity a -> a`

Retrieves the field `data` from a value of `Identity`.

### `act_data : [f : Std::Functor] (a -> f a) -> Minilib.Monad.Identity::Identity a -> f (Minilib.Monad.Identity::Identity a)`

Updates a value of `Identity` by applying a functorial action to field `data`.

### `mod_data : (a -> a) -> Minilib.Monad.Identity::Identity a -> Minilib.Monad.Identity::Identity a`

Updates a value of `Identity` by applying a function to field `data`.

### `set_data : a -> Minilib.Monad.Identity::Identity a -> Minilib.Monad.Identity::Identity a`

Updates a value of `Identity` by setting field `data` to a specified one.