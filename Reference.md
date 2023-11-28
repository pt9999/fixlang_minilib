
## Library Reference

NOTE: This file is under construction.

### json.fix
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

### json_decode.fix
#### decode: String -> Result ErrMsg Json;
Parses JSON text and returns a JSON value.

### json_encode.fix
#### encode: Json -> String;
Encode JSON and convert it to a string.

#### encode_pretty: Json -> String;
Encode JSON and convert it to a string. (pretty-printing)

### ordered_map.fix
#### OrderedMap
Similar to HashMap, but `to_iter()`` returns entries in the same order as they were inserted.

```
type OrderedMap k v = unbox struct {
    map: HashMap k (I64, v),
    serial: I64
};
```

### simple_parser.fix
#### Stream
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

#### Parser
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

#### match_any_char: Parser Char;
Matches any single character. Returns the single matching character.

