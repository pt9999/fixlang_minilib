# Index

| Module Name | Summary |
| ----------- | ------- |
| [Minilib.App.Clap](lib/app/clap.md) | Command line argument parser. |
| [Minilib.Collection.Deque](lib/collection/deque.md) | Deque (double-ended queue). |
| [Minilib.Collection.OrderedMap](lib/collection/ordered_map.md) | Ordered map. |
| [Minilib.Collection.RBTree](lib/collection/rbtree.md) | Red-Black Tree. |
| [Minilib.Collection.TreeMap](lib/collection/tree_map.md) | TreeMap is a map that manages keys in sorted order. |
| [Minilib.Collection.TreeSet](lib/collection/tree_set.md) | TreeSet is a set that manages elements in sorted order. |
| [Minilib.Common.Common](lib/common/common.md) | Common functions such as `id` and `flip`. |
| [Minilib.Comonad.Env](lib/comonad/env.md) | Env comonad. (a.k.a CoReader comonad) |
| [Minilib.Comonad.IdentityC](lib/comonad/identity_c.md) | Identity comonad |
| [Minilib.Comonad.Traced](lib/comonad/traced.md) | Traced comonad. (a.k.a CoWriter comonad) |
| [Minilib.Crypto.AES.GCM](lib/crypto/aes/aes_gcm.md) | Galois/Counter Mode (GCM) for AES |
| [Minilib.Crypto.AES](lib/crypto/aes.md) | Advanced Encryption Standard (AES) |
| [Minilib.Crypto.HMAC.HmacMD5](lib/crypto/hmac/hmac_md5.md) | An HMAC instance that uses MD5 as a hash function. |
| [Minilib.Crypto.HMAC.HmacSHA1](lib/crypto/hmac/hmac_sha1.md) | An HMAC instance that uses SHA1 as a hash function. |
| [Minilib.Crypto.HMAC.HmacSHA256](lib/crypto/hmac/hmac_sha256.md) | An HMAC instance that uses SHA256 as a hash function. |
| [Minilib.Crypto.HMAC](lib/crypto/hmac.md) | The Keyed-Hash Message Authentication Code (HMAC) |
| [Minilib.Crypto.MD5](lib/crypto/md5.md) | MD5 secure hash function. |
| [Minilib.Crypto.SecureRandom](lib/crypto/secure_random.md) | Secure random number generator. |
| [Minilib.Crypto.SHA1](lib/crypto/sha1.md) | SHA-1 secure hash function. |
| [Minilib.Crypto.SHA256](lib/crypto/sha256.md) | SHA-256 secure hash function. |
| [Minilib.Crypto.SHA512](lib/crypto/sha512.md) | SHA-512 secure hash function. |
| [Minilib.Encoding.Base64](lib/encoding/base64.md) | BASE64 encoding and decoding |
| [Minilib.Encoding.Binary](lib/encoding/binary.md) | Binary utility, such as: |
| [Minilib.Encoding.Json.JsonDecoder](lib/encoding/json/json_decoder.md) | Decodes a JSON value from a string. |
| [Minilib.Encoding.Json.JsonEncoder](lib/encoding/json/json_encoder.md) | Encodes a JSON value to a string. |
| [Minilib.Encoding.Json](lib/encoding/json.md) | Definition of the structure of a JSON value. |
| [Minilib.Encoding.Xml.XmlHelpers](lib/encoding/xml/xml_helpers.md) | XML helpers, such as escaping/unescaping special characters. |
| [Minilib.Encoding.Xml.XmlParser](lib/encoding/xml/xml_parser.md) | Simple XML 1.1 Parser. |
| [Minilib.Encoding.Xml](lib/encoding/xml.md) | Simple XML Model. |
| [Minilib.IO.Channel](lib/io/channel.md) | A Channel that can be used for the communication of threads. |
| [Minilib.IO.Errno](lib/io/errno.md) | Functions for `errno` which is set by system calls and some library functions. |
| [Minilib.IO.FileSystem](lib/io/file_system.md) | File system module. For example, finding files, checks if file or directory exists, |
| [Minilib.IO.Path](lib/io/path.md) | File Path handling, such as joining paths and retrieving directory name. |
| [Minilib.IO.Platform](lib/io/platform.md) | Get kernel information such as system name, machine archtecture. |
| [Minilib.Math.BigFloat](lib/math/bigfloat.md) | Arbitrary-precision floating point number. |
| [Minilib.Math.BigInt](lib/math/bigint.md) | Arbitrary-precision integer. |
| [Minilib.Math.BigIntPrime](lib/math/bigint_prime.md) | Generates probable prime numbers of arbitrary-precision integer. |
| [Minilib.Math.BigNat](lib/math/bignat.md) | Arbitrary-precision natural number. This is internal module of BigInt. |
| [Minilib.Math.Complex](lib/math/complex.md) | Complex number, for example `1 + 2i`. |
| [Minilib.Math.Euclid](lib/math/euclid.md) | Euclid algorithms, such as `gcd` (greatest common divisor). |
| [Minilib.Math.Modular](lib/math/modular.md) | This is an arithmetic with a modulus (modulo), for example `2 * 5 = 10 = 3 (mod 7)`. |
| [Minilib.Math.Polynomial](lib/math/polynomial.md) | Polynomial of one variable, for example `x^2 + 2x + 1`. The coefficients can be any ring. |
| [Minilib.Math.RandomEx](lib/math/random_ex.md) | Extension of `Random` module. For example, generating a random integer in range, or a random array. |
| [Minilib.Math.Rational](lib/math/rational.md) | Rational number arithmetic, for example `1/2 + 1/3 = 5/6`. |
| [Minilib.Math.Ring](lib/math/ring.md) | Functions for a ring, for example multiplication or exponent with an integer. |
| [Minilib.Math.Types](lib/math/types.md) | Type definitions for mathematical concepts, for example AdditiveGroup, Ring, Field. |
| [Minilib.Media.Image](lib/media/image.md) | Basic image definitions. |
| [Minilib.Media.Png](lib/media/png.md) | PNG image I/O. |
| [Minilib.Media.Svg](lib/media/svg.md) | Scalable Vector Graphics (SVG) 1.1 |
| [Minilib.Monad.Cont](lib/monad/cont.md) | Continuation Monad. |
| [Minilib.Monad.Error](lib/monad/error.md) | Definition of `MonadErrorIF` trait which can report errors. |
| [Minilib.Monad.Except](lib/monad/except.md) | Except monad transformer that implements `MonadErrorIF`. |
| [Minilib.Monad.FunctorM](lib/monad/functor_m.md) | `map_m`, `foreach_m` for Array and Iterator. |
| [Minilib.Monad.Identity](lib/monad/identity.md) | Identity monad |
| [Minilib.Monad.IO](lib/monad/io.md) | Monadic traits which can lift IO and IOFail monad. |
| [Minilib.Monad.Reader](lib/monad/reader.md) | Reader monad. |
| [Minilib.Monad.State](lib/monad/state.md) | State Monad which maintains a mutable state. |
| [Minilib.Monad.Trans](lib/monad/trans.md) | Trait for a monad transformer. |
| [Minilib.Monad.Writer](lib/monad/writer.md) | Writer monad. |
| [Minilib.Net.HTML](lib/net/html.md) | Simple HTML DOM model, as well as escaping/unescaping HTML special characters. |
| [Minilib.Net.HttpServer](lib/net/http_server.md) | Simple HTTP server. |
| [Minilib.Net.Request](lib/net/request.md) | HTTP request and response. |
| [Minilib.Net.Router](lib/net/router.md) | HTTP request router. |
| [Minilib.Net.Tcp](lib/net/tcp.md) | IPv4 TCP Socket operations. |
| [Minilib.Net.URL](lib/net/url.md) | URL and URI parsing |
| [Minilib.Testing.TestUtilArray](lib/testing/test_util_array.md) | Array utility functions for testing. |
| [Minilib.Testing.UnitTest](lib/testing/unit_test.md) | Unit Test Framework |
| [Minilib.Text.Hex](lib/text/hex.md) | Hexadecimal string conversion |
| [Minilib.Text.RegExp.RegExpNFA](lib/text/regexp/regexp_nfa.md) | NFA (Nondeterministic Finite Automaton). This is internal module of `RegExp`. |
| [Minilib.Text.RegExp.RegExpPattern](lib/text/regexp/regexp_pattern.md) | Character class and Pattern parser. This is internal module of `RegExp`. |
| [Minilib.Text.RegExp](lib/text/regexp.md) | Simple regular expression. |
| [Minilib.Text.SimpleParser](lib/text/simple_parser.md) | Simple text parser. Customizable by monadic operations. |
| [Minilib.Text.StringEx](lib/text/string_ex.md) | String utility functions. |
| [Minilib.Text.Unicode](lib/text/unicode.md) | Unicode conversions (UTF8 <-> UTF32 <-> UTF16) |
| [Minilib.Thread.Future](lib/thread/future.md) | A computation that is performed in a TaskPool in parallel. |
| [Minilib.Thread.TaskPool](lib/thread/task_pool.md) | A task pool that can be used parallel computation. |
| [Minilib.Thread.Time](lib/thread/time.md) | Timing module, such as sleep for a while, and measuring execution time. |
| [Minilib.Trait.Comonad](lib/trait/comonad.md) | Comonad trait and associated functions. |
| [Minilib.Trait.Monoid](lib/trait/monoid.md) | Monoid trait and its several implementations (Array, Iterator, String etc). |
| [Minilib.Trait.Semigroup](lib/trait/semigroup.md) | Semigroup trait and its several implementations (Array, Iterator, String etc). |
