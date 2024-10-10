# `module Minilib.Comonad.Traced`

Traced comonad. (a.k.a CoWriter comonad)

For details, see [blog post: The Reader and Writer Monads and Comonads](https://www.olivierverdier.com/posts/2014/12/31/reader-writer-monad-comonad/).

# Types and aliases

## `namespace Minilib.Comonad.Traced`

### `type Traced = Minilib.Comonad.Traced::TracedT e Minilib.Comonad.IdentityC::IdentityC a`

### `type [w : *->*] TracedT e w a = unbox struct { ...fields... }`

Traced comonad.
`e` is a type of an environment.
`w` is a type of an underlyind comonad.
`a` is a type of a value.

#### field `data : w (e -> a)`

# Traits and aliases

# Trait implementations

### `impl [e : Minilib.Trait.Monoid::Monoid, w : Minilib.Trait.Comonad::Comonad] Minilib.Comonad.Traced::TracedT e w : Minilib.Trait.Comonad::Comonad`

### `impl [w : Minilib.Trait.Comonad::Comonad] Minilib.Comonad.Traced::TracedT e w : Std::Functor`

# Values

## `namespace Minilib.Comonad.Traced::Traced`

### `run_traced : e -> Minilib.Comonad.Traced::TracedT e Minilib.Comonad.IdentityC::IdentityC a -> a`

Runs a traced commonad with the supplied environment.

### `run_traced_t : [w : Minilib.Trait.Comonad::Comonad] Minilib.Comonad.Traced::TracedT e w a -> w (e -> a)`

Runs a generic traced commonad with the supplied environment.

### `traced : (e -> a) -> Minilib.Comonad.Traced::TracedT e Minilib.Comonad.IdentityC::IdentityC a`

Creates a traced comonad from a function.

### `traced_t : [w : Minilib.Trait.Comonad::Comonad] w (e -> a) -> Minilib.Comonad.Traced::TracedT e w a`

Creates a generic traced comonad from a function.

## `namespace Minilib.Comonad.Traced::TracedT`

### `@data : Minilib.Comonad.Traced::TracedT e w a -> w (e -> a)`

Retrieves the field `data` from a value of `TracedT`.

### `act_data : [f : Std::Functor] (w (e -> a) -> f (w (e -> a))) -> Minilib.Comonad.Traced::TracedT e w a -> f (Minilib.Comonad.Traced::TracedT e w a)`

Updates a value of `TracedT` by applying a functorial action to field `data`.

### `mod_data : (w (e -> a) -> w (e -> a)) -> Minilib.Comonad.Traced::TracedT e w a -> Minilib.Comonad.Traced::TracedT e w a`

Updates a value of `TracedT` by applying a function to field `data`.

### `set_data : w (e -> a) -> Minilib.Comonad.Traced::TracedT e w a -> Minilib.Comonad.Traced::TracedT e w a`

Updates a value of `TracedT` by setting field `data` to a specified one.