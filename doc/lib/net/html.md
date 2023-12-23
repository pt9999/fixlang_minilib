## html.fix

### namespace HTML

#### html: HTMLDocument;

An empty HTML document.

#### head: HTMLElement;

An empty `<head>` element.

#### meta: HTMLElement;

An empty `<meta>` element.

#### title: HTMLElement;

An empty `<title>` element.

#### script: HTMLElement;

An empty `<script>` element.

#### body: HTMLElement;

An empty `<body>` element.

#### div: HTMLElement;

An empty `<div>` element.

#### div_: HTMLElement;

to avoid ambiguity with Std::Div::div

#### span: HTMLElement;

An empty `<span>` element.

#### input: HTMLElement;

An empty `<input>` element.

#### button: HTMLElement;

An empty `<button>` element.

#### table: HTMLElement;

An empty `<table>` element.

#### th: HTMLElement;

An empty `<th>` element.

#### tr: HTMLElement;

An empty `<tr>` element.

#### td: HTMLElement;

An empty `<td>` element.

### type HTMLDocument

A type that represents an HTML document.

```
type HTMLDocument = unbox struct {
    html: HTMLElement           // root element, ie. `<html>`
};
```
### namespace HTMLDocument

#### empty: HTMLDocument;

An empty HTML document.

#### add: HTMLElement -> HTMLDocument -> HTMLDocument;

Adds a child element to `<html>` element.

#### to_html: HTMLDocument -> String;

Converts the HTML document to HTML string.

### type HTMLNode

A type that represents an HTML node.

```
type HTMLNode = box union {
    element: HTMLElement,           // HTML element
    text_node: String               // text node
};
```
### type HTMLElement

A type that represents an HTML element.

```
type HTMLElement = unbox struct {
    tag: String,                    // tag name
    attrs: Iterator HTMLAttribute,  // attributes (reversed iterator)
    children: Array HTMLNode        // child nodes
};
```
### namespace HTMLElement

#### make: String -> HTMLElement;

`HTMLElement::make(tag)` creates an empty element with specified tag name.

#### attr: String -> String -> HTMLElement -> HTMLElement;

`el.attr(name,value)` adds an attribute to `el`.
If an attribute of same name exists, it will be removed first.
NOTE: validity of attribute names are not checked.

#### add: HTMLElement -> HTMLElement -> HTMLElement;

`el.add(child)` adds a child element to `el`.

#### text: String -> HTMLElement -> HTMLElement;

`el.text(txt)` adds a text node to `el`.

#### to_html: HTMLElement -> String;

`el.to_html` converts the element to HTML string.

### type HTMLAttribute

A type that represents name and value of an attribute.

```
type HTMLAttribute = (String, String);
```
### namespace HTMLAttribute

### namespace HTMLHelpers

#### escape_html: String -> String;

Escapes HTML special characters.
eg. `&` -> `&amp;`, `<` -> `&lt;`, `>` -> `&gt;`, `\"` -> `&quot;`, `'` -> `&#039;`

