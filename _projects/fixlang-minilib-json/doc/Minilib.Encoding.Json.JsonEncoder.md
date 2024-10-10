# `module Minilib.Encoding.Json.JsonEncoder`

Encodes a JSON value to a string.

# Types and aliases

## `namespace Minilib.Encoding.Json.JsonEncoder`

### `type EncodeParam = unbox struct { ...fields... }`

#### field `space : Std::String`

#### field `newline : Std::String`

#### field `indent : Std::String`

#### field `indent_incr : Std::String`

#### field `number_prec : Std::U8`

# Traits and aliases

# Trait implementations

# Values

## `namespace Minilib.Encoding.Json.JsonEncoder`

### `_encode : Minilib.Encoding.Json.JsonEncoder::EncodeParam -> Std::Array Std::String -> Minilib.Encoding.Json::Json -> Std::Array Std::String`

### `_encode_array : Minilib.Encoding.Json.JsonEncoder::EncodeParam -> Std::Array Std::String -> Std::Array Minilib.Encoding.Json::Json -> Std::Array Std::String`

### `_encode_number : Minilib.Encoding.Json.JsonEncoder::EncodeParam -> Std::F64 -> Std::String`

### `_encode_object : Minilib.Encoding.Json.JsonEncoder::EncodeParam -> Std::Array Std::String -> Minilib.Collection.OrderedMap::OrderedMap Std::String Minilib.Encoding.Json::Json -> Std::Array Std::String`

### `_encode_string : Std::String -> Std::String`

### `_escape_table : Std::Array Std::U8`

### `_hex_table : Std::Array Std::U8`

### `encode : Minilib.Encoding.Json::Json -> Std::String`

Encodes JSON and converts it to a string.

### `encode_pretty : Minilib.Encoding.Json::Json -> Std::String`

Encodes JSON and converts it to a string. (pretty-printing)

### `encode_with_param : Minilib.Encoding.Json.JsonEncoder::EncodeParam -> Minilib.Encoding.Json::Json -> Std::String`

Encodes JSON and converts it to a string using the specified parameter.

## `namespace Minilib.Encoding.Json.JsonEncoder::EncodeParam`

### `@indent : Minilib.Encoding.Json.JsonEncoder::EncodeParam -> Std::String`

Retrieves the field `indent` from a value of `EncodeParam`.

### `@indent_incr : Minilib.Encoding.Json.JsonEncoder::EncodeParam -> Std::String`

Retrieves the field `indent_incr` from a value of `EncodeParam`.

### `@newline : Minilib.Encoding.Json.JsonEncoder::EncodeParam -> Std::String`

Retrieves the field `newline` from a value of `EncodeParam`.

### `@number_prec : Minilib.Encoding.Json.JsonEncoder::EncodeParam -> Std::U8`

Retrieves the field `number_prec` from a value of `EncodeParam`.

### `@space : Minilib.Encoding.Json.JsonEncoder::EncodeParam -> Std::String`

Retrieves the field `space` from a value of `EncodeParam`.

### `act_indent : [f : Std::Functor] (Std::String -> f Std::String) -> Minilib.Encoding.Json.JsonEncoder::EncodeParam -> f Minilib.Encoding.Json.JsonEncoder::EncodeParam`

Updates a value of `EncodeParam` by applying a functorial action to field `indent`.

### `act_indent_incr : [f : Std::Functor] (Std::String -> f Std::String) -> Minilib.Encoding.Json.JsonEncoder::EncodeParam -> f Minilib.Encoding.Json.JsonEncoder::EncodeParam`

Updates a value of `EncodeParam` by applying a functorial action to field `indent_incr`.

### `act_newline : [f : Std::Functor] (Std::String -> f Std::String) -> Minilib.Encoding.Json.JsonEncoder::EncodeParam -> f Minilib.Encoding.Json.JsonEncoder::EncodeParam`

Updates a value of `EncodeParam` by applying a functorial action to field `newline`.

### `act_number_prec : [f : Std::Functor] (Std::U8 -> f Std::U8) -> Minilib.Encoding.Json.JsonEncoder::EncodeParam -> f Minilib.Encoding.Json.JsonEncoder::EncodeParam`

Updates a value of `EncodeParam` by applying a functorial action to field `number_prec`.

### `act_space : [f : Std::Functor] (Std::String -> f Std::String) -> Minilib.Encoding.Json.JsonEncoder::EncodeParam -> f Minilib.Encoding.Json.JsonEncoder::EncodeParam`

Updates a value of `EncodeParam` by applying a functorial action to field `space`.

### `default : Minilib.Encoding.Json.JsonEncoder::EncodeParam`

### `increment_indent : Minilib.Encoding.Json.JsonEncoder::EncodeParam -> Minilib.Encoding.Json.JsonEncoder::EncodeParam`

### `mod_indent : (Std::String -> Std::String) -> Minilib.Encoding.Json.JsonEncoder::EncodeParam -> Minilib.Encoding.Json.JsonEncoder::EncodeParam`

Updates a value of `EncodeParam` by applying a function to field `indent`.

### `mod_indent_incr : (Std::String -> Std::String) -> Minilib.Encoding.Json.JsonEncoder::EncodeParam -> Minilib.Encoding.Json.JsonEncoder::EncodeParam`

Updates a value of `EncodeParam` by applying a function to field `indent_incr`.

### `mod_newline : (Std::String -> Std::String) -> Minilib.Encoding.Json.JsonEncoder::EncodeParam -> Minilib.Encoding.Json.JsonEncoder::EncodeParam`

Updates a value of `EncodeParam` by applying a function to field `newline`.

### `mod_number_prec : (Std::U8 -> Std::U8) -> Minilib.Encoding.Json.JsonEncoder::EncodeParam -> Minilib.Encoding.Json.JsonEncoder::EncodeParam`

Updates a value of `EncodeParam` by applying a function to field `number_prec`.

### `mod_space : (Std::String -> Std::String) -> Minilib.Encoding.Json.JsonEncoder::EncodeParam -> Minilib.Encoding.Json.JsonEncoder::EncodeParam`

Updates a value of `EncodeParam` by applying a function to field `space`.

### `pretty_print : Minilib.Encoding.Json.JsonEncoder::EncodeParam`

### `set_indent : Std::String -> Minilib.Encoding.Json.JsonEncoder::EncodeParam -> Minilib.Encoding.Json.JsonEncoder::EncodeParam`

Updates a value of `EncodeParam` by setting field `indent` to a specified one.

### `set_indent_incr : Std::String -> Minilib.Encoding.Json.JsonEncoder::EncodeParam -> Minilib.Encoding.Json.JsonEncoder::EncodeParam`

Updates a value of `EncodeParam` by setting field `indent_incr` to a specified one.

### `set_newline : Std::String -> Minilib.Encoding.Json.JsonEncoder::EncodeParam -> Minilib.Encoding.Json.JsonEncoder::EncodeParam`

Updates a value of `EncodeParam` by setting field `newline` to a specified one.

### `set_number_prec : Std::U8 -> Minilib.Encoding.Json.JsonEncoder::EncodeParam -> Minilib.Encoding.Json.JsonEncoder::EncodeParam`

Updates a value of `EncodeParam` by setting field `number_prec` to a specified one.

### `set_space : Std::String -> Minilib.Encoding.Json.JsonEncoder::EncodeParam -> Minilib.Encoding.Json.JsonEncoder::EncodeParam`

Updates a value of `EncodeParam` by setting field `space` to a specified one.