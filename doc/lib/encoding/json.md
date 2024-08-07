# Module Minilib.Encoding.Json (json.fix)

Definition of the structure of a JSON value.

### `type Json`

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
### `impl Json: ToString`

### `to_object: Array (String, Json) -> Json;`

Converts an array of keys and values to a JSON object.

### `impl Json: Eq`

Checks whether two JSON values are equal.

