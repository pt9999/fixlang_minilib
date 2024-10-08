# Module Minilib.Crypto.SHA1 (sha1.fix)

SHA-1 secure hash function.

Implemented from specification of FIPS PUB 180-4:
https://csrc.nist.gov/files/pubs/fips/180-4/final/docs/fips180-4.pdf

NOTE: FIPS 180-4 (2012) is superseded by FIPS 180-4 (2015), with the only change being
made in the Applicability Clause. There are no changes to the technical specifications.
FIPS 180-4 (2015):
http://dx.doi.org/10.6028/NIST.FIPS.180-4


### `digest: Array U8 -> Array U8;`

`SHA1::digest(bytes)` computes SHA-1 secure hash function of `bytes`.

### `type SHA1`

SHA-1 hasher.
Usually it is sufficient to simply call `SHA1:digest(bytes)` without using this structure.

```
type SHA1 = unbox struct {
    hash: Array U32,
    msglen: U64,
    msgbuf: Array U8
};
```
### `empty: SHA1;`

An empty SHA-1 hasher.

### `update: Array U8 -> SHA1 -> SHA1;`

`sha1.update(bytes)` processes `bytes`, and updates its internal state.

### `finalize: SHA1 -> Array U8;`

`sha1.finalize` retrieves a final SHA-1 hash value.

