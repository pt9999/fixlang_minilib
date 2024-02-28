# platform.fix

## module Minilib.IO.Platform

Get kernel information such as system name, machine archtecture.

### type UName

A type of name and information of current kernel.

```
type UName = unbox struct {
    sysname: String,
    nodename: String,
    release: String,
    version: String,
    machine: String
};
```
#### uname: UName;

The name and information of current kernel.
Calls POSIX C function `uname()`, and split the result by null characters.
NOTE: The system information does not change during program execution,
so this variable is constant.

#### byte_order: ByteOrder;

The byte order of platform.

