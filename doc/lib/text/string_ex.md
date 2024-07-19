# Module Minilib.Text.StringEx (string_ex.fix)

String utility functions.

Features:
- Array U8 -> String conversion
- Search, replace, split, comparison of String
- Format
- ToString extensions

### `to_lower: String -> String;`

Converts the specified string to lowercase.

### `to_upper: String -> String;`

Converts the specified string to uppercase.

### `byte_to_string: U8 -> String;`

Converts a byte (a character) to a string of length 1.

### `find_byte: U8 -> String -> Option I64;`

Searches for the specified byte from the beginning of a string.
If found, returns the index of that byte.

### `find_last_byte: U8 -> String -> Option I64;`

Searches for the specified byte from the end of a string.
If found, returns the index of that byte.

### `replace_all: String -> String -> String -> String;`

`input.replace_all(from, to)` replaces all occurrences of `from` in the input string with `to`.

### `replace_suffix: String -> String -> String -> Result ErrMsg String;`

`str.replace_suffix(from, to)` replaces `from` at the end of `str` with `to`.
if `str` does not end with `from`, an error occurs.
Example:
```
"test.txt".replace_suffix(".txt", ".tmp")  ==> ok("test.tmp")
"test.jpg".replace_suffix(".txt", ".tmp")  ==> err("suffix does not match: test.jpg")
```

### `split_first: String -> String -> (String, String);`

`str.split_first(delim)` splits the string `str` into two parts with the delimiter `delim`.
Returns `(left, right)` where `left` is the left part of the delimiter, and
`right` is the right part of the delimiter.
Returns `(str, "")` if the delimiter is not found.

### `split_ex: String -> String -> Iterator String;`

Same as Std::String::split, except that `"foo".split_ex(",")` returns a singleton iterator of "foo".

### `split_by: (U8 -> Bool) -> String -> Iterator String;`

Splits a string by a function that checks whether a character is a delimiter or not.
The result will not contain any empty string.

### `substring: I64 -> I64 -> String -> String;`

Returns a substring extracted from a specified range from a string.
If the specified range exceeds the string, it will be truncated to fit within the string.

### `subarray: I64 -> I64 -> Array a -> Array a;`

Returns a subarray extracted from a specified range from an array.
If the specified range exceeds the array, it will be truncated to fit within the array.

### `starts_with: String -> String -> Bool;`

Checks if a string starts with the specified prefix.

### `ends_with: String -> String -> Bool;`

Checks if a string ends with the specified suffix.

### `formatv: String -> Array String -> String;`

`array.formatv(str)` replaces each occurence of `{}` in the format string `str`
with each element of `array`.
Currently only supports `{}`.

## `namespace Array`

### `format: [a: ToString] String -> Array a -> String;`

`array.format(str)` replaces each occurence of `{}` in the format string `str`
with each element of `array`.
Currently only supports `{}`.

## `namespace Tuple1`

### `format: [a: ToString] String -> (a,) -> String;`

`(a, ).format(str)` replaces an occurence of `{}` in the format string `str`
with `a`.

## `namespace Tuple2`

### `format: [a: ToString, b: ToString] String -> (a,b) -> String;`

`(a, b).format(str)` replaces each occurence of `{}` in the format string `str`
with `a`, `b`.

## `namespace Tuple3`

### `format: [a: ToString, b: ToString, c:ToString] String -> (a,b,c) -> String;`

`(a, b, c).format(str)` replaces each occurence of `{}` in the format string `str`
with `a`, `b`, `c`.

## `namespace Tuple4`

### `format: [a: ToString, b: ToString, c:ToString, d:ToString] String -> (a,b,c,d) -> String;`

`(a, b, c, d).format(str)` replaces each occurence of `{}` in the format string `str`
with `a`, `b`, `c`, `d`.

## `namespace Tuple5`

### `format: [a: ToString, b: ToString, c:ToString, d:ToString, e:ToString] String -> (a,b,c,d,e) -> String;`

`(a, b, c, d, e).format(str)` replaces each occurence of `{}` in the format string `str`
with `a`, `b`, `c`, `d`, `e`.

## `namespace HashMap`

### `to_string_ex: [k: ToString, v: ToString] HashMap k v -> String;`

Converts `HashMap k v` to a string, for example `"{a:1,b:2}"` etc.

