# io_ex.fix

## module IOEx

IO extensions, such as:
- Create or delete files and directories
- Directory listing
- Find files under directory
- Checks if file or directory exists
- Retrieve file information, such as file size and time stamps
- Get kernel information such as system name, machine archtecture

#### creat: String -> U32 -> IOFail I32;

Creates a new file or rewrites an existing one.
For details, see Linux manual page for [creat()](https://man7.org/linux/man-pages/man3/creat.3p.html).

#### unlink: String -> IOFail ();

Deletes a name from the filesystem and possibly the file it refers to.
For details, see Linux manual page for [unlink()](https://man7.org/linux/man-pages/man2/unlink.2.html).

#### fflush : IOHandle -> IOFail ();

Flushes a file stream.
For details, see Linux manual page for [fflush()](https://man7.org/linux/man-pages/man3/fflush.3.html).

#### fdopen: I32 -> String -> IOFail IOHandle;

Associates a stream with a file descriptor.
For details, see Linux manual page for [fdopen()](https://man7.org/linux/man-pages/man3/fdopen.3p.html).

#### pipe: IOFail (I32, I32);

Creates a pipe. It returns `(read_fd, write_fd)` where `read_fd` is the file descriptor of
read-end of the pipe, and `write_fd` is the file descriptor of write-end of the pipe.
For details, see Linux manual page for [pipe()](https://man7.org/linux/man-pages/man2/pipe.2.html).

#### open_pipe: IOFail (IOHandle, IOHandle);

Creates a pipe stream. It returns `(read_fh, write_fh)` where `read_fd` is the stream of
read-end of the pipe, and `write_fd` is the stream of write-end of the pipe.
For details, see Linux manual page for [pipe()](https://man7.org/linux/man-pages/man2/pipe.2.html).

#### usleep: U32 -> IOFail ();

Sleeps for specified micro-seconds.
For details, see Linux manual page for [usleep()](https://man7.org/linux/man-pages/man3/usleep.3.html).

#### list_dir: String -> IOFail (Array String);

Lists a directory.
Returns filenames in the specified directory.
The filenames will be sorted in lexicographical order.

#### file_exists: String -> IO Bool;

Returns true if the specified file exists.

#### directory_exists: String -> IO Bool;

Returns true if the specified directory exists.

### type FileStat

Type of file status

```
type FileStat = unbox struct {
    data: ByteBuffer  // struct stat
};
```
### namespace FileStat

#### stat: String -> IOFail FileStat;

`stat(file_path)` retrieves information about the file pointed to by `file_path`.

#### is_file: FileStat -> Bool;

Returns true if it is a regular file.

#### is_dir: FileStat -> Bool;

Returns true if it is a directory.

#### st_dev: FileStat -> U64;

#### st_ino: FileStat -> U64;

#### st_nlink: FileStat -> U64;

#### st_mode: FileStat -> U32;

#### st_uid: FileStat -> U32;

#### st_gid: FileStat -> U32;

#### st_rdev: FileStat -> U64;

#### st_size: FileStat -> I64;

#### st_blksize: FileStat -> I64;

#### st_blocks: FileStat -> U64;

#### st_atime: FileStat -> U64;

#### st_mtime: FileStat -> U64;

#### st_ctime: FileStat -> U64;

#### find_files: String -> IOFail (Array String);

`find_files(dir_path)` finds all files under
specified directory and its subdirectories.

#### mkdir: String -> Option U32 -> IOFail ();

`mkdir(path, mode)` creates a directory.
If `mode` is `none()`, octal 0777 is used as a mode.
This mode is modified by the process's umask in the usual way.

#### rmdir: String -> IOFail ();

`rmdir(path)` deletes a directory, which must be empty.

#### make_dirs: String -> Option U32 -> IOFail ();

`make_dirs(dir_path, mode)` creates specified directory
as well as its parent directories recursively.
If the directory already exists, it does nothing.
If `mode` is `none()`, octal 0777 is used as a mode.
This mode is modified by the process's umask in the usual way.

### namespace Platform

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

