# Index

### [module Minilib.App.Clap (lib/app/clap.fix)](lib/app/clap.md)

Command line argument parser.
Inspired by [`clap` crate of Rust](https://docs.rs/clap/3.2.0/clap/index.html).

### [module Minilib.Collection.Deque (lib/collection/deque.fix)](lib/collection/deque.md)

Deque (double-ended queue).
Deque can be used as a FIFO such as a message queue.
When used as a FIFO, the amortized costs of `push_back()` and
`pop_front()` are `O(1)`.

### [module Minilib.Collection.OrderedMap (lib/collection/ordered_map.fix)](lib/collection/ordered_map.md)

Ordered map.
This is similar to HashMap except it preserves the order of entries.

### [module Minilib.Collection.RBTree (lib/collection/rbtree.fix)](lib/collection/rbtree.md)

Red-Black Tree.
(This is an internal module of `TreeMap` and `TreeSet`.)

### [module Minilib.Collection.TreeMap (lib/collection/tree_map.fix)](lib/collection/tree_map.md)

TreeMap is a map that manages keys in sorted order.

### [module Minilib.Collection.TreeSet (lib/collection/tree_set.fix)](lib/collection/tree_set.md)

TreeSet is a set that manages elements in sorted order.

### [module Minilib.Common.Common (lib/common/common.fix)](lib/common/common.md)

Common functions such as `id` and `flip`.

### [module Minilib.Crypto.SHA1 (lib/crypto/sha1.fix)](lib/crypto/sha1.md)

SHA-1 secure hash function.

### [module Minilib.Crypto.SHA256 (lib/crypto/sha256.fix)](lib/crypto/sha256.md)

SHA-256 secure hash function.

### [module Minilib.Encoding.Binary (lib/encoding/binary.fix)](lib/encoding/binary.md)

Binary utility, such as:
- Byte order
- Byte buffer

### [module Minilib.Encoding.Json.JsonDecoder (lib/encoding/json/json_decoder.fix)](lib/encoding/json/json_decoder.md)

Decodes a JSON value from a string.

### [module Minilib.Encoding.Json.JsonEncoder (lib/encoding/json/json_encoder.fix)](lib/encoding/json/json_encoder.md)

Encodes a JSON value to a string.

### [module Minilib.Encoding.Json (lib/encoding/json.fix)](lib/encoding/json.md)

Definition of the structure of a JSON value.

### [module Minilib.IO.Channel (lib/io/channel.fix)](lib/io/channel.md)

A Channel that can be used for the communication of threads.

### [module Minilib.IO.IOEx (lib/io/io_ex.fix)](lib/io/io_ex.md)

IO extensions, such as:
- Create or delete files and directories
- Directory listing
- Find files under directory
- Checks if file or directory exists
- Retrieve file information, such as file size and time stamps
- Get kernel information such as system name, machine archtecture

### [module Minilib.Math.BigFloat (lib/math/bigfloat.fix)](lib/math/bigfloat.md)

Arbitrary-precision floating point number.

### [module Minilib.Math.BigInt (lib/math/bigint.fix)](lib/math/bigint.md)

Arbitrary-precision integer.

### [module Minilib.Math.BigIntPrime (lib/math/bigint_prime.fix)](lib/math/bigint_prime.md)

Generates probable prime numbers of arbitrary-precision integer.

### [module Minilib.Math.BigNat (lib/math/bignat.fix)](lib/math/bignat.md)

Arbitrary-precision natural number. This is internal module of BigInt.

### [module Minilib.Math.Complex (lib/math/complex.fix)](lib/math/complex.md)

Complex number.

### [module Minilib.Math.Rational (lib/math/rational.fix)](lib/math/rational.md)

Rational number

### [module Minilib.Math.Types (lib/math/types.fix)](lib/math/types.md)

Type definitions for mathematical concepts.

### [module Minilib.Media.Image (lib/media/image.fix)](lib/media/image.md)


### [module Minilib.Media.Png (lib/media/png.fix)](lib/media/png.md)

PNG image I/O.

### [module Minilib.Monad.FunctorM (lib/monad/functor_m.fix)](lib/monad/functor_m.md)

`map_m`, `foreach_m` for Array and Iterator.

### [module Minilib.Monad.Reader (lib/monad/reader.fix)](lib/monad/reader.md)

Reader monad. (a.k.a Traced, CoWriter comonad)

### [module Minilib.Monad.State (lib/monad/state.fix)](lib/monad/state.md)

State Monad. NOTE that currently this interface is unstable.

### [module Minilib.Monad.Writer (lib/monad/writer.fix)](lib/monad/writer.md)

Writer monad. (a.k.a Env, CoReader comonad)

### [module Minilib.Net.HTML (lib/net/html.fix)](lib/net/html.md)

HTML handling, such as:
- Very simple DOM model (HTMLDocument, HTMLElement)
- Escape/unescape HTML special characters

### [module Minilib.Net.HttpServer (lib/net/http_server.fix)](lib/net/http_server.md)

Simple HTTP server.
The interface is similar to `express` of Node.js.
- Insert a request handler on specific path
- Listen for incoming requests

### [module Minilib.Net.Request (lib/net/request.fix)](lib/net/request.md)

HTTP request and response.
- Parses HTTP request headers and query strings, POST data
(currently only `application/x-www-form-urlencoded` is supported)
- Writes response back to client

### [module Minilib.Net.Router (lib/net/router.fix)](lib/net/router.md)

HTTP request router.
- Mounts a request handler to specific path and method
- Finds a request handler from path and method of the HTTP request

### [module Minilib.Net.Tcp (lib/net/tcp.fix)](lib/net/tcp.md)

TCP operation, such as:
- IP address, port number
- Resolves IP address from hostname
- IPv4 Socket address
- IPv4 TCP Socket

### [module Minilib.Net.URL (lib/net/url.fix)](lib/net/url.md)

URL and URI parsing

### [module Minilib.Task.Future (lib/task/future.fix)](lib/task/future.md)

A computation that is performed in a TaskPool in parallel.

### [module Minilib.Task.TaskPool (lib/task/task_pool.fix)](lib/task/task_pool.md)

A task pool that can be used parallel computation.

### [module Minilib.Testing.TestUtilArray (lib/testing/test_util_array.fix)](lib/testing/test_util_array.md)

Array utility functions for testing.

### [module Minilib.Testing.Timeit (lib/testing/timeit.fix)](lib/testing/timeit.md)

Measures execution time. Similar to `timeit` module of Python.

### [module Minilib.Testing.UnitTest (lib/testing/unit_test.fix)](lib/testing/unit_test.md)

Unit Test Framework

### [module Minilib.Text.RegExp.RegExpNFA (lib/text/regexp/regexp_nfa.fix)](lib/text/regexp/regexp_nfa.md)

NFA (Nondeterministic Finite Automaton). This is internal module of `RegExp`.

### [module Minilib.Text.RegExp.RegExpPattern (lib/text/regexp/regexp_pattern.fix)](lib/text/regexp/regexp_pattern.md)

Character class and Pattern parser. This is internal module of `RegExp`.

### [module Minilib.Text.RegExp (lib/text/regexp.fix)](lib/text/regexp.md)

Simple regular expression.

### [module Minilib.Text.SimpleParser (lib/text/simple_parser.fix)](lib/text/simple_parser.md)

Simple text parser. Customizable by monadic operations.
- Stream of characters
- Basic parsers such as character matching
- Create complex parsers with composition

### [module Minilib.Text.StringEx (lib/text/string_ex.fix)](lib/text/string_ex.md)

String extensions, such as:
- ToString for Tuple, Option, Result, Array, HashMap
- Array U8 -> String conversion
- Search, replace, split, comparison of String
- Hexadecimal String
- File Path handling

### [module Minilib.Text.Unicode (lib/text/unicode.fix)](lib/text/unicode.md)

Unicode conversions (UTF8 <-> UTF32 <-> UTF16)

### [module Minilib.Trait.Comonad (lib/trait/comonad.fix)](lib/trait/comonad.md)

Comonad trait and associated functions.

### [module Minilib.Trait.Monoid (lib/trait/monoid.fix)](lib/trait/monoid.md)

Monoid trait and its several implementations (Array, Iterator, String etc).

### [module Minilib.Trait.Semigroup (lib/trait/semigroup.fix)](lib/trait/semigroup.md)

Semigroup trait and its several implementations (Array, Iterator, String etc).

