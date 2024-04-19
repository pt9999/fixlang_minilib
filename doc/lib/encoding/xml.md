# xml.fix

## module Minilib.Encoding.Xml

Simple XML Model.

This module is intended to support
[Extensible Markup Language (XML) 1.1 (Second Edition)](https://www.w3.org/TR/2006/REC-xml11-20060816/),
but it is not fully supported at this time.

This module is not intended to support DOM API.

This module does not support XML namespace (xmlns).

### type XmlDocument

A type that represents an XML document.

```
type XmlDocument = box struct {
    xml_decl: XmlDeclaration,
    prolog: Array XmlNode,
    document_element: XmlElement,
    epilog: Array XmlNode
};
```
### namespace XmlDocument

#### empty: XmlDocument;

An empty XML document.

#### make: XmlElement -> XmlDocument;

Creates a XML document with the specified document element.

#### add_to_prolog: XmlNode -> XmlDocument -> XmlDocument;

Adds a child node to the prolog of the document.

#### add_to_epilog: XmlNode -> XmlDocument -> XmlDocument;

Adds a child node to the epilog of the document.

#### `impl XmlDocument: Eq`

#### `impl XmlDocument: ToString`

### type XmlDeclaration

A type that represents an XML declaration.

```
type XmlDeclaration = unbox struct {
    version: String,
    encoding: Option String,
    standalone: Option String
};
```
### namespace XmlDeclaration

#### default: XmlDeclaration;

A default XML declaration with version="1.1", encoding="utf-8".

#### `impl XmlDeclaration: Eq`

#### `impl XmlDeclaration: ToString`

### type XmlNode

A type that represents an XML node.
cf. [DOM: 4.4. Interface Node](https://dom.spec.whatwg.org/#node)

```
type XmlNode = box union {
    element_node: XmlElement,      // element node(1)
    attribute_node: XmlAttribute, // attribute node(2)
    text_node: XmlText,            // text node(3)
    cdata_section: XmlCDATASection, // cdata section node(4)
    processing_instruction: XmlProcessingInstruction,    // processing instruction node(7)
    comment_node: XmlComment,      // comment node(8)
    document_node: XmlDocument     // document node(9)
    // TODO: document type node(10)
    // TODO: document fragment node(11)
};
```
#### `impl XmlNode: Eq`

#### `impl XmlNode: ToString`

### type XmlElement

A type that represents an XML element.

```
type XmlElement = unbox struct {
    tag_name: String,                   // tag name
    attributes: Array XmlAttribute,     // attributes
    children: Array XmlNode             // child nodes
};
```
### namespace XmlElement

#### make: String -> XmlElement;

`XmlElement::make(tag_name)` creates an empty element with the specified tag name.

#### element: String -> XmlElement;

Synonym for `XmlElement::make`.

#### get_attribute: String -> XmlElement -> Option String;

`element.get_attribute(name)` gets the value of a specified attribute
on the element.

#### set_attribute: String -> String -> XmlElement -> XmlElement;

`element.set_attribute(name,value)` sets the value of an attribute
on the element.
If an attribute of same name exists, it will be replaced.
NOTE: validity of attribute names are not checked.

#### remove_attribute: String -> XmlElement -> XmlElement;

`element.remove_attribute(name)` removes the attribute with the specified name
from the element. If the specified attribute does not exist, this function does nothing.

#### attr: String -> String -> XmlElement -> XmlElement;

`attr` is synonym for `set_attribute`.

#### append_child: XmlNode -> XmlElement -> XmlElement;

`parent.append_child(child_node)` adds a child node to `parent`.

#### add_node: XmlNode -> XmlElement -> XmlElement;

`add_node` is synonym for `append_child`.

#### add: XmlElement -> XmlElement -> XmlElement;

`parent.add(child)` adds a child element to `parent`.

#### addF: XmlElement -> XmlElement -> XmlElement;

`parent.addF $ child` adds a child element to `parent`.
This is a flipped version of `add`.

#### text: String -> XmlElement -> XmlElement;

`element.text(content)` adds a text node to `element`.

#### concat_text_nodes: XmlElement -> XmlElement;

`element.concat_text_nodes` concats adjuscent text nodes.

#### `impl XmlElement: Eq`

#### `impl XmlElement: ToString`

### type XmlAttribute

A type that represents name and value of an attribute.

```
type XmlAttribute = unbox struct {
    name: String,
    value: String
};
```
### namespace XmlAttribute

#### make: String -> String -> XmlAttribute;

`XmlAttribute::make(name, value)` creates an attribute with the specified name and value.

#### `impl XmlAttribute: Eq`

#### `impl XmlAttribute: ToString`

### type XmlText

A type that represents a text node.

```
type XmlText = unbox struct {
    content: String
};
```
### namespace XmlText

#### make: String -> XmlText;

`XmlText::make(content)` creates a text node with the specified content.

#### `impl XmlText: Eq`

#### `impl XmlText: ToString`

#### `impl XmlText: Add`

### type XmlCDATASection

A type that represents a CDATA section.

```
type XmlCDATASection = unbox struct {
    content: String
};
```
### namespace XmlCDATASection

#### make: String -> XmlCDATASection;

`XmlCDATASection::make(content)` creates a CDATA section with the specified content.
If `content` contains the end marker of CDATA section(`"]]>"`), this function panics.

#### `impl XmlCDATASection: Eq`

#### `impl XmlCDATASection: ToString`

### type XmlComment

A type that represents a comment node.

```
type XmlComment = unbox struct {
    content: String
};
```
### namespace XmlComment

#### make: String -> XmlComment;

`XmlComment::make(content)` creates a comment node with the specified content.
If `content` contains the end marker of comment(`"-->"`), this function panics.

#### `impl XmlComment: Eq`

#### `impl XmlComment: ToString`

### type XmlProcessingInstruction

A type that represents a processing instruction.

```
type XmlProcessingInstruction = unbox struct {
    content: String
};
```
### namespace XmlProcessingInstruction

#### make: String -> XmlProcessingInstruction;

`XmlProcessingInstruction::make(content)` creates a processing instruction with the specified content.

#### `impl XmlProcessingInstruction: Eq`

#### `impl XmlProcessingInstruction: ToString`

#### escape_special: String -> String;

Escapes XML special characters.
eg. `&` -> `&amp;`, `<` -> `&lt;`, `>` -> `&gt;`, `\"` -> `&quot;`, `'` -> `&#039;`

#### unescape_special: String -> String;

Unescapes XML special characters.
eg. `&amp;` -> `&`, `&lt;` -> `<`, `&gt;` -> `>`, `&quot;` -> `\"`, `&#039;` -> `'`.
NOTE: Other character references is also converted.

