# state.fix

## module Minilib.Monad.State

State Monad which maintains a mutable state.

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

#### get_state: [m: Monad] StateT s m s;

A StateT monad that returns the current state as a value.

#### put_state: [m: Monad] s -> StateT s m ();

Creates a StateT monad of the specified state.

#### mod_state: [m: Monad] (s -> s) -> StateT s m ();

Creates a StateT monad that changes the state with the specified function.

#### lift_state: [m: Monad] m a -> StateT s m a;

Converts an underlying monad to a StateT monad.

#### map_state_t: [m: Monad, n: Monad] (m (a, s) -> n (b, s)) -> StateT s m a -> StateT s n b;

Maps both the return value and final state.

#### `impl [m: Monad] StateT s m: Functor`

#### `impl [m: Monad] StateT s m: Monad`

