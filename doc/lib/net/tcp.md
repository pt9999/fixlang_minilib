# tcp.fix

## module Tcp

TCP operation, such as:
- IP address, port number
- Resolves IP address from hostname
- IPv4 Socket address
- IPv4 TCP Socket

Tested platform: x86_64-linux-gnu, aarch64-linux-gnu
WARNING: IPv6 is not supported yet.


#### get_sub_ex: I64 -> I64 -> Array a -> Array a;

### type IpAddress

This type represents IPv4 ip address,
eg. 127.0.0.1, 192.168.0.1 etc.

```
type IpAddress = unbox struct {
    addr: Array U8
};
```
#### `impl IpAddress: FromString`

#### `impl IpAddress: ToString`

### type HostEnt

```
type HostEnt = unbox struct {
    data: Array U8,
    buf: Array U8
};
```
### namespace HostEnt

#### get_h_length: HostEnt -> IOFail I64;

get `h_length` field of the hostent.

#### get_h_addr: I64 -> HostEnt -> IOFail IpAddress;

get `h_addr_list[index]` field of the hostent.

### namespace IpAddress

#### from_array: Array U8 -> IpAddress;

Converts a byte array to an `IpAddress`. The length of the byte array must be 4.

#### resolve: String -> IOFail IpAddress;

Resolve a hostname such as "127.0.0.1" or "www.example.com".

### type Port

This type reprents IPv4 port number, 0-65535.

```
type Port = unbox struct { port: U16 };
```
#### `impl Port: FromString`

#### `impl Port: ToString`

### namespace SocketAddress

### type SocketAddress

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

#### `impl SocketAddress : ToString`

### type Socket

This type represents an IPv4 socket.
It consists of a socket file descriptor.
The socket file descripter is closed automatically when Socket is deallocated.

```
type Socket = unbox struct {
    data: Destructor I32
};
```
#### `impl Socket: ToString`

### namespace Socket

#### make_tcp_socket: () -> IOFail Socket;

Creates new tcp socket.
The socket will be automatically closed when `Socket` is deallocated.

#### bind: SocketAddress -> Socket -> IOFail ();

Assigns an IPv4 ip address and a port number to the socket.

#### listen: I64 -> Socket -> IOFail ();

Listens the socket for incoming connection requests.
The first argument (backlog) is the maximum length to which the queue of pending connections for sockfd may grow.

#### accept: Socket -> IOFail (Socket, SocketAddress);

Waits for an incoming connection request. If an incoming connection arrives, accept it,
and returns a socket of accepted connection and the remote socket address.

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

### type BufferedSocket

This type is a structure that wraps a `Socket` and maintains a write buffer, a read buffer and an EOF flag.

```
type BufferedSocket = unbox struct {
    socket: Socket,
    write_buf: Array U8,
    read_buf: Array U8,
    eof: Bool
};
```
### namespace BufferedSocket

#### make: Socket -> BufferedSocket;

Makes a `BufferedSocket` from a `Socket`.

#### write_str: String -> BufferedSocket -> IOFail BufferedSocket;

Writes a string to the write buffer. The contents of the write buffer is not sent
until the size of the write buffer is equal to or greater than `_BUFSIZE`, or `flush()` is called.

#### flush: BufferedSocket -> IOFail BufferedSocket;

Sends the contents of the writer buffer to the socket and cleans the write buffer.

#### read_line: BufferedSocket -> IOFail (String, BufferedSocket);

Reads out a line (ie. a string that ends with a newline) from the read buffer.
When the read buffer does not contain a newline, it will read some bytes upto
_BUFSIZE from the socket, and search for a newline again.
When the connection is closed, the return value may or may not contain a newline.
The next call of `read_line()` returns an empty string, which represents that the connection is closed.

#### connect_to_tcp_server: String  -> IOFail Socket;

Connects to a remote TCP server as a client.
The first argument is `{host}:{port}`, where `{host}` is an IP Address (eg. `192.168.0.1`),
or a FQDN host name (eg. `www.example.com`), and `{port}` is a port number (eg. `8080`).
If the port number is omitted, the default port number is 80.

#### listen_tcp_server: String -> I64 -> IOFail Socket;

Listens at the specified address as a server.

The first argument is `{host}:{port}`, where `{host}` is an IP Address (typically, `127.0.0.1`),
or a FQDN host name (typically, `localhost`), and `{port}` is a port number (eg. `8080`).
If the port number is omitted, the default port number is 80.

The second argument (`backlog`) is the maximum length to which the queue of pending connections
for the socket may grow.

