# time.fix

## module Minilib.Testing.Time

Timing module, such as sleep for a while, and measuring execution time.

#### usleep: U32 -> IOFail ();

Sleeps for specified micro-seconds.
For details, see Linux manual page for [usleep()](https://man7.org/linux/man-pages/man3/usleep.3.html).

#### timeit: [a: ToString] String -> (() -> a) -> IO a;

Measures execution time of a function.
It executes the function many times, and measures total time.
Prints the result and measured time per loop.

#### notimeit: [a: ToString] String -> (() -> a) -> IO a;

Same interface as `timeit()` but does not measure time.

#### consumed_realtime_while_io : IO a -> IO (a, F64);

