# error.fix

## module Minilib.Monad.Error

### trait MonadError = Monad + MonadErrorIF;

A trait for the interface of monads which can report errors.

### trait MonadErrorIF

A trait for monads which can report errors.

```
trait [m: * -> *] m: MonadErrorIF {
    // The type of error.
    type ErrorType m;

    // `error(e)` reports an error.
    error: ErrorType m -> m a;

    // `ma.catch(handler)` catches any error that is reported during the computation of `ma`.
    catch: (ErrorType m -> m a) -> m a -> m a;
}
```
#### `impl Result e: MonadErrorIF`

#### `impl IOFail: MonadErrorIF`
