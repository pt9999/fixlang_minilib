## json_encoder.fix

Encodes a JSON value to a string.

#### `impl Json: ToString`

#### encode: Json -> String;

Encodes JSON and converts it to a string.

#### encode_pretty: Json -> String;

Encodes JSON and converts it to a string. (pretty-printing)

#### encode_with_param: EncodeParam -> Json -> String;

Encodes JSON and converts it to a string using the specified parameter.

### type EncodeParam

```
type EncodeParam = unbox struct {
    space: String,
    newline: String,
    indent: String,
    indent_incr: String,
    number_prec: U8
};
```
### namespace EncodeParam

#### default: EncodeParam;

#### pretty_print: EncodeParam;

#### increment_indent: EncodeParam -> EncodeParam;

