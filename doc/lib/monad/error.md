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

    // Reports an error.
    error: ErrorType m -> m a;
}
```
#### `impl Result e: MonadErrorIF`

### type ErrorType

```
    type ErrorType (Result e) = e;
```
#### `impl IOFail: MonadErrorIF`

### type ErrorType

```
    type ErrorType IOFail = ErrMsg;
```
