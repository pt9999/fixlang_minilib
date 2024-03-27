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

### [module Minilib.Crypto.AES (lib/crypto/aes.fix)](lib/crypto/aes.md)

Advanced Encryption Standard (AES)

### [module Minilib.Crypto.HMAC (lib/crypto/hmac.fix)](lib/crypto/hmac.md)

The Keyed-Hash Message Authentication Code (HMAC)

### [module Minilib.Crypto.MD5 (lib/crypto/md5.fix)](lib/crypto/md5.md)

MD5 secure hash function.

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

### [module Minilib.IO.FileSystem (lib/io/file_system.fix)](lib/io/file_system.md)

File system module. For example, finding files, checks if file or directory exists,
getting file size and last modified time.

### [module Minilib.IO.Path (lib/io/path.fix)](lib/io/path.md)

File Path handling, such as joining paths and retrieving directory name.

### [module Minilib.IO.Platform (lib/io/platform.fix)](lib/io/platform.md)

Get kernel information such as system name, machine archtecture.

### [module Minilib.Math.BigFloat (lib/math/bigfloat.fix)](lib/math/bigfloat.md)

Arbitrary-precision floating point number.

### [module Minilib.Math.BigInt (lib/math/bigint.fix)](lib/math/bigint.md)

Arbitrary-precision integer.

### [module Minilib.Math.BigIntPrime (lib/math/bigint_prime.fix)](lib/math/bigint_prime.md)

Generates probable prime numbers of arbitrary-precision integer.

### [module Minilib.Math.BigNat (lib/math/bignat.fix)](lib/math/bignat.md)

Arbitrary-precision natural number. This is internal module of BigInt.

### [module Minilib.Math.Complex (lib/math/complex.fix)](lib/math/complex.md)

Complex number, for example `1 + 2i`.

### [module Minilib.Math.Euclid (lib/math/euclid.fix)](lib/math/euclid.md)

Euclid algorithms, such as `gcd` (greatest common divisor).

### [module Minilib.Math.Modular (lib/math/modular.fix)](lib/math/modular.md)

This is an arithmetic with a modulus (modulo), for example `2 * 5 = 10 = 3 (mod 7)`.

### [module Minilib.Math.Polynomial (lib/math/polynomial.fix)](lib/math/polynomial.md)

Polynomial of one variable, for example `x^2 + 2x + 1`. The coefficients can be any ring.

### [module Minilib.Math.RandomEx (lib/math/random_ex.fix)](lib/math/random_ex.md)

Extension of `Random` module. For example, generating a random integer in range, or a random array.

### [module Minilib.Math.Rational (lib/math/rational.fix)](lib/math/rational.md)

Rational number arithmetic, for example `1/2 + 1/3 = 5/6`.

### [module Minilib.Math.Ring (lib/math/ring.fix)](lib/math/ring.md)

Functions for a ring, for example multiplication or exponent with an integer.

### [module Minilib.Math.Types (lib/math/types.fix)](lib/math/types.md)

Type definitions for mathematical concepts, for example AdditiveGroup, Ring, Field.

### [module Minilib.Media.Image (lib/media/image.fix)](lib/media/image.md)


### [module Minilib.Media.Png (lib/media/png.fix)](lib/media/png.md)

PNG image I/O.

### [module Minilib.Monad.FunctorM (lib/monad/functor_m.fix)](lib/monad/functor_m.md)

`map_m`, `foreach_m` for Array and Iterator.

### [module Minilib.Monad.Identity (lib/monad/identity.fix)](lib/monad/identity.md)

Identity monad

### [module Minilib.Monad.Reader (lib/monad/reader.fix)](lib/monad/reader.md)

Reader monad. (a.k.a Traced, CoWriter comonad)

### [module Minilib.Monad.State (lib/monad/state.fix)](lib/monad/state.md)

State Monad which maintains a mutable state.

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

### [module Minilib.Testing.TestUtilArray (lib/testing/test_util_array.fix)](lib/testing/test_util_array.md)

Array utility functions for testing.

### [module Minilib.Testing.UnitTest (lib/testing/unit_test.fix)](lib/testing/unit_test.md)

Unit Test Framework

### [module Minilib.Text.Hex (lib/text/hex.fix)](lib/text/hex.md)

Hexadecimal string conversion

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
- Array U8 -> String conversion
- Search, replace, split, comparison of String
- Format
- ToString extensions

### [module Minilib.Text.Unicode (lib/text/unicode.fix)](lib/text/unicode.md)

Unicode conversions (UTF8 <-> UTF32 <-> UTF16)

### [module Minilib.Thread.Future (lib/thread/future.fix)](lib/thread/future.md)

A computation that is performed in a TaskPool in parallel.

### [module Minilib.Thread.TaskPool (lib/thread/task_pool.fix)](lib/thread/task_pool.md)

A task pool that can be used parallel computation.

### [module Minilib.Thread.Time (lib/thread/time.fix)](lib/thread/time.md)

Timing module, such as sleep for a while, and measuring execution time.

### [module Minilib.Trait.Comonad (lib/trait/comonad.fix)](lib/trait/comonad.md)

Comonad trait and associated functions.

### [module Minilib.Trait.Monoid (lib/trait/monoid.fix)](lib/trait/monoid.md)

Monoid trait and its several implementations (Array, Iterator, String etc).

### [module Minilib.Trait.Semigroup (lib/trait/semigroup.fix)](lib/trait/semigroup.md)

Semigroup trait and its several implementations (Array, Iterator, String etc).

