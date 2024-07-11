# Module Minilib.Thread.TaskPool (task_pool.fix)

A task pool that can be used parallel computation.

A task pool creates IOTasks and starts them.
Each task waits for request until shutdown.
When the task receives the request, it performs the request as a computation.
When the task pool is shutdown, all tasks are stopped.
Computations are never performed after shutdown.


### `type TaskPool`

A task pool that manages a collection of IOTasks.

```
type TaskPool = unbox struct {
    chan: Channel FutureToken,
    tasks: Array (IOTask ())
};
```
### `make: I64 -> IO TaskPool;`

`TaskPool::make(task_count)` creates a TaskPool.

### `register_future: FutureToken -> TaskPool -> IOFail ();`

Register a future.
It sends a future token to the channel.

### `cancel_all_pendings_futures: TaskPool -> IO ();`

Cancel all pending futures and clears the queue.

### `is_shutdown: TaskPool -> IO Bool;`

Checks whether the taskpool has been shutdown.

### `shutdown: TaskPool -> IO TaskPool;`

Shutdowns a taskpool.

