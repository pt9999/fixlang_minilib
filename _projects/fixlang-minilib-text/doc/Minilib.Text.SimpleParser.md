# `module Minilib.Text.SimpleParser`

Simple text parser. Customizable by monadic operations.
- Stream of characters
- Basic parsers such as character matching
- Create complex parsers with composition

# Types and aliases

## `namespace Minilib.Text.SimpleParser`

### `type Char = Std::U8`

The type of characters. Currently only UTF-8 string is supported.

### `type ParseResult = Std::Result Std::ErrMsg (a, Minilib.Text.SimpleParser::Stream::Stream)`

Result type that returns a value of an arbitrary type and a stream.

### `type Parser a = unbox struct { ...fields... }`

A structure with a function that receive a stream, parse it, and
return the parsed result and the next stream position.

#### field `_parser : Minilib.Text.SimpleParser::Stream::Stream -> Std::Result Std::String (a, Minilib.Text.SimpleParser::Stream::Stream)`

## `namespace Minilib.Text.SimpleParser::Stream`

### `type Stream = unbox struct { ...fields... }`

A character iterator that stores the file name, line number, column number,
and offset from the beginning of the file.

#### field `filename : Std::String`

#### field `line : Std::I64`

#### field `column : Std::I64`

#### field `position : Std::I64`

#### field `iter : Std::Iterator Std::U8`

# Traits and aliases

# Trait implementations

### `impl Minilib.Text.SimpleParser::Parser : Std::Functor`

### `impl Minilib.Text.SimpleParser::Parser : Std::Monad`

### `impl Minilib.Text.SimpleParser::Stream::Stream : Std::FromString`

Creates a stream from a string.

### `impl Minilib.Text.SimpleParser::Stream::Stream : Std::ToString`

Converts a stream to a string, for example `"Stream(pos=1001)"`

# Values

## `namespace Minilib.Text.SimpleParser`

### `_NotMatch : Std::String`

A special error message that represents the parser is not matched.

### `parser : (Minilib.Text.SimpleParser::Stream::Stream -> Std::Result Std::String (a, Minilib.Text.SimpleParser::Stream::Stream)) -> Minilib.Text.SimpleParser::Parser a`

A function that creates a Parser structure based on the parsing function.

## `namespace Minilib.Text.SimpleParser::Parser`

### `@_parser : Minilib.Text.SimpleParser::Parser a -> Minilib.Text.SimpleParser::Stream::Stream -> Std::Result Std::String (a, Minilib.Text.SimpleParser::Stream::Stream)`

Retrieves the field `_parser` from a value of `Parser`.

### `act__parser : [f : Std::Functor] ((Minilib.Text.SimpleParser::Stream::Stream -> Std::Result Std::String (a, Minilib.Text.SimpleParser::Stream::Stream)) -> f (Minilib.Text.SimpleParser::Stream::Stream -> Std::Result Std::String (a, Minilib.Text.SimpleParser::Stream::Stream))) -> Minilib.Text.SimpleParser::Parser a -> f (Minilib.Text.SimpleParser::Parser a)`

Updates a value of `Parser` by applying a functorial action to field `_parser`.

### `debug : [a : Std::ToString] Std::String -> Minilib.Text.SimpleParser::Parser a -> Minilib.Text.SimpleParser::Parser a`

Prints the parser result.

### `error_parser : Std::String -> Minilib.Text.SimpleParser::Parser a`

Raises the specified string as an error.

### `filter : (a -> Std::Bool) -> Minilib.Text.SimpleParser::Parser a -> Minilib.Text.SimpleParser::Parser a`

Checks whether the parsed result of the specified Parser satisfies the specified conditions.
Raises a `_NotMatch` error if the specified condition is not met.

### `get_stream : Minilib.Text.SimpleParser::Parser Minilib.Text.SimpleParser::Stream::Stream`

Returns the current stream position.

### `if_exists : Minilib.Text.SimpleParser::Parser a -> Minilib.Text.SimpleParser::Parser (Std::Option a)`

`p.if_exists` returns `some(x)` if `p` returns `x` as a parse result,
or `none()` if `p` does not match.

### `map_result : (a -> Std::Result Std::String b) -> Minilib.Text.SimpleParser::Parser a -> Minilib.Text.SimpleParser::Parser b`

`parser.map_result(f)` maps the parser result with `f`, possibly reports
an error message.

### `match_any_char : Minilib.Text.SimpleParser::Parser Std::U8`

Matches any single character. The parsed result is
a single matched character.
If the match fails (eg. the end of stream), a `_NotMatch` error is raised.

### `match_char : Std::U8 -> Minilib.Text.SimpleParser::Parser ()`

Matches a single character specified by the argument.
The parsed result is nothing.
If the match fails, a `_NotMatch` error is raised.

### `match_char_class : (Std::U8 -> Std::Bool) -> Minilib.Text.SimpleParser::Parser Std::U8`

Matches a character satisfying the specified condition.

### `match_char_if_exists : Std::U8 -> Minilib.Text.SimpleParser::Parser (Std::Option Std::U8)`

Matches a single character if it exists.
The parsed result is `some(c)` if it exists,
`none()` if it does not exist.

### `match_empty_str : Minilib.Text.SimpleParser::Parser Std::String`

Matches a zero-length string.

### `match_end_of_stream : Minilib.Text.SimpleParser::Parser ()`

Matches zero-length string at the end of stream.

### `match_integer : Minilib.Text.SimpleParser::Parser Std::I64`

Matches an integer.

### `match_one_of_char : Std::String -> Minilib.Text.SimpleParser::Parser Std::String`

Matches a character which is included in the specified string.
The parsed result is a string consisting of the single matched character.
If the match fails, a `_NotMatch` error is raised.

### `match_str : Std::String -> Minilib.Text.SimpleParser::Parser ()`

Matches a string specified by the argument.
The parsed result is nothing.
If the match fails, a `_NotMatch` error is raised.

### `match_str_class : (Std::U8 -> Std::Bool) -> Minilib.Text.SimpleParser::Parser Std::String`

Matches a zero-or-more-length string. Each character should satisfy the specified condition.

### `match_str_class_digit : Minilib.Text.SimpleParser::Parser Std::String`

Matches a zero-or-more-length string of digit characters.

### `match_str_class_lower : Minilib.Text.SimpleParser::Parser Std::String`

Matches a zero-or-more-length string of lowercase characters.

### `match_str_class_whitespace : Minilib.Text.SimpleParser::Parser Std::String`

Matches a zero-or-more-length string of whitespace characters.

### `mod__parser : ((Minilib.Text.SimpleParser::Stream::Stream -> Std::Result Std::String (a, Minilib.Text.SimpleParser::Stream::Stream)) -> Minilib.Text.SimpleParser::Stream::Stream -> Std::Result Std::String (a, Minilib.Text.SimpleParser::Stream::Stream)) -> Minilib.Text.SimpleParser::Parser a -> Minilib.Text.SimpleParser::Parser a`

Updates a value of `Parser` by applying a function to field `_parser`.

### `not_match : Minilib.Text.SimpleParser::Parser a`

Raises a `_NotMatch` error.

### `one_or_more : Minilib.Text.SimpleParser::Parser a -> Minilib.Text.SimpleParser::Parser (Std::Array a)`

Same as `zero_or_more`, but raises a _NotMatch error
if the array length is zero.

### `or_else : Minilib.Text.SimpleParser::Parser a -> Minilib.Text.SimpleParser::Parser a -> Minilib.Text.SimpleParser::Parser a`

If the first Parser raises a `_NotMatch` error, tries the second Parser.
Note that `pa1.or_else(pa2)` is interpreted as `or_else(pa2, pa1)`,
and  that `pa1.or_else $ pa2` is interpreted as `or_else(pa1, pa2)`.

### `or_elseF : Minilib.Text.SimpleParser::Parser a -> Minilib.Text.SimpleParser::Parser a -> Minilib.Text.SimpleParser::Parser a`

Flipped version of `or_else`.
`pa1.or_elseF $ pa2` is equivalent to `pa1.or_else(pa2)`.

### `or_error : Std::String -> Minilib.Text.SimpleParser::Parser a -> Minilib.Text.SimpleParser::Parser a`

If the Parser reports any error (including `_NotMatch`),
raises the specified string as an error.

### `repeat : Minilib.Text.SimpleParser::Parser a -> Minilib.Text.SimpleParser::Parser (Std::Array a)`

Repeats matches as many as possible. The parse result is
an array of successful matches.
If a _NotMatch error is raised, returns as success.
If an error other than _NotMatch is raised, reports that error.

### `run_parser : Minilib.Text.SimpleParser::Stream::Stream -> Minilib.Text.SimpleParser::Parser a -> Std::Result Std::String (a, Minilib.Text.SimpleParser::Stream::Stream)`

Apply a stream to a parsing function and return the parsed result.

### `run_parser_str : Std::String -> Minilib.Text.SimpleParser::Parser a -> Std::Result Std::String (a, Minilib.Text.SimpleParser::Stream::Stream)`

Create a stream from a string, then apply a stream to a parsing function
and return the parsed result.

### `set__parser : (Minilib.Text.SimpleParser::Stream::Stream -> Std::Result Std::String (a, Minilib.Text.SimpleParser::Stream::Stream)) -> Minilib.Text.SimpleParser::Parser a -> Minilib.Text.SimpleParser::Parser a`

Updates a value of `Parser` by setting field `_parser` to a specified one.

### `unit : Minilib.Text.SimpleParser::Parser ()`

Match zero-length string.

### `zero_or_more : Minilib.Text.SimpleParser::Parser a -> Minilib.Text.SimpleParser::Parser (Std::Array a)`

Synonym for `repeat`.

## `namespace Minilib.Text.SimpleParser::Stream`

### `advance : Minilib.Text.SimpleParser::Stream::Stream -> Std::Option (Std::U8, Minilib.Text.SimpleParser::Stream::Stream)`

`stream.advance` gets next character and increment the stream position.

### `empty : Minilib.Text.SimpleParser::Stream::Stream`

An empty Stream.

### `error : Std::String -> Minilib.Text.SimpleParser::Stream::Stream -> Std::Result Std::String a`

`stream.error(str)` reports an error along with where it occurred.

### `make : Std::String -> Minilib.Text.SimpleParser::Stream::Stream`

Creates a stream from specified string.

### `read_all : Minilib.Text.SimpleParser::Stream::Stream -> (Std::Array Std::U8, Minilib.Text.SimpleParser::Stream::Stream)`

`stream.read_all` reads all characters to the end of stream.

### `read_string : Std::I64 -> Minilib.Text.SimpleParser::Stream::Stream -> Std::String`

`stream.read_string(n)` reads at most `n` characters and convert them to a string.

### `read_string_between : Minilib.Text.SimpleParser::Stream::Stream -> Minilib.Text.SimpleParser::Stream::Stream -> Std::String`

`start_stream.read_string_between(end_stream)` reads characters from `start_stream` to `end_stream`
 and convert them to a string.

## `namespace Minilib.Text.SimpleParser::Stream::Stream`

### `@column : Minilib.Text.SimpleParser::Stream::Stream -> Std::I64`

Retrieves the field `column` from a value of `Stream`.

### `@filename : Minilib.Text.SimpleParser::Stream::Stream -> Std::String`

Retrieves the field `filename` from a value of `Stream`.

### `@iter : Minilib.Text.SimpleParser::Stream::Stream -> Std::Iterator Std::U8`

Retrieves the field `iter` from a value of `Stream`.

### `@line : Minilib.Text.SimpleParser::Stream::Stream -> Std::I64`

Retrieves the field `line` from a value of `Stream`.

### `@position : Minilib.Text.SimpleParser::Stream::Stream -> Std::I64`

Retrieves the field `position` from a value of `Stream`.

### `act_column : [f : Std::Functor] (Std::I64 -> f Std::I64) -> Minilib.Text.SimpleParser::Stream::Stream -> f Minilib.Text.SimpleParser::Stream::Stream`

Updates a value of `Stream` by applying a functorial action to field `column`.

### `act_filename : [f : Std::Functor] (Std::String -> f Std::String) -> Minilib.Text.SimpleParser::Stream::Stream -> f Minilib.Text.SimpleParser::Stream::Stream`

Updates a value of `Stream` by applying a functorial action to field `filename`.

### `act_iter : [f : Std::Functor] (Std::Iterator Std::U8 -> f (Std::Iterator Std::U8)) -> Minilib.Text.SimpleParser::Stream::Stream -> f Minilib.Text.SimpleParser::Stream::Stream`

Updates a value of `Stream` by applying a functorial action to field `iter`.

### `act_line : [f : Std::Functor] (Std::I64 -> f Std::I64) -> Minilib.Text.SimpleParser::Stream::Stream -> f Minilib.Text.SimpleParser::Stream::Stream`

Updates a value of `Stream` by applying a functorial action to field `line`.

### `act_position : [f : Std::Functor] (Std::I64 -> f Std::I64) -> Minilib.Text.SimpleParser::Stream::Stream -> f Minilib.Text.SimpleParser::Stream::Stream`

Updates a value of `Stream` by applying a functorial action to field `position`.

### `mod_column : (Std::I64 -> Std::I64) -> Minilib.Text.SimpleParser::Stream::Stream -> Minilib.Text.SimpleParser::Stream::Stream`

Updates a value of `Stream` by applying a function to field `column`.

### `mod_filename : (Std::String -> Std::String) -> Minilib.Text.SimpleParser::Stream::Stream -> Minilib.Text.SimpleParser::Stream::Stream`

Updates a value of `Stream` by applying a function to field `filename`.

### `mod_iter : (Std::Iterator Std::U8 -> Std::Iterator Std::U8) -> Minilib.Text.SimpleParser::Stream::Stream -> Minilib.Text.SimpleParser::Stream::Stream`

Updates a value of `Stream` by applying a function to field `iter`.

### `mod_line : (Std::I64 -> Std::I64) -> Minilib.Text.SimpleParser::Stream::Stream -> Minilib.Text.SimpleParser::Stream::Stream`

Updates a value of `Stream` by applying a function to field `line`.

### `mod_position : (Std::I64 -> Std::I64) -> Minilib.Text.SimpleParser::Stream::Stream -> Minilib.Text.SimpleParser::Stream::Stream`

Updates a value of `Stream` by applying a function to field `position`.

### `set_column : Std::I64 -> Minilib.Text.SimpleParser::Stream::Stream -> Minilib.Text.SimpleParser::Stream::Stream`

Updates a value of `Stream` by setting field `column` to a specified one.

### `set_filename : Std::String -> Minilib.Text.SimpleParser::Stream::Stream -> Minilib.Text.SimpleParser::Stream::Stream`

Updates a value of `Stream` by setting field `filename` to a specified one.

### `set_iter : Std::Iterator Std::U8 -> Minilib.Text.SimpleParser::Stream::Stream -> Minilib.Text.SimpleParser::Stream::Stream`

Updates a value of `Stream` by setting field `iter` to a specified one.

### `set_line : Std::I64 -> Minilib.Text.SimpleParser::Stream::Stream -> Minilib.Text.SimpleParser::Stream::Stream`

Updates a value of `Stream` by setting field `line` to a specified one.

### `set_position : Std::I64 -> Minilib.Text.SimpleParser::Stream::Stream -> Minilib.Text.SimpleParser::Stream::Stream`

Updates a value of `Stream` by setting field `position` to a specified one.