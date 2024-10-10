# `module Minilib.Text.Hex`

Hexadecimal string conversion

# Types and aliases

# Traits and aliases

## `namespace Minilib.Text.Hex`

### `trait a : FromStringHex`

#### method `from_string_hex : Std::String -> Std::Result Std::String a`

### `trait a : ToStringHex`

#### method `to_string_hex : a -> Std::String`

# Trait implementations

### `impl Std::Array Std::U8 : Minilib.Text.Hex::FromStringHex`

Converts a byte array from a hex string.
For example, `"a5b6".from_string_hex == ok $ [ 0xa5_U8, 0xb6_U8 ]`.
Whitespaces are ignored.

### `impl [a : Minilib.Text.Hex::ToStringHex] Std::Array a : Minilib.Text.Hex::ToStringHex`

Converts an array to a hex string by concatenation.
For example, `[ 0xa5_U8, 0xb6_U8 ].to_hex_string == "a5b6"`.

### `impl Std::U16 : Minilib.Text.Hex::FromStringHex`

Converts a hex string of 1..4 characters to U16.

### `impl Std::U16 : Minilib.Text.Hex::ToStringHex`

Converts U16 to a hex string of 4 characters.
For example, `0x0a1b_U16.to_hex_string == "0a1b"`.

### `impl Std::U32 : Minilib.Text.Hex::FromStringHex`

Converts a hex string of 1..8 characters to U32.

### `impl Std::U32 : Minilib.Text.Hex::ToStringHex`

Converts U32 to a hex string of 8 characters.
For example, `0xdeadbeef_U32.to_hex_string == "deadbeef"`.

### `impl Std::U64 : Minilib.Text.Hex::FromStringHex`

Converts a hex string of 1..16 characters to U64.

### `impl Std::U64 : Minilib.Text.Hex::ToStringHex`

Converts U64 to a hex string of 16 characters.
For example, `0xa5b6_U64.to_hex_string == "000000000000a5b6"`.

### `impl Std::U8 : Minilib.Text.Hex::FromStringHex`

Converts a hex string of 1..2 characters to U8.

### `impl Std::U8 : Minilib.Text.Hex::ToStringHex`

Converts U8 to a hex string of 2 characters.
For example, `0x03_U8.to_hex_string == "03"`.

# Values

## `namespace Minilib.Text.Hex`

### `_array_from_string_hex : [a : Minilib.Text.Hex::FromStringHex] Std::I64 -> Std::String -> Std::Result Std::String (Std::Array a)`

`input._array_from_string_hex(n)` splits the input string
to `n` characters each, then converts each component to numbers.
Whitespaces are ignored.

### `_from_string_hex : Std::I64 -> Std::String -> Std::Result Std::String Std::U64`

`input._from_string_hex(n)` converts a hex string of `1..n` characters
to a 64bit number.

### `_to_string_hex : Std::I64 -> Std::U64 -> Std::String`

`input._to_string_hex(n)` converts least significant `4 * n` bits of `input`
to a hex string of `n` characters.

### `decode_hex_char : Std::U8 -> Std::Result Std::String Std::U8`

Converts a hex character ('0'..'9', 'A'..'F' or 'a'..'f') to a 4bit number (0..15).

### `encode_hex_char : Std::U8 -> Std::U8`

Converts a 4bit number (0..15) to a hex character ('0'..'9', 'a'..'f').

## `namespace Minilib.Text.Hex::FromStringHex`

### `from_string_hex : [a : Minilib.Text.Hex::FromStringHex] Std::String -> Std::Result Std::String a`

## `namespace Minilib.Text.Hex::ToStringHex`

### `to_string_hex : [a : Minilib.Text.Hex::ToStringHex] a -> Std::String`