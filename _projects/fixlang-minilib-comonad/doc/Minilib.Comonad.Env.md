# `module Minilib.Comonad.Env`

Env comonad. (a.k.a CoReader comonad)

For details, see [blog post: The Reader and Writer Monads and Comonads](https://www.olivierverdier.com/posts/2014/12/31/reader-writer-monad-comonad/).

# Types and aliases

## `namespace Minilib.Comonad.Env`

### `type Env = Minilib.Comonad.Env::EnvT e Minilib.Comonad.IdentityC::IdentityC a`

### `type [w : *->*] EnvT e w a = unbox struct { ...fields... }`

Env comonad wraps a pair of an environment and a value.
`e` is a type of an environment.
`w` is a type of an underlyind comonad.
`a` is a type of a value.

#### field `env : e`

#### field `value : w a`

# Traits and aliases

# Trait implementations

### `impl [w : Minilib.Trait.Comonad::Comonad] Minilib.Comonad.Env::EnvT e w : Minilib.Trait.Comonad::Comonad`

### `impl [w : Minilib.Trait.Comonad::Comonad] Minilib.Comonad.Env::EnvT e w : Std::Functor`

# Values

## `namespace Minilib.Comonad.Env::Env`

### `env : e -> a -> Minilib.Comonad.Env::EnvT e Minilib.Comonad.IdentityC::IdentityC a`

Creates an env comonad from an enviroment and a value.

### `env_t : [w : Minilib.Trait.Comonad::Comonad] e -> w a -> Minilib.Comonad.Env::EnvT e w a`

Creates a generic env comonad from an enviroment and a value.

### `get_env : [w : Minilib.Trait.Comonad::Comonad] Minilib.Comonad.Env::EnvT e w a -> e`

Gets the envirionment from an env comonad.

### `get_value : [w : Minilib.Trait.Comonad::Comonad] Minilib.Comonad.Env::EnvT e w a -> a`

Gets the value from an env comonad.

### `to_tuple : [w : Minilib.Trait.Comonad::Comonad] Minilib.Comonad.Env::EnvT e w a -> (e, a)`

Converts a env comonad to a pair of an enviroment and a value.

## `namespace Minilib.Comonad.Env::EnvT`

### `@env : Minilib.Comonad.Env::EnvT e w a -> e`

Retrieves the field `env` from a value of `EnvT`.

### `@value : Minilib.Comonad.Env::EnvT e w a -> w a`

Retrieves the field `value` from a value of `EnvT`.

### `act_env : [f : Std::Functor] (e -> f e) -> Minilib.Comonad.Env::EnvT e w a -> f (Minilib.Comonad.Env::EnvT e w a)`

Updates a value of `EnvT` by applying a functorial action to field `env`.

### `act_value : [f : Std::Functor] (w a -> f (w a)) -> Minilib.Comonad.Env::EnvT e w a -> f (Minilib.Comonad.Env::EnvT e w a)`

Updates a value of `EnvT` by applying a functorial action to field `value`.

### `mod_env : (e -> e) -> Minilib.Comonad.Env::EnvT e w a -> Minilib.Comonad.Env::EnvT e w a`

Updates a value of `EnvT` by applying a function to field `env`.

### `mod_value : (w a -> w a) -> Minilib.Comonad.Env::EnvT e w a -> Minilib.Comonad.Env::EnvT e w a`

Updates a value of `EnvT` by applying a function to field `value`.

### `set_env : e -> Minilib.Comonad.Env::EnvT e w a -> Minilib.Comonad.Env::EnvT e w a`

Updates a value of `EnvT` by setting field `env` to a specified one.

### `set_value : w a -> Minilib.Comonad.Env::EnvT e w a -> Minilib.Comonad.Env::EnvT e w a`

Updates a value of `EnvT` by setting field `value` to a specified one.