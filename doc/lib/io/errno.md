# Module Minilib.IO.Errno (errno.fix)

Functions for `errno` which is set by system calls and some library functions.

### `clear_errno: IO ();`

Clears `errno`, the global variable that stores the last error number.

### `get_errno: IO CInt;`

Gets the last error number from `errno`.

### `get_last_error: IO String;`

Gets the error message corresponding to the last error number.

### `strerror: CInt -> IO String;`

Converts the error number returned by `get_errno` to a string.
This function may have race conditions, but is more portable.

### `strerror_r: CInt -> IO String;`

Converts the error number returned by `get_errno` to a string.
This function has no race conditions, but is less portable.  (This function is GNU C library specific)

