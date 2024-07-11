# Module Minilib.IO.FileSystem (file_system.fix)

File system module. For example, finding files, checks if file or directory exists,
getting file size and last modified time.

### `file_exists: String -> IO Bool;`

Returns true if the specified file exists.

### `directory_exists: String -> IO Bool;`

Returns true if the specified directory exists.

### `type FileStat`

Type of file status

```
type FileStat = unbox struct {
    data: ByteBuffer  // struct stat
};
```
## `namespace FileStat`

### `stat: String -> IOFail FileStat;`

`stat(file_path)` retrieves information about the file pointed to by `file_path`.

### `is_file: FileStat -> Bool;`

Returns true if it is a regular file.

### `is_dir: FileStat -> Bool;`

Returns true if it is a directory.

### `st_dev: FileStat -> U64;`

### `st_ino: FileStat -> U64;`

### `st_nlink: FileStat -> U64;`

### `st_mode: FileStat -> U32;`

### `st_uid: FileStat -> U32;`

### `st_gid: FileStat -> U32;`

### `st_rdev: FileStat -> U64;`

### `st_size: FileStat -> I64;`

### `st_blksize: FileStat -> I64;`

### `st_blocks: FileStat -> U64;`

### `st_atime: FileStat -> U64;`

### `st_mtime: FileStat -> U64;`

### `st_ctime: FileStat -> U64;`

### `find_files: String -> IOFail (Array String);`

`find_files(dir_path)` finds all files under
specified directory and its subdirectories.

### `list_dir: String -> IOFail (Array String);`

Lists a directory.
Returns filenames in the specified directory.
The filenames will be sorted in lexicographical order.

### `make_dirs: String -> Option U32 -> IOFail ();`

`make_dirs(dir_path, mode)` creates specified directory
as well as its parent directories recursively.
If the directory already exists, it does nothing.
If `mode` is `none()`, octal 0777 is used as a mode.
This mode is modified by the process's umask in the usual way.

### `mkdir: String -> Option U32 -> IOFail ();`

`mkdir(path, mode)` creates a directory.
If `mode` is `none()`, octal 0777 is used as a mode.
This mode is modified by the process's umask in the usual way.

### `rmdir: String -> IOFail ();`

`rmdir(path)` deletes a directory, which must be empty.

### `fflush : IOHandle -> IOFail ();`

Flushes a file stream.
For details, see Linux manual page for [fflush()](https://man7.org/linux/man-pages/man3/fflush.3.html).

### `set_unbuffered_mode: IOHandle -> IO ();`

Sets IOHandle to unbuffered mode.
For detials, see Linux manual page for [setbuf()](https://man7.org/linux/man-pages/man3/setbuf.3.html).
NOTE: When a fix program is invoked by `run_with_stream()`,
then the stdout and stderr becomes not a TTY but a file stream.
So the stdout becomes block-buffered. The stderr also seems to be block-buffered.

### `creat: String -> U32 -> IOFail I32;`

Creates a new file or rewrites an existing one.
For details, see Linux manual page for [creat()](https://man7.org/linux/man-pages/man3/creat.3p.html).

### `unlink: String -> IOFail ();`

Deletes a name from the filesystem and possibly the file it refers to.
For details, see Linux manual page for [unlink()](https://man7.org/linux/man-pages/man2/unlink.2.html).

### `fdopen: I32 -> String -> IOFail IOHandle;`

Associates a stream with a file descriptor.
For details, see Linux manual page for [fdopen()](https://man7.org/linux/man-pages/man3/fdopen.3p.html).

### `pipe: IOFail (I32, I32);`

Creates a pipe. It returns `(read_fd, write_fd)` where `read_fd` is the file descriptor of
read-end of the pipe, and `write_fd` is the file descriptor of write-end of the pipe.
For details, see Linux manual page for [pipe()](https://man7.org/linux/man-pages/man2/pipe.2.html).

### `open_pipe: IOFail (IOHandle, IOHandle);`

Creates a pipe stream. It returns `(read_fh, write_fh)` where `read_fd` is the stream of
read-end of the pipe, and `write_fd` is the stream of write-end of the pipe.
For details, see Linux manual page for [pipe()](https://man7.org/linux/man-pages/man2/pipe.2.html).

