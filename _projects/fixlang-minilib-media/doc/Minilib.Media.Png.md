# `module Minilib.Media.Png`

PNG image I/O.

 How to use:
 1. Install PNG library. For example, run the command below.
    `$ sudo apt install libpng-dev`
 2. Add `-d png -d z` option to `fix run` and `fix build` arguments.

# Types and aliases

## `namespace Minilib.Media.Png`

### `type PngImageIO = unbox struct { ...fields... }`

#### field `data : Minilib.Encoding.Binary::ByteBuffer`

## `namespace Minilib.Media.Png::PngImageIO`

### `type DefPngImage = unbox struct { ...fields... }`

`png_image` structure layout

#### field `offsetof_opaque : Std::I64`

#### field `offsetof_version : Std::I64`

#### field `offsetof_width : Std::I64`

#### field `offsetof_height : Std::I64`

#### field `offsetof_format : Std::I64`

#### field `offsetof_flags : Std::I64`

#### field `offsetof_colormap_entries : Std::I64`

#### field `offsetof_warning_or_error : Std::I64`

#### field `offsetof_message : Std::I64`

#### field `sizeof_png_image : Std::I64`

# Traits and aliases

# Trait implementations

# Values

## `namespace Minilib.Media.Png`

### `_to_png_imageio : Minilib.Media.Image::Image -> Minilib.Media.Png::PngImageIO`

### `write_png_file : Std::String -> Minilib.Media.Image::Image -> Std::IO::IOFail ()`

### `write_png_to_memory : Minilib.Media.Image::Image -> Std::IO::IOFail (Std::Array Std::U8)`

## `namespace Minilib.Media.Png::PngImageIO`

### `@data : Minilib.Media.Png::PngImageIO -> Minilib.Encoding.Binary::ByteBuffer`

Retrieves the field `data` from a value of `PngImageIO`.

### `_PNG_FORMAT_FLAG_AFIRST : Std::I64`

### `_PNG_FORMAT_FLAG_ALPHA : Std::I64`

### `_PNG_FORMAT_FLAG_ASSOCIATED_ALPHA : Std::I64`

### `_PNG_FORMAT_FLAG_BGR : Std::I64`

### `_PNG_FORMAT_FLAG_COLOR : Std::I64`

### `_PNG_FORMAT_FLAG_COLORMAP : Std::I64`

### `_PNG_FORMAT_FLAG_LINEAR : Std::I64`

### `_check_warning_or_error : Std::String -> Std::I32 -> Minilib.Media.Png::PngImageIO -> Std::IO::IOFail ()`

### `_def_png_image : Minilib.Media.Png::PngImageIO::DefPngImage`

### `act_data : [f : Std::Functor] (Minilib.Encoding.Binary::ByteBuffer -> f Minilib.Encoding.Binary::ByteBuffer) -> Minilib.Media.Png::PngImageIO -> f Minilib.Media.Png::PngImageIO`

Updates a value of `PngImageIO` by applying a functorial action to field `data`.

### `empty : Minilib.Media.Png::PngImageIO`

### `get_height : Minilib.Media.Png::PngImageIO -> Std::I64`

### `get_message : Minilib.Media.Png::PngImageIO -> Std::String`

### `get_warning_or_error : Minilib.Media.Png::PngImageIO -> Std::I64`

### `get_width : Minilib.Media.Png::PngImageIO -> Std::I64`

### `mod_data : (Minilib.Encoding.Binary::ByteBuffer -> Minilib.Encoding.Binary::ByteBuffer) -> Minilib.Media.Png::PngImageIO -> Minilib.Media.Png::PngImageIO`

Updates a value of `PngImageIO` by applying a function to field `data`.

### `parse_format : Std::String -> Std::I64`

### `set_data : Minilib.Encoding.Binary::ByteBuffer -> Minilib.Media.Png::PngImageIO -> Minilib.Media.Png::PngImageIO`

Updates a value of `PngImageIO` by setting field `data` to a specified one.

### `set_flags : Std::I64 -> Minilib.Media.Png::PngImageIO -> Minilib.Media.Png::PngImageIO`

### `set_format : Std::I64 -> Minilib.Media.Png::PngImageIO -> Minilib.Media.Png::PngImageIO`

### `set_height : Std::I64 -> Minilib.Media.Png::PngImageIO -> Minilib.Media.Png::PngImageIO`

### `set_version : Std::I64 -> Minilib.Media.Png::PngImageIO -> Minilib.Media.Png::PngImageIO`

### `set_width : Std::I64 -> Minilib.Media.Png::PngImageIO -> Minilib.Media.Png::PngImageIO`

### `write_to_file : Std::String -> Std::Bool -> Std::Array Std::U8 -> Std::I64 -> Minilib.Media.Png::PngImageIO -> Std::IO::IOFail ()`

### `write_to_memory : Std::Bool -> Std::Array Std::U8 -> Std::I64 -> Minilib.Media.Png::PngImageIO -> Std::IO::IOFail (Std::Array Std::U8)`

## `namespace Minilib.Media.Png::PngImageIO::DefPngImage`

### `@offsetof_colormap_entries : Minilib.Media.Png::PngImageIO::DefPngImage -> Std::I64`

Retrieves the field `offsetof_colormap_entries` from a value of `DefPngImage`.

### `@offsetof_flags : Minilib.Media.Png::PngImageIO::DefPngImage -> Std::I64`

Retrieves the field `offsetof_flags` from a value of `DefPngImage`.

### `@offsetof_format : Minilib.Media.Png::PngImageIO::DefPngImage -> Std::I64`

Retrieves the field `offsetof_format` from a value of `DefPngImage`.

### `@offsetof_height : Minilib.Media.Png::PngImageIO::DefPngImage -> Std::I64`

Retrieves the field `offsetof_height` from a value of `DefPngImage`.

### `@offsetof_message : Minilib.Media.Png::PngImageIO::DefPngImage -> Std::I64`

Retrieves the field `offsetof_message` from a value of `DefPngImage`.

### `@offsetof_opaque : Minilib.Media.Png::PngImageIO::DefPngImage -> Std::I64`

Retrieves the field `offsetof_opaque` from a value of `DefPngImage`.

### `@offsetof_version : Minilib.Media.Png::PngImageIO::DefPngImage -> Std::I64`

Retrieves the field `offsetof_version` from a value of `DefPngImage`.

### `@offsetof_warning_or_error : Minilib.Media.Png::PngImageIO::DefPngImage -> Std::I64`

Retrieves the field `offsetof_warning_or_error` from a value of `DefPngImage`.

### `@offsetof_width : Minilib.Media.Png::PngImageIO::DefPngImage -> Std::I64`

Retrieves the field `offsetof_width` from a value of `DefPngImage`.

### `@sizeof_png_image : Minilib.Media.Png::PngImageIO::DefPngImage -> Std::I64`

Retrieves the field `sizeof_png_image` from a value of `DefPngImage`.

### `act_offsetof_colormap_entries : [f : Std::Functor] (Std::I64 -> f Std::I64) -> Minilib.Media.Png::PngImageIO::DefPngImage -> f Minilib.Media.Png::PngImageIO::DefPngImage`

Updates a value of `DefPngImage` by applying a functorial action to field `offsetof_colormap_entries`.

### `act_offsetof_flags : [f : Std::Functor] (Std::I64 -> f Std::I64) -> Minilib.Media.Png::PngImageIO::DefPngImage -> f Minilib.Media.Png::PngImageIO::DefPngImage`

Updates a value of `DefPngImage` by applying a functorial action to field `offsetof_flags`.

### `act_offsetof_format : [f : Std::Functor] (Std::I64 -> f Std::I64) -> Minilib.Media.Png::PngImageIO::DefPngImage -> f Minilib.Media.Png::PngImageIO::DefPngImage`

Updates a value of `DefPngImage` by applying a functorial action to field `offsetof_format`.

### `act_offsetof_height : [f : Std::Functor] (Std::I64 -> f Std::I64) -> Minilib.Media.Png::PngImageIO::DefPngImage -> f Minilib.Media.Png::PngImageIO::DefPngImage`

Updates a value of `DefPngImage` by applying a functorial action to field `offsetof_height`.

### `act_offsetof_message : [f : Std::Functor] (Std::I64 -> f Std::I64) -> Minilib.Media.Png::PngImageIO::DefPngImage -> f Minilib.Media.Png::PngImageIO::DefPngImage`

Updates a value of `DefPngImage` by applying a functorial action to field `offsetof_message`.

### `act_offsetof_opaque : [f : Std::Functor] (Std::I64 -> f Std::I64) -> Minilib.Media.Png::PngImageIO::DefPngImage -> f Minilib.Media.Png::PngImageIO::DefPngImage`

Updates a value of `DefPngImage` by applying a functorial action to field `offsetof_opaque`.

### `act_offsetof_version : [f : Std::Functor] (Std::I64 -> f Std::I64) -> Minilib.Media.Png::PngImageIO::DefPngImage -> f Minilib.Media.Png::PngImageIO::DefPngImage`

Updates a value of `DefPngImage` by applying a functorial action to field `offsetof_version`.

### `act_offsetof_warning_or_error : [f : Std::Functor] (Std::I64 -> f Std::I64) -> Minilib.Media.Png::PngImageIO::DefPngImage -> f Minilib.Media.Png::PngImageIO::DefPngImage`

Updates a value of `DefPngImage` by applying a functorial action to field `offsetof_warning_or_error`.

### `act_offsetof_width : [f : Std::Functor] (Std::I64 -> f Std::I64) -> Minilib.Media.Png::PngImageIO::DefPngImage -> f Minilib.Media.Png::PngImageIO::DefPngImage`

Updates a value of `DefPngImage` by applying a functorial action to field `offsetof_width`.

### `act_sizeof_png_image : [f : Std::Functor] (Std::I64 -> f Std::I64) -> Minilib.Media.Png::PngImageIO::DefPngImage -> f Minilib.Media.Png::PngImageIO::DefPngImage`

Updates a value of `DefPngImage` by applying a functorial action to field `sizeof_png_image`.

### `mod_offsetof_colormap_entries : (Std::I64 -> Std::I64) -> Minilib.Media.Png::PngImageIO::DefPngImage -> Minilib.Media.Png::PngImageIO::DefPngImage`

Updates a value of `DefPngImage` by applying a function to field `offsetof_colormap_entries`.

### `mod_offsetof_flags : (Std::I64 -> Std::I64) -> Minilib.Media.Png::PngImageIO::DefPngImage -> Minilib.Media.Png::PngImageIO::DefPngImage`

Updates a value of `DefPngImage` by applying a function to field `offsetof_flags`.

### `mod_offsetof_format : (Std::I64 -> Std::I64) -> Minilib.Media.Png::PngImageIO::DefPngImage -> Minilib.Media.Png::PngImageIO::DefPngImage`

Updates a value of `DefPngImage` by applying a function to field `offsetof_format`.

### `mod_offsetof_height : (Std::I64 -> Std::I64) -> Minilib.Media.Png::PngImageIO::DefPngImage -> Minilib.Media.Png::PngImageIO::DefPngImage`

Updates a value of `DefPngImage` by applying a function to field `offsetof_height`.

### `mod_offsetof_message : (Std::I64 -> Std::I64) -> Minilib.Media.Png::PngImageIO::DefPngImage -> Minilib.Media.Png::PngImageIO::DefPngImage`

Updates a value of `DefPngImage` by applying a function to field `offsetof_message`.

### `mod_offsetof_opaque : (Std::I64 -> Std::I64) -> Minilib.Media.Png::PngImageIO::DefPngImage -> Minilib.Media.Png::PngImageIO::DefPngImage`

Updates a value of `DefPngImage` by applying a function to field `offsetof_opaque`.

### `mod_offsetof_version : (Std::I64 -> Std::I64) -> Minilib.Media.Png::PngImageIO::DefPngImage -> Minilib.Media.Png::PngImageIO::DefPngImage`

Updates a value of `DefPngImage` by applying a function to field `offsetof_version`.

### `mod_offsetof_warning_or_error : (Std::I64 -> Std::I64) -> Minilib.Media.Png::PngImageIO::DefPngImage -> Minilib.Media.Png::PngImageIO::DefPngImage`

Updates a value of `DefPngImage` by applying a function to field `offsetof_warning_or_error`.

### `mod_offsetof_width : (Std::I64 -> Std::I64) -> Minilib.Media.Png::PngImageIO::DefPngImage -> Minilib.Media.Png::PngImageIO::DefPngImage`

Updates a value of `DefPngImage` by applying a function to field `offsetof_width`.

### `mod_sizeof_png_image : (Std::I64 -> Std::I64) -> Minilib.Media.Png::PngImageIO::DefPngImage -> Minilib.Media.Png::PngImageIO::DefPngImage`

Updates a value of `DefPngImage` by applying a function to field `sizeof_png_image`.

### `set_offsetof_colormap_entries : Std::I64 -> Minilib.Media.Png::PngImageIO::DefPngImage -> Minilib.Media.Png::PngImageIO::DefPngImage`

Updates a value of `DefPngImage` by setting field `offsetof_colormap_entries` to a specified one.

### `set_offsetof_flags : Std::I64 -> Minilib.Media.Png::PngImageIO::DefPngImage -> Minilib.Media.Png::PngImageIO::DefPngImage`

Updates a value of `DefPngImage` by setting field `offsetof_flags` to a specified one.

### `set_offsetof_format : Std::I64 -> Minilib.Media.Png::PngImageIO::DefPngImage -> Minilib.Media.Png::PngImageIO::DefPngImage`

Updates a value of `DefPngImage` by setting field `offsetof_format` to a specified one.

### `set_offsetof_height : Std::I64 -> Minilib.Media.Png::PngImageIO::DefPngImage -> Minilib.Media.Png::PngImageIO::DefPngImage`

Updates a value of `DefPngImage` by setting field `offsetof_height` to a specified one.

### `set_offsetof_message : Std::I64 -> Minilib.Media.Png::PngImageIO::DefPngImage -> Minilib.Media.Png::PngImageIO::DefPngImage`

Updates a value of `DefPngImage` by setting field `offsetof_message` to a specified one.

### `set_offsetof_opaque : Std::I64 -> Minilib.Media.Png::PngImageIO::DefPngImage -> Minilib.Media.Png::PngImageIO::DefPngImage`

Updates a value of `DefPngImage` by setting field `offsetof_opaque` to a specified one.

### `set_offsetof_version : Std::I64 -> Minilib.Media.Png::PngImageIO::DefPngImage -> Minilib.Media.Png::PngImageIO::DefPngImage`

Updates a value of `DefPngImage` by setting field `offsetof_version` to a specified one.

### `set_offsetof_warning_or_error : Std::I64 -> Minilib.Media.Png::PngImageIO::DefPngImage -> Minilib.Media.Png::PngImageIO::DefPngImage`

Updates a value of `DefPngImage` by setting field `offsetof_warning_or_error` to a specified one.

### `set_offsetof_width : Std::I64 -> Minilib.Media.Png::PngImageIO::DefPngImage -> Minilib.Media.Png::PngImageIO::DefPngImage`

Updates a value of `DefPngImage` by setting field `offsetof_width` to a specified one.

### `set_sizeof_png_image : Std::I64 -> Minilib.Media.Png::PngImageIO::DefPngImage -> Minilib.Media.Png::PngImageIO::DefPngImage`

Updates a value of `DefPngImage` by setting field `sizeof_png_image` to a specified one.