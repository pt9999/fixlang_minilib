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

