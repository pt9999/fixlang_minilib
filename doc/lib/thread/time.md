# time.fix

## module Minilib.Thread.Time

Timing module, such as sleep for a while, and measuring execution time.

#### usleep: U32 -> IOFail ();

Sleeps for specified micro-seconds.
For details, see Linux manual page for [usleep()](https://man7.org/linux/man-pages/man3/usleep.3.html).

#### timeit: [a: ToString] String -> (() -> a) -> IO a;

Measures wall-clock time per a function call.
Specifically, It calls the function many times and measures the total time.
It then prints the function result and measured time per loop.
NOTE: The measured time per loop has a overhead about 0.1~1.0 usec.

#### timeit_io: [a: ToString] String -> IO a -> IO a;

Measures wall-clock time per an IO operation.
Specifically, It performs an IO operation many times and measures the total time.
It then prints the IO operation result and measured time per loop.
NOTE: The measured time per loop has a overhead about 0.1~1.0 usec.

#### notimeit: [a: ToString] String -> (() -> a) -> IO a;

Same interface as `timeit()` but does not measure time.

#### consumed_realtime_while_io : IO a -> IO (a, F64);

Get wall-clock time elapsed while executing an I/O action.

