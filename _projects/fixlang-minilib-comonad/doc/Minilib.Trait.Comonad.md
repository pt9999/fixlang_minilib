# `module Minilib.Trait.Comonad`

Comonad trait and associated functions.

For details, see web sites below.
- [Comonads in Haskell](https://www.slideshare.net/davidoverton/comonad)
- [Haskell: Control.Comonad](https://hackage.haskell.org/package/comonad-5.0.8/docs/Control-Comonad.html)

# Types and aliases

# Traits and aliases

## `namespace Minilib.Trait.Comonad`

### `trait [w : *->*] w : Comonad`

#### method `extract : w a -> a`

Extracts a value from a comonad.

#### method `extend : (w b -> a) -> w b -> w a`

Extends a comonad with a function.

# Trait implementations

# Values

## `namespace Minilib.Trait.Comonad::Comonad`

### `duplicate : [w : Minilib.Trait.Comonad::Comonad] w a -> w (w a)`

Duplicates a comonad.

### `extend : [w : Minilib.Trait.Comonad::Comonad] (w b -> a) -> w b -> w a`

Extends a comonad with a function.

### `extendF : [w : Minilib.Trait.Comonad::Comonad] w b -> (w b -> a) -> w a`

Flipped version of `extend`.

### `extract : [w : Minilib.Trait.Comonad::Comonad] w a -> a`

Extracts a value from a comonad.