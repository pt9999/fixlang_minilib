# `module Minilib.Media.Image`

Basic image definitions.

# Types and aliases

## `namespace Minilib.Media.Image`

### `type Image = unbox struct { ...fields... }`

#### field `width : Std::I64`

#### field `height : Std::I64`

#### field `channels : Std::I64`

#### field `format : Std::String`

#### field `data : Std::Array Std::U8`

# Traits and aliases

# Trait implementations

# Values

## `namespace Minilib.Media.Image`

### `calc_channels_by_format : Std::String -> Std::I64`

### `calc_index : Std::I64 -> Std::I64 -> Std::I64 -> Minilib.Media.Image::Image -> Std::I64`

### `get : Std::I64 -> Minilib.Media.Image::Image -> Std::U8`

### `get_rgb : Std::I64 -> Minilib.Media.Image::Image -> (Std::U8, Std::U8, Std::U8)`

### `make : Std::I64 -> Std::I64 -> Std::String -> Minilib.Media.Image::Image`

### `set : Std::I64 -> Std::U8 -> Minilib.Media.Image::Image -> Minilib.Media.Image::Image`

### `set_rgb : Std::I64 -> (Std::U8, Std::U8, Std::U8) -> Minilib.Media.Image::Image -> Minilib.Media.Image::Image`

## `namespace Minilib.Media.Image::Image`

### `@channels : Minilib.Media.Image::Image -> Std::I64`

Retrieves the field `channels` from a value of `Image`.

### `@data : Minilib.Media.Image::Image -> Std::Array Std::U8`

Retrieves the field `data` from a value of `Image`.

### `@format : Minilib.Media.Image::Image -> Std::String`

Retrieves the field `format` from a value of `Image`.

### `@height : Minilib.Media.Image::Image -> Std::I64`

Retrieves the field `height` from a value of `Image`.

### `@width : Minilib.Media.Image::Image -> Std::I64`

Retrieves the field `width` from a value of `Image`.

### `act_channels : [f : Std::Functor] (Std::I64 -> f Std::I64) -> Minilib.Media.Image::Image -> f Minilib.Media.Image::Image`

Updates a value of `Image` by applying a functorial action to field `channels`.

### `act_data : [f : Std::Functor] (Std::Array Std::U8 -> f (Std::Array Std::U8)) -> Minilib.Media.Image::Image -> f Minilib.Media.Image::Image`

Updates a value of `Image` by applying a functorial action to field `data`.

### `act_format : [f : Std::Functor] (Std::String -> f Std::String) -> Minilib.Media.Image::Image -> f Minilib.Media.Image::Image`

Updates a value of `Image` by applying a functorial action to field `format`.

### `act_height : [f : Std::Functor] (Std::I64 -> f Std::I64) -> Minilib.Media.Image::Image -> f Minilib.Media.Image::Image`

Updates a value of `Image` by applying a functorial action to field `height`.

### `act_width : [f : Std::Functor] (Std::I64 -> f Std::I64) -> Minilib.Media.Image::Image -> f Minilib.Media.Image::Image`

Updates a value of `Image` by applying a functorial action to field `width`.

### `mod_channels : (Std::I64 -> Std::I64) -> Minilib.Media.Image::Image -> Minilib.Media.Image::Image`

Updates a value of `Image` by applying a function to field `channels`.

### `mod_data : (Std::Array Std::U8 -> Std::Array Std::U8) -> Minilib.Media.Image::Image -> Minilib.Media.Image::Image`

Updates a value of `Image` by applying a function to field `data`.

### `mod_format : (Std::String -> Std::String) -> Minilib.Media.Image::Image -> Minilib.Media.Image::Image`

Updates a value of `Image` by applying a function to field `format`.

### `mod_height : (Std::I64 -> Std::I64) -> Minilib.Media.Image::Image -> Minilib.Media.Image::Image`

Updates a value of `Image` by applying a function to field `height`.

### `mod_width : (Std::I64 -> Std::I64) -> Minilib.Media.Image::Image -> Minilib.Media.Image::Image`

Updates a value of `Image` by applying a function to field `width`.

### `set_channels : Std::I64 -> Minilib.Media.Image::Image -> Minilib.Media.Image::Image`

Updates a value of `Image` by setting field `channels` to a specified one.

### `set_data : Std::Array Std::U8 -> Minilib.Media.Image::Image -> Minilib.Media.Image::Image`

Updates a value of `Image` by setting field `data` to a specified one.

### `set_format : Std::String -> Minilib.Media.Image::Image -> Minilib.Media.Image::Image`

Updates a value of `Image` by setting field `format` to a specified one.

### `set_height : Std::I64 -> Minilib.Media.Image::Image -> Minilib.Media.Image::Image`

Updates a value of `Image` by setting field `height` to a specified one.

### `set_width : Std::I64 -> Minilib.Media.Image::Image -> Minilib.Media.Image::Image`

Updates a value of `Image` by setting field `width` to a specified one.