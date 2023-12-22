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

