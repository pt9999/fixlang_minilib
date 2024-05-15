# aes.fix

## module Minilib.Crypto.AES

Advanced Encryption Standard (AES)

Implemented from specification of FIPS 197:
https://nvlpubs.nist.gov/nistpubs/FIPS/NIST.FIPS.197-upd1.pdf
https://doi.org/10.6028/NIST.FIPS.197-upd1


### type AES

```
type AES = unbox struct {
    key_length: I64,    // 128, 192, 256
    key: Array U8,      // key (128 bits / 192 bits / 256 bits)
    w: Array U32,       // expanded key
    c01: U64,           // state column 0,1  row 0123, 0123
    c23: U64            // state column 2,3  row 0123, 0123
};
```
### namespace AES

#### make: Array U8 -> AES;

`AES::make(key)` creates an AES cipher.
`key` must be a byte array of 128 bits (= 16 bytes), 192 bits (= 24 bytes), or
256 bits (= 32 bytes).

#### encrypt_block: Array U8 -> AES -> Array U8;

`aes.encrypt_block(plaintext)` encrypts a block of plaintext to a block of ciphertext.
`plaintext` must be a byte array of 128 bits (= 16 bytes).

#### decrypt_block: Array U8 -> AES -> Array U8;

`aes.decrypt_block(ciphertext)` decrypts a block of ciphertext to a block of plaintext.
`ciphertext` must be a byte array of 128 bits (= 16 bytes).

### namespace GF8

Arithmetic in GF(2^8)
NOTE: It might be better to rename GF8 to GF256 or GF2_8, but shorter is better.

