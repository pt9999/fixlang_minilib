# xml_helpers.fix

## module Minilib.Encoding.Xml.XmlHelpers

XML helpers, such as:
- Escape/unescape special characters

#### escape_special: String -> String;

Escapes XML special characters.
eg. `&` -> `&amp;`, `<` -> `&lt;`, `>` -> `&gt;`, `\"` -> `&quot;`, `'` -> `&#039;`

#### unescape_special: String -> String;

Unescapes XML special characters.
eg. `&amp;` -> `&`, `&lt;` -> `<`, `&gt;` -> `>`, `&quot;` -> `\"`, `&#039;` -> `'`.
NOTE: Other character references is also converted.

