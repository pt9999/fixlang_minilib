# `module Minilib.Thread.Future`

A computation that is performed in a TaskPool in parallel.

# Types and aliases

## `namespace Minilib.Thread.Future`

### `type Future a = unbox struct { ...fields... }`

A computation that is performed in a TaskPool in parallel.

#### field `var_state : AsyncTask::Var::Var Minilib.Thread.Future::FutureState`

#### field `var_result : AsyncTask::Var::Var (Std::Option a)`

### `type FutureState = unbox union { ...variants... }`

A state of a future.

#### variant `pending : ()`

#### variant `running : ()`

#### variant `completed : ()`

#### variant `canceled : ()`

### `type FutureToken = unbox struct { ...fields... }`

[nofixdoc]
A token of a future for the taskpool.
Since the taskpool has no type variable, it cannot perform `IO a`.
So the future token has `IO ()`.

#### field `var_state : AsyncTask::Var::Var Minilib.Thread.Future::FutureState`

#### field `io_unit : Std::IO ()`

# Traits and aliases

# Trait implementations

# Values

## `namespace Minilib.Thread.Future`

### `get : Minilib.Thread.Future::Future a -> Std::IO::IOFail a`

Gets the result of the Future.
It waits for future state to be either completed or canceled.

### `make : Minilib.Thread.TaskPool::TaskPool -> Std::IO a -> Std::IO::IOFail (Minilib.Thread.Future::Future a)`

`Future::make(task_pool, io) creates a Future.
`io` is performed in the task pool.
If the task pool has been shutdown, an error is thrown.

## `namespace Minilib.Thread.Future::Future`

### `@var_result : Minilib.Thread.Future::Future a -> AsyncTask::Var::Var (Std::Option a)`

Retrieves the field `var_result` from a value of `Future`.

### `@var_state : Minilib.Thread.Future::Future a -> AsyncTask::Var::Var Minilib.Thread.Future::FutureState`

Retrieves the field `var_state` from a value of `Future`.

### `act_var_result : [f : Std::Functor] (AsyncTask::Var::Var (Std::Option a) -> f (AsyncTask::Var::Var (Std::Option a))) -> Minilib.Thread.Future::Future a -> f (Minilib.Thread.Future::Future a)`

Updates a value of `Future` by applying a functorial action to field `var_result`.

### `act_var_state : [f : Std::Functor] (AsyncTask::Var::Var Minilib.Thread.Future::FutureState -> f (AsyncTask::Var::Var Minilib.Thread.Future::FutureState)) -> Minilib.Thread.Future::Future a -> f (Minilib.Thread.Future::Future a)`

Updates a value of `Future` by applying a functorial action to field `var_state`.

### `mod_var_result : (AsyncTask::Var::Var (Std::Option a) -> AsyncTask::Var::Var (Std::Option a)) -> Minilib.Thread.Future::Future a -> Minilib.Thread.Future::Future a`

Updates a value of `Future` by applying a function to field `var_result`.

### `mod_var_state : (AsyncTask::Var::Var Minilib.Thread.Future::FutureState -> AsyncTask::Var::Var Minilib.Thread.Future::FutureState) -> Minilib.Thread.Future::Future a -> Minilib.Thread.Future::Future a`

Updates a value of `Future` by applying a function to field `var_state`.

### `set_var_result : AsyncTask::Var::Var (Std::Option a) -> Minilib.Thread.Future::Future a -> Minilib.Thread.Future::Future a`

Updates a value of `Future` by setting field `var_result` to a specified one.

### `set_var_state : AsyncTask::Var::Var Minilib.Thread.Future::FutureState -> Minilib.Thread.Future::Future a -> Minilib.Thread.Future::Future a`

Updates a value of `Future` by setting field `var_state` to a specified one.

## `namespace Minilib.Thread.Future::FutureState`

### `as_canceled : Minilib.Thread.Future::FutureState -> ()`

Unwraps a union value of `FutureState` as the variant `canceled`.
If the value is not the variant `canceled`, this function aborts the program.

### `as_completed : Minilib.Thread.Future::FutureState -> ()`

Unwraps a union value of `FutureState` as the variant `completed`.
If the value is not the variant `completed`, this function aborts the program.

### `as_pending : Minilib.Thread.Future::FutureState -> ()`

Unwraps a union value of `FutureState` as the variant `pending`.
If the value is not the variant `pending`, this function aborts the program.

### `as_running : Minilib.Thread.Future::FutureState -> ()`

Unwraps a union value of `FutureState` as the variant `running`.
If the value is not the variant `running`, this function aborts the program.

### `canceled : () -> Minilib.Thread.Future::FutureState`

Constructs a value of union `FutureState` taking the variant `canceled`.

### `completed : () -> Minilib.Thread.Future::FutureState`

Constructs a value of union `FutureState` taking the variant `completed`.

### `is_canceled : Minilib.Thread.Future::FutureState -> Std::Bool`

Checks if a union value of `FutureState` is the variant `canceled`.

### `is_completed : Minilib.Thread.Future::FutureState -> Std::Bool`

Checks if a union value of `FutureState` is the variant `completed`.

### `is_pending : Minilib.Thread.Future::FutureState -> Std::Bool`

Checks if a union value of `FutureState` is the variant `pending`.

### `is_running : Minilib.Thread.Future::FutureState -> Std::Bool`

Checks if a union value of `FutureState` is the variant `running`.

### `mod_canceled : (() -> ()) -> Minilib.Thread.Future::FutureState -> Minilib.Thread.Future::FutureState`

Updates a value of union `FutureState` by applying a function if it is the variant `canceled`, or doing nothing otherwise.

### `mod_completed : (() -> ()) -> Minilib.Thread.Future::FutureState -> Minilib.Thread.Future::FutureState`

Updates a value of union `FutureState` by applying a function if it is the variant `completed`, or doing nothing otherwise.

### `mod_pending : (() -> ()) -> Minilib.Thread.Future::FutureState -> Minilib.Thread.Future::FutureState`

Updates a value of union `FutureState` by applying a function if it is the variant `pending`, or doing nothing otherwise.

### `mod_running : (() -> ()) -> Minilib.Thread.Future::FutureState -> Minilib.Thread.Future::FutureState`

Updates a value of union `FutureState` by applying a function if it is the variant `running`, or doing nothing otherwise.

### `pending : () -> Minilib.Thread.Future::FutureState`

Constructs a value of union `FutureState` taking the variant `pending`.

### `running : () -> Minilib.Thread.Future::FutureState`

Constructs a value of union `FutureState` taking the variant `running`.

## `namespace Minilib.Thread.Future::FutureToken`

### `@io_unit : Minilib.Thread.Future::FutureToken -> Std::IO ()`

Retrieves the field `io_unit` from a value of `FutureToken`.

### `@var_state : Minilib.Thread.Future::FutureToken -> AsyncTask::Var::Var Minilib.Thread.Future::FutureState`

Retrieves the field `var_state` from a value of `FutureToken`.

### `act_io_unit : [f : Std::Functor] (Std::IO () -> f (Std::IO ())) -> Minilib.Thread.Future::FutureToken -> f Minilib.Thread.Future::FutureToken`

Updates a value of `FutureToken` by applying a functorial action to field `io_unit`.

### `act_var_state : [f : Std::Functor] (AsyncTask::Var::Var Minilib.Thread.Future::FutureState -> f (AsyncTask::Var::Var Minilib.Thread.Future::FutureState)) -> Minilib.Thread.Future::FutureToken -> f Minilib.Thread.Future::FutureToken`

Updates a value of `FutureToken` by applying a functorial action to field `var_state`.

### `make : AsyncTask::Var::Var Minilib.Thread.Future::FutureState -> Std::IO () -> Minilib.Thread.Future::FutureToken`

### `mod_io_unit : (Std::IO () -> Std::IO ()) -> Minilib.Thread.Future::FutureToken -> Minilib.Thread.Future::FutureToken`

Updates a value of `FutureToken` by applying a function to field `io_unit`.

### `mod_var_state : (AsyncTask::Var::Var Minilib.Thread.Future::FutureState -> AsyncTask::Var::Var Minilib.Thread.Future::FutureState) -> Minilib.Thread.Future::FutureToken -> Minilib.Thread.Future::FutureToken`

Updates a value of `FutureToken` by applying a function to field `var_state`.

### `set_io_unit : Std::IO () -> Minilib.Thread.Future::FutureToken -> Minilib.Thread.Future::FutureToken`

Updates a value of `FutureToken` by setting field `io_unit` to a specified one.

### `set_state : Minilib.Thread.Future::FutureState -> Minilib.Thread.Future::FutureToken -> Std::IO ()`

### `set_var_state : AsyncTask::Var::Var Minilib.Thread.Future::FutureState -> Minilib.Thread.Future::FutureToken -> Minilib.Thread.Future::FutureToken`

Updates a value of `FutureToken` by setting field `var_state` to a specified one.