# minilib Reference for 'net/' module

NOTE: This file is under construction.

## Table of contents

- [Table of contents](#table-of-contents)
- [tcp.fix](#tcpfix)
- [io_ex.fix](#ioexfix)
- [url.fix](#urlfix)
- [request.fix](#requestfix)
- [router.fix](#routerfix)
- [http_server.fix](#httpserverfix)

## tcp.fix

WARNING: This module only supports x86_64-linux-gnu and aarch64-linux-gnu.

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

#### from_array: Array U8 -> IpAddress;

Creates `IPAddress` from an array. The array size must be 4.

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

#### get_ipaddress: SocketAddress -> IpAddress;

Extracts an ip address from the socket address.

#### get_port: SocketAddress -> I64;

Extracts a port number from the socket address.

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

#### _unsafe_from_fd: I32 -> Socket;

Creates `Socket` from a file descriptor of a socket.
The socket will be automatically closed when `Socket` is deallocated.

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

#### accept_fd: Socket -> IOFail (I32, SocketAddress);

Same as `accept()`, except that it returns the accepted socket's file descriptor instead of `Socket`.

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


## io_ex.fix

#### creat: String -> U32 -> IOFail I32;

#### unlink: String -> IOFail ();

#### fflush : IOHandle -> IOFail ();

#### fdopen: I32 -> String -> IOFail IOHandle;

#### open_pipe: IOFail (IOHandle, IOHandle);

#### usleep: U32 -> IOFail ();

## url.fix

### type URL

```
type URL = unbox struct {
    url: String,
    scheme: String,
    host: String,
    port: String,
    path: String
};
```

### namespace URL

#### parse: String -> Result ErrMsg URL;

Parses a string as a URL.
Recognized format of a URL is:
[scheme://]host[:port][path]
If the scheme part is omitted, a default value ("http") is used as a scheme.
The host and port part should not contain "/".
If the port part is omitted, a default value ("443" if scheme == "https", "80" otherwise)
is used as a port.
The path part should be starts with "/".
If the path part is omitted, a default value ("/") is used as a path.

### namespace URI

#### encodeURI: String -> String;

#### decodeURI: String -> Result ErrMsg String;

#### encodeURIComponent: String -> String;

#### decodeURIComponent: String -> Result ErrMsg String;

## request.fix

### type Header

A type that represents a header. The header is a tuple of field name and field value.
Note that the field name is case-insensitive (RFC9112).

```
type Header = (String, String);
```
### type Headers

A collection of headers.

```
type Headers = unbox struct {
    iter: Iterator Header
};
```
### namespace Headers

#### empty: Headers;

An empty collection of headers.

#### set: String -> String -> Headers -> Headers;

`headers.set(name, value)` sets the value of the field named `name` to `value`.
The field name is converted to lowercase.
If a field with the same name already exists, it will be removed first.

#### append: String -> String -> Headers -> Headers;

`headers.append(name, value)` appends a new field `(name, value)` to the current headers collection.
The field name is converted to lowercase.
It will not be removed even if a field with the same name already exists,

#### find: String -> Headers -> Option String;

`headers.find(name)` finds the field with name `name`.
The field name is converted to lowercase.

#### to_iter: Headers -> Iterator (String, String);

`headers.to_iter` returns an iterator of headers.

### type Request

A type that represents an HTTP request.

```
type Request = unbox struct {
    connection: IOHandle,       // An IOHandle of the socket
    remote_addr: String,        // The remote address, eg. "192.168.0.1:65432"
    method: String,             // eg. "GET"
    request_target: String,     // eg. "/blogs/search?q=hello%25world&limit=30"
    http_version: String,       // eg. "HTTP/1.1"
    headers: Headers,           // A collection of headers of the request
    path: String,               // eg. "/blogs/search"
    query: Array (String, String), // eg. [("q", "hello%world"), ("limit", "30")]
    body: Array U8              // The body of the request
};
```
### namespace Request

#### parse: IOHandle -> String -> IOFail Request;

`Request::parse(connection, remote_addr)` reads the HTTP request from `connection` and parse it.

### type Response

A type that represents an HTTP response.

```
type Response = unbox struct {
    request: Request,
    connection: IOHandle,
    http_version: String,
    status: I64,
    reason: String,
    headers: Headers,
    headersSent: Bool
};
```
### namespace Response

#### make: Request -> Response;

`Response::make(request)` creates a basic HTTP response for an HTTP request.

#### status: I64 -> Response -> Response;

`response.status(code)` sets the HTTP status code. (eg. 404)
It will also set the reason phrase (eg. "Not Found") of the status.

#### content_type: String -> Response -> Response;

`response.content_type(type)` sets the `Content-Type` header.
You can specify an alias for the content type (e.g. "text", "json").
See the definition of `_CONTENT_TYPE_ALIASES` for a list of available aliases.

#### header: String -> String -> Response -> Response;

`response.header(name, value)` sets a response header.

#### write_str: String -> Response -> IOFail Response;

`response.write_str(str)` sends headers with a status line if they have not already been sent.
Then it sends the specified string.

#### end: Response -> IOFail Response;

Sends headers with a status line if they have not already been sent.
Then flush the connection.

## http_server.fix

### type RequestHandler

```
type RequestHandler = Request -> Response -> IOFail Response;
```
### type Worker

```
type Worker = unbox struct {
    app: App
};
```
### namespace Worker

#### make: App -> Worker;

#### handle: IOHandle -> String -> Worker -> IOFail ();

#### not_found_handler: Request -> Response -> IOFail Response;

### type App

```
type App = unbox struct {
    router: Router RequestHandler,
    backlog: I64
};
```
### namespace App

#### empty: App;

#### insert_handler: String -> String -> RequestHandler -> App -> App;

#### on: String -> String -> RequestHandler -> App -> App;

#### listen: String -> App -> IOFail ();

