# future.fix

## module Minilib.Task.Future

A computation that is performed in a TaskPool in parallel.

### type Future

A computation that is performed in a TaskPool in parallel.

```
type Future a = unbox struct {
    var: Var (Option a)
};
```
### trait FutureRunner

A trait that can perform the computation of a Future.

```
trait r: FutureRunner {
    run_future: IO () -> r -> IOFail ();
}
```
#### make: [r: FutureRunner] r -> IO a -> IOFail (Future a);

`Future::make(runner, io) creates a Future.
`io` is performed in the runner.
If the runner has been shutdown, the future will never be resolved.

#### get: Future a -> IO a;

Gets the result of the Future.
If the `io` is not performed yet, wait until `io` is performed.
If the taskpool has been shutdown, it may or may not wait forever.

