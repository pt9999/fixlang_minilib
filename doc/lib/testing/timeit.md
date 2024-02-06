# timeit.fix

## module Minilib.Testing.Timeit

Measures execution time. Similar to `timeit` module of Python.

#### timeit: [a: ToString] String -> (() -> a) -> IO a;

Measures execution time of a function.
It executes the function many times, and measures total time.
Prints the result and measured time per loop.

#### notimeit: [a: ToString] String -> (() -> a) -> IO a;

Same interface as `timeit()` but does not measure time.

#### get_now : IO Time;

Get current time.

#### consumed_realtime_while_io : IO a -> IO (a, F64);

