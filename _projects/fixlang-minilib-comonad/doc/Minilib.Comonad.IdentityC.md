# `module Minilib.Comonad.IdentityC`

Identity comonad

# Types and aliases

## `namespace Minilib.Comonad.IdentityC`

### `type IdentityC a = unbox struct { ...fields... }`

Identity comonad

#### field `data : a`

# Traits and aliases

# Trait implementations

### `impl Minilib.Comonad.IdentityC::IdentityC : Minilib.Trait.Comonad::Comonad`

### `impl Minilib.Comonad.IdentityC::IdentityC : Std::Functor`

# Values

## `namespace Minilib.Comonad.IdentityC`

### `get : Minilib.Comonad.IdentityC::IdentityC a -> a`

Gets a value from an identity comonad.

### `make : a -> Minilib.Comonad.IdentityC::IdentityC a`

Creates an identity comonad from a value.

## `namespace Minilib.Comonad.IdentityC::IdentityC`

### `@data : Minilib.Comonad.IdentityC::IdentityC a -> a`

Retrieves the field `data` from a value of `IdentityC`.

### `act_data : [f : Std::Functor] (a -> f a) -> Minilib.Comonad.IdentityC::IdentityC a -> f (Minilib.Comonad.IdentityC::IdentityC a)`

Updates a value of `IdentityC` by applying a functorial action to field `data`.

### `mod_data : (a -> a) -> Minilib.Comonad.IdentityC::IdentityC a -> Minilib.Comonad.IdentityC::IdentityC a`

Updates a value of `IdentityC` by applying a function to field `data`.

### `set_data : a -> Minilib.Comonad.IdentityC::IdentityC a -> Minilib.Comonad.IdentityC::IdentityC a`

Updates a value of `IdentityC` by setting field `data` to a specified one.