
# minilib Reference

NOTE: This file is under construction.

## Table of contents

- [Table of contents](#table-of-contents)
- [json.fix](#jsonfix)
- [json_decode.fix](#json_decodefix)
- [json_encode.fix](#json_encodefix)
- [ordered_map.fix](#ordered_mapfix)
- [simple_parser.fix](#simple_parserfix)
- [string_ex.fix](#string_exfix)
- [unit_test.fix](#unit_testfix)
- [tcp.fix](#tcpfix)
- [clap.fix](#clapfix)

## json.fix

### Json
A structure representing a JSON value.
```
type Json = box union {
    null: (),
    bool: Bool,
    number: F64,
    string: String,
    object: OrderedMap String Json,
    array:  Array Json
};
```

#### to_object: Array (String, Json) -> Json;
Converts an array of keys and values to a JSON object.

#### `impl Json: Eq`

## json_decode.fix

#### decode: String -> Result ErrMsg Json;
Parses JSON text and returns a JSON value.

## json_encode.fix
#### `impl Json: ToString`

#### encode: Json -> String;
Encodes JSON and converts it to a string.

#### encode_pretty: Json -> String;
Encodes JSON and converts it to a string. (pretty-printing)

#### encode_with_param: EncodeParam -> Json -> String;
Encodes JSON and converts it to a string using the specified parameter.

## ordered_map.fix
#### OrderedMap
Similar to HashMap, but `to_iter()` returns entries in the same order as they were inserted.

```
type OrderedMap k v = unbox struct {
    map: HashMap k (I64, v),
    serial: I64
};
```

## simple_parser.fix

### Stream
A character iterator that stores the file name, line number, column number, and offset from the beginning of the file.

```
type Stream = unbox struct {
    filename: String,
    line: I64,
    column: I64,
    position: I64,
    iter: Iterator Char
};
```
#### `impl Stream : FromString`
Creates a stream from a string.

### ParseResult
Result type that returns a value of an arbitrary type and a stream.

```
type ParseResult a = Result ErrMsg (a, Stream);
```

#### `impl ParseResult : ToString`

#### _NotMatch: ErrMsg;

A special error message that represents the parser is not matched.

### Parser
A structure with a function that receive a stream, parse it, and
return the parsed result and the next stream position.

```
type Parser a = unbox struct { _parser: Stream -> ParseResult a };

type ParseResult a = Result ErrMsg (a, Stream);
```

#### parser: (Stream -> ParseResult a) -> Parser a;
A function that creates a Parser structure based on the parsing function.

#### run_parser: Stream -> Parser a -> ParseResult a;
Apply a stream to a parsing function and return the parsed result.

#### run_parser_str: String -> Parser a -> ParseResult a;
Create a stream from a string, then apply a stream to a parsing function and return the parsed result.

#### `impl Parser : Functor`

#### `impl Parser : Monad`

#### map_result: (a -> Result ErrMsg b) -> Parser a -> Parser b;

Maps the parser result of the specified parser with the specified function which may report an error.

#### debug: [a: ToString] String -> Parser a -> Parser a;
Outputs diagnostic information for parser debugging.

#### filter: (a -> Bool) -> Parser a -> Parser a;

Checks whether the parsed result of the specified Parser satisfies the specified conditions.
Raises a `_NotMatch` error if the specified condition is not met.

#### or_else: Parser a -> Parser a -> Parser a;

If the first Parser raises a `_NotMatch` error, tries the second Parser.

#### or_error: String -> Parser a -> Parser a;

If the Parser reports any error (including `_NotMatch`), raises the specified string as an error.

#### error_parser: String -> Parser a;

Raises the specified string as an error.

#### not_match: Parser a;

Raises a `_NotMatch` error.

#### repeat: Parser a -> Parser (Array a);

Repeats matches as many as possible. The parse result is an array of successful matches.  Never raises an error.

#### zero_or_more: Parser a -> Parser (Array a);

Synonym for `repeat`.

#### one_or_more: Parser a -> Parser (Array a);

Same as `zero_or_more`, but raises a `_NotMatch` error if the array length is zero.

#### match_end_of_stream: Parser ();

Matches zero-length string at the end of stream.

#### match_any_char: Parser Char;

Matches any single character.
The parsed result is a single matched character.
If the match fails (eg. the end of stream), a `_NotMatch` error is raised.

#### match_char: Char -> Parser ();

Matches a single character specified by the argument.
The parsed result is nothing.
If the match fails, a `_NotMatch` error is raised.

#### match_one_of_char: String -> Parser String;

Matches a character which is included in the specified string.
The parsed result is a string consisting of the single matched character.
If the match fails, a `_NotMatch` error is raised.

#### match_str: String -> Parser ();

Matches a string specified by the argument.
The parsed result is nothing.
If the match fails, a `_NotMatch` error is raised.

#### match_empty_str : Parser String;

Matches a zero-length string.

#### match_char_class = (Char -> Bool) -> Parser Char;

Matches a character satisfying the specified condition.

#### match_str_class: (Char -> Bool) -> Parser String;

Matches a zero-or-more-length string. Each character should satisfy the specified condition.

## string_ex.fix

#### `impl (): ToString`

#### `impl [a : ToString, b : ToString, c : ToString] (a, b, c) : ToString`

#### `impl [a : ToString, b : ToString, c : ToString, d : ToString] (a, b, c, d) : ToString`

#### `impl [a: ToString] Option a: ToString`

#### `impl [k: ToString, v: ToString] HashMap k v : ToString`

#### `impl [a: ToString] Array a: ToString`

#### _unsafe_to_string: Array U8 -> String;

Convert a byte array to a string. Specifically, it calls `String::_unsafe_to_string()` after appending a null character to the end of the byte array.

#### find_byte: U8 -> String -> Option I64;

Searches for the specified byte from the beginning of a string. If found, returns the index of that byte.

#### substring: I64 -> I64 -> String -> String;

Returns a substring extracted from a specified range from a string. If the specified range exceeds the string, it will be truncated to fit within the string.

#### string_less_than: (String, String) -> Bool;

Compares two strings. Returns True if and only if the first string is less than the second string.

#### `impl String: LessThan`

#### utf8_to_utf32: Array U8 -> Array U32 -> Array U32;

Convert UTF8 string to UTF32 string. Please specify the output destination buffer. (Same below)

#### utf32_to_utf8: Array U32 -> Array U8 -> Array U8;

Convert UTF32 string to UTF8 string.

#### utf16_to_utf32: Array U16 -> Array U32 -> Array U32;

Convert UTF16 string to UTF32 string.

#### utf32_to_utf16: Array U32 -> Array U16 -> Array U16;

Convert UTF32 string to UTF16 string.

## unit_test.fix

#### _TEST_VERBOSE: Bool;

If _TEST_VERBOSE is false, only failed testcases will be reported.

### TestCase

TestCase is a type that counts the number of successful and failed tests.

```
type TestCase = Lazy (IOFail (I64, I64));
```

#### empty: TestCase;

A test case where the number of successes and number of failures are both equal to 0.
Can be used as a placeholder at the end of an array of test cases.

#### run_test_driver: Array TestCase -> IO ();

Executes all test cases and prints the results (number of passes and number of failures).
Exit with exitcode=1 if any test failed or any error occured, exitcode=0 otherwise.

#### run_tests: Array (TestCase) -> TestCase;

Executes all test cases and treat the results as one test case.

#### make_test: String -> Lazy (IOFail ()) -> TestCase;

Creates a named test case from a lazy `IOFail ()`.

#### assert_true : String -> Bool -> IOFail ();

Verifies that the boolean value is true. If the boolean value is false, the test will fail with the specified message.

#### assert_equal : [a: Eq, a: ToString] String -> a -> a -> IOFail ();

Verifies that two values are equal. If the values are different, the test will fail with the specified message.

#### assert_not_equal : [a: Eq, a: ToString] String -> a -> a -> IOFail ();

Verifies that two values are not equal. If the values are equal, the test will fail with the specified message.

## tcp.fix

WARNING: This module only supports x86_64-linux-gnu.

WARNING: IPv6 is not supported yet.

### IpAddress
This type represents IPv4 ip address,
eg. 127.0.0.1, 192.168.0.1 etc.

```
type IpAddress = unbox struct {
    addr: Array U8
};
```

#### `impl IpAddress: FromString`

#### `impl IpAddress: ToString`

#### resolve: String -> IOFail IpAddress;

Resolves a hostname such as "127.0.0.1" or "www.example.com".

### Port
This type reprents IPv4 port number, 0-65535.

```
type Port = unbox struct { port: U16 };
```

#### `impl Port: FromString`

#### `impl Port: ToString`

### SocketAddress

This type represents IPv4 ip address and port number.

```
type SocketAddress = unbox struct {
    sockaddr_in: Array U8
};
```

#### make: IpAddress -> Port -> SocketAddress;

Creates a `SocketAddress` from an ip address and a port.

#### resolve: String -> IOFail SocketAddress;

Splits the first argument into a host name and a port number, then resolves the host
name to an ip address, then creates a `SocketAddress` from the ip address and
the port number.

The first argument is `{host}:{port}`, where `{host}` is an IP Address (eg. `192.168.0.1`),
or a FQDN host name (eg. `www.example.com`), and `{port}` is a port number (eg. `8080`).
If the port number is omitted, the default port number is 80.

#### `impl SocketAddress: ToString`

### Socket

This type represents an IPv4 socket.
It consists of a socket file descriptor.
The socket file descripter is closed automatically when Socket is deallocated.

```
type Socket = unbox struct {
    data: Destructor I32
};
```

#### `impl Socket: ToString`

#### make_tcp_socket: () -> IOFail Socket;

Creates new tcp socket.
The socket will be automatically closed when `Socket` is deallocated.

#### bind: SocketAddress -> Socket -> IOFail ();

Assigns an IPv4 ip address and a port number to the socket.

#### listen: I64 -> Socket -> IOFail ();

Listens the socket for incoming connection requests.
The first argument (backlog) is the maximum length to which the queue of pending connections for sockfd may grow.

#### accept: Socket -> IOFail (Socket, SocketAddress);

Waits for an incoming connection request. If an incoming connection arrives, accept it, and returns a socket of accepted connection and the remote socket address.

#### connect: SocketAddress -> Socket -> IOFail ();

Connects to the specified address.

#### send: Array U8 -> Socket -> IOFail I64;

Transmits a message to another socket.
May be used only when the socket is in a connected state.
Returns the number of bytes sent.

#### recv: I64 -> Socket -> IOFail (Array U8);

Receives messages from a socket.
The first argument is the maximum number of bytes to receive.
If no message are available at the socket, `recv()` waits for a message to arrive.
Returns the number of bytes received.
When the socket has been shutdown, the return value will be 0.

### BufferedSocket

This type is a structure that wraps a `Socket` and maintains a write buffer, a read buffer and an EOF flag.

```
type BufferedSocket = unbox struct {
    socket: Socket,
    write_buf: Array U8,
    read_buf: Array U8,
    eof: Bool
};
```

#### make: Socket -> BufferedSocket;

Makes a `BufferedSocket` from a `Socket`.

#### write_str: String -> BufferedSocket -> IOFail BufferedSocket;

Writes a string to the write buffer. The contents of the write buffer is not sent until the size of the write buffer is equal to or greater than `_BUFSIZE`, or `flush()` is called.

#### flush: BufferedSocket -> IOFail BufferedSocket;

Sends the contents of the writer buffer to the socket and cleans the write buffer.

#### read_line: BufferedSocket -> IOFail (String, BufferedSocket);

Reads out a line (ie. a string that ends with a newline) from the read buffer. When the read buffer does not contain a newline, it will read some bytes upto _BUFSIZE from the socket, and search for a newline again.
When the connection is closed, the return value may or may not contain a newline. The next call of `read_line()` returns an empty string, which represents that the connection is closed.

### connect_to_tcp_server: String  -> IOFail Socket;

Connects to a remote TCP server as a client.
The first argument is `{host}:{port}`, where `{host}` is an IP Address (eg. `192.168.0.1`), or a FQDN host name (eg. `www.example.com`), and `{port}` is a port number (eg. `8080`).
If the port number is omitted, the default port number is 80.

### listen_tcp_server: String -> I64 -> IOFail Socket;

Listens at the specified address as a server.

The first argument is `{host}:{port}`, where `{host}` is an IP Address (typically, `127.0.0.1`), or a FQDN host name (typically, `localhost`), and `{port}` is a port number (eg. `8080`).
If the port number is omitted, the default port number is 80.

The second argument (`backlog`) is the maximum length to which the queue of pending connections for the socket may grow.


## clap.fix

Command line argument parser.  (Inspired by `clap` crate of Rust)

### ArgAction

The action taken when the argument is parsed.

```
type ArgAction = unbox union {
    set: (),        // Sets next input to the single argument value.
    append: (),     // Appends next input to the array of argument values.
    set_true: (),   // Sets "true" as the single argument value.
    set_false: (),  // Sets "false" as the single argument value.
    help: (),       // Displays help for the command.
    version: ()     // Displays the version of the command.
};
```

### Arg

A structure that defines arguments.
Arguments can be either optional or positional arguments.
If either `short` or `long` is set, it becomes an optional argument.
Otherwise, it is a positional argument.

```
type Arg = unbox struct {
    id: String,             // A unique ID that identifies the argument.
    short: U8,              // A one-hypen option, eg. `-n`
    long: String,           // A two-hypen option, eg. `--count`
    required: Bool,         // Whether the argument is required or not.
    takes_value: Bool,      // Whether the argument takes some value.
    multiple_values: Bool,  // Whether the argument value(s) is singule or multiple.
    default_value: Option String,   // A default value of the argument.
    value_name: String,     // The name of the argument value which is displayed in help message.
    help: String,           // The help message of the argument.
    action: ArgAction       // The action taken when the argument is parsed.
};

```
#### new: String -> Arg;

Creates new argument.

#### short: U8 -> Arg -> Arg;

Sets `@short`.

#### long: String -> Arg -> Arg;

Sets `@long`.

#### required: Arg -> Arg;

Sets `@required` to true.

#### takes_value: Arg -> Arg;

Sets `@takes_value` to true, and `@action` to `set()`.

#### takes_multiple_values: Arg -> Arg;

Sets `@takes_value` to true, `@multiple_values` to true, and `@action` to `append()`.

#### default_value: String -> Arg -> Arg;

Sets `@default_value`.

#### value_name: String -> Arg -> Arg;

Sets `@value_name`.

#### help: String -> Arg -> Arg;

Sets `@help`.

### Command

A structure representing a command (ie. application).

```
type Command = unbox struct {
    name: String,           // The name of the command.
    bin_name: String,       // The name of the executable binary of the command.
    display_name: String,   // The display name of the command.
    version: String,        // The version of the command.
    author: String,         // Author of the command.
    about: String,          // Description about the command.
    args: Array Arg,        // Argument definitions of the command.
    help_template: HelpTemplate,    // A help template of the command.
    version_template: HelpTemplate  // A version template of the command.
};
```

#### new: String -> Command;

Creates a command structure by specifying the command name.

#### name: String -> Command -> Command;

Sets the name of the command.

#### bin_name: String -> Command -> Command;

Sets the name of the executable binary of the command.

#### display_name: String -> Command -> Command;

Sets the display name of the command.

#### version: String -> Command -> Command;

Sets the version of the command.

#### author: String -> Command -> Command;

Sets the author of the command.

#### about: String -> Command -> Command;

Sets the description about the command.

#### arg: Arg -> Command -> Command;

Add an argument definition to the command.

#### render_help: Command -> String;

Generates a help string based on the help template.

#### render_version: Command -> String;

Generates a version string based on the version template.

#### get_matches: Command -> IOFail ArgMatches;

Parse command line arguments based on `IO::get_args`.
If `--help` or `--version` is specified, the help string or version string will be returned as `throw`.

#### get_matches_from: Array String -> Command -> Result ErrMsg ArgMatches;

Parses command line arguments based on the specified input array.
If `--help` or `--version` is specified, the help string or version string will be returned as the error message.

### ArgMatches

A structure representing the result of parsing command line arguments.

```
type ArgMatches = unbox struct {
    map: HashMap String (Array String)
};
```

#### empty: ArgMatches;

An empty `ArgMatches` structure.

#### get_many: String -> ArgMatches -> Option (Array String);

Gets the array of argument values with the specified ID.

#### get_one: String -> ArgMatches -> Option String;

Gets the value of the argument with the specified ID.

