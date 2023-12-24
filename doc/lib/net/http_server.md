# http_server.fix

## module HttpServer

### type RequestHandler

The request handler interprets an HTTP request and outputs an HTTP response to `response.@connection`.
It returns an HTTP response with (probably modified) application state.
`s` is the type of any application state.

```
type RequestHandler s = Request s -> Response s -> IOFail (Response s);
```
### type Worker

The worker is responsible for processing a request. Specifically,
it reads one request from the socket, processes it, and writes a response to the socket.
`s` is the type of any application state.

```
type Worker s = unbox struct {
    app: App s
};
```
### namespace Worker

#### make: App s -> Worker s;

Creates a worker for the application.

#### handle: IOHandle -> String -> Worker s -> IO s;

`worker.handle(connection, remote_addr)` receives an HTTP request from the socket connection,
then finds the request handler for the request, and call that handler.

### type App

This type represents an application. `s` is an application state.

```
type App s = unbox struct {
    state: s,                           // An application state
    merge_state: s -> s -> s,           // A function that merges two application state
    router: Router (RequestHandler s),  // An HTTP request router
    backlog: I64                        // Number of backlogs used for `listen()`
};
```
### namespace App

#### make: () -> App ();

`App::make()` creates an empty application with no state.

#### make_with_state: s -> (s -> s -> s) -> App s;

`App::make_with_state(state, merge_state)` creates
an empty application with a state and a function to merge two states.

#### insert_handler: String -> String -> RequestHandler s -> App s -> App s;

`app.insert_handler(method, path, handler)` inserts a handler
at `path` for `method`.

#### on: String -> String -> RequestHandler s -> App s -> App s;

Alias of `insert_handler`.

#### listen: String -> App s -> IOFail (App s);

`app.listen(server_host_port)` listens for incoming requests,
and respond to accepted connections.

