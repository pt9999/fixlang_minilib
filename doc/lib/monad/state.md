# state.fix

## module Minilib.Monad.State

State Monad which maintains a mutable state.

### type State

State monad wraps a function from a initial state to a pair of a value and a final state.

```
type State s a = unbox struct {
    _data: s -> (a, s)
};
```
#### make_state_monad: (s -> (a, s)) -> State s a;

Creates a State monad from a function.

#### run_state: s -> State s a -> (a, s);

Runs a State monad with the supplied initial state.

#### get_state: State s s;

A State monad that returns the current state as a value.

#### put_state: s -> State s ();

Creates a State monad of the specified state.

#### mod_state: (s -> s) -> State s ();

Creates a State monad that changes the state with the specified function.

#### liftS: [f: Functor] State s a -> State (f s) (f a);

Lift a State monad.

#### `impl State s: Monad`

#### `impl State s: Functor`

