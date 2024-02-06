# functor_m.fix

## module Minilib.Monad.FunctorM

`map_m`, `foreach_m` for Array and Iterator.

#### map_m : [m : Monad] (a -> m b) -> f a -> m (f b);

#### foreach_m : [m : Monad] (a -> m ()) -> f a -> m ();

#### `impl Array: FunctorM`

#### `impl Iterator: FunctorM`

