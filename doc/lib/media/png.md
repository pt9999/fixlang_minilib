# Module Minilib.Media.Png (png.fix)

PNG image I/O.

How to use:
1. Install PNG library. For example, run the command below.
`$ sudo apt install libpng-dev`
2. Add `-d png -d z` option to `fix run` and `fix build` arguments.


### `write_png_file: String -> Image -> IOFail ();`

### `write_png_to_memory: Image -> IOFail (Array U8);`

### `type PngImageIO`

```
type PngImageIO = unbox struct {
    data: ByteBuffer
};
```
## `namespace PngImageIO`

### `empty: PngImageIO;`

### `get_width: PngImageIO -> I64;`

### `get_height: PngImageIO -> I64;`

### `get_warning_or_error: PngImageIO -> I64;`

### `get_message: PngImageIO -> String;`

### `set_version: I64 -> PngImageIO -> PngImageIO;`

### `set_width: I64 -> PngImageIO -> PngImageIO;`

### `set_height: I64 -> PngImageIO -> PngImageIO;`

### `set_format: I64 -> PngImageIO -> PngImageIO;`

### `set_flags: I64 -> PngImageIO -> PngImageIO;`

### `write_to_file: String -> Bool -> Array U8 -> I64 -> PngImageIO -> IOFail ();`

### `write_to_memory:  Bool -> Array U8 -> I64 -> PngImageIO -> IOFail (Array U8);`

### `parse_format: String -> I64;`

### `type DefPngImage`

`png_image` structure layout

```
    type DefPngImage = unbox struct {
        offsetof_opaque: I64,
        offsetof_version: I64,
        offsetof_width: I64,
        offsetof_height: I64,
        offsetof_format: I64,
        offsetof_flags: I64,
        offsetof_colormap_entries: I64,
        offsetof_warning_or_error: I64,
        offsetof_message: I64,
        sizeof_png_image: I64
    };
```
