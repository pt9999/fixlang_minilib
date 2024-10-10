# `module Minilib.Thread.TaskPool`

A task pool that can be used parallel computation.

A task pool creates IOTasks and starts them.
Each task waits for request until shutdown.
When the task receives the request, it performs the request as a computation.
When the task pool is shutdown, all tasks are stopped.
Computations are never performed after shutdown.

# Types and aliases

## `namespace Minilib.Thread.TaskPool`

### `type TaskPool = unbox struct { ...fields... }`

A task pool that manages a collection of IOTasks.

#### field `chan : Minilib.IO.Channel::Channel Minilib.Thread.Future::FutureToken`

#### field `tasks : Std::Array (AsyncTask::AsyncIOTask::IOTask ())`

# Traits and aliases

# Trait implementations

# Values

## `namespace Minilib.Thread.TaskPool`

### `_task_func : Minilib.IO.Channel::Channel Minilib.Thread.Future::FutureToken -> Std::IO ()`

The task function of the taskpool.

### `cancel_all_pendings_futures : Minilib.Thread.TaskPool::TaskPool -> Std::IO ()`

Cancel all pending futures and clears the queue.

### `is_shutdown : Minilib.Thread.TaskPool::TaskPool -> Std::IO Std::Bool`

Checks whether the taskpool has been shutdown.

### `make : Std::I64 -> Std::IO Minilib.Thread.TaskPool::TaskPool`

`TaskPool::make(task_count)` creates a TaskPool.

### `register_future : Minilib.Thread.Future::FutureToken -> Minilib.Thread.TaskPool::TaskPool -> Std::IO::IOFail ()`

Register a future.
It sends a future token to the channel.

### `shutdown : Minilib.Thread.TaskPool::TaskPool -> Std::IO Minilib.Thread.TaskPool::TaskPool`

Shutdowns a taskpool.

## `namespace Minilib.Thread.TaskPool::TaskPool`

### `@chan : Minilib.Thread.TaskPool::TaskPool -> Minilib.IO.Channel::Channel Minilib.Thread.Future::FutureToken`

Retrieves the field `chan` from a value of `TaskPool`.

### `@tasks : Minilib.Thread.TaskPool::TaskPool -> Std::Array (AsyncTask::AsyncIOTask::IOTask ())`

Retrieves the field `tasks` from a value of `TaskPool`.

### `act_chan : [f : Std::Functor] (Minilib.IO.Channel::Channel Minilib.Thread.Future::FutureToken -> f (Minilib.IO.Channel::Channel Minilib.Thread.Future::FutureToken)) -> Minilib.Thread.TaskPool::TaskPool -> f Minilib.Thread.TaskPool::TaskPool`

Updates a value of `TaskPool` by applying a functorial action to field `chan`.

### `act_tasks : [f : Std::Functor] (Std::Array (AsyncTask::AsyncIOTask::IOTask ()) -> f (Std::Array (AsyncTask::AsyncIOTask::IOTask ()))) -> Minilib.Thread.TaskPool::TaskPool -> f Minilib.Thread.TaskPool::TaskPool`

Updates a value of `TaskPool` by applying a functorial action to field `tasks`.

### `mod_chan : (Minilib.IO.Channel::Channel Minilib.Thread.Future::FutureToken -> Minilib.IO.Channel::Channel Minilib.Thread.Future::FutureToken) -> Minilib.Thread.TaskPool::TaskPool -> Minilib.Thread.TaskPool::TaskPool`

Updates a value of `TaskPool` by applying a function to field `chan`.

### `mod_tasks : (Std::Array (AsyncTask::AsyncIOTask::IOTask ()) -> Std::Array (AsyncTask::AsyncIOTask::IOTask ())) -> Minilib.Thread.TaskPool::TaskPool -> Minilib.Thread.TaskPool::TaskPool`

Updates a value of `TaskPool` by applying a function to field `tasks`.

### `set_chan : Minilib.IO.Channel::Channel Minilib.Thread.Future::FutureToken -> Minilib.Thread.TaskPool::TaskPool -> Minilib.Thread.TaskPool::TaskPool`

Updates a value of `TaskPool` by setting field `chan` to a specified one.

### `set_tasks : Std::Array (AsyncTask::AsyncIOTask::IOTask ()) -> Minilib.Thread.TaskPool::TaskPool -> Minilib.Thread.TaskPool::TaskPool`

Updates a value of `TaskPool` by setting field `tasks` to a specified one.