# xml.fix

## module Minilib.Encoding.Xml

XML Document Object Model (DOM).

This module is intended to support
[Extensible Markup Language (XML) 1.1 (Second Edition)](https://www.w3.org/TR/2006/REC-xml11-20060816/),
but it is not fully supported at this time.

The DOM API is based on
[MDN: XMLDocument](https://developer.mozilla.org/ja/docs/Web/API/XMLDocument).


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

Creates a XML document with specified document element.

#### add_to_prolog: XmlNode -> XmlDocument -> XmlDocument;

Adds a child node to the prolog of the document.

#### add_to_epilog: XmlNode -> XmlDocument -> XmlDocument;

Adds a child node to the epilog of the document.

#### `impl XmlDocument: Eq`

#### `impl XmlDocument: ToString`

### type XmlDeclaration

```
type XmlDeclaration = unbox struct {
    version: String,
    encoding: Option String,
    standalone: Option String
};
```
### namespace XmlDeclaration

#### default: XmlDeclaration;

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
    tag: String,                   // tag name
    attrs: Array XmlAttribute,      // attributes
    children: Array XmlNode        // child nodes
};
```
### namespace XmlElement

#### make: String -> XmlElement;

`XmlElement::make(tag)` creates an empty element with specified tag name.

#### element: String -> XmlElement;

Synonym for `XmlElement::make`.

#### attr: String -> String -> XmlElement -> XmlElement;

`el.attr(name,value)` adds an attribute to `el`.
If an attribute of same name exists, it will be replaced.
NOTE: validity of attribute names are not checked.

#### add_node: XmlNode -> XmlElement -> XmlElement;

`parent.add_node(child_node)` adds a child node to `parent`.

#### add: XmlElement -> XmlElement -> XmlElement;

`parent.add(child)` adds a child element to `parent`.

#### addF: XmlElement -> XmlElement -> XmlElement;

`parent.addF $ child` adds a child element to `parent`.
This is a flipped version of `add`.

#### text: String -> XmlElement -> XmlElement;

`el.text(content)` adds a text node to `el`.

#### concat_text_nodes: XmlElement -> XmlElement;

`el.concat_text_nodes` concats adjuscent text nodes.

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

#### `impl XmlAttribute: Eq`

#### `impl XmlAttribute: ToString`

### type XmlText

```
type XmlText = unbox struct {
    content: String
};
```
### namespace XmlText

#### make: String -> XmlText;

#### `impl XmlText: Eq`

#### `impl XmlText: ToString`

#### `impl XmlText: Add`

### type XmlCDATASection

```
type XmlCDATASection = unbox struct {
    content: String
};
```
### namespace XmlCDATASection

#### make: String -> XmlCDATASection;

#### `impl XmlCDATASection: Eq`

#### `impl XmlCDATASection: ToString`

### type XmlComment

```
type XmlComment = unbox struct {
    content: String
};
```
### namespace XmlComment

#### make: String -> XmlComment;

#### `impl XmlComment: Eq`

#### `impl XmlComment: ToString`

### type XmlProcessingInstruction

```
type XmlProcessingInstruction = unbox struct {
    content: String
};
```
### namespace XmlProcessingInstruction

#### make: String -> XmlProcessingInstruction;

#### `impl XmlProcessingInstruction: Eq`

#### `impl XmlProcessingInstruction: ToString`

#### escape_special: String -> String;

Escapes XML special characters.
eg. `&` -> `&amp;`, `<` -> `&lt;`, `>` -> `&gt;`, `\"` -> `&quot;`, `'` -> `&#039;`

#### unescape_special: String -> String;

Unescapes XML special characters.
eg. `&amp;` -> `&`, `&lt;` -> `<`, `&gt;` -> `>`, `&quot;` -> `\"`, `&#039;` -> `'`.
NOTE: Other character references is also converted.

