# task_pool.fix

## module Minilib.Thread.TaskPool

A task pool that can be used parallel computation.

A task pool creates IOTasks and starts them.
Each task waits for request until shutdown.
When the task receives the request, it performs the request as a computation.
When the task pool is shutdown, all tasks are stopped.
Computations are never performed after shutdown.


### type TaskPool

A task pool that manages a collection of IOTasks.

```
type TaskPool = unbox struct {
    chan: Channel (IO ()),
    tasks: Array (IOTask ())
};
```
#### make: I64 -> IO TaskPool;

`TaskPool::make(task_count)` creates a TaskPool.

#### clear: TaskPool -> IO ();

Clears the queue of futures.

#### shutdown: TaskPool -> IO TaskPool;

Shutdowns a taskpool.

#### `impl TaskPool: FutureRunner`

