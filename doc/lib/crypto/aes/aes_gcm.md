# aes_gcm.fix

## module Minilib.Crypto.AES.GCM

Galois/Counter Mode (GCM) for AES

Implemented from specification of NIST Special Publication 800-38D:
Recommendation for Block Cipher Modes of Operation: Galois/Counter Mode (GCM) and GMAC
https://doi.org/10.6028/NIST.SP.800-38D

### type Block

A block is a bit string of 128 bits.
We use two U64 as a representation.
When converted to a bit string, it is encoded in big-endian.
If a byte sequence is encoded to a bit string, MSB of the first byte becomes the leftmost bit.

```
type Block = unbox struct {
  hi: U64,
  lo: U64
};
```
#### `impl Block: Eq`

#### `impl Block: ToStringHex`

#### `impl Block: ToString`

#### `impl Block: FromBytes`

#### `impl Block: ToBytes`

### namespace Block

#### make: U64 -> U64 -> Block;

`Block::make(hi, lo)` creates a 128 bit block.

#### get_block_be: I64 -> Array U8 -> Block;

`buf.get_block_be(i)` reads a 128 bit block in big endian at position `i` in array `buf`.

#### set_block_be: I64 -> Block -> Array U8 -> Array U8;

`buf.set_block_be(i, block)` writes a 128 bit block in big endian at position `i` in array `buf`.

### namespace GCM

#### gcm_ae: (Block -> Block) -> Array U8 -> Array U8 -> Array U8 -> I64 -> (Array U8, Array U8);

Performs authenticated encryption.
Input:
- cipher: 128-bit block cipher
- iv: initialization vector, typically 96 bits
- plaintext: a byte sequence which will be encrypted
- auth_data: a byte sequence which will not be encrypted
- len_t: tag length in bits
Output: (c, t)
- c: ciphertext
- t: authentication tag

#### gcm_ad: (Block -> Block) -> Array U8 -> Array U8 -> Array U8 -> Array U8 -> I64 -> Result ErrMsg (Array U8);

Performs authenticated decryption.
Input:
- cipher: 128-bit block cipher
- iv: initialization vector, typically 96 bits
- ciphertext: a byte sequence which will be decrypted
- auth_data: a byte sequence which will not be encrypted
- tag: authentication tag
Output: ok(plaintext) or err(ErrMsg)
- ok(plaintext): decrypted byte sequence
- err(ErrMsg): inauthenticity

### namespace CLMul

Carryless Multiplication
NOTE: the bit order is reversed, ie. bit 0 is MSB, bit (n-1) is LSB

