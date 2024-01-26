# binary.fix

## module Minilib.Encoding.Binary

Binary utility, such as:
- Byte order
- Byte buffer

### type ByteOrder

```
type ByteOrder = unbox union {
    little_endian: (),
    big_endian: ()
};
```
### type ByteBuffer

```
type ByteBuffer = unbox struct {
    array: Array U8,            // internal byte array
    byte_order: ByteOrder       // byte order
};
```
### namespace ByteBuffer

#### make: Array U8 -> ByteOrder -> ByteBuffer;

`ByteBuffer::make(array, byte_order)` creates new byte buffer such that:
- The internal byte array is `array`
- The byte order is `byte_order`

#### empty: I64 -> ByteOrder -> ByteBuffer;

`ByteBuffer::empty(capacity, byte_order)` creates new byte buffer such that:
- The internal byte array is an empty array with capacity `capacity`
- The byte order is `byte_order`

#### fill: I64 -> U8 -> ByteOrder -> ByteBuffer;

`ByteBuffer::fill(size, value, byte_order)` creates new byte buffer such that:
- The internal byte array is initialized by size `size` and filled with `value`
- The byte order is `byte_order`

#### borrow_ptr : (Ptr -> b) -> ByteBuffer -> b;

Calls a function with a pointer to the memory region where elements are stored.

#### get_size: ByteBuffer -> I64;

Gets the size of internal byte array.

#### get_bytes: ByteBuffer -> Array U8;

Gets the internal byte array.

#### get_u8: I64 -> ByteBuffer -> U8;

Gets U8 from the byte buffer at position `i`.

#### get_u16: I64 -> ByteBuffer -> U16;

Gets U16 from the byte buffer at position `i`.

#### get_u32: I64 -> ByteBuffer -> U32;

Gets U32 from the byte buffer at position `i`.

#### get_u64: I64 -> ByteBuffer -> U64;

Gets U64 from the byte buffer at position `i`.

#### set_u8: I64 -> U8 -> ByteBuffer -> ByteBuffer;

Sets U8 into the byte buffer at position `i`.

#### set_u16: I64 -> U16 -> ByteBuffer -> ByteBuffer;

Sets U16 into the byte buffer at position `i`.

#### set_u32: I64 -> U32 -> ByteBuffer -> ByteBuffer;

Sets U32 into the byte buffer at position `i`.

#### set_u64: I64 -> U64 -> ByteBuffer -> ByteBuffer;

Sets U64 into the byte buffer at position `i`.

#### to_u8_array: ByteBuffer -> Array U8;

#### to_u32_array: ByteBuffer -> Array U32;

#### from_u32_array: Array U32 -> ByteOrder -> ByteBuffer;

#### get_u8_le: I64 -> Array U8 -> U8;

Decodes U8 from `array` at position `i` with little endian.

#### get_u16_le: I64 -> Array U8 -> U16;

Decodes U16 from `array` at position `i` with little endian.

#### get_u32_le: I64 -> Array U8 -> U32;

Decodes U32 from `array` at position `i` with little endian.

#### get_u64_le: I64 -> Array U8 -> U64;

Decodes U64 from `array` at position `i` with little endian.

#### set_u8_le: I64 -> U8 -> Array U8 -> Array U8;

Encodes U8 into `array` at position `i` with little endian.

#### set_u16_le: I64 -> U16 -> Array U8 -> Array U8;

Encodes U16 into `array` at position `i` with little endian.

#### set_u32_le: I64 -> U32 -> Array U8 -> Array U8;

Encodes U32 into `array` at position `i` with little endian.

#### set_u64_le: I64 -> U64 -> Array U8 -> Array U8;

Encodes U64 into `array` at position `i` with little endian.

#### get_u8_be: I64 -> Array U8 -> U8;

Decodes U8 from `array` at position `i` with big endian.

#### get_u16_be: I64 -> Array U8 -> U16;

Decodes U16 from `array` at position `i` with big endian.

#### get_u32_be: I64 -> Array U8 -> U32;

Decodes U32 from `array` at position `i` with big endian.

#### get_u64_be: I64 -> Array U8 -> U64;

Decodes U64 from `array` at position `i` with big endian.

#### set_u8_be: I64 -> U8 -> Array U8 -> Array U8;

Encodes U8 into `array` at position `i` with big endian.

#### set_u16_be: I64 -> U16 -> Array U8 -> Array U8;

Encodes U16 into `array` at position `i` with big endian.

#### set_u32_be: I64 -> U32 -> Array U8 -> Array U8;

Encodes U32 into `array` at position `i` with big endian.

#### set_u64_be: I64 -> U64 -> Array U8 -> Array U8;

Encodes U64 into `array` at position `i` with big endian.

