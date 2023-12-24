# url.fix

## module URL

URL and URI parsing

### type URL

A structure that represents an URL.

```
type URL = unbox struct {
    url: String,        // Original URL (eg. "http://127.0.0.1:8080/blogs/search?q=hello%25world&limit=30)
    scheme: String,     // Scheme       (eg. "http")
    host: String,       // Host         (eg. "127.0.0.1")
    port: String,       // Port         (eg. "8080", default: "80")
    path: String        // Path and query (eg. "/blogs/search?q=hello%25world&limit=30")
};
```
#### `impl URL: Eq`

Checks whether two URLs are equal.

#### `impl URL: ToString`

Converts an URL to a string.

### namespace URL

A namespace for parsing URLs.

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

A namespace for encoding/decoding URIs.

#### encodeURI: String -> String;

Same as JavaScript `encodeURI()`.
For details, see [encodeURI()](https://developer.mozilla.org/ja/docs/Web/JavaScript/Reference/Global_Objects/encodeURI)
of MDN web docs.

#### decodeURI: String -> Result ErrMsg String;

Same as JavaScript `decodeURI()`.
For details, see [decodeURI()](https://developer.mozilla.org/ja/docs/Web/JavaScript/Reference/Global_Objects/decodeURI)
of MDN web docs.

#### encodeURIComponent: String -> String;

Same as JavaScript `encodeURIComponent()`.
For details, see [encodeURIComponent()](https://developer.mozilla.org/ja/docs/Web/JavaScript/Reference/Global_Objects/encodeURIComponent)
of MDN web docs.

#### decodeURIComponent: String -> Result ErrMsg String;

Same as JavaScript `decodeURIComponent()`.
For details, see [decodeURIComponent()](https://developer.mozilla.org/ja/docs/Web/JavaScript/Reference/Global_Objects/decodeURIComponent)
of MDN web docs.

