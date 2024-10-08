# Module Minilib.Media.Image (image.fix)

Basic image definitions.

### `type Image`

```
type Image = unbox struct {
    width: I64,
    height: I64,
    channels: I64,
    format: String,
    data: Array U8
};
```
### `make: I64 -> I64 -> String -> Image;`

### `calc_channels_by_format: String -> I64;`

### `calc_index: I64 -> I64 -> I64 -> Image -> I64;`

### `get: I64 -> Image -> U8;`

### `set: I64 -> U8 -> Image -> Image;`

### `get_rgb: I64 -> Image -> (U8, U8, U8);`

### `set_rgb: I64 -> (U8, U8, U8) -> Image -> Image;`

