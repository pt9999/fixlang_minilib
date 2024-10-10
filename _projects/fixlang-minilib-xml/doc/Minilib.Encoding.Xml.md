# `module Minilib.Encoding.Xml`

Simple XML Model.

This module is intended to support
[Extensible Markup Language (XML) 1.1 (Second Edition)](https://www.w3.org/TR/2006/REC-xml11-20060816/),
but it is not fully supported at this time.

This module is not intended to support DOM API.

This module does not support XML namespace (xmlns).

# Types and aliases

## `namespace Minilib.Encoding.Xml`

### `type XmlAttribute = unbox struct { ...fields... }`

A type that represents name and value of an attribute.

#### field `name : Std::String`

#### field `value : Std::String`

### `type XmlCDATASection = unbox struct { ...fields... }`

A type that represents a CDATA section.

#### field `content : Std::String`

### `type XmlComment = unbox struct { ...fields... }`

A type that represents a comment node.

#### field `content : Std::String`

### `type XmlDeclaration = unbox struct { ...fields... }`

A type that represents an XML declaration.

#### field `version : Std::String`

#### field `encoding : Std::Option Std::String`

#### field `standalone : Std::Option Std::String`

### `type XmlDocument = box struct { ...fields... }`

A type that represents an XML document.

#### field `xml_decl : Minilib.Encoding.Xml::XmlDeclaration`

#### field `prolog : Std::Array Minilib.Encoding.Xml::XmlNode`

#### field `document_element : Minilib.Encoding.Xml::XmlElement`

#### field `epilog : Std::Array Minilib.Encoding.Xml::XmlNode`

### `type XmlElement = unbox struct { ...fields... }`

A type that represents an XML element.

#### field `tag_name : Std::String`

#### field `attributes : Std::Array Minilib.Encoding.Xml::XmlAttribute`

#### field `children : Std::Array Minilib.Encoding.Xml::XmlNode`

### `type XmlNode = box union { ...variants... }`

A type that represents an XML node.
cf. [DOM: 4.4. Interface Node](https://dom.spec.whatwg.org/#node)

#### variant `element_node : Minilib.Encoding.Xml::XmlElement`

#### variant `attribute_node : Minilib.Encoding.Xml::XmlAttribute`

#### variant `text_node : Minilib.Encoding.Xml::XmlText`

#### variant `cdata_section : Minilib.Encoding.Xml::XmlCDATASection`

#### variant `processing_instruction : Minilib.Encoding.Xml::XmlProcessingInstruction`

#### variant `comment_node : Minilib.Encoding.Xml::XmlComment`

#### variant `document_node : Minilib.Encoding.Xml::XmlDocument`

### `type XmlProcessingInstruction = unbox struct { ...fields... }`

A type that represents a processing instruction.

#### field `content : Std::String`

### `type XmlText = unbox struct { ...fields... }`

A type that represents a text node.

#### field `content : Std::String`

# Traits and aliases

# Trait implementations

### `impl Minilib.Encoding.Xml::XmlAttribute : Std::Eq`

### `impl Minilib.Encoding.Xml::XmlAttribute : Std::ToString`

### `impl Minilib.Encoding.Xml::XmlCDATASection : Std::Eq`

### `impl Minilib.Encoding.Xml::XmlCDATASection : Std::ToString`

### `impl Minilib.Encoding.Xml::XmlComment : Std::Eq`

### `impl Minilib.Encoding.Xml::XmlComment : Std::ToString`

### `impl Minilib.Encoding.Xml::XmlDeclaration : Std::Eq`

### `impl Minilib.Encoding.Xml::XmlDeclaration : Std::ToString`

### `impl Minilib.Encoding.Xml::XmlDocument : Std::Eq`

### `impl Minilib.Encoding.Xml::XmlDocument : Std::ToString`

### `impl Minilib.Encoding.Xml::XmlElement : Std::Eq`

### `impl Minilib.Encoding.Xml::XmlElement : Std::ToString`

### `impl Minilib.Encoding.Xml::XmlNode : Std::Eq`

### `impl Minilib.Encoding.Xml::XmlNode : Std::ToString`

### `impl Minilib.Encoding.Xml::XmlProcessingInstruction : Std::Eq`

### `impl Minilib.Encoding.Xml::XmlProcessingInstruction : Std::ToString`

### `impl Minilib.Encoding.Xml::XmlText : Std::Add`

### `impl Minilib.Encoding.Xml::XmlText : Std::Eq`

### `impl Minilib.Encoding.Xml::XmlText : Std::ToString`

# Values

## `namespace Minilib.Encoding.Xml`

### `escape_special : Std::String -> Std::String`

Escapes XML special characters.
eg. `&` -> `&amp;`, `<` -> `&lt;`, `>` -> `&gt;`, `\"` -> `&quot;`, `'` -> `&#039;`

### `unescape_special : Std::String -> Std::String`

Unescapes XML special characters.
eg. `&amp;` -> `&`, `&lt;` -> `<`, `&gt;` -> `>`, `&quot;` -> `\"`, `&#039;` -> `'`.
NOTE: Other character references is also converted.

## `namespace Minilib.Encoding.Xml::XmlAttribute`

### `@name : Minilib.Encoding.Xml::XmlAttribute -> Std::String`

Retrieves the field `name` from a value of `XmlAttribute`.

### `@value : Minilib.Encoding.Xml::XmlAttribute -> Std::String`

Retrieves the field `value` from a value of `XmlAttribute`.

### `_sort_by_name : Std::Array Minilib.Encoding.Xml::XmlAttribute -> Std::Array Minilib.Encoding.Xml::XmlAttribute`

`attributes._sort_by_name` sorts an array of attributes by the name.

### `act_name : [f : Std::Functor] (Std::String -> f Std::String) -> Minilib.Encoding.Xml::XmlAttribute -> f Minilib.Encoding.Xml::XmlAttribute`

Updates a value of `XmlAttribute` by applying a functorial action to field `name`.

### `act_value : [f : Std::Functor] (Std::String -> f Std::String) -> Minilib.Encoding.Xml::XmlAttribute -> f Minilib.Encoding.Xml::XmlAttribute`

Updates a value of `XmlAttribute` by applying a functorial action to field `value`.

### `make : Std::String -> Std::String -> Minilib.Encoding.Xml::XmlAttribute`

`XmlAttribute::make(name, value)` creates an attribute with the specified name and value.

### `mod_name : (Std::String -> Std::String) -> Minilib.Encoding.Xml::XmlAttribute -> Minilib.Encoding.Xml::XmlAttribute`

Updates a value of `XmlAttribute` by applying a function to field `name`.

### `mod_value : (Std::String -> Std::String) -> Minilib.Encoding.Xml::XmlAttribute -> Minilib.Encoding.Xml::XmlAttribute`

Updates a value of `XmlAttribute` by applying a function to field `value`.

### `set_name : Std::String -> Minilib.Encoding.Xml::XmlAttribute -> Minilib.Encoding.Xml::XmlAttribute`

Updates a value of `XmlAttribute` by setting field `name` to a specified one.

### `set_value : Std::String -> Minilib.Encoding.Xml::XmlAttribute -> Minilib.Encoding.Xml::XmlAttribute`

Updates a value of `XmlAttribute` by setting field `value` to a specified one.

## `namespace Minilib.Encoding.Xml::XmlCDATASection`

### `@content : Minilib.Encoding.Xml::XmlCDATASection -> Std::String`

Retrieves the field `content` from a value of `XmlCDATASection`.

### `act_content : [f : Std::Functor] (Std::String -> f Std::String) -> Minilib.Encoding.Xml::XmlCDATASection -> f Minilib.Encoding.Xml::XmlCDATASection`

Updates a value of `XmlCDATASection` by applying a functorial action to field `content`.

### `make : Std::String -> Minilib.Encoding.Xml::XmlCDATASection`

`XmlCDATASection::make(content)` creates a CDATA section with the specified content.
If `content` contains the end marker of CDATA section(`"]]>"`), this function panics.

### `mod_content : (Std::String -> Std::String) -> Minilib.Encoding.Xml::XmlCDATASection -> Minilib.Encoding.Xml::XmlCDATASection`

Updates a value of `XmlCDATASection` by applying a function to field `content`.

### `set_content : Std::String -> Minilib.Encoding.Xml::XmlCDATASection -> Minilib.Encoding.Xml::XmlCDATASection`

Updates a value of `XmlCDATASection` by setting field `content` to a specified one.

## `namespace Minilib.Encoding.Xml::XmlComment`

### `@content : Minilib.Encoding.Xml::XmlComment -> Std::String`

Retrieves the field `content` from a value of `XmlComment`.

### `act_content : [f : Std::Functor] (Std::String -> f Std::String) -> Minilib.Encoding.Xml::XmlComment -> f Minilib.Encoding.Xml::XmlComment`

Updates a value of `XmlComment` by applying a functorial action to field `content`.

### `make : Std::String -> Minilib.Encoding.Xml::XmlComment`

`XmlComment::make(content)` creates a comment node with the specified content.
If `content` contains a double-hyphen(`"--"`), this function panics.

### `mod_content : (Std::String -> Std::String) -> Minilib.Encoding.Xml::XmlComment -> Minilib.Encoding.Xml::XmlComment`

Updates a value of `XmlComment` by applying a function to field `content`.

### `set_content : Std::String -> Minilib.Encoding.Xml::XmlComment -> Minilib.Encoding.Xml::XmlComment`

Updates a value of `XmlComment` by setting field `content` to a specified one.

## `namespace Minilib.Encoding.Xml::XmlDeclaration`

### `@encoding : Minilib.Encoding.Xml::XmlDeclaration -> Std::Option Std::String`

Retrieves the field `encoding` from a value of `XmlDeclaration`.

### `@standalone : Minilib.Encoding.Xml::XmlDeclaration -> Std::Option Std::String`

Retrieves the field `standalone` from a value of `XmlDeclaration`.

### `@version : Minilib.Encoding.Xml::XmlDeclaration -> Std::String`

Retrieves the field `version` from a value of `XmlDeclaration`.

### `act_encoding : [f : Std::Functor] (Std::Option Std::String -> f (Std::Option Std::String)) -> Minilib.Encoding.Xml::XmlDeclaration -> f Minilib.Encoding.Xml::XmlDeclaration`

Updates a value of `XmlDeclaration` by applying a functorial action to field `encoding`.

### `act_standalone : [f : Std::Functor] (Std::Option Std::String -> f (Std::Option Std::String)) -> Minilib.Encoding.Xml::XmlDeclaration -> f Minilib.Encoding.Xml::XmlDeclaration`

Updates a value of `XmlDeclaration` by applying a functorial action to field `standalone`.

### `act_version : [f : Std::Functor] (Std::String -> f Std::String) -> Minilib.Encoding.Xml::XmlDeclaration -> f Minilib.Encoding.Xml::XmlDeclaration`

Updates a value of `XmlDeclaration` by applying a functorial action to field `version`.

### `default : Minilib.Encoding.Xml::XmlDeclaration`

A default XML declaration with version="1.1", encoding="utf-8".

### `mod_encoding : (Std::Option Std::String -> Std::Option Std::String) -> Minilib.Encoding.Xml::XmlDeclaration -> Minilib.Encoding.Xml::XmlDeclaration`

Updates a value of `XmlDeclaration` by applying a function to field `encoding`.

### `mod_standalone : (Std::Option Std::String -> Std::Option Std::String) -> Minilib.Encoding.Xml::XmlDeclaration -> Minilib.Encoding.Xml::XmlDeclaration`

Updates a value of `XmlDeclaration` by applying a function to field `standalone`.

### `mod_version : (Std::String -> Std::String) -> Minilib.Encoding.Xml::XmlDeclaration -> Minilib.Encoding.Xml::XmlDeclaration`

Updates a value of `XmlDeclaration` by applying a function to field `version`.

### `set_encoding : Std::Option Std::String -> Minilib.Encoding.Xml::XmlDeclaration -> Minilib.Encoding.Xml::XmlDeclaration`

Updates a value of `XmlDeclaration` by setting field `encoding` to a specified one.

### `set_standalone : Std::Option Std::String -> Minilib.Encoding.Xml::XmlDeclaration -> Minilib.Encoding.Xml::XmlDeclaration`

Updates a value of `XmlDeclaration` by setting field `standalone` to a specified one.

### `set_version : Std::String -> Minilib.Encoding.Xml::XmlDeclaration -> Minilib.Encoding.Xml::XmlDeclaration`

Updates a value of `XmlDeclaration` by setting field `version` to a specified one.

## `namespace Minilib.Encoding.Xml::XmlDocument`

### `@document_element : Minilib.Encoding.Xml::XmlDocument -> Minilib.Encoding.Xml::XmlElement`

Retrieves the field `document_element` from a value of `XmlDocument`.

### `@epilog : Minilib.Encoding.Xml::XmlDocument -> Std::Array Minilib.Encoding.Xml::XmlNode`

Retrieves the field `epilog` from a value of `XmlDocument`.

### `@prolog : Minilib.Encoding.Xml::XmlDocument -> Std::Array Minilib.Encoding.Xml::XmlNode`

Retrieves the field `prolog` from a value of `XmlDocument`.

### `@xml_decl : Minilib.Encoding.Xml::XmlDocument -> Minilib.Encoding.Xml::XmlDeclaration`

Retrieves the field `xml_decl` from a value of `XmlDocument`.

### `act_document_element : [f : Std::Functor] (Minilib.Encoding.Xml::XmlElement -> f Minilib.Encoding.Xml::XmlElement) -> Minilib.Encoding.Xml::XmlDocument -> f Minilib.Encoding.Xml::XmlDocument`

Updates a value of `XmlDocument` by applying a functorial action to field `document_element`.

### `act_epilog : [f : Std::Functor] (Std::Array Minilib.Encoding.Xml::XmlNode -> f (Std::Array Minilib.Encoding.Xml::XmlNode)) -> Minilib.Encoding.Xml::XmlDocument -> f Minilib.Encoding.Xml::XmlDocument`

Updates a value of `XmlDocument` by applying a functorial action to field `epilog`.

### `act_prolog : [f : Std::Functor] (Std::Array Minilib.Encoding.Xml::XmlNode -> f (Std::Array Minilib.Encoding.Xml::XmlNode)) -> Minilib.Encoding.Xml::XmlDocument -> f Minilib.Encoding.Xml::XmlDocument`

Updates a value of `XmlDocument` by applying a functorial action to field `prolog`.

### `act_xml_decl : [f : Std::Functor] (Minilib.Encoding.Xml::XmlDeclaration -> f Minilib.Encoding.Xml::XmlDeclaration) -> Minilib.Encoding.Xml::XmlDocument -> f Minilib.Encoding.Xml::XmlDocument`

Updates a value of `XmlDocument` by applying a functorial action to field `xml_decl`.

### `add_to_epilog : Minilib.Encoding.Xml::XmlNode -> Minilib.Encoding.Xml::XmlDocument -> Minilib.Encoding.Xml::XmlDocument`

Adds a child node to the epilog of the document.

### `add_to_prolog : Minilib.Encoding.Xml::XmlNode -> Minilib.Encoding.Xml::XmlDocument -> Minilib.Encoding.Xml::XmlDocument`

Adds a child node to the prolog of the document.

### `empty : Minilib.Encoding.Xml::XmlDocument`

An empty XML document.

### `make : Minilib.Encoding.Xml::XmlElement -> Minilib.Encoding.Xml::XmlDocument`

Creates a XML document with the specified document element.

### `mod_document_element : (Minilib.Encoding.Xml::XmlElement -> Minilib.Encoding.Xml::XmlElement) -> Minilib.Encoding.Xml::XmlDocument -> Minilib.Encoding.Xml::XmlDocument`

Updates a value of `XmlDocument` by applying a function to field `document_element`.

### `mod_epilog : (Std::Array Minilib.Encoding.Xml::XmlNode -> Std::Array Minilib.Encoding.Xml::XmlNode) -> Minilib.Encoding.Xml::XmlDocument -> Minilib.Encoding.Xml::XmlDocument`

Updates a value of `XmlDocument` by applying a function to field `epilog`.

### `mod_prolog : (Std::Array Minilib.Encoding.Xml::XmlNode -> Std::Array Minilib.Encoding.Xml::XmlNode) -> Minilib.Encoding.Xml::XmlDocument -> Minilib.Encoding.Xml::XmlDocument`

Updates a value of `XmlDocument` by applying a function to field `prolog`.

### `mod_xml_decl : (Minilib.Encoding.Xml::XmlDeclaration -> Minilib.Encoding.Xml::XmlDeclaration) -> Minilib.Encoding.Xml::XmlDocument -> Minilib.Encoding.Xml::XmlDocument`

Updates a value of `XmlDocument` by applying a function to field `xml_decl`.

### `set_document_element : Minilib.Encoding.Xml::XmlElement -> Minilib.Encoding.Xml::XmlDocument -> Minilib.Encoding.Xml::XmlDocument`

Updates a value of `XmlDocument` by setting field `document_element` to a specified one.

### `set_epilog : Std::Array Minilib.Encoding.Xml::XmlNode -> Minilib.Encoding.Xml::XmlDocument -> Minilib.Encoding.Xml::XmlDocument`

Updates a value of `XmlDocument` by setting field `epilog` to a specified one.

### `set_prolog : Std::Array Minilib.Encoding.Xml::XmlNode -> Minilib.Encoding.Xml::XmlDocument -> Minilib.Encoding.Xml::XmlDocument`

Updates a value of `XmlDocument` by setting field `prolog` to a specified one.

### `set_xml_decl : Minilib.Encoding.Xml::XmlDeclaration -> Minilib.Encoding.Xml::XmlDocument -> Minilib.Encoding.Xml::XmlDocument`

Updates a value of `XmlDocument` by setting field `xml_decl` to a specified one.

## `namespace Minilib.Encoding.Xml::XmlElement`

### `@attributes : Minilib.Encoding.Xml::XmlElement -> Std::Array Minilib.Encoding.Xml::XmlAttribute`

Retrieves the field `attributes` from a value of `XmlElement`.

### `@children : Minilib.Encoding.Xml::XmlElement -> Std::Array Minilib.Encoding.Xml::XmlNode`

Retrieves the field `children` from a value of `XmlElement`.

### `@tag_name : Minilib.Encoding.Xml::XmlElement -> Std::String`

Retrieves the field `tag_name` from a value of `XmlElement`.

### `act_attributes : [f : Std::Functor] (Std::Array Minilib.Encoding.Xml::XmlAttribute -> f (Std::Array Minilib.Encoding.Xml::XmlAttribute)) -> Minilib.Encoding.Xml::XmlElement -> f Minilib.Encoding.Xml::XmlElement`

Updates a value of `XmlElement` by applying a functorial action to field `attributes`.

### `act_children : [f : Std::Functor] (Std::Array Minilib.Encoding.Xml::XmlNode -> f (Std::Array Minilib.Encoding.Xml::XmlNode)) -> Minilib.Encoding.Xml::XmlElement -> f Minilib.Encoding.Xml::XmlElement`

Updates a value of `XmlElement` by applying a functorial action to field `children`.

### `act_tag_name : [f : Std::Functor] (Std::String -> f Std::String) -> Minilib.Encoding.Xml::XmlElement -> f Minilib.Encoding.Xml::XmlElement`

Updates a value of `XmlElement` by applying a functorial action to field `tag_name`.

### `add : Minilib.Encoding.Xml::XmlElement -> Minilib.Encoding.Xml::XmlElement -> Minilib.Encoding.Xml::XmlElement`

`parent.add(child)` adds a child element to `parent`.

### `addF : Minilib.Encoding.Xml::XmlElement -> Minilib.Encoding.Xml::XmlElement -> Minilib.Encoding.Xml::XmlElement`

`parent.addF $ child` adds a child element to `parent`.
This is a flipped version of `add`.

### `add_node : Minilib.Encoding.Xml::XmlNode -> Minilib.Encoding.Xml::XmlElement -> Minilib.Encoding.Xml::XmlElement`

`add_node` is synonym for `append_child`.

### `append_child : Minilib.Encoding.Xml::XmlNode -> Minilib.Encoding.Xml::XmlElement -> Minilib.Encoding.Xml::XmlElement`

`parent.append_child(child_node)` adds a child node to `parent`.

### `attr : Std::String -> Std::String -> Minilib.Encoding.Xml::XmlElement -> Minilib.Encoding.Xml::XmlElement`

`attr` is synonym for `set_attribute`.

### `concat_text_nodes : Minilib.Encoding.Xml::XmlElement -> Minilib.Encoding.Xml::XmlElement`

`element.concat_text_nodes` concats adjuscent text nodes.

### `element : Std::String -> Minilib.Encoding.Xml::XmlElement`

Synonym for `XmlElement::make`.

### `get_attribute : Std::String -> Minilib.Encoding.Xml::XmlElement -> Std::Option Std::String`

`element.get_attribute(name)` gets the value of a specified attribute
on the element.

### `make : Std::String -> Minilib.Encoding.Xml::XmlElement`

`XmlElement::make(tag_name)` creates an empty element with the specified tag name.

### `mod_attributes : (Std::Array Minilib.Encoding.Xml::XmlAttribute -> Std::Array Minilib.Encoding.Xml::XmlAttribute) -> Minilib.Encoding.Xml::XmlElement -> Minilib.Encoding.Xml::XmlElement`

Updates a value of `XmlElement` by applying a function to field `attributes`.

### `mod_children : (Std::Array Minilib.Encoding.Xml::XmlNode -> Std::Array Minilib.Encoding.Xml::XmlNode) -> Minilib.Encoding.Xml::XmlElement -> Minilib.Encoding.Xml::XmlElement`

Updates a value of `XmlElement` by applying a function to field `children`.

### `mod_tag_name : (Std::String -> Std::String) -> Minilib.Encoding.Xml::XmlElement -> Minilib.Encoding.Xml::XmlElement`

Updates a value of `XmlElement` by applying a function to field `tag_name`.

### `remove_attribute : Std::String -> Minilib.Encoding.Xml::XmlElement -> Minilib.Encoding.Xml::XmlElement`

`element.remove_attribute(name)` removes the attribute with the specified name
from the element. If the specified attribute does not exist, this function does nothing.

### `set_attribute : Std::String -> Std::String -> Minilib.Encoding.Xml::XmlElement -> Minilib.Encoding.Xml::XmlElement`

`element.set_attribute(name,value)` sets the value of an attribute
on the element.
If an attribute of same name exists, it will be replaced.
NOTE: validity of attribute names are not checked.

### `set_attributes : Std::Array Minilib.Encoding.Xml::XmlAttribute -> Minilib.Encoding.Xml::XmlElement -> Minilib.Encoding.Xml::XmlElement`

Updates a value of `XmlElement` by setting field `attributes` to a specified one.

### `set_children : Std::Array Minilib.Encoding.Xml::XmlNode -> Minilib.Encoding.Xml::XmlElement -> Minilib.Encoding.Xml::XmlElement`

Updates a value of `XmlElement` by setting field `children` to a specified one.

### `set_tag_name : Std::String -> Minilib.Encoding.Xml::XmlElement -> Minilib.Encoding.Xml::XmlElement`

Updates a value of `XmlElement` by setting field `tag_name` to a specified one.

### `text : Std::String -> Minilib.Encoding.Xml::XmlElement -> Minilib.Encoding.Xml::XmlElement`

`element.text(content)` adds a text node to `element`.

## `namespace Minilib.Encoding.Xml::XmlNode`

### `as_attribute_node : Minilib.Encoding.Xml::XmlNode -> Minilib.Encoding.Xml::XmlAttribute`

Unwraps a union value of `XmlNode` as the variant `attribute_node`.
If the value is not the variant `attribute_node`, this function aborts the program.

### `as_cdata_section : Minilib.Encoding.Xml::XmlNode -> Minilib.Encoding.Xml::XmlCDATASection`

Unwraps a union value of `XmlNode` as the variant `cdata_section`.
If the value is not the variant `cdata_section`, this function aborts the program.

### `as_comment_node : Minilib.Encoding.Xml::XmlNode -> Minilib.Encoding.Xml::XmlComment`

Unwraps a union value of `XmlNode` as the variant `comment_node`.
If the value is not the variant `comment_node`, this function aborts the program.

### `as_document_node : Minilib.Encoding.Xml::XmlNode -> Minilib.Encoding.Xml::XmlDocument`

Unwraps a union value of `XmlNode` as the variant `document_node`.
If the value is not the variant `document_node`, this function aborts the program.

### `as_element_node : Minilib.Encoding.Xml::XmlNode -> Minilib.Encoding.Xml::XmlElement`

Unwraps a union value of `XmlNode` as the variant `element_node`.
If the value is not the variant `element_node`, this function aborts the program.

### `as_processing_instruction : Minilib.Encoding.Xml::XmlNode -> Minilib.Encoding.Xml::XmlProcessingInstruction`

Unwraps a union value of `XmlNode` as the variant `processing_instruction`.
If the value is not the variant `processing_instruction`, this function aborts the program.

### `as_text_node : Minilib.Encoding.Xml::XmlNode -> Minilib.Encoding.Xml::XmlText`

Unwraps a union value of `XmlNode` as the variant `text_node`.
If the value is not the variant `text_node`, this function aborts the program.

### `attribute_node : Minilib.Encoding.Xml::XmlAttribute -> Minilib.Encoding.Xml::XmlNode`

Constructs a value of union `XmlNode` taking the variant `attribute_node`.

### `cdata_section : Minilib.Encoding.Xml::XmlCDATASection -> Minilib.Encoding.Xml::XmlNode`

Constructs a value of union `XmlNode` taking the variant `cdata_section`.

### `comment_node : Minilib.Encoding.Xml::XmlComment -> Minilib.Encoding.Xml::XmlNode`

Constructs a value of union `XmlNode` taking the variant `comment_node`.

### `document_node : Minilib.Encoding.Xml::XmlDocument -> Minilib.Encoding.Xml::XmlNode`

Constructs a value of union `XmlNode` taking the variant `document_node`.

### `element_node : Minilib.Encoding.Xml::XmlElement -> Minilib.Encoding.Xml::XmlNode`

Constructs a value of union `XmlNode` taking the variant `element_node`.

### `is_attribute_node : Minilib.Encoding.Xml::XmlNode -> Std::Bool`

Checks if a union value of `XmlNode` is the variant `attribute_node`.

### `is_cdata_section : Minilib.Encoding.Xml::XmlNode -> Std::Bool`

Checks if a union value of `XmlNode` is the variant `cdata_section`.

### `is_comment_node : Minilib.Encoding.Xml::XmlNode -> Std::Bool`

Checks if a union value of `XmlNode` is the variant `comment_node`.

### `is_document_node : Minilib.Encoding.Xml::XmlNode -> Std::Bool`

Checks if a union value of `XmlNode` is the variant `document_node`.

### `is_element_node : Minilib.Encoding.Xml::XmlNode -> Std::Bool`

Checks if a union value of `XmlNode` is the variant `element_node`.

### `is_processing_instruction : Minilib.Encoding.Xml::XmlNode -> Std::Bool`

Checks if a union value of `XmlNode` is the variant `processing_instruction`.

### `is_text_node : Minilib.Encoding.Xml::XmlNode -> Std::Bool`

Checks if a union value of `XmlNode` is the variant `text_node`.

### `mod_attribute_node : (Minilib.Encoding.Xml::XmlAttribute -> Minilib.Encoding.Xml::XmlAttribute) -> Minilib.Encoding.Xml::XmlNode -> Minilib.Encoding.Xml::XmlNode`

Updates a value of union `XmlNode` by applying a function if it is the variant `attribute_node`, or doing nothing otherwise.

### `mod_cdata_section : (Minilib.Encoding.Xml::XmlCDATASection -> Minilib.Encoding.Xml::XmlCDATASection) -> Minilib.Encoding.Xml::XmlNode -> Minilib.Encoding.Xml::XmlNode`

Updates a value of union `XmlNode` by applying a function if it is the variant `cdata_section`, or doing nothing otherwise.

### `mod_comment_node : (Minilib.Encoding.Xml::XmlComment -> Minilib.Encoding.Xml::XmlComment) -> Minilib.Encoding.Xml::XmlNode -> Minilib.Encoding.Xml::XmlNode`

Updates a value of union `XmlNode` by applying a function if it is the variant `comment_node`, or doing nothing otherwise.

### `mod_document_node : (Minilib.Encoding.Xml::XmlDocument -> Minilib.Encoding.Xml::XmlDocument) -> Minilib.Encoding.Xml::XmlNode -> Minilib.Encoding.Xml::XmlNode`

Updates a value of union `XmlNode` by applying a function if it is the variant `document_node`, or doing nothing otherwise.

### `mod_element_node : (Minilib.Encoding.Xml::XmlElement -> Minilib.Encoding.Xml::XmlElement) -> Minilib.Encoding.Xml::XmlNode -> Minilib.Encoding.Xml::XmlNode`

Updates a value of union `XmlNode` by applying a function if it is the variant `element_node`, or doing nothing otherwise.

### `mod_processing_instruction : (Minilib.Encoding.Xml::XmlProcessingInstruction -> Minilib.Encoding.Xml::XmlProcessingInstruction) -> Minilib.Encoding.Xml::XmlNode -> Minilib.Encoding.Xml::XmlNode`

Updates a value of union `XmlNode` by applying a function if it is the variant `processing_instruction`, or doing nothing otherwise.

### `mod_text_node : (Minilib.Encoding.Xml::XmlText -> Minilib.Encoding.Xml::XmlText) -> Minilib.Encoding.Xml::XmlNode -> Minilib.Encoding.Xml::XmlNode`

Updates a value of union `XmlNode` by applying a function if it is the variant `text_node`, or doing nothing otherwise.

### `processing_instruction : Minilib.Encoding.Xml::XmlProcessingInstruction -> Minilib.Encoding.Xml::XmlNode`

Constructs a value of union `XmlNode` taking the variant `processing_instruction`.

### `text_node : Minilib.Encoding.Xml::XmlText -> Minilib.Encoding.Xml::XmlNode`

Constructs a value of union `XmlNode` taking the variant `text_node`.

## `namespace Minilib.Encoding.Xml::XmlProcessingInstruction`

### `@content : Minilib.Encoding.Xml::XmlProcessingInstruction -> Std::String`

Retrieves the field `content` from a value of `XmlProcessingInstruction`.

### `act_content : [f : Std::Functor] (Std::String -> f Std::String) -> Minilib.Encoding.Xml::XmlProcessingInstruction -> f Minilib.Encoding.Xml::XmlProcessingInstruction`

Updates a value of `XmlProcessingInstruction` by applying a functorial action to field `content`.

### `make : Std::String -> Minilib.Encoding.Xml::XmlProcessingInstruction`

`XmlProcessingInstruction::make(content)` creates a processing instruction with the specified content.

### `mod_content : (Std::String -> Std::String) -> Minilib.Encoding.Xml::XmlProcessingInstruction -> Minilib.Encoding.Xml::XmlProcessingInstruction`

Updates a value of `XmlProcessingInstruction` by applying a function to field `content`.

### `set_content : Std::String -> Minilib.Encoding.Xml::XmlProcessingInstruction -> Minilib.Encoding.Xml::XmlProcessingInstruction`

Updates a value of `XmlProcessingInstruction` by setting field `content` to a specified one.

## `namespace Minilib.Encoding.Xml::XmlText`

### `@content : Minilib.Encoding.Xml::XmlText -> Std::String`

Retrieves the field `content` from a value of `XmlText`.

### `act_content : [f : Std::Functor] (Std::String -> f Std::String) -> Minilib.Encoding.Xml::XmlText -> f Minilib.Encoding.Xml::XmlText`

Updates a value of `XmlText` by applying a functorial action to field `content`.

### `make : Std::String -> Minilib.Encoding.Xml::XmlText`

`XmlText::make(content)` creates a text node with the specified content.

### `mod_content : (Std::String -> Std::String) -> Minilib.Encoding.Xml::XmlText -> Minilib.Encoding.Xml::XmlText`

Updates a value of `XmlText` by applying a function to field `content`.

### `set_content : Std::String -> Minilib.Encoding.Xml::XmlText -> Minilib.Encoding.Xml::XmlText`

Updates a value of `XmlText` by setting field `content` to a specified one.