
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
- [unit_test.fix](#unit_testfix)

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
Converts an array of keys and values ​​to a JSON object.

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
Similar to HashMap, but `to_iter()`` returns entries in the same order as they were inserted.

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
Create a stream from a string.

### ParseResult
Result type that returns a value of an arbitrary type and a stream.

```
type ParseResult a = Result ErrMsg (a, Stream);
```

#### `impl ParseResult : ToString`

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
Raises a _NotMatch error if the specified condition is not met.

#### or_else: Parser a -> Parser a -> Parser a;

If the first Parser raises a _NotMatch error, try the second Parser.

#### or_error: String -> Parser a -> Parser a;

If the Parser reports any error (including _NotMatch), raises the specified string as an error.

#### error_parser: String -> Parser a;

Raises the specified string as an error.

#### not_match: Parser a;

Raises a _NotMatch error.

#### repeat: Parser a -> Parser (Array a);

Repeat matches as many as possible. The parse result is an array of successful matches.  Never raise an error.

#### zero_or_more: Parser a -> Parser (Array a);

Synonym of `repeat`.

#### one_or_more: Parser a -> Parser (Array a);

Same as `zero_or_more`, except if the array length is zero, an _NotMatch error is raised.

#### match_end_of_stream: Parser ();

Matches zero-length string at the end of stream.

#### match_any_char: Parser Char;
Matches any single character. The parsed result is the single matching character.

#### match_char: Char -> Parser ();

Matches a single character specified by the argument. If not, an _NotMatch error is raised.

#### match_one_of_char: String -> Parser String;

Matches a character which is included in the specified string. If not, an _NotMatch error is raised.

#### match_str: String -> Parser ();

Matches a string specified by the argument.  If not, an _NotMatch error is raised.

#### match_empty_str : Parser String;

Matches a zero-length string.

## string_ex.fix

#### `impl (): ToString`

#### `impl [a : ToString, b : ToString, c : ToString] (a, b, c) : ToString`

#### `impl [a : ToString, b : ToString, c : ToString, d : ToString] (a, b, c, d) : ToString`

#### `impl [a: ToString] Option a: ToString`

#### `impl [k: ToString, v: ToString] HashMap k v : ToString`

#### `impl [a: ToString] Array a: ToString`

#### _unsafe_to_string: Array U8 -> String;

Convert a byte array to a string. Specifically, it calls `String::_unsafe_to_string()` after appending a null character to the end of the byte array.

#### find_byte: U8 -> String -> Option I64;

Searches for the specified byte from the beginning of a string. If found, returns the index of that byte.

#### substring: I64 -> I64 -> String -> String;

Returns a substring extracted from a specified range from a string. If the specified range exceeds the string, it will be truncated to fit within the string.

#### string_less_than: (String, String) -> Bool;

Compares two strings. Returns True if and only if the first string is less than the second string.

#### `impl String: LessThan`

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

#### assert_equal : [a: Eq, a: ToString] String -> a -> a -> IOFail ();

Verifies that two values ​​are equal. If the values ​​are different, the test will fail with the specified message.

#### assert_equal : [a: Eq, a: ToString] String -> a -> a -> IOFail ();

Verifies that two values ​​are equal. If the values ​​are different, the test will fail with the specified message.

#### assert_not_equal : [a: Eq, a: ToString] String -> a -> a -> IOFail ();

Verifies that two values ​​are not equal. If the values ​​are equal, the test will fail with the specified message.
