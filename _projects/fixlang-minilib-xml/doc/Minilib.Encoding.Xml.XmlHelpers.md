# `module Minilib.Encoding.Xml.XmlHelpers`

XML helpers, such as escaping/unescaping special characters.

# Types and aliases

# Traits and aliases

# Trait implementations

# Values

## `namespace Minilib.Encoding.Xml.XmlHelpers`

### `_match_char_reference : Std::Array Std::U8 -> Std::I64 -> Std::Option (Std::U32, Std::I64)`

### `escape_special : Std::String -> Std::String`

Escapes XML special characters.
eg. `&` -> `&amp;`, `<` -> `&lt;`, `>` -> `&gt;`, `\"` -> `&quot;`, `'` -> `&#039;`

### `unescape_special : Std::String -> Std::String`

Unescapes XML special characters.
eg. `&amp;` -> `&`, `&lt;` -> `<`, `&gt;` -> `>`, `&quot;` -> `\"`, `&#039;` -> `'`.
NOTE: Other character references is also converted.