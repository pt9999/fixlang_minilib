# Module Minilib.IO.Path (path.fix)

File Path handling, such as joining paths and retrieving directory name.

### `is_path_sep: U8 -> Bool;`

Checks if the byte is a path separator. Currently only '/' is supported.

### `join_paths: Array String -> String;`

`join_paths(path_segments)` joins segments into a path.

### `basename: String -> String;`

`basename(path)` returns the last non-slash component. The trailing slashes are removed.

### `dirname: String -> String;`

`dirname(path)` returns the path with its last non-slash component and trailing slashes removed.
if `path` contains no `/`s, returns `"."`.

### `relativize: String -> String -> Result ErrMsg String;`

`base.relativize(target)` constructs a relative path from `base` to `target`.
`base` and `target` should have the same type (i.e. relative path or absolute path).
If only one of `base` and `target` is an absolute path, "different type of path" error is returned.
If `base` == `target`, then an empty string is returned.

