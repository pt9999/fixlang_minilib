# `module Minilib.Text.StringEx`

String utility functions.

Features:
- Array U8 -> String conversion
- Search, replace, split, comparison of String
- Format
- ToString extensions

# Types and aliases

# Traits and aliases

# Trait implementations

# Values

## `namespace Minilib.Text.StringEx`

### `_append_range : Std::Array a -> Std::I64 -> Std::I64 -> Std::Array a -> Std::Array a`

### `_unsafe_to_string : Std::Array Std::U8 -> Std::String`

Converts a byte array to a string. Specifically, it calls `String::_unsafe_to_string()`
after appending a null character to the end of the byte array.

### `byte_to_string : Std::U8 -> Std::String`

Converts a byte (a character) to a string of length 1.

### `ends_with : Std::String -> Std::String -> Std::Bool`

Checks if a string ends with the specified suffix.

### `find_byte : Std::U8 -> Std::String -> Std::Option Std::I64`

Searches for the specified byte from the beginning of a string.
If found, returns the index of that byte.

### `find_last_byte : Std::U8 -> Std::String -> Std::Option Std::I64`

Searches for the specified byte from the end of a string.
If found, returns the index of that byte.

### `formatv : Std::String -> Std::Array Std::String -> Std::String`

`array.formatv(str)` replaces each occurence of `{}` in the format string `str`
with each element of `array`.
Currently only supports `{}`.

### `replace_all : Std::String -> Std::String -> Std::String -> Std::String`

`input.replace_all(from, to)` replaces all occurrences of `from` in the input string with `to`.

### `replace_suffix : Std::String -> Std::String -> Std::String -> Std::Result Std::String Std::String`

`str.replace_suffix(from, to)` replaces `from` at the end of `str` with `to`.
if `str` does not end with `from`, an error occurs.
Example:
```
"test.txt".replace_suffix(".txt", ".tmp")  ==> ok("test.tmp")
"test.jpg".replace_suffix(".txt", ".tmp")  ==> err("suffix does not match: test.jpg")
```

### `split_by : (Std::U8 -> Std::Bool) -> Std::String -> Std::Iterator Std::String`

Splits a string by a function that checks whether a character is a delimiter or not.
The result will not contain any empty string.

### `split_ex : Std::String -> Std::String -> Std::Iterator Std::String`

Same as Std::String::split, except that `"foo".split_ex(",")` returns a singleton iterator of "foo".

### `split_first : Std::String -> Std::String -> (Std::String, Std::String)`

`str.split_first(delim)` splits the string `str` into two parts with the delimiter `delim`.
Returns `(left, right)` where `left` is the left part of the delimiter, and
`right` is the right part of the delimiter.
Returns `(str, "")` if the delimiter is not found.

### `starts_with : Std::String -> Std::String -> Std::Bool`

Checks if a string starts with the specified prefix.

### `subarray : Std::I64 -> Std::I64 -> Std::Array a -> Std::Array a`

Returns a subarray extracted from a specified range from an array.
If the specified range exceeds the array, it will be truncated to fit within the array.

### `substring : Std::I64 -> Std::I64 -> Std::String -> Std::String`

Returns a substring extracted from a specified range from a string.
If the specified range exceeds the string, it will be truncated to fit within the string.

### `to_lower : Std::String -> Std::String`

Converts the specified string to lowercase.

### `to_upper : Std::String -> Std::String`

Converts the specified string to uppercase.

## `namespace Minilib.Text.StringEx::Array`

### `format : [a : Std::ToString] Std::String -> Std::Array a -> Std::String`

`array.format(str)` replaces each occurence of `{}` in the format string `str`
with each element of `array`.
Currently only supports `{}`.

## `namespace Minilib.Text.StringEx::HashMap`

### `to_string_ex : [k : Std::ToString, v : Std::ToString] HashMap::HashMap k v -> Std::String`

Converts `HashMap k v` to a string, for example `"{a:1,b:2}"` etc.

## `namespace Minilib.Text.StringEx::Tuple1`

### `format : [a : Std::ToString] Std::String -> (a,) -> Std::String`

`(a, ).format(str)` replaces an occurence of `{}` in the format string `str`
with `a`.

## `namespace Minilib.Text.StringEx::Tuple2`

### `format : [a : Std::ToString, b : Std::ToString] Std::String -> (a, b) -> Std::String`

`(a, b).format(str)` replaces each occurence of `{}` in the format string `str`
with `a`, `b`.

## `namespace Minilib.Text.StringEx::Tuple3`

### `format : [a : Std::ToString, b : Std::ToString, c : Std::ToString] Std::String -> (a, b, c) -> Std::String`

`(a, b, c).format(str)` replaces each occurence of `{}` in the format string `str`
with `a`, `b`, `c`.

## `namespace Minilib.Text.StringEx::Tuple4`

### `format : [a : Std::ToString, b : Std::ToString, c : Std::ToString, d : Std::ToString] Std::String -> (a, b, c, d) -> Std::String`

`(a, b, c, d).format(str)` replaces each occurence of `{}` in the format string `str`
with `a`, `b`, `c`, `d`.

## `namespace Minilib.Text.StringEx::Tuple5`

### `format : [a : Std::ToString, b : Std::ToString, c : Std::ToString, d : Std::ToString, e : Std::ToString] Std::String -> (a, b, c, d, e) -> Std::String`

`(a, b, c, d, e).format(str)` replaces each occurence of `{}` in the format string `str`
with `a`, `b`, `c`, `d`, `e`.