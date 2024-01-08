# Index
### [lib/clap.fix](lib/clap.md)

Command line argument parser.
Inspired by [`clap` crate of Rust](https://docs.rs/clap/3.2.0/clap/index.html).


### [lib/collection/deque.fix](lib/collection/deque.md)

Double-ended queues


### [lib/collection/ordered_map.fix](lib/collection/ordered_map.md)

Ordered map.
This is similar to HashMap except it preserves the order of entries.


### [lib/io_ex.fix](lib/io_ex.md)

IO extensions


### [lib/json.fix](lib/json.md)

Definition of the structure of a JSON value.


### [lib/json_decoder.fix](lib/json_decoder.md)

Decodes a JSON value from a string.


### [lib/json_encoder.fix](lib/json_encoder.md)

Encodes a JSON value to a string.


### [lib/net/html.fix](lib/net/html.md)


### [lib/net/http_server.fix](lib/net/http_server.md)


### [lib/net/request.fix](lib/net/request.md)


### [lib/net/router.fix](lib/net/router.md)


### [lib/net/tcp.fix](lib/net/tcp.md)


### [lib/net/url.fix](lib/net/url.md)

URL and URI parsing


### [lib/simple_parser.fix](lib/simple_parser.md)

A monadic text parser


### [lib/string_ex.fix](lib/string_ex.md)

String extensions


### [lib/text/regexp/regexp.fix](lib/text/regexp/regexp.md)

An implementation of simple regular expression.

Currently it only supports patterns below:
- Character classes: `[xyz]`, `[^xyz]`, `.`, `\d`, `\D`, `\w`, `\W`, `\s`,
`\S`, `\t`, `\r`, `\n`, `\v`, `\f`, `[\b]`, `x|y`
- Assertions: `^`, `$`
- Groups: `(x)`
- Quantifiers: `x*`, `x+`, `x?`, `x{n}`, `x{n,}`, `x{n,m}`

For details, see
[mdn web docs: Regular expressions](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Guide/Regular_expressions).

LIMITATION:

Currently, only single byte characters (U+0001..U+007F) can be specified in character classes.
Non-ASCII characters (U+0080..U+10FFFF) are encoded to two or more bytes in UTF-8, so they cannot be specified in character classes.
And the null character (U+0000) cannot be used in Fix strings.



### [lib/text/regexp/regexp_nfa.fix](lib/text/regexp/regexp_nfa.md)

This is internal module of `RegExp`.

NFA (Nondeterministic Finite Automaton)

For details, see web pages below.
- https://swtch.com/~rsc/regexp/regexp1.html
- https://zenn.dev/canalun/articles/regexp_and_automaton



### [lib/text/regexp/regexp_pattern.fix](lib/text/regexp/regexp_pattern.md)

This is internal module of `RegExp`.

Character class and Pattern parser


### [lib/unicode.fix](lib/unicode.md)


### [lib/unit_test.fix](lib/unit_test.md)

Unit Test Framework


