# trans.fix

## module Minilib.Monad.Trans

### trait MonadTrans

Trait for a monad transformer.

```
trait [t: (* -> *) -> (* -> *)] t: MonadTrans {
    // Lifts an underlying monad to a transformed monad.
    lift_t: [m: Monad] m a -> t m a;
}
```