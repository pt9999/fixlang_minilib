# jpeg.fix

## module Minilib.Media.Jpeg

JPEG image I/O.

How to use:
1. Install libjpeg8 library. For example, run the command below.
`$ sudo apt install libjpeg8-dev`
2. Add `-d jpeg` option to `fix run` and `fix build` arguments.


#### write_jpeg_file: String -> Image -> IOFail ();

### type JpegCompress

```
type JpegCompress = unbox struct {
    cinfo: ByteBuffer,
    err_mgr: ByteBuffer
};
```
### namespace JpegCompress

#### make: () -> JpegCompress;

