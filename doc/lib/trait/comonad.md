# comonad.fix

## module Minilib.Trait.Comonad

Comonad trait and associated functions.

For details, see web sites below.
- [Comonads in Haskell](https://www.slideshare.net/davidoverton/comonad)
- [Haskell: Control.Comonad](https://hackage.haskell.org/package/comonad-5.0.8/docs/Control-Comonad.html)


#### extract : w a -> a;

Extracts a value from a comonad.

#### extend : (w b -> a) -> w b -> w a;

Extends a comonad with a function.

### namespace Comonad

#### duplicate : [w : Comonad] w a -> w (w a);

Duplicates a comonad.

#### extendF : [w : Comonad] w b -> (w b -> a) -> w a;

Flipped version of `extend`.

