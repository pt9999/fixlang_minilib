# Module Minilib.Net.HttpServer (http_server.fix)

Simple HTTP server.
The interface is similar to `express` of Node.js.
- Insert a request handler on specific path
- Listen for incoming requests

### `type RequestHandler`

The request handler interprets an HTTP request and outputs an HTTP response to `response.@connection`.
It returns an HTTP response.

```
type RequestHandler = Request -> Response -> IOFail Response;
```
### `type Worker`

The worker is responsible for processing a request. Specifically,
it reads one request from the socket, processes it, and writes a response to the socket.

```
type Worker = unbox struct {
    app: App
};
```
## `namespace Worker`

### `make: App -> Worker;`

Creates a worker for the application.

### `handle: IOHandle -> String -> Worker -> IO ();`

`worker.handle(connection, remote_addr)` receives an HTTP request from the socket connection,
then finds the request handler for the request, and call that handler.

### `type App`

This type represents an application.

```
type App = unbox struct {
    router: Router RequestHandler,      // An HTTP request router
    backlog: I64                        // Number of backlogs used for `listen()`
};
```
## `namespace App`

### `make: () -> App;`

`App::make()` creates an empty application.

### `insert_handler: String -> String -> RequestHandler -> App -> App;`

`app.insert_handler(method, path, handler)` inserts a handler
at `path` for `method`.

### `on: String -> String -> RequestHandler -> App -> App;`

Alias of `insert_handler`.

### `listen: String -> App -> IOFail App;`

`app.listen(server_host_port)` listens for incoming requests,
and respond to accepted connections.

This function sets the signal handler for SIGPIPE to SIG_IGN to avoid
abnormal program termination when writing to a closed socket.

