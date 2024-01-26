# unicode.fix

## module Minilib.Text.Unicode

Unicode conversions (UTF8 <-> UTF32 <-> UTF16)


#### utf8_to_utf32: Array U8 -> Array U32 -> Array U32;

Convert UTF8 string to UTF32 string. Please specify the output destination buffer.

#### encode_code_point_to_utf8: U32 -> Array U8 -> Array U8;

Encode a unicode code point to UTF-8

#### utf32_to_utf8: Array U32 -> Array U8 -> Array U8;

Convert UTF32 string to UTF8 string. Please specify the output destination buffer.

#### utf16_to_utf32: Array U16 -> Array U32 -> Array U32;

Convert UTF16 string to UTF32 string.

#### utf32_to_utf16: Array U32 -> Array U16 -> Array U16;

Convert UTF32 string to UTF16 string.

