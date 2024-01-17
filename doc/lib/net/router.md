# router.fix

## module Router

HTTP request router.
- Mounts a request handler to specific path and method
- Finds a request handler from path and method of the HTTP request

### type RouterEntry

`RouterEntry h` represents a map from method name to a request handler.
`h` is a type of request handler.

```
type RouterEntry h = box struct {
    map: HashMap String h
};
```
### namespace RouterEntry

#### empty: RouterEntry h;

An empty entry.

#### is_empty: RouterEntry h -> Bool;

Returns true iff it is an empty entry.

#### update: String -> h -> RouterEntry h -> RouterEntry h;

`router_entry.update(method, handler)` sets the handler of the method `method` to `handler`.

#### find: String -> RouterEntry h -> Option h;

`router_entry.find(method)` finds the handler of the method.

#### show: [h: ToString] RouterEntry h -> IO ();

### type RouterNode

`RouterNode h` represents a resource of URI.
`h` is a type of request handler.

```
type RouterNode h = box struct {
    directory: HashMap String (RouterNode h),
    entry: RouterEntry h
};
```
### namespace RouterNode

#### empty: RouterNode h;

An empty router node.

#### create: Iterator String -> (RouterEntry h -> RouterEntry h) -> RouterNode h;

`RouterNode::create(path, entry_updater)` creates a node.

#### update: Iterator String -> (RouterEntry h -> RouterEntry h) -> RouterNode h -> RouterNode h;

`current_node.update(path, entry_updater)` updates the entry of a target node that is reached via `path` from `current_node`.
`path` is a path from `current_node` to the target node. If `path` is an empty iterator, `current_node` becomes the target node.
`entry_updater` is a function that updates the `RouterEntry` of the target node.

#### find: Iterator String -> RouterNode h -> Option (RouterEntry h);

Finds the entry in the node following the path from the current node.

#### show: [h: ToString] String -> RouterNode h -> IO ();

### type Router

Router is a mapping from a method name and a path to a request handler.
`h` is a type of request handler.

```
type Router h = box struct {
    root: RouterNode h
};
```
### namespace Router

#### empty: Router h;

An empty router.

#### insert: String -> String -> h -> Router h -> Router h;

`router.insert(method, path, handler)` tells that `method` and  path
should be mapped to this handler.

#### find: String -> String -> Router h -> Option h;

`router.find(method, path)` finds the handler that matches `method` and `path`.

