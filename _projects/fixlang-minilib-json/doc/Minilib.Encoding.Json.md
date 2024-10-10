# `module Minilib.Encoding.Json`

Definition of the structure of a JSON value.

# Types and aliases

## `namespace Minilib.Encoding.Json`

### `type Json = box union { ...variants... }`

A structure representing a JSON value.

#### variant `null : ()`

#### variant `bool : Std::Bool`

#### variant `number : Std::F64`

#### variant `string : Std::String`

#### variant `object : Minilib.Collection.OrderedMap::OrderedMap Std::String Minilib.Encoding.Json::Json`

#### variant `array : Std::Array Minilib.Encoding.Json::Json`

# Traits and aliases

# Trait implementations

### `impl Minilib.Encoding.Json::Json : Std::Eq`

Checks whether two JSON values are equal.

### `impl Minilib.Encoding.Json::Json : Std::ToString`

# Values

## `namespace Minilib.Encoding.Json`

### `to_object : Std::Array (Std::String, Minilib.Encoding.Json::Json) -> Minilib.Encoding.Json::Json`

Converts an array of keys and values to a JSON object.

## `namespace Minilib.Encoding.Json::Json`

### `array : Std::Array Minilib.Encoding.Json::Json -> Minilib.Encoding.Json::Json`

Constructs a value of union `Json` taking the variant `array`.

### `as_array : Minilib.Encoding.Json::Json -> Std::Array Minilib.Encoding.Json::Json`

Unwraps a union value of `Json` as the variant `array`.
If the value is not the variant `array`, this function aborts the program.

### `as_bool : Minilib.Encoding.Json::Json -> Std::Bool`

Unwraps a union value of `Json` as the variant `bool`.
If the value is not the variant `bool`, this function aborts the program.

### `as_null : Minilib.Encoding.Json::Json -> ()`

Unwraps a union value of `Json` as the variant `null`.
If the value is not the variant `null`, this function aborts the program.

### `as_number : Minilib.Encoding.Json::Json -> Std::F64`

Unwraps a union value of `Json` as the variant `number`.
If the value is not the variant `number`, this function aborts the program.

### `as_object : Minilib.Encoding.Json::Json -> Minilib.Collection.OrderedMap::OrderedMap Std::String Minilib.Encoding.Json::Json`

Unwraps a union value of `Json` as the variant `object`.
If the value is not the variant `object`, this function aborts the program.

### `as_string : Minilib.Encoding.Json::Json -> Std::String`

Unwraps a union value of `Json` as the variant `string`.
If the value is not the variant `string`, this function aborts the program.

### `bool : Std::Bool -> Minilib.Encoding.Json::Json`

Constructs a value of union `Json` taking the variant `bool`.

### `is_array : Minilib.Encoding.Json::Json -> Std::Bool`

Checks if a union value of `Json` is the variant `array`.

### `is_bool : Minilib.Encoding.Json::Json -> Std::Bool`

Checks if a union value of `Json` is the variant `bool`.

### `is_null : Minilib.Encoding.Json::Json -> Std::Bool`

Checks if a union value of `Json` is the variant `null`.

### `is_number : Minilib.Encoding.Json::Json -> Std::Bool`

Checks if a union value of `Json` is the variant `number`.

### `is_object : Minilib.Encoding.Json::Json -> Std::Bool`

Checks if a union value of `Json` is the variant `object`.

### `is_string : Minilib.Encoding.Json::Json -> Std::Bool`

Checks if a union value of `Json` is the variant `string`.

### `mod_array : (Std::Array Minilib.Encoding.Json::Json -> Std::Array Minilib.Encoding.Json::Json) -> Minilib.Encoding.Json::Json -> Minilib.Encoding.Json::Json`

Updates a value of union `Json` by applying a function if it is the variant `array`, or doing nothing otherwise.

### `mod_bool : (Std::Bool -> Std::Bool) -> Minilib.Encoding.Json::Json -> Minilib.Encoding.Json::Json`

Updates a value of union `Json` by applying a function if it is the variant `bool`, or doing nothing otherwise.

### `mod_null : (() -> ()) -> Minilib.Encoding.Json::Json -> Minilib.Encoding.Json::Json`

Updates a value of union `Json` by applying a function if it is the variant `null`, or doing nothing otherwise.

### `mod_number : (Std::F64 -> Std::F64) -> Minilib.Encoding.Json::Json -> Minilib.Encoding.Json::Json`

Updates a value of union `Json` by applying a function if it is the variant `number`, or doing nothing otherwise.

### `mod_object : (Minilib.Collection.OrderedMap::OrderedMap Std::String Minilib.Encoding.Json::Json -> Minilib.Collection.OrderedMap::OrderedMap Std::String Minilib.Encoding.Json::Json) -> Minilib.Encoding.Json::Json -> Minilib.Encoding.Json::Json`

Updates a value of union `Json` by applying a function if it is the variant `object`, or doing nothing otherwise.

### `mod_string : (Std::String -> Std::String) -> Minilib.Encoding.Json::Json -> Minilib.Encoding.Json::Json`

Updates a value of union `Json` by applying a function if it is the variant `string`, or doing nothing otherwise.

### `null : () -> Minilib.Encoding.Json::Json`

Constructs a value of union `Json` taking the variant `null`.

### `number : Std::F64 -> Minilib.Encoding.Json::Json`

Constructs a value of union `Json` taking the variant `number`.

### `object : Minilib.Collection.OrderedMap::OrderedMap Std::String Minilib.Encoding.Json::Json -> Minilib.Encoding.Json::Json`

Constructs a value of union `Json` taking the variant `object`.

### `string : Std::String -> Minilib.Encoding.Json::Json`

Constructs a value of union `Json` taking the variant `string`.