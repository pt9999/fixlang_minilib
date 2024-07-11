# error.fix

## module Minilib.Monad.Error

Definition of `MonadErrorIF` trait which can report errors.

### trait MonadError = Monad + MonadErrorIF;

A trait for the interface of monads which can report errors.

### trait MonadErrorIF

A trait for monads which can report errors.

```
trait [m: * -> *] m: MonadErrorIF {
    // `error(e)` throws an error.
    error: ErrMsg -> m a;

    // `ma.catch(handler)` catches any error that is thrown during the computation of `ma`.
    catch: (ErrMsg -> m a) -> m a -> m a;
}
```
#### `impl Result ErrMsg: MonadErrorIF`

#### `impl IOFail: MonadErrorIF`

#### lift_result: [m: MonadError] Result ErrMsg a -> m a;

#### from_result_t: [m: MonadError] Result ErrMsg a -> m a;

#### to_result_t: [m: MonadError] m a -> m (Result ErrMsg a);

