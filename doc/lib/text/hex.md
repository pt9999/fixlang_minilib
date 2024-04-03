# hex.fix

## module Minilib.Text.Hex

Hexadecimal string conversion

#### encode_hex_char: U8 -> U8;

Converts a 4bit number (0..15) to a hex character ('0'..'9', 'a'..'f').

#### decode_hex_char: U8 -> Result ErrMsg U8;

Converts a hex character ('0'..'9', 'A'..'F' or 'a'..'f') to a 4bit number (0..15).

### trait FromStringHex

```
trait a: FromStringHex {
    from_string_hex: String -> Result ErrMsg a;
}
```
#### `impl U8: FromStringHex`

Converts a hex string of 1..2 characters to U8.

#### `impl U16: FromStringHex`

Converts a hex string of 1..4 characters to U16.

#### `impl U32: FromStringHex`

Converts a hex string of 1..8 characters to U32.

#### `impl U64: FromStringHex`

Converts a hex string of 1..16 characters to U64.

#### `impl Array U8: FromStringHex`

Converts a byte array from a hex string.
For example, `"a5b6".from_string_hex == ok $ [ 0xa5_U8, 0xb6_U8 ]`.
Whitespaces are ignored.

### trait ToStringHex

```
trait a: ToStringHex {
    to_string_hex: a -> String;
}
```
#### `impl U8: ToStringHex`

Converts U8 to a hex string of 2 characters.
For example, `0x03_U8.to_hex_string == "03"`.

#### `impl U16: ToStringHex`

Converts U16 to a hex string of 4 characters.
For example, `0x0a1b_U16.to_hex_string == "0a1b"`.

#### `impl U32: ToStringHex`

Converts U32 to a hex string of 8 characters.
For example, `0xdeadbeef_U32.to_hex_string == "deadbeef"`.

#### `impl U64: ToStringHex`

Converts U64 to a hex string of 16 characters.
For example, `0xa5b6_U64.to_hex_string == "000000000000a5b6"`.

#### `impl [a: ToStringHex] Array a: ToStringHex`

Converts an array to a hex string by concatenation.
For example, `[ 0xa5_U8, 0xb6_U8 ].to_hex_string == "a5b6"`.

