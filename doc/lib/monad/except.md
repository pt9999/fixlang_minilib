# except.fix

## module Minilib.Monad.Except

### type ExceptT

```
type [m: *->*] ExceptT e m a = unbox struct {
    data: m (Result e a)
};
```
#### except_t: [m: *->*] m (Result e a) -> ExceptT e m a;

#### run_except_t: [m: *->*] ExceptT e m a -> m (Result e a);

#### map_except_t: [m: *->*, n: *->*] (m (Result e a) -> n (Result e1 b)) -> ExceptT e m a -> ExceptT e1 n b;

#### lift_except_t: [m: Monad] m a -> ExceptT e m a;

#### `impl [m: Functor] ExceptT e m: Functor`

#### `impl [m: Monad] ExceptT e m: Monad`

#### `impl ExceptT e: MonadTrans`

#### `impl [m: Monad] ExceptT e m: MonadErrorIF`

