# except.fix

## module Minilib.Monad.Except

Except monad transformer that implements `MonadErrorIF`.

### type ExceptT

Except monad wraps an operation result (success or error).
`e` is a type of an error if the operation fails.
`m` is a type of an underlying monad.
`a` is a type of an operation result if operation is successful.

```
type [m: *->*] ExceptT e m a = unbox struct {
    data: m (Result e a)
};
```
#### except_t: [m: *->*] m (Result e a) -> ExceptT e m a;

Creates an Except monad from an operation result.

#### run_except_t: [m: *->*] ExceptT e m a -> m (Result e a);

Gets the operation result.

#### map_except_t: [m: *->*, n: *->*] (m (Result e a) -> n (Result e1 b)) -> ExceptT e m a -> ExceptT e1 n b;

Maps an underlying monad and an operation result using the specified function.

#### lift_except_t: [m: Monad] m a -> ExceptT e m a;

Lifts an underlying monad to an Except monad.

#### `impl [m: Functor] ExceptT e m: Functor`

#### `impl [m: Monad] ExceptT e m: Monad`

#### `impl ExceptT e: MonadTrans`

#### `impl [m: Monad] ExceptT e m: MonadErrorIF`

