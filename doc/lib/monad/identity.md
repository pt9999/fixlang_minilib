# Module Minilib.Monad.Identity (identity.fix)

Identity monad

### `type Identity`

Identity monad

```
type Identity a = unbox struct {
    data: a
};
```
### `make: a -> Identity a;`

Creates an identity monad from a value.

### `get: Identity a -> a;`

Gets a value from an identity monad.

### `impl Identity: Functor`

### `impl Identity: Monad`

