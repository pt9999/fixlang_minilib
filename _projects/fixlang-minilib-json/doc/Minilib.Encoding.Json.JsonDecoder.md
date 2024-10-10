# `module Minilib.Encoding.Json.JsonDecoder`

Decodes a JSON value from a string.

# Types and aliases

# Traits and aliases

# Trait implementations

# Values

## `namespace Minilib.Encoding.Json.JsonDecoder`

### `_DOUBLEQUOTE : Std::U8`

### `_begin_array : Minilib.Text.SimpleParser::Parser ()`

### `_begin_object : Minilib.Text.SimpleParser::Parser ()`

### `_end_array : Minilib.Text.SimpleParser::Parser ()`

### `_end_object : Minilib.Text.SimpleParser::Parser ()`

### `_json_text : Minilib.Text.SimpleParser::Parser Minilib.Encoding.Json::Json`

### `_match_quoted_char_u16 : Minilib.Text.SimpleParser::Parser Std::U16`

Parse a quoted character. ("\n", "\uD83D" etc.)
NOTE: Escape sequences of the form "\uXXXX" can only represent
the range U+0000 to U+FFFF. Characters in the range U+10000 to U+10FFFF
become surrogate pairs and are split like "\uD83D\uDE38".
Therefore, we first interpret these strings as UTF16. Later convert it
to UTF32 and join the surrogate pair, then convert it to UTF8.

### `_match_quoted_str : Minilib.Text.SimpleParser::Parser Std::String`

### `_match_str_inner : Minilib.Text.SimpleParser::Parser Std::String`

### `_match_unquoted_char : Minilib.Text.SimpleParser::Parser Std::U8`

### `_match_unquoted_str : Minilib.Text.SimpleParser::Parser Std::String`

### `_name_separator : Minilib.Text.SimpleParser::Parser ()`

### `_parse_array : Minilib.Text.SimpleParser::Parser (Std::Array Minilib.Encoding.Json::Json)`

### `_parse_bool : Minilib.Text.SimpleParser::Parser Std::Bool`

### `_parse_null : Minilib.Text.SimpleParser::Parser ()`

### `_parse_number : Minilib.Text.SimpleParser::Parser Std::F64`

### `_parse_object : Minilib.Text.SimpleParser::Parser (Minilib.Collection.OrderedMap::OrderedMap Std::String Minilib.Encoding.Json::Json)`

### `_parse_string : Minilib.Text.SimpleParser::Parser Std::String`

### `_parse_value : Minilib.Text.SimpleParser::Parser Minilib.Encoding.Json::Json`

### `_unescape_table : Std::Array Std::U8`

### `_value_separator : Minilib.Text.SimpleParser::Parser ()`

### `_wrap_whitespaces : Minilib.Text.SimpleParser::Parser a -> Minilib.Text.SimpleParser::Parser a`

### `_ws : Minilib.Text.SimpleParser::Parser ()`

### `decode : Std::String -> Std::Result Std::String Minilib.Encoding.Json::Json`

Parses JSON text and returns a JSON value.