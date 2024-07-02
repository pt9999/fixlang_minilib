# base64.fix

## module Minilib.Encoding.Base64

BASE64 encoding and decoding

#### base64_encode: Array U8 -> String;

Encodes a byte array to a BASE64 string.

#### base64_decode: String -> Array U8;

Decodes a string which contains BASE64 characters to a byte array.
Characters other than BASE64 are ignored.

