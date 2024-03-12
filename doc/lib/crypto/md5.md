# md5.fix

## module Minilib.Crypto.MD5

MD5 secure hash function.

Implemented from specification of RFC 1321:
https://www.rfc-editor.org/rfc/rfc1321.txt


#### digest: Array U8 -> Array U8;

`MD5::digest(bytes)` computes MD5 secure hash function of `bytes`.

### type MD5

MD5 hasher.
Usually it is sufficient to simply call `MD5:digest(bytes)` without using this structure.

```
type MD5 = unbox struct {
    hash: Array U32,
    msglen: U64,
    msgbuf: Array U8
};
```
#### empty: MD5;

An empty MD5 hasher.

#### update: Array U8 -> MD5 -> MD5;

`md5.update(bytes)` processes `bytes`, and updates its internal state.

#### finalize: MD5 -> Array U8;

`md5.finalize` retrieves a final MD5 hash value.

