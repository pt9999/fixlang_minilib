
# Library Reference

NOTE: This file is under construction.

## json.fix
#### Json
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
#### `impl Json: Eq`

## json_decode.fix
#### decode: String -> Result ErrMsg Json;
Parses JSON text and returns a JSON value.

## json_encode.fix
#### encode: Json -> String;
Encode JSON and convert it to a string.

#### encode_pretty: Json -> String;
Encode JSON and convert it to a string. (pretty-printing)

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
A character iterator that stores the file name, line number, column number, 
and offset from the beginning of the file.

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
