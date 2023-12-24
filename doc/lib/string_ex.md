# string_ex.fix

## module StringEx

String extensions

#### `impl (): ToString`

Converts `()` to a string `"()"`.

#### `impl [a : ToString, b : ToString, c : ToString] (a, b, c) : ToString`

Converts `(a, b, c)` to a string, for example `"(123, 3.14, abc)"`.

#### `impl [a : ToString, b : ToString, c : ToString, d : ToString] (a, b, c, d) : ToString`

Converts `(a, b, c, d)` to a string, for example `"(123, 3.14, abc, ())"`.

#### `impl [a: ToString] Option a: ToString`

Converts `Option a` to a string, for example `"none()"`, `"some(1)"` etc.

#### `impl [a: ToString, e: ToString] Result e a: ToString`

Converts `Result e a` to a string, for example `"err(File not found)"`, `"ok(1)"` etc.

#### `impl [k: ToString, v: ToString] HashMap k v : ToString`

Converts `HashMap k v` to a string, for example `"{a:1,b:2}"` etc.

#### `impl [a: ToString] Array a: ToString`

Converts `Array a` to a string, for example `"[1,2,3]"` etc.

#### to_lower: String -> String;

Converts the specified string to lowercase.

#### to_upper: String -> String;

Converts the specified string to uppercase.

#### byte_to_string: U8 -> String;

Converts a byte (a character) to a string of length 1.

#### find_byte: U8 -> String -> Option I64;

Searches for the specified byte from the beginning of a string.
If found, returns the index of that byte.

#### replace_all: String -> String -> String -> String;

Replaces all occurrences of `from` in the string with `to`.

#### split_first: String -> String -> (String, String);

`str.split_first(delim)` splits the string `str` into two parts with the delimiter `delim`.
Returns `(left, right)` where `left` is the left part of the delimiter, and
`right` is the right part of the delimiter.
Returns `(str, "")` if the delimiter is not found.

#### split_ex: String -> String -> Iterator String;

Same as Std::String::split, except that `"foo".split_ex(",")` returns a singleton iterator of "foo".

#### substring: I64 -> I64 -> String -> String;

Returns a substring extracted from a specified range from a string.
If the specified range exceeds the string, it will be truncated to fit within the string.

#### string_less_than: (String, String) -> Bool;

`string_less_than((str1,str2))` compares two strings.
Returns True if and only if `str1` is less than `str2` in lexicographical order.

#### `impl String: LessThan`

`less_than(str1,str2) compares two strings.
Returns True if and only if `str1` is less than `str2` in lexicographical order.

#### encode_hex_char: U8 -> U8;

Converts a 4bit number (0..15) to a hex character ('0'..'9', 'A'..'F').

#### decode_hex_char: U8 -> Result ErrMsg U8;

Converts a hex character ('0'..'9', 'A'..'F' or 'a'..'f') to a 4bit number (0..15).

#### to_string_hex: U64 -> String;

Converts a 64bit number to a hex string.

#### from_string_hex: String -> Result ErrMsg U64;

Converts a hex string to a 64bit number.

