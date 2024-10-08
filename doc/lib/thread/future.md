# Module Minilib.Thread.Future (future.fix)

A computation that is performed in a TaskPool in parallel.

### `type Future`

A computation that is performed in a TaskPool in parallel.

```
type Future a = unbox struct {
    var_state: Var FutureState,     // the state of a future
    var_result: Var (Option a)      // the result of a future
};
```
### `make: TaskPool -> IO a -> IOFail (Future a);`

`Future::make(task_pool, io) creates a Future.
`io` is performed in the task pool.
If the task pool has been shutdown, an error is thrown.

### `get: Future a -> IOFail a;`

Gets the result of the Future.
It waits for future state to be either completed or canceled.

### `type FutureState`

A state of a future.

```
type FutureState = unbox union {
    pending: (),
    running: (),
    completed: (),
    canceled: ()
};
```
## `namespace FutureToken`

### `make: Var FutureState -> IO () -> FutureToken;`

### `set_state: FutureState -> FutureToken -> IO ();`

