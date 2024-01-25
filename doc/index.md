# Index

### [lib/app/clap.fix](lib/app/clap.md)

Command line argument parser.
Inspired by [`clap` crate of Rust](https://docs.rs/clap/3.2.0/clap/index.html).

### [lib/collection/deque.fix](lib/collection/deque.md)

Deque (double-ended queue).
Deque can be used as a FIFO such as a message queue.
When used as a FIFO, the amortized costs of `push_back()` and
`pop_front()` are `O(1)`.

### [lib/collection/ordered_map.fix](lib/collection/ordered_map.md)

Ordered map.
This is similar to HashMap except it preserves the order of entries.

### [lib/collection/rbtree.fix](lib/collection/rbtree.md)

Red-Black Tree.
(This is an internal module of `TreeMap` and `TreeSet`.)

### [lib/collection/tree_map.fix](lib/collection/tree_map.md)

TreeMap is a map that manages keys in sorted order.

### [lib/collection/tree_set.fix](lib/collection/tree_set.md)

TreeSet is a set that manages elements in sorted order.

### [lib/crypto/sha1.fix](lib/crypto/sha1.md)

SHA-1 secure hash function.

### [lib/crypto/sha256.fix](lib/crypto/sha256.md)

SHA-256 secure hash function.

### [lib/encoding/binary.fix](lib/encoding/binary.md)

Binary utility, such as:
- Byte order
- Byte buffer

### [lib/encoding/json/json_decoder.fix](lib/encoding/json/json_decoder.md)

Decodes a JSON value from a string.

### [lib/encoding/json/json_encoder.fix](lib/encoding/json/json_encoder.md)

Encodes a JSON value to a string.

### [lib/encoding/json.fix](lib/encoding/json.md)

Definition of the structure of a JSON value.

### [lib/io_ex.fix](lib/io_ex.md)

IO extensions, such as:
- Create or delete files and directories
- Directory listing
- Find files under directory
- Checks if file or directory exists
- Retrieve file information, such as file size and time stamps
- Get kernel information such as system name, machine archtecture

### [lib/net/html.fix](lib/net/html.md)

HTML handling, such as:
- Very simple DOM model (HTMLDocument, HTMLElement)
- Escape/unescape HTML special characters

### [lib/net/http_server.fix](lib/net/http_server.md)

Simple HTTP server.
The interface is similar to `express` of Node.js.
- Insert a request handler on specific path
- Listen for incoming requests

### [lib/net/request.fix](lib/net/request.md)

HTTP request and response.
- Parses HTTP request headers and query strings, POST data
(currently only `application/x-www-form-urlencoded` is supported)
- Writes response back to client

### [lib/net/router.fix](lib/net/router.md)

HTTP request router.
- Mounts a request handler to specific path and method
- Finds a request handler from path and method of the HTTP request

### [lib/net/tcp.fix](lib/net/tcp.md)

TCP operation, such as:
- IP address, port number
- Resolves IP address from hostname
- IPv4 Socket address
- IPv4 TCP Socket

### [lib/net/url.fix](lib/net/url.md)

URL and URI parsing

### [lib/text/regexp/regexp.fix](lib/text/regexp/regexp.md)

Simple regular expression.

### [lib/text/regexp/regexp_nfa.fix](lib/text/regexp/regexp_nfa.md)

NFA (Nondeterministic Finite Automaton). This is internal module of `RegExp`.

### [lib/text/regexp/regexp_pattern.fix](lib/text/regexp/regexp_pattern.md)

Character class and Pattern parser. This is internal module of `RegExp`.

### [lib/text/simple_parser.fix](lib/text/simple_parser.md)

Simple text parser. Customizable by monadic operations.
- Stream of characters
- Basic parsers such as character matching
- Create complex parsers with composition

### [lib/text/string_ex.fix](lib/text/string_ex.md)

String extensions, such as:
- ToString for Tuple, Option, Result, Array, HashMap
- Array U8 -> String conversion
- Search, replace, split, comparison of String
- Hexadecimal String
- File Path handling

### [lib/text/unicode.fix](lib/text/unicode.md)

Unicode conversions (UTF8 <-> UTF32 <-> UTF16)

### [lib/unit_test.fix](lib/unit_test.md)

Unit Test Framework

