
# minilib Reference

NOTE: This file is under construction.

## Table of contents

- [Table of contents](#table-of-contents)
- [json.fix](#jsonfix)
- [json_decode.fix](#json_decodefix)
- [json_encode.fix](#json_encodefix)
- [ordered_map.fix](#ordered_mapfix)
- [simple_parser.fix](#simple_parserfix)
- [string_ex.fix](#string_exfix)
- [unicode.fix](#unicodefix)
- [unit_test.fix](#unit_testfix)
- [clap.fix](#clapfix)

## json.fix

### Json
A structure representing a JSON value.
```
type Json = box union {
    null: (),
    bool: Bool,
    number: F64,
    string: String,
    object: OrderedMap String Json,
    array:  Array Json
};
```

#### to_object: Array (String, Json) -> Json;
Converts an array of keys and values to a JSON object.

#### `impl Json: Eq`

## json_decode.fix

#### decode: String -> Result ErrMsg Json;
Parses JSON text and returns a JSON value.

## json_encode.fix
#### `impl Json: ToString`

#### encode: Json -> String;
Encodes JSON and converts it to a string.

#### encode_pretty: Json -> String;
Encodes JSON and converts it to a string. (pretty-printing)

#### encode_with_param: EncodeParam -> Json -> String;
Encodes JSON and converts it to a string using the specified parameter.

## ordered_map.fix
#### OrderedMap
Similar to HashMap, but `to_iter()` returns entries in the same order as they were inserted.

```
type OrderedMap k v = unbox struct {
    map: HashMap k (I64, v),
    serial: I64
};
```

## simple_parser.fix

### Stream
A character iterator that stores the file name, line number, column number, and offset from the beginning of the file.

```
type Stream = unbox struct {
    filename: String,
    line: I64,
    column: I64,
    position: I64,
    iter: Iterator Char
};
```
#### `impl Stream : FromString`
Creates a stream from a string.

#### `impl Stream : ToString`

### ParseResult
Result type that returns a value of an arbitrary type and a stream.

```
type ParseResult a = Result ErrMsg (a, Stream);
```

#### _NotMatch: ErrMsg;

A special error message that represents the parser is not matched.

### Parser
A structure with a function that receive a stream, parse it, and
return the parsed result and the next stream position.

```
type Parser a = unbox struct { _parser: Stream -> ParseResult a };

type ParseResult a = Result ErrMsg (a, Stream);
```

#### parser: (Stream -> ParseResult a) -> Parser a;
A function that creates a Parser structure based on the parsing function.

#### run_parser: Stream -> Parser a -> ParseResult a;
Apply a stream to a parsing function and return the parsed result.

#### run_parser_str: String -> Parser a -> ParseResult a;
Create a stream from a string, then apply a stream to a parsing function and return the parsed result.

#### `impl Parser : Functor`

#### `impl Parser : Monad`

#### map_result: (a -> Result ErrMsg b) -> Parser a -> Parser b;

Maps the parser result of the specified parser with the specified function which may report an error.

#### debug: [a: ToString] String -> Parser a -> Parser a;
Outputs diagnostic information for parser debugging.

#### filter: (a -> Bool) -> Parser a -> Parser a;

Checks whether the parsed result of the specified Parser satisfies the specified conditions.
Raises a `_NotMatch` error if the specified condition is not met.

#### or_else: Parser a -> Parser a -> Parser a;

If the first Parser raises a `_NotMatch` error, tries the second Parser.

#### or_error: String -> Parser a -> Parser a;

If the Parser reports any error (including `_NotMatch`), raises the specified string as an error.

#### error_parser: String -> Parser a;

Raises the specified string as an error.

#### not_match: Parser a;

Raises a `_NotMatch` error.

#### repeat: Parser a -> Parser (Array a);

Repeats matches as many as possible. The parse result is an array of successful matches.  Never raises an error.

#### zero_or_more: Parser a -> Parser (Array a);

Synonym for `repeat`.

#### one_or_more: Parser a -> Parser (Array a);

Same as `zero_or_more`, but raises a `_NotMatch` error if the array length is zero.

#### match_end_of_stream: Parser ();

Matches zero-length string at the end of stream.

#### match_any_char: Parser Char;

Matches any single character.
The parsed result is a single matched character.
If the match fails (eg. the end of stream), a `_NotMatch` error is raised.

#### match_char: Char -> Parser ();

Matches a single character specified by the argument.
The parsed result is nothing.
If the match fails, a `_NotMatch` error is raised.

#### match_one_of_char: String -> Parser String;

Matches a character which is included in the specified string.
The parsed result is a string consisting of the single matched character.
If the match fails, a `_NotMatch` error is raised.

#### match_str: String -> Parser ();

Matches a string specified by the argument.
The parsed result is nothing.
If the match fails, a `_NotMatch` error is raised.

#### match_empty_str : Parser String;

Matches a zero-length string.

#### match_char_class = (Char -> Bool) -> Parser Char;

Matches a character satisfying the specified condition.

#### match_str_class: (Char -> Bool) -> Parser String;

Matches a zero-or-more-length string. Each character should satisfy the specified condition.

## string_ex.fix

#### `impl (): ToString`

#### `impl [a : ToString, b : ToString, c : ToString] (a, b, c) : ToString`

#### `impl [a : ToString, b : ToString, c : ToString, d : ToString] (a, b, c, d) : ToString`

#### `impl [a: ToString] Option a: ToString`

#### `impl [a: ToString, e: ToString] Result e a: ToString`

#### `impl [k: ToString, v: ToString] HashMap k v : ToString`

#### `impl [a: ToString] Array a: ToString`

#### _unsafe_to_string: Array U8 -> String;

Convert a byte array to a string. Specifically, it calls `String::_unsafe_to_string()` after appending a null character to the end of the byte array.

#### to_lower: String -> String;

Converts the specified string to lowercase.

#### to_upper: String -> String;

Converts the specified string to uppercase.

#### byte_to_string: U8 -> String;

Converts a byte (a character) to a string of length 1.

#### find_byte: U8 -> String -> Option I64;

Searches for the specified byte from the beginning of a string. If found, returns the index of that byte.

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

Returns a substring extracted from a specified range from a string. If the specified range exceeds the string, it will be truncated to fit within the string.

#### string_less_than: (String, String) -> Bool;

Compares two strings. Returns True if and only if the first string is less than the second string.

#### `impl String: LessThan`

#### encode_hex_char: U8 -> U8;

Converts a 4bit number (0..15) to a hex character ('0'..'9', 'A'..'F').

#### decode_hex_char: U8 -> Result ErrMsg U8;

Converts a hex character ('0'..'9', 'A'..'F' or 'a'..'f') to a 4bit number (0..15).

#### to_string_hex: U64 -> String;

Converts a 64bit number to a hex string.

#### from_string_hex: String -> Result ErrMsg U64;

Converts a hex string to a 64bit number.

## unicode.fix

#### utf8_to_utf32: Array U8 -> Array U32 -> Array U32;

Convert UTF8 string to UTF32 string. Please specify the output destination buffer. (Same below)

#### utf32_to_utf8: Array U32 -> Array U8 -> Array U8;

Convert UTF32 string to UTF8 string.

#### utf16_to_utf32: Array U16 -> Array U32 -> Array U32;

Convert UTF16 string to UTF32 string.

#### utf32_to_utf16: Array U32 -> Array U16 -> Array U16;

Convert UTF32 string to UTF16 string.

## unit_test.fix

#### _TEST_VERBOSE: Bool;

If _TEST_VERBOSE is false, only failed testcases will be reported.

### TestCase

TestCase is a type that counts the number of successful and failed tests.

```
type TestCase = Lazy (IOFail (I64, I64));
```

#### empty: TestCase;

A test case where the number of successes and number of failures are both equal to 0.
Can be used as a placeholder at the end of an array of test cases.

#### run_test_driver: Array TestCase -> IO ();

Executes all test cases and prints the results (number of passes and number of failures).
Exit with exitcode=1 if any test failed or any error occured, exitcode=0 otherwise.

#### run_tests: Array (TestCase) -> TestCase;

Executes all test cases and treat the results as one test case.

#### make_test: String -> Lazy (IOFail ()) -> TestCase;

Creates a named test case from a lazy `IOFail ()`.

#### assert_true : String -> Bool -> IOFail ();

Verifies that the boolean value is true. If the boolean value is false, the test will fail with the specified message.

#### assert_equal : [a: Eq, a: ToString] String -> a -> a -> IOFail ();

Verifies that two values are equal. If the values are different, the test will fail with the specified message.

#### assert_not_equal : [a: Eq, a: ToString] String -> a -> a -> IOFail ();

Verifies that two values are not equal. If the values are equal, the test will fail with the specified message.

## clap.fix

Command line argument parser.  (Inspired by `clap` crate of Rust)

### ArgAction

The action taken when the argument is parsed.

```
type ArgAction = unbox union {
    set: (),        // Sets next input to the single argument value.
    append: (),     // Appends next input to the array of argument values.
    set_true: (),   // Sets "true" as the single argument value.
    set_false: (),  // Sets "false" as the single argument value.
    help: (),       // Displays help for the command.
    version: ()     // Displays the version of the command.
};
```

### Arg

A structure that defines arguments.
Arguments can be either optional or positional arguments.
If either `short` or `long` is set, it becomes an optional argument.
Otherwise, it is a positional argument.

```
type Arg = unbox struct {
    id: String,             // A unique ID that identifies the argument.
    short: U8,              // A one-hypen option, eg. `-n`
    long: String,           // A two-hypen option, eg. `--count`
    required: Bool,         // Whether the argument is required or not.
    takes_value: Bool,      // Whether the argument takes some value.
    multiple_values: Bool,  // Whether the argument value(s) is singule or multiple.
    default_value: Option String,   // A default value of the argument.
    value_name: String,     // The name of the argument value which is displayed in help message.
    help: String,           // The help message of the argument.
    action: ArgAction       // The action taken when the argument is parsed.
};

```
#### new: String -> Arg;

Creates new argument.

#### short: U8 -> Arg -> Arg;

Sets `@short`.

#### long: String -> Arg -> Arg;

Sets `@long`.

#### required: Arg -> Arg;

Sets `@required` to true.

#### takes_value: Arg -> Arg;

Sets `@takes_value` to true, and `@action` to `set()`.

#### takes_multiple_values: Arg -> Arg;

Sets `@takes_value` to true, `@multiple_values` to true, and `@action` to `append()`.

#### default_value: String -> Arg -> Arg;

Sets `@default_value`.

#### value_name: String -> Arg -> Arg;

Sets `@value_name`.

#### help: String -> Arg -> Arg;

Sets `@help`.

### Command

A structure representing a command (ie. application).

```
type Command = unbox struct {
    name: String,           // The name of the command.
    bin_name: String,       // The name of the executable binary of the command.
    display_name: String,   // The display name of the command.
    version: String,        // The version of the command.
    author: String,         // Author of the command.
    about: String,          // Description about the command.
    args: Array Arg,        // Argument definitions of the command.
    help_template: HelpTemplate,    // A help template of the command.
    version_template: HelpTemplate  // A version template of the command.
};
```

#### new: String -> Command;

Creates a command structure by specifying the command name.

#### name: String -> Command -> Command;

Sets the name of the command.

#### bin_name: String -> Command -> Command;

Sets the name of the executable binary of the command.

#### display_name: String -> Command -> Command;

Sets the display name of the command.

#### version: String -> Command -> Command;

Sets the version of the command.

#### author: String -> Command -> Command;

Sets the author of the command.

#### about: String -> Command -> Command;

Sets the description about the command.

#### arg: Arg -> Command -> Command;

Add an argument definition to the command.

#### render_help: Command -> String;

Generates a help string based on the help template.

#### render_version: Command -> String;

Generates a version string based on the version template.

#### get_matches: Command -> IOFail ArgMatches;

Parse command line arguments based on `IO::get_args`.
If `--help` or `--version` is specified, the help string or version string will be returned as `throw`.

#### get_matches_from: Array String -> Command -> Result ErrMsg ArgMatches;

Parses command line arguments based on the specified input array.
If `--help` or `--version` is specified, the help string or version string will be returned as the error message.

### ArgMatches

A structure representing the result of parsing command line arguments.

```
type ArgMatches = unbox struct {
    map: HashMap String (Array String)
};
```

#### empty: ArgMatches;

An empty `ArgMatches` structure.

#### get_many: String -> ArgMatches -> Option (Array String);

Gets the array of argument values with the specified ID.

#### get_one: String -> ArgMatches -> Option String;

Gets the value of the argument with the specified ID.

