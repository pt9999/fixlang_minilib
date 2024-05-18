# error.fix

## module Minilib.Monad.Error

### trait MonadError = Monad + MonadErrorIF;

### trait MonadErrorIF

```
trait [m: * -> *] m: MonadErrorIF {
    type ErrorType m;
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
