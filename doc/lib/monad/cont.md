# cont.fix

## module Minilib.Monad.Cont

Continuation Monad.

### trait MonadCont = Monad + MonadContIF;

A trait for the interface of generic continuation  monads.

### trait MonadContIF

A trait for generic continuation  monads.

```
trait [cm: * -> *] cm: MonadContIF {
    // `call_cc(f)` calls `f` with the current continuation, and returns a continuation monad.
    // `f` takes the current continuation (the exit function) and should return a continuation monad.
    // For example, `call_cc(|exit| ... if condition { exit(false) }; ... pure(true))`.
```
#### call_cc: ((a -> cm b) -> cm a) -> cm a;

The exit function can be passed to another function.

### type ContT

A continuation monad transformer.
`r` is a type of the result of the continuation function.
`m` is a type of an underlyind monad.
`a` is a type of a value.

```
type [m: * -> *] ContT r m a = unbox struct {
    data: (a -> m r) -> m r
};
```
### type Cont

A continuation monad whose undelying monad is Identity.

```
type Cont r a = ContT r Identity a;
```
#### cont_t: [m: Monad] ((a -> m r) -> m r) -> ContT r m a;

Creates a ContT monad from a function which receives a continuation function and returns the monadic value of the result.

#### cont: ((a -> r) -> r) -> Cont r a;

Creates a Cont monad from a function which receives a continuation function and returns the result value.

#### run_cont_t: [m: Monad] (a -> m r) -> ContT r m a -> m r;

Runs a ContT monad with the supplied continuation function.

#### run_cont: (a -> r) -> Cont r a -> r;

Runs a Cont monad with the supplied continuation function.

#### lift_cont: [m: Monad] m a -> ContT r m a;

Lifts an underlying monad to a continuation monad.

#### `impl [m: Monad] ContT r m: Functor`

#### `impl [m: Monad] ContT r m: Monad`

#### `impl ContT r: MonadTrans`

#### `impl [m: Monad] ContT r m: MonadContIF`

