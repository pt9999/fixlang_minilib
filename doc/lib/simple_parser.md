# simple_parser.fix

## module SimpleParser

A monadic text parser

### type Char

The type of characters. Currently only UTF-8 string is supported.

```
type Char = U8;
```
### namespace Stream

### type Stream

A character iterator that stores the file name, line number, column number,
and offset from the beginning of the file.

```
    type Stream = unbox struct {
        filename: String,       // File name (empty if no file name is set)
        line: I64,              // Line number
        column: I64,            // Column number
        position: I64,          // Stream position from the beginning of the file
        iter: Iterator Char     // The character iterator
    };
```
#### empty: Stream;

An empty Stream.

#### advance: Stream -> Option (Char, Stream);

`stream.advance` gets next character and increment the stream position.

#### read_all: Stream -> (Array Char, Stream);

`stream.read_all` reads all characters to the end of stream.

#### error: String -> Stream -> Result ErrMsg a;

`stream.error(str)` reports an error along with where it occurred.

#### `impl Stream: FromString`

Creates a stream from a string.

#### `impl Stream: ToString`

Converts a stream to a string, for example `"Stream(pos=1001)"`

### type ParseResult

Result type that returns a value of an arbitrary type and a stream.

```
type ParseResult a = Result ErrMsg (a, Stream);
```
### type Parser

A structure with a function that receive a stream, parse it, and
return the parsed result and the next stream position.

```
type Parser a = unbox struct { _parser: Stream -> ParseResult a };
```
#### parser: (Stream -> ParseResult a) -> Parser a;

A function that creates a Parser structure based on the parsing function.

### namespace Parser

#### run_parser: Stream -> Parser a -> ParseResult a;

Apply a stream to a parsing function and return the parsed result.

#### run_parser_str: String -> Parser a -> ParseResult a;

Create a stream from a string, then apply a stream to a parsing function
and return the parsed result.

#### `impl Parser: Functor`

#### `impl Parser: Monad`

### namespace Parser

#### map_result: (a -> Result ErrMsg b) -> Parser a -> Parser b;

`parser.map_result(f)` maps the parser result with `f`, possibly reports
an error message.

#### debug: [a: ToString] String -> Parser a -> Parser a;

Prints the parser result.

#### unit: Parser ();

Match zero-length string.

#### get_stream: Parser Stream;

Returns the current stream position.

#### filter: (a -> Bool) -> Parser a -> Parser a;

Checks whether the parsed result of the specified Parser satisfies the specified conditions.
Raises a `_NotMatch` error if the specified condition is not met.

#### or_else: Parser a -> Parser a -> Parser a;

If the first Parser raises a `_NotMatch` error, tries the second Parser.

#### or_error: String -> Parser a -> Parser a;

If the Parser reports any error (including `_NotMatch`),
raises the specified string as an error.

#### error_parser: String -> Parser a;

Raises the specified string as an error.

#### not_match: Parser a;

Raises a `_NotMatch` error.

#### repeat: Parser a -> Parser (Array a);

Repeats matches as many as possible. The parse result is
an array of successful matches.  Never raises an error.

#### zero_or_more: Parser a -> Parser (Array a);

Synonym for `repeat`.

#### one_or_more: Parser a -> Parser (Array a);

Same as `zero_or_more`, but raises a _NotMatch error
if the array length is zero.

#### match_end_of_stream: Parser ();

Matches zero-length string at the end of stream.

#### match_any_char: Parser Char;

Matches any single character. The parsed result is
a single matched character.
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

#### match_empty_str: Parser String;

Matches a zero-length string.

#### match_char_class: (Char -> Bool) -> Parser Char;

Matches a character satisfying the specified condition.

#### match_str_class: (Char -> Bool) -> Parser String;

Matches a zero-or-more-length string. Each character should satisfy the specified condition.

#### class: (Char -> Bool) -> Parser String;

Matches a zero-or-more-length string. Each character should satisfy the specified condition.

#### class_whitespace: Parser String;

Matches a zero-or-more-length string of whitespace characters.

#### class_lower: Parser String;

Matches a zero-or-more-length string of lowercase characters.

#### class_digit: Parser String;

Matches a zero-or-more-length string of digit characters.

#### integer: Parser I64;

Matches an integer.
