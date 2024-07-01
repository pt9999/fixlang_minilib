# state.fix

## module Minilib.Monad.State

State Monad which maintains a mutable state.

### trait MonadState = Monad + MonadStateIF;

A trait for the interface of generic state monads.

### trait MonadStateIF

A trait for generic state monads that manages the internal state.

```
trait [sm: * -> *] sm: MonadStateIF {
    // The type of the internal state.
    type StateType sm;
    // A monad that returns the internal state as a value.
    get_state: sm (StateType sm);
    // A monad that puts the specified value to the internal state.
    put_state: (StateType sm) -> sm ();
}
```
#### mod_state: [sm: MonadState] (StateType sm -> StateType sm) -> sm ();

A monad that modifies the current state with the specified function.

### type StateT

State monad wraps a function from a initial state to a pair of a value and a final state.

```
type [m: *->*] StateT s m a = unbox struct {
    data: s -> m (a, s)
};
```
### type State

```
type State s a = StateT s Identity a;
```
#### make_state_t_monad: [m: Monad] (s -> m (a, s)) -> StateT s m a;

Creates a StateT monad from a function.

#### make_state_monad: (s -> (a, s)) -> State s a;

Creates a State monad from a function.

#### run_state_t: [m: Monad] s -> StateT s m a -> m (a, s);

Runs a StateT monad with the supplied initial state.

#### run_state: s -> State s a -> (a, s);

Runs a State monad with the supplied initial state.

#### eval_state_t: [m: Monad] s -> StateT s m a -> m a;

Runs a StateT monad with the supplied initial state and return the final value, discarding the final state.

#### exec_state_t: [m: Monad] s -> StateT s m a -> m s;

Runs a StateT monad with the supplied initial state and return the final state, discarding the final value.

#### lift_state: [m: Monad] m a -> StateT s m a;

Converts an underlying monad to a StateT monad.

#### map_state_t: [m: Monad, n: Monad] (m (a, s) -> n (b, s)) -> StateT s m a -> StateT s n b;

Maps both the return value and final state.

#### `impl [m: Monad] StateT s m: Functor`

#### `impl [m: Monad] StateT s m: Monad`

#### `impl [m: Monad] StateT s m: MonadStateIF`

#### `impl StateT s: MonadTrans`

#### `impl [m: MonadError] StateT s m: MonadErrorIF`

#### `impl [m: MonadIO] StateT s m: MonadIOIF`

#### `impl [m: MonadIOFail] StateT s m: MonadIOFailIF`

