# `module Minilib.Encoding.Binary`

Binary utility, such as:
- Byte order
- Byte buffer

# Types and aliases

## `namespace Minilib.Encoding.Binary`

### `type ByteBuffer = unbox struct { ...fields... }`

#### field `array : Std::Array Std::U8`

#### field `byte_order : Minilib.Encoding.Binary::ByteOrder`

#### field `position : Std::I64`

### `type ByteOrder = unbox union { ...variants... }`

#### variant `little_endian : ()`

#### variant `big_endian : ()`

# Traits and aliases

## `namespace Minilib.Encoding.Binary`

### `trait a : Marshal`

#### method `marshal : a -> Minilib.Encoding.Binary::ByteBuffer -> Minilib.Encoding.Binary::ByteBuffer`

### `trait a : Unmarshal`

#### method `unmarshal : Minilib.Encoding.Binary::ByteBuffer -> Std::Result Std::String (a, Minilib.Encoding.Binary::ByteBuffer)`

# Trait implementations

### `impl Std::U16 : Minilib.Encoding.Binary::Marshal`

### `impl Std::U16 : Minilib.Encoding.Binary::Unmarshal`

### `impl Std::U32 : Minilib.Encoding.Binary::Marshal`

### `impl Std::U32 : Minilib.Encoding.Binary::Unmarshal`

### `impl Std::U64 : Minilib.Encoding.Binary::Marshal`

### `impl Std::U64 : Minilib.Encoding.Binary::Unmarshal`

### `impl Std::U8 : Minilib.Encoding.Binary::Marshal`

### `impl Std::U8 : Minilib.Encoding.Binary::Unmarshal`

# Values

## `namespace Minilib.Encoding.Binary`

### `get_u16_be : Std::I64 -> Std::Array Std::U8 -> Std::U16`

Decodes U16 from `array` at position `i` with big endian.

### `get_u16_le : Std::I64 -> Std::Array Std::U8 -> Std::U16`

Decodes U16 from `array` at position `i` with little endian.

### `get_u32_be : Std::I64 -> Std::Array Std::U8 -> Std::U32`

Decodes U32 from `array` at position `i` with big endian.

### `get_u32_le : Std::I64 -> Std::Array Std::U8 -> Std::U32`

Decodes U32 from `array` at position `i` with little endian.

### `get_u64_be : Std::I64 -> Std::Array Std::U8 -> Std::U64`

Decodes U64 from `array` at position `i` with big endian.

### `get_u64_le : Std::I64 -> Std::Array Std::U8 -> Std::U64`

Decodes U64 from `array` at position `i` with little endian.

### `get_u8_be : Std::I64 -> Std::Array Std::U8 -> Std::U8`

Decodes U8 from `array` at position `i` with big endian.

### `get_u8_le : Std::I64 -> Std::Array Std::U8 -> Std::U8`

Decodes U8 from `array` at position `i` with little endian.

### `set_u16_be : Std::I64 -> Std::U16 -> Std::Array Std::U8 -> Std::Array Std::U8`

Encodes U16 into `array` at position `i` with big endian.

### `set_u16_le : Std::I64 -> Std::U16 -> Std::Array Std::U8 -> Std::Array Std::U8`

Encodes U16 into `array` at position `i` with little endian.

### `set_u32_be : Std::I64 -> Std::U32 -> Std::Array Std::U8 -> Std::Array Std::U8`

Encodes U32 into `array` at position `i` with big endian.

### `set_u32_le : Std::I64 -> Std::U32 -> Std::Array Std::U8 -> Std::Array Std::U8`

Encodes U32 into `array` at position `i` with little endian.

### `set_u64_be : Std::I64 -> Std::U64 -> Std::Array Std::U8 -> Std::Array Std::U8`

Encodes U64 into `array` at position `i` with big endian.

### `set_u64_le : Std::I64 -> Std::U64 -> Std::Array Std::U8 -> Std::Array Std::U8`

Encodes U64 into `array` at position `i` with little endian.

### `set_u8_be : Std::I64 -> Std::U8 -> Std::Array Std::U8 -> Std::Array Std::U8`

Encodes U8 into `array` at position `i` with big endian.

### `set_u8_le : Std::I64 -> Std::U8 -> Std::Array Std::U8 -> Std::Array Std::U8`

Encodes U8 into `array` at position `i` with little endian.

## `namespace Minilib.Encoding.Binary::ByteBuffer`

### `@array : Minilib.Encoding.Binary::ByteBuffer -> Std::Array Std::U8`

Retrieves the field `array` from a value of `ByteBuffer`.

### `@byte_order : Minilib.Encoding.Binary::ByteBuffer -> Minilib.Encoding.Binary::ByteOrder`

Retrieves the field `byte_order` from a value of `ByteBuffer`.

### `@position : Minilib.Encoding.Binary::ByteBuffer -> Std::I64`

Retrieves the field `position` from a value of `ByteBuffer`.

### `_marshal : (Std::I64 -> a -> Minilib.Encoding.Binary::ByteBuffer -> Minilib.Encoding.Binary::ByteBuffer) -> Std::I64 -> a -> Minilib.Encoding.Binary::ByteBuffer -> Minilib.Encoding.Binary::ByteBuffer`

Writes a value to the byte buffer.

### `_unmarshal : (Std::I64 -> Minilib.Encoding.Binary::ByteBuffer -> a) -> Std::I64 -> Minilib.Encoding.Binary::ByteBuffer -> Std::Result Std::String (a, Minilib.Encoding.Binary::ByteBuffer)`

Reads a value from the byte buffer.

### `act_array : [f : Std::Functor] (Std::Array Std::U8 -> f (Std::Array Std::U8)) -> Minilib.Encoding.Binary::ByteBuffer -> f Minilib.Encoding.Binary::ByteBuffer`

Updates a value of `ByteBuffer` by applying a functorial action to field `array`.

### `act_byte_order : [f : Std::Functor] (Minilib.Encoding.Binary::ByteOrder -> f Minilib.Encoding.Binary::ByteOrder) -> Minilib.Encoding.Binary::ByteBuffer -> f Minilib.Encoding.Binary::ByteBuffer`

Updates a value of `ByteBuffer` by applying a functorial action to field `byte_order`.

### `act_position : [f : Std::Functor] (Std::I64 -> f Std::I64) -> Minilib.Encoding.Binary::ByteBuffer -> f Minilib.Encoding.Binary::ByteBuffer`

Updates a value of `ByteBuffer` by applying a functorial action to field `position`.

### `borrow_ptr : (Std::Ptr -> b) -> Minilib.Encoding.Binary::ByteBuffer -> b`

Calls a function with a pointer to the memory region where elements are stored.

### `empty : Std::I64 -> Minilib.Encoding.Binary::ByteOrder -> Minilib.Encoding.Binary::ByteBuffer`

`ByteBuffer::empty(capacity, byte_order)` creates new byte buffer such that:
- The internal byte array is an empty array with capacity `capacity`
- The byte order is `byte_order`

### `ensure_size : Std::I64 -> Minilib.Encoding.Binary::ByteBuffer -> Minilib.Encoding.Binary::ByteBuffer`

`buf.ensure_size(req_size)` ensures that the size of the byte buffer is at least `req_size`.
If not, appends zeros at the end of the byte buffer.

### `fill : Std::I64 -> Std::U8 -> Minilib.Encoding.Binary::ByteOrder -> Minilib.Encoding.Binary::ByteBuffer`

`ByteBuffer::fill(size, value, byte_order)` creates new byte buffer such that:
- The internal byte array is initialized by size `size` and filled with `value`
- The byte order is `byte_order`

### `from_u32_array : Std::Array Std::U32 -> Minilib.Encoding.Binary::ByteOrder -> Minilib.Encoding.Binary::ByteBuffer`

### `get_bytes : Minilib.Encoding.Binary::ByteBuffer -> Std::Array Std::U8`

Gets the internal byte array.

### `get_position : Minilib.Encoding.Binary::ByteBuffer -> Std::I64`

Gets the read/write position.

### `get_size : Minilib.Encoding.Binary::ByteBuffer -> Std::I64`

Gets the size of internal byte array.

### `get_u16 : Std::I64 -> Minilib.Encoding.Binary::ByteBuffer -> Std::U16`

Gets U16 from the byte buffer at position `i`.

### `get_u32 : Std::I64 -> Minilib.Encoding.Binary::ByteBuffer -> Std::U32`

Gets U32 from the byte buffer at position `i`.

### `get_u64 : Std::I64 -> Minilib.Encoding.Binary::ByteBuffer -> Std::U64`

Gets U64 from the byte buffer at position `i`.

### `get_u8 : Std::I64 -> Minilib.Encoding.Binary::ByteBuffer -> Std::U8`

Gets U8 from the byte buffer at position `i`.

### `make : Std::Array Std::U8 -> Minilib.Encoding.Binary::ByteOrder -> Minilib.Encoding.Binary::ByteBuffer`

`ByteBuffer::make(array, byte_order)` creates new byte buffer such that:
- The internal byte array is `array`
- The byte order is `byte_order`

### `mod_array : (Std::Array Std::U8 -> Std::Array Std::U8) -> Minilib.Encoding.Binary::ByteBuffer -> Minilib.Encoding.Binary::ByteBuffer`

Updates a value of `ByteBuffer` by applying a function to field `array`.

### `mod_byte_order : (Minilib.Encoding.Binary::ByteOrder -> Minilib.Encoding.Binary::ByteOrder) -> Minilib.Encoding.Binary::ByteBuffer -> Minilib.Encoding.Binary::ByteBuffer`

Updates a value of `ByteBuffer` by applying a function to field `byte_order`.

### `mod_position : (Std::I64 -> Std::I64) -> Minilib.Encoding.Binary::ByteBuffer -> Minilib.Encoding.Binary::ByteBuffer`

Updates a value of `ByteBuffer` by applying a function to field `position`.

### `set_array : Std::Array Std::U8 -> Minilib.Encoding.Binary::ByteBuffer -> Minilib.Encoding.Binary::ByteBuffer`

Updates a value of `ByteBuffer` by setting field `array` to a specified one.

### `set_byte_order : Minilib.Encoding.Binary::ByteOrder -> Minilib.Encoding.Binary::ByteBuffer -> Minilib.Encoding.Binary::ByteBuffer`

Updates a value of `ByteBuffer` by setting field `byte_order` to a specified one.

### `set_position : Std::I64 -> Minilib.Encoding.Binary::ByteBuffer -> Minilib.Encoding.Binary::ByteBuffer`

Updates a value of `ByteBuffer` by setting field `position` to a specified one.

### `set_u16 : Std::I64 -> Std::U16 -> Minilib.Encoding.Binary::ByteBuffer -> Minilib.Encoding.Binary::ByteBuffer`

Sets U16 into the byte buffer at position `i`.

### `set_u32 : Std::I64 -> Std::U32 -> Minilib.Encoding.Binary::ByteBuffer -> Minilib.Encoding.Binary::ByteBuffer`

Sets U32 into the byte buffer at position `i`.

### `set_u64 : Std::I64 -> Std::U64 -> Minilib.Encoding.Binary::ByteBuffer -> Minilib.Encoding.Binary::ByteBuffer`

Sets U64 into the byte buffer at position `i`.

### `set_u8 : Std::I64 -> Std::U8 -> Minilib.Encoding.Binary::ByteBuffer -> Minilib.Encoding.Binary::ByteBuffer`

Sets U8 into the byte buffer at position `i`.

### `to_u32_array : Minilib.Encoding.Binary::ByteBuffer -> Std::Array Std::U32`

### `to_u8_array : Minilib.Encoding.Binary::ByteBuffer -> Std::Array Std::U8`

## `namespace Minilib.Encoding.Binary::ByteOrder`

### `as_big_endian : Minilib.Encoding.Binary::ByteOrder -> ()`

Unwraps a union value of `ByteOrder` as the variant `big_endian`.
If the value is not the variant `big_endian`, this function aborts the program.

### `as_little_endian : Minilib.Encoding.Binary::ByteOrder -> ()`

Unwraps a union value of `ByteOrder` as the variant `little_endian`.
If the value is not the variant `little_endian`, this function aborts the program.

### `big_endian : () -> Minilib.Encoding.Binary::ByteOrder`

Constructs a value of union `ByteOrder` taking the variant `big_endian`.

### `is_big_endian : Minilib.Encoding.Binary::ByteOrder -> Std::Bool`

Checks if a union value of `ByteOrder` is the variant `big_endian`.

### `is_little_endian : Minilib.Encoding.Binary::ByteOrder -> Std::Bool`

Checks if a union value of `ByteOrder` is the variant `little_endian`.

### `little_endian : () -> Minilib.Encoding.Binary::ByteOrder`

Constructs a value of union `ByteOrder` taking the variant `little_endian`.

### `mod_big_endian : (() -> ()) -> Minilib.Encoding.Binary::ByteOrder -> Minilib.Encoding.Binary::ByteOrder`

Updates a value of union `ByteOrder` by applying a function if it is the variant `big_endian`, or doing nothing otherwise.

### `mod_little_endian : (() -> ()) -> Minilib.Encoding.Binary::ByteOrder -> Minilib.Encoding.Binary::ByteOrder`

Updates a value of union `ByteOrder` by applying a function if it is the variant `little_endian`, or doing nothing otherwise.

## `namespace Minilib.Encoding.Binary::Marshal`

### `marshal : [a : Minilib.Encoding.Binary::Marshal] a -> Minilib.Encoding.Binary::ByteBuffer -> Minilib.Encoding.Binary::ByteBuffer`

## `namespace Minilib.Encoding.Binary::Unmarshal`

### `unmarshal : [a : Minilib.Encoding.Binary::Unmarshal] Minilib.Encoding.Binary::ByteBuffer -> Std::Result Std::String (a, Minilib.Encoding.Binary::ByteBuffer)`