# `module Minilib.Net.Tcp`

IPv4 TCP Socket operations.

Features:
- IP address, port number
- Resolves IP address from hostname
- IPv4 Socket address
- IPv4 TCP Socket

Tested platform: x86_64-linux-gnu, aarch64-linux-gnu
WARNING: IPv6 is not supported yet.

# Types and aliases

## `namespace Minilib.Net.Tcp`

### `type BufferedSocket = unbox struct { ...fields... }`

This type is a structure that wraps a `Socket` and maintains a write buffer, a read buffer and an EOF flag.

#### field `socket : Minilib.Net.Tcp::Socket`

#### field `write_buf : Std::Array Std::U8`

#### field `read_buf : Std::Array Std::U8`

#### field `eof : Std::Bool`

### `type HostEnt = unbox struct { ...fields... }`

#### field `data : Std::Array Std::U8`

#### field `buf : Std::Array Std::U8`

### `type IpAddress = unbox struct { ...fields... }`

This type represents IPv4 ip address,
eg. 127.0.0.1, 192.168.0.1 etc.

#### field `addr : Std::Array Std::U8`

### `type Port = unbox struct { ...fields... }`

This type reprents IPv4 port number, 0-65535.

#### field `port : Std::U16`

### `type Socket = unbox struct { ...fields... }`

This type represents an IPv4 socket.
It consists of a socket file descriptor.
The socket file descripter is closed automatically when Socket is deallocated.

#### field `data : Std::FFI::Destructor Std::I32`

## `namespace Minilib.Net.Tcp::SocketAddress`

### `type SocketAddress = unbox struct { ...fields... }`

This type represents IPv4 ip address and port number.

#### field `sockaddr_in : Std::Array Std::U8`

# Traits and aliases

# Trait implementations

### `impl Minilib.Net.Tcp::IpAddress : Std::FromString`

### `impl Minilib.Net.Tcp::IpAddress : Std::ToString`

### `impl Minilib.Net.Tcp::Port : Std::FromString`

### `impl Minilib.Net.Tcp::Port : Std::ToString`

### `impl Minilib.Net.Tcp::Socket : Std::ToString`

### `impl Minilib.Net.Tcp::SocketAddress::SocketAddress : Std::ToString`

# Values

## `namespace Minilib.Net.Tcp`

### `_perror : Std::String -> Std::IO ()`

### `connect_to_tcp_server : Std::String -> Std::IO::IOFail Minilib.Net.Tcp::Socket`

Connects to a remote TCP server as a client.
The first argument is `{host}:{port}`, where `{host}` is an IP Address (eg. `192.168.0.1`),
or a FQDN host name (eg. `www.example.com`), and `{port}` is a port number (eg. `8080`).
If the port number is omitted, the default port number is 80.

### `get_sub_ex : Std::I64 -> Std::I64 -> Std::Array a -> Std::Array a`

### `listen_tcp_server : Std::String -> Std::I64 -> Std::IO::IOFail Minilib.Net.Tcp::Socket`

Listens at the specified address as a server.

The first argument is `{host}:{port}`, where `{host}` is an IP Address (typically, `127.0.0.1`),
or a FQDN host name (typically, `localhost`), and `{port}` is a port number (eg. `8080`).
If the port number is omitted, the default port number is 80.

The second argument (`backlog`) is the maximum length to which the queue of pending connections
for the socket may grow.

## `namespace Minilib.Net.Tcp::BufferedSocket`

### `@eof : Minilib.Net.Tcp::BufferedSocket -> Std::Bool`

Retrieves the field `eof` from a value of `BufferedSocket`.

### `@read_buf : Minilib.Net.Tcp::BufferedSocket -> Std::Array Std::U8`

Retrieves the field `read_buf` from a value of `BufferedSocket`.

### `@socket : Minilib.Net.Tcp::BufferedSocket -> Minilib.Net.Tcp::Socket`

Retrieves the field `socket` from a value of `BufferedSocket`.

### `@write_buf : Minilib.Net.Tcp::BufferedSocket -> Std::Array Std::U8`

Retrieves the field `write_buf` from a value of `BufferedSocket`.

### `_BUFSIZE : Std::I64`

### `act_eof : [f : Std::Functor] (Std::Bool -> f Std::Bool) -> Minilib.Net.Tcp::BufferedSocket -> f Minilib.Net.Tcp::BufferedSocket`

Updates a value of `BufferedSocket` by applying a functorial action to field `eof`.

### `act_read_buf : [f : Std::Functor] (Std::Array Std::U8 -> f (Std::Array Std::U8)) -> Minilib.Net.Tcp::BufferedSocket -> f Minilib.Net.Tcp::BufferedSocket`

Updates a value of `BufferedSocket` by applying a functorial action to field `read_buf`.

### `act_socket : [f : Std::Functor] (Minilib.Net.Tcp::Socket -> f Minilib.Net.Tcp::Socket) -> Minilib.Net.Tcp::BufferedSocket -> f Minilib.Net.Tcp::BufferedSocket`

Updates a value of `BufferedSocket` by applying a functorial action to field `socket`.

### `act_write_buf : [f : Std::Functor] (Std::Array Std::U8 -> f (Std::Array Std::U8)) -> Minilib.Net.Tcp::BufferedSocket -> f Minilib.Net.Tcp::BufferedSocket`

Updates a value of `BufferedSocket` by applying a functorial action to field `write_buf`.

### `flush : Minilib.Net.Tcp::BufferedSocket -> Std::IO::IOFail Minilib.Net.Tcp::BufferedSocket`

Sends the contents of the writer buffer to the socket and cleans the write buffer.

### `make : Minilib.Net.Tcp::Socket -> Minilib.Net.Tcp::BufferedSocket`

Makes a `BufferedSocket` from a `Socket`.

### `mod_eof : (Std::Bool -> Std::Bool) -> Minilib.Net.Tcp::BufferedSocket -> Minilib.Net.Tcp::BufferedSocket`

Updates a value of `BufferedSocket` by applying a function to field `eof`.

### `mod_read_buf : (Std::Array Std::U8 -> Std::Array Std::U8) -> Minilib.Net.Tcp::BufferedSocket -> Minilib.Net.Tcp::BufferedSocket`

Updates a value of `BufferedSocket` by applying a function to field `read_buf`.

### `mod_socket : (Minilib.Net.Tcp::Socket -> Minilib.Net.Tcp::Socket) -> Minilib.Net.Tcp::BufferedSocket -> Minilib.Net.Tcp::BufferedSocket`

Updates a value of `BufferedSocket` by applying a function to field `socket`.

### `mod_write_buf : (Std::Array Std::U8 -> Std::Array Std::U8) -> Minilib.Net.Tcp::BufferedSocket -> Minilib.Net.Tcp::BufferedSocket`

Updates a value of `BufferedSocket` by applying a function to field `write_buf`.

### `read_line : Minilib.Net.Tcp::BufferedSocket -> Std::IO::IOFail (Std::String, Minilib.Net.Tcp::BufferedSocket)`

Reads out a line (ie. a string that ends with a newline) from the read buffer.
When the read buffer does not contain a newline, it will read some bytes upto
_BUFSIZE from the socket, and search for a newline again.
When the connection is closed, the return value may or may not contain a newline.
The next call of `read_line()` returns an empty string, which represents that the connection is closed.

### `set_eof : Std::Bool -> Minilib.Net.Tcp::BufferedSocket -> Minilib.Net.Tcp::BufferedSocket`

Updates a value of `BufferedSocket` by setting field `eof` to a specified one.

### `set_read_buf : Std::Array Std::U8 -> Minilib.Net.Tcp::BufferedSocket -> Minilib.Net.Tcp::BufferedSocket`

Updates a value of `BufferedSocket` by setting field `read_buf` to a specified one.

### `set_socket : Minilib.Net.Tcp::Socket -> Minilib.Net.Tcp::BufferedSocket -> Minilib.Net.Tcp::BufferedSocket`

Updates a value of `BufferedSocket` by setting field `socket` to a specified one.

### `set_write_buf : Std::Array Std::U8 -> Minilib.Net.Tcp::BufferedSocket -> Minilib.Net.Tcp::BufferedSocket`

Updates a value of `BufferedSocket` by setting field `write_buf` to a specified one.

### `write_str : Std::String -> Minilib.Net.Tcp::BufferedSocket -> Std::IO::IOFail Minilib.Net.Tcp::BufferedSocket`

Writes a string to the write buffer. The contents of the write buffer is not sent
until the size of the write buffer is equal to or greater than `_BUFSIZE`, or `flush()` is called.

## `namespace Minilib.Net.Tcp::HostEnt`

### `@buf : Minilib.Net.Tcp::HostEnt -> Std::Array Std::U8`

Retrieves the field `buf` from a value of `HostEnt`.

### `@data : Minilib.Net.Tcp::HostEnt -> Std::Array Std::U8`

Retrieves the field `data` from a value of `HostEnt`.

### `_get_I32 : Std::Ptr -> Std::I64 -> Std::I32`

Extract an I32 value, ie. *(u32_t*)(ptr + offset)

### `_get_Ptr : Std::Ptr -> Std::I64 -> Std::Ptr`

Extract an Ptr value, ie. *(void**)(ptr + offset)

### `_gethostbyname_r : Std::String -> Std::IO::IOFail Minilib.Net.Tcp::HostEnt`

### `_hostent_size : Std::I64`

### `act_buf : [f : Std::Functor] (Std::Array Std::U8 -> f (Std::Array Std::U8)) -> Minilib.Net.Tcp::HostEnt -> f Minilib.Net.Tcp::HostEnt`

Updates a value of `HostEnt` by applying a functorial action to field `buf`.

### `act_data : [f : Std::Functor] (Std::Array Std::U8 -> f (Std::Array Std::U8)) -> Minilib.Net.Tcp::HostEnt -> f Minilib.Net.Tcp::HostEnt`

Updates a value of `HostEnt` by applying a functorial action to field `data`.

### `get_h_addr : Std::I64 -> Minilib.Net.Tcp::HostEnt -> Std::IO::IOFail Minilib.Net.Tcp::IpAddress`

get `h_addr_list[index]` field of the hostent.

### `get_h_length : Minilib.Net.Tcp::HostEnt -> Std::IO::IOFail Std::I64`

get `h_length` field of the hostent.

### `mod_buf : (Std::Array Std::U8 -> Std::Array Std::U8) -> Minilib.Net.Tcp::HostEnt -> Minilib.Net.Tcp::HostEnt`

Updates a value of `HostEnt` by applying a function to field `buf`.

### `mod_data : (Std::Array Std::U8 -> Std::Array Std::U8) -> Minilib.Net.Tcp::HostEnt -> Minilib.Net.Tcp::HostEnt`

Updates a value of `HostEnt` by applying a function to field `data`.

### `set_buf : Std::Array Std::U8 -> Minilib.Net.Tcp::HostEnt -> Minilib.Net.Tcp::HostEnt`

Updates a value of `HostEnt` by setting field `buf` to a specified one.

### `set_data : Std::Array Std::U8 -> Minilib.Net.Tcp::HostEnt -> Minilib.Net.Tcp::HostEnt`

Updates a value of `HostEnt` by setting field `data` to a specified one.

## `namespace Minilib.Net.Tcp::IpAddress`

### `@addr : Minilib.Net.Tcp::IpAddress -> Std::Array Std::U8`

Retrieves the field `addr` from a value of `IpAddress`.

### `act_addr : [f : Std::Functor] (Std::Array Std::U8 -> f (Std::Array Std::U8)) -> Minilib.Net.Tcp::IpAddress -> f Minilib.Net.Tcp::IpAddress`

Updates a value of `IpAddress` by applying a functorial action to field `addr`.

### `from_array : Std::Array Std::U8 -> Minilib.Net.Tcp::IpAddress`

Converts a byte array to an `IpAddress`. The length of the byte array must be 4.

### `mod_addr : (Std::Array Std::U8 -> Std::Array Std::U8) -> Minilib.Net.Tcp::IpAddress -> Minilib.Net.Tcp::IpAddress`

Updates a value of `IpAddress` by applying a function to field `addr`.

### `resolve : Std::String -> Std::IO::IOFail Minilib.Net.Tcp::IpAddress`

Resolve a hostname such as "127.0.0.1" or "www.example.com".

### `set_addr : Std::Array Std::U8 -> Minilib.Net.Tcp::IpAddress -> Minilib.Net.Tcp::IpAddress`

Updates a value of `IpAddress` by setting field `addr` to a specified one.

## `namespace Minilib.Net.Tcp::Port`

### `@port : Minilib.Net.Tcp::Port -> Std::U16`

Retrieves the field `port` from a value of `Port`.

### `act_port : [f : Std::Functor] (Std::U16 -> f Std::U16) -> Minilib.Net.Tcp::Port -> f Minilib.Net.Tcp::Port`

Updates a value of `Port` by applying a functorial action to field `port`.

### `mod_port : (Std::U16 -> Std::U16) -> Minilib.Net.Tcp::Port -> Minilib.Net.Tcp::Port`

Updates a value of `Port` by applying a function to field `port`.

### `set_port : Std::U16 -> Minilib.Net.Tcp::Port -> Minilib.Net.Tcp::Port`

Updates a value of `Port` by setting field `port` to a specified one.

## `namespace Minilib.Net.Tcp::Socket`

### `@data : Minilib.Net.Tcp::Socket -> Std::FFI::Destructor Std::I32`

Retrieves the field `data` from a value of `Socket`.

### `_AF_INET : Std::I32`

from /usr/include/x86_64-linux-gnu/bits/

### `_SOCK_STREAM : Std::I32`

### `_unsafe_from_fd : Std::I32 -> Minilib.Net.Tcp::Socket`

Creates `Socket` from a file descriptor of a socket.
The socket will be automatically closed when `Socket` is deallocated.

### `accept : Minilib.Net.Tcp::Socket -> Std::IO::IOFail (Minilib.Net.Tcp::Socket, Minilib.Net.Tcp::SocketAddress::SocketAddress)`

Waits for an incoming connection request. If an incoming connection arrives, accept it,
and returns a socket of accepted connection and the remote socket address.

### `accept_fd : Minilib.Net.Tcp::Socket -> Std::IO::IOFail (Std::I32, Minilib.Net.Tcp::SocketAddress::SocketAddress)`

Same as `accept()`, except that it returns the accepted socket's file descriptor instead of `Socket`.

### `act_data : [f : Std::Functor] (Std::FFI::Destructor Std::I32 -> f (Std::FFI::Destructor Std::I32)) -> Minilib.Net.Tcp::Socket -> f Minilib.Net.Tcp::Socket`

Updates a value of `Socket` by applying a functorial action to field `data`.

### `bind : Minilib.Net.Tcp::SocketAddress::SocketAddress -> Minilib.Net.Tcp::Socket -> Std::IO::IOFail ()`

Assigns an IPv4 ip address and a port number to the socket.

### `connect : Minilib.Net.Tcp::SocketAddress::SocketAddress -> Minilib.Net.Tcp::Socket -> Std::IO::IOFail ()`

Connects to the specified address.

### `listen : Std::I64 -> Minilib.Net.Tcp::Socket -> Std::IO::IOFail ()`

Listens the socket for incoming connection requests.
The first argument (backlog) is the maximum length to which the queue of pending connections for sockfd may grow.

### `make_tcp_socket : () -> Std::IO::IOFail Minilib.Net.Tcp::Socket`

Creates new tcp socket.
The socket will be automatically closed when `Socket` is deallocated.

### `mod_data : (Std::FFI::Destructor Std::I32 -> Std::FFI::Destructor Std::I32) -> Minilib.Net.Tcp::Socket -> Minilib.Net.Tcp::Socket`

Updates a value of `Socket` by applying a function to field `data`.

### `recv : Std::I64 -> Minilib.Net.Tcp::Socket -> Std::IO::IOFail (Std::Array Std::U8)`

Receives messages from a socket.
The first argument is the maximum number of bytes to receive.
If no message are available at the socket, `recv()` waits for a message to arrive.
Returns the number of bytes received.
When the socket has been shutdown, the return value will be 0.

### `send : Std::Array Std::U8 -> Minilib.Net.Tcp::Socket -> Std::IO::IOFail Std::I64`

Transmits a message to another socket.
May be used only when the socket is in a connected state.
Returns the number of bytes sent.

### `set_data : Std::FFI::Destructor Std::I32 -> Minilib.Net.Tcp::Socket -> Minilib.Net.Tcp::Socket`

Updates a value of `Socket` by setting field `data` to a specified one.

## `namespace Minilib.Net.Tcp::SocketAddress`

### `_sockaddr_in_size : Std::I64`

### `_unsafe_from_array : Std::Array Std::U8 -> Minilib.Net.Tcp::SocketAddress::SocketAddress`

### `get_ipaddress : Minilib.Net.Tcp::SocketAddress::SocketAddress -> Minilib.Net.Tcp::IpAddress`

Extracts an ip address from the socket address.

### `get_port : Minilib.Net.Tcp::SocketAddress::SocketAddress -> Std::I64`

Extracts a port number from the socket address.

### `make : Minilib.Net.Tcp::IpAddress -> Minilib.Net.Tcp::Port -> Minilib.Net.Tcp::SocketAddress::SocketAddress`

Creates a `SocketAddress` from an ip address and a port.

### `resolve : Std::String -> Std::IO::IOFail Minilib.Net.Tcp::SocketAddress::SocketAddress`

Splits the first argument into a host name and a port number, then resolves the host
name to an ip address, then creates a `SocketAddress` from the ip address and
the port number.

The first argument is `{host}:{port}`, where `{host}` is an IP Address (eg. `192.168.0.1`),
or a FQDN host name (eg. `www.example.com`), and `{port}` is a port number (eg. `8080`).
If the port number is omitted, the default port number is 80.

## `namespace Minilib.Net.Tcp::SocketAddress::SocketAddress`

### `@sockaddr_in : Minilib.Net.Tcp::SocketAddress::SocketAddress -> Std::Array Std::U8`

Retrieves the field `sockaddr_in` from a value of `SocketAddress`.

### `act_sockaddr_in : [f : Std::Functor] (Std::Array Std::U8 -> f (Std::Array Std::U8)) -> Minilib.Net.Tcp::SocketAddress::SocketAddress -> f Minilib.Net.Tcp::SocketAddress::SocketAddress`

Updates a value of `SocketAddress` by applying a functorial action to field `sockaddr_in`.

### `mod_sockaddr_in : (Std::Array Std::U8 -> Std::Array Std::U8) -> Minilib.Net.Tcp::SocketAddress::SocketAddress -> Minilib.Net.Tcp::SocketAddress::SocketAddress`

Updates a value of `SocketAddress` by applying a function to field `sockaddr_in`.

### `set_sockaddr_in : Std::Array Std::U8 -> Minilib.Net.Tcp::SocketAddress::SocketAddress -> Minilib.Net.Tcp::SocketAddress::SocketAddress`

Updates a value of `SocketAddress` by setting field `sockaddr_in` to a specified one.