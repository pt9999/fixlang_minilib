# Module Minilib.Encoding.Xml.XmlParser (xml_parser.fix)

Simple XML 1.1 Parser.

Implemented from specification of XML 1.1:
- [Extensible Markup Language (XML) 1.1 (Second Edition)](https://www.w3.org/TR/2006/REC-xml11-20060816/)

Known Problems:
- Currently only UTF-8 encoding is supported.
- Currently Document Type Definition (DTD) is not supported.

### `parse_document_from_string: String -> Result ErrMsg XmlDocument;`

Reads an XML document from a string.

### `parse_element_from_string: String -> Result ErrMsg XmlElement;`

Reads an XML element from a string.

