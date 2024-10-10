# `module Minilib.Encoding.Xml.XmlParser`

Simple XML 1.1 Parser.

Implemented from specification of XML 1.1:
- [Extensible Markup Language (XML) 1.1 (Second Edition)](https://www.w3.org/TR/2006/REC-xml11-20060816/)

Known Problems:
- Currently only UTF-8 encoding is supported.
- Currently Document Type Definition (DTD) is not supported.

# Types and aliases

# Traits and aliases

# Trait implementations

# Values

## `namespace Minilib.Encoding.Xml.XmlParser`

### `_DoubleQuote : Std::U8`

### `_SingleQuote : Std::U8`

### `_negative_lookahead : Std::String -> Minilib.Text.SimpleParser::Parser ()`

Checks whether it does not match `str` at current position.
Raises `_NotMatch` if it matches.

### `_parse_att_value : Minilib.Text.SimpleParser::Parser Std::String`

[10]   	AttValue	   ::=   	'"' ([^<&"] | Reference)* '"'
                              |  "'" ([^<&'] | Reference)* "'"

### `_parse_attribute : Minilib.Text.SimpleParser::Parser Minilib.Encoding.Xml::XmlAttribute`

[41]   	Attribute	   ::=   	Name Eq AttValue

### `_parse_cdsect : Minilib.Text.SimpleParser::Parser Minilib.Encoding.Xml::XmlNode`

[18]   	CDSect	   ::=   	CDStart CData CDEnd
[19]   	CDStart	   ::=   	'<![CDATA['
[20]   	CData	   ::=   	(Char* - (Char* ']]>' Char*))
[21]   	CDEnd	   ::=   	']]>'

### `_parse_char_data : Minilib.Text.SimpleParser::Parser Std::String`

Character Data
[14]   	CharData	   ::=   	[^<&]* - ([^<&]* ']]>' [^<&]*)

### `_parse_char_ref : Minilib.Text.SimpleParser::Parser ()`

Character Reference
[66]   	CharRef	   ::=   	'&#' [0-9]+ ';'
                             | '&#x' [0-9a-fA-F]+ ';'

### `_parse_comment : Minilib.Text.SimpleParser::Parser Minilib.Encoding.Xml::XmlNode`

[15]   	Comment	   ::=   	'<!--' ((Char - '-') | ('-' (Char - '-')))* '-->'

### `_parse_content : Minilib.Encoding.Xml::XmlElement -> Minilib.Text.SimpleParser::Parser Minilib.Encoding.Xml::XmlElement`

Content of Elements
[43]   	content	   ::=   	CharData? ((element | Reference | CDSect | PI | Comment) CharData?)*

### `_parse_document : Minilib.Text.SimpleParser::Parser Minilib.Encoding.Xml::XmlDocument`

[1]   	document	   ::=   	( prolog element Misc* ) - ( Char* RestrictedChar Char* )

### `_parse_element : Minilib.Text.SimpleParser::Parser Minilib.Encoding.Xml::XmlElement`

[39]   	element	   ::=   	EmptyElemTag
                             | STag content ETag

### `_parse_empty_elem_tag_or_stag : Minilib.Text.SimpleParser::Parser (Std::Bool, Minilib.Encoding.Xml::XmlElement)`

[44]   	EmptyElemTag	   ::=   	'<' Name (S Attribute)* S? '/>'
[40]   	STag	   ::=   	'<' Name (S Attribute)* S? '>'

### `_parse_enc_name : Minilib.Text.SimpleParser::Parser Std::String`

[81]   	EncName	   ::=   	[A-Za-z] ([A-Za-z0-9._] | '-')*

### `_parse_encoding_decl : Minilib.Text.SimpleParser::Parser Std::String`

[80]   	EncodingDecl	   ::=   	S 'encoding' Eq ('"' EncName '"' | "'" EncName "'" )

### `_parse_entity_ref : Minilib.Text.SimpleParser::Parser ()`

[68]   	EntityRef	   ::=   	'&' Name ';'

### `_parse_eq : Minilib.Text.SimpleParser::Parser ()`

[25]   	Eq	   ::=   	S? '=' S?

### `_parse_etag : Minilib.Encoding.Xml::XmlElement -> Minilib.Text.SimpleParser::Parser Minilib.Encoding.Xml::XmlElement`

[42]   	ETag	   ::=   	'</' Name S? '>'

### `_parse_misc : Minilib.Text.SimpleParser::Parser Minilib.Encoding.Xml::XmlNode`

[27]   	Misc	   ::=   	Comment | PI | S

### `_parse_name : Minilib.Text.SimpleParser::Parser Std::String`

[5]   	Name	   ::=   	NameStartChar (NameChar)*

### `_parse_name_char : Minilib.Text.SimpleParser::Parser Std::U8`

[4a]   	NameChar	   ::=   	NameStartChar | "-" | "." | [0-9] |
                                  #xB7 | [#x0300-#x036F] | [#x203F-#x2040]

### `_parse_name_start_char : Minilib.Text.SimpleParser::Parser Std::U8`

[4]   	NameStartChar	   ::=   	":" | [A-Z] | "_" | [a-z] | [#xC0-#xD6] |
             [#xD8-#xF6] | [#xF8-#x2FF] | [#x370-#x37D] | [#x37F-#x1FFF] |
             [#x200C-#x200D] | [#x2070-#x218F] | [#x2C00-#x2FEF] | [#x3001-#xD7FF] |
             [#xF900-#xFDCF] | [#xFDF0-#xFFFD] | [#x10000-#xEFFFF]

### `_parse_pi : Minilib.Text.SimpleParser::Parser Minilib.Encoding.Xml::XmlNode`

[16]   	PI	   ::=   	'<?' PITarget (S (Char* - (Char* '?>' Char*)))? '?>'
[17]   	PITarget	   ::=   	Name - (('X' | 'x') ('M' | 'm') ('L' | 'l'))

### `_parse_prolog : Minilib.Text.SimpleParser::Parser Minilib.Encoding.Xml::XmlDocument`

[22]   	prolog	   ::=   	XMLDecl Misc* (doctypedecl Misc*)?

### `_parse_reference : Minilib.Text.SimpleParser::Parser ()`

Entity Reference
[67]   	Reference	   ::=   	EntityRef | CharRef

### `_parse_reference_as_text_node : Minilib.Text.SimpleParser::Parser Minilib.Encoding.Xml::XmlNode`

### `_parse_s : Minilib.Text.SimpleParser::Parser Std::String`

White Space
[3]   	S	   ::=   	(#x20 | #x9 | #xD | #xA)+

### `_parse_s_as_text_node : Minilib.Text.SimpleParser::Parser Minilib.Encoding.Xml::XmlNode`

### `_parse_sd_decl : Minilib.Text.SimpleParser::Parser Std::String`

[32]   	SDDecl	   ::=   	S 'standalone' Eq (("'" ('yes' | 'no') "'") | ('"' ('yes' | 'no') '"'))

### `_parse_version_info : Minilib.Text.SimpleParser::Parser Std::String`

[24]   	VersionInfo	   ::=   	S 'version' Eq ("'" VersionNum "'" | '"' VersionNum '"')

### `_parse_xml_declaration : Minilib.Text.SimpleParser::Parser Minilib.Encoding.Xml::XmlDeclaration`

[23]   	XMLDecl	   ::=   	'<?xml' VersionInfo EncodingDecl? SDDecl? S? '?>'

### `_whitespace : Minilib.Text.SimpleParser::Parser Std::U8`

### `parse_document_from_string : Std::String -> Std::Result Std::String Minilib.Encoding.Xml::XmlDocument`

Reads an XML document from a string.

### `parse_element_from_string : Std::String -> Std::Result Std::String Minilib.Encoding.Xml::XmlElement`

Reads an XML element from a string.