# identity_c.fix

## module Minilib.Comonad.IdentityC

Identity comonad

### type IdentityC

Identity comonad

```
type IdentityC a = unbox struct {
    data: a
};
```
#### make: a -> IdentityC a;

Creates an identity comonad from a value.

#### get: IdentityC a -> a;

Gets a value from an identity comonad.

#### `impl IdentityC: Functor`

#### `impl IdentityC: Comonad`

