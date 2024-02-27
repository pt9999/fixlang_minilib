# state.fix

## module Minilib.Monad.State

State Monad. NOTE that currently this interface is unstable.

#### from_io: IO a -> m a;

#### from_iofail: IOFail a -> m a;

### type State

State monad wraps a function from a initial state to a pair of a value and a final state.

```
type State s a = unbox struct {
    _data: s -> (a, s)
};
```
### namespace State

#### make_state_monad: (s -> (a, s)) -> State s a;

Creates a State monad from a function.

#### run_state: s -> State s a -> (a, s);

Runs a State monad with the supplied initial state.

#### get_state_: State s s;

A State monad that returns the current state as a value.

#### put_state_: s -> State s ();

Creates a State monad of the specified state.

#### mod_state_: (s -> s) -> State s ();

Creates a State monad that changes the state with the specified function.

#### liftS: [f: Functor] State s a -> State (f s) (f a);

Lift a State monad.

#### `impl State s: Monad`

#### `impl State s: Functor`

#### get_state: m s;

`get_state` is a monad that returns the current state.

#### put_state: s -> m ();

`put_state(s)` is a monad that changes the state to `s`.

### trait StateMonad = Functor + Monad + GetPutState;

A trait of generic state monad.

#### `impl State s: GetPutState`

An implementation of `GetPutState` for the state monad.

#### mod_state: [m: StateMonad] (s -> s) -> m ();

`mod_state(f)` is a monad that modifies the state with `f`.
This is a weak typing because `[m: StateMonad]` does not have `s`.
If the type of `s` does not match, undefined behavior may occur.

#### to_state: m a -> State s a;

### type StateIO

StateIO monad wraps a function from a initial state to an IO monad
of a pair of a value and a final state.

```
type StateIO s a = unbox struct {
    _data: s -> IO (a, s)
};
```
### namespace StateIO

#### make_stateio_monad: (s -> IO (a, s)) -> StateIO s a;

Creates a StateIO monad from a function.

#### run_stateio: s -> StateIO s a -> IO (a, s);

Runs a StateIO monad with the supplied initial state.

#### `impl StateIO s: Functor`

#### `impl StateIO s: Monad`

#### `impl StateIO s: GetPutState`

#### to_stateio: m a -> StateIO s a;

#### `impl State s: ToStateIO`

#### `impl IO: ToStateIO`

#### `impl StateIO s: FromIO`

### trait StateIOMonad = StateMonad + FromIO;

### type StateIOF

StateIOF monad wraps a function from a initial state to an IOFail monad
of a pair of a value and a final state.

```
type StateIOF s a = unbox struct {
    _data: s -> IOFail (a, s)
};
```
### namespace StateIOF

#### make_stateiof_monad: (s -> IOFail (a, s)) -> StateIOF s a;

Creates a StateIOF monad from a function.

#### run_stateiof: s -> StateIOF s a -> IOFail (a, s);

Runs a StateIOF monad with the supplied initial state.

#### `impl StateIOF s: Functor`

#### `impl StateIOF s: Monad`

#### `impl StateIOF s: GetPutState`

#### to_stateiof: m a -> StateIOF s a;

#### `impl State s: ToStateIOF`

#### `impl StateIO s: ToStateIOF`

#### `impl IO: ToStateIOF`

#### `impl StateIOF s: FromIO`

#### `impl IOFail: ToStateIOF`

#### `impl StateIOF s: FromIOFail`

### trait StateIOFMonad = StateIOMonad + FromIOFail;

#### `impl Result ErrMsg: ToStateIOF`

