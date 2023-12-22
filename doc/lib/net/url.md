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

