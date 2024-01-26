# sha1.fix

## module Minilib.Crypto.SHA1

SHA-1 secure hash function.

Implemented from specification of FIPS PUB 180-4:
https://csrc.nist.gov/files/pubs/fips/180-4/final/docs/fips180-4.pdf


#### digest: Array U8 -> Array U8;

`SHA1::digest(bytes)` computes SHA-1 secure hash function of `bytes`.

### type SHA1

SHA-1 hasher.
Usually it is sufficient to simply call `SHA1:digest(bytes)` without using this structure.

```
type SHA1 = unbox struct {
    hash: Array U32,
    msglen: U64,
    msgbuf: Array U8
};
```
#### empty: SHA1;

An empty SHA-1 hasher.

#### update: Array U8 -> SHA1 -> SHA1;

`sha1.update(bytes)` processes `bytes`, and updates its internal state.

#### finalize: SHA1 -> Array U8;

`sha1.finalize` retrieves a final SHA-1 hash value.

