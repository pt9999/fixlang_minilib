# hmac.fix

## module Minilib.Crypto.HMAC

The Keyed-Hash Message Authentication Code (HMAC)

Implemented from specification of FIPS 198-1:
https://nvlpubs.nist.gov/nistpubs/FIPS/NIST.FIPS.198-1.pdf
https://doi.org/10.6028/NIST.FIPS.198-1

### type HMAC

A type that generates a message authentication code.

```
type HMAC = unbox struct {
    h: Array U8 -> Array U8,    // hash function (H)
    input_block_size: I64,      // input block size of hash function (B)
    output_block_size: I64      // output block size of hash function (L)
};
```
### namespace HMAC

#### hmac_md5: HMAC;

An HMAC instance that uses MD5 as a hash function.

#### hmac_sha1: HMAC;

An HMAC instance that uses SHA1 as a hash function.

#### make: (Array U8 -> Array U8) -> I64 -> I64 -> HMAC;

`HMAC::make(h,b,l)` creates an HMAC instance.
`h` is a secure hash function, such as MD5::digest or SHA1::digest.
`b` is the input block size of `h`.
`l` is the output block size of `h`.
`l` must be less than or equal to `b`.

#### digest: Array U8 -> Array U8 -> HMAC -> Array U8;

`hmac.digest(key, text)` creates a message authentication code from `key` and `text`.

