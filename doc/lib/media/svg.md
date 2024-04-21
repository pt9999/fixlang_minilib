# svg.fix

## module Minilib.Media.Svg

Scalable Vector Graphics (SVG) 1.1

This module uses `Minilib.Encoding.Xml` to handle XML.

### trait SvgNum

A trait that can be converted to an attribute value of a SVG element.
For example, a number, or a list of numbers is an instance of this trait.
Convert to an attribute value of a SVG element.

```
trait a: SvgNum {
    to_attr_value: a -> String;
}
```
#### `impl Bool: SvgNum`

Bool is converted to either "1" or "0". For example,
`true` -> `"1"`, `false` -> `"0"`.

#### `impl I64: SvgNum`

I64 is converted to a decimal string.
For example, `100` -> `"100"`.

#### `impl F64: SvgNum`

F64 is converted to a decimal string. Trailing zeros and trailing periods are stripped.
For example, `123.45` -> `"123.45"`, `100.00` -> `"100"`.

#### `impl [a: SvgNum] (a, a): SvgNum`

`(a, a)` is converted to a string `a a`.
For example, `(123.45, 100.00)` -> `"123.45 100"`.

#### `impl [a: SvgNum] Array a: SvgNum`

An array is converted to a string by joining elements with `", "`.
For example, `[(123.45, 100.00), (234.60, 345.70)]` -> `"123.45 100, 234.6 345.7"`.

### type PathData

Path data of `<path>` element.

```
type PathData = unbox struct {
    data: String
};
```
### namespace PathData

#### empty: PathData;

`PathData::empty` is an empty PathData.

#### newpath: PathData;

Synonym for `PathData::empty`.

#### moveto: [a: SvgNum] a -> a -> PathData -> PathData;

`pathdata.moveto(x, y)` starts a new sub-path at the given `(x,y)` coordinates.
Coordinates are absolute.

#### rmoveto: [a: SvgNum] a -> a -> PathData -> PathData;

Same as `moveto` but coordinates are relative.

#### lineto: [a: SvgNum] a -> a -> PathData -> PathData;

`pathdata.lineto(x, y)` draws a line from the current point to the given `(x,y)` coordinates
which becomes the new current point.
Coordinates are absolute.

#### rlineto: [a: SvgNum] a -> a -> PathData -> PathData;

Same as `lineto` but coordinates are relative.

#### closepath: PathData -> PathData;

`pathdata.closepath` ends the current sub-path by connecting it back to its initial point.

#### curveto: [a: SvgNum] a -> a -> a -> a -> a -> a -> PathData -> PathData;

`pathdata.curveto(x1, y1, x2, y2, x, y)` draws a cubic Bézier curve
from the current point to `(x,y)` using `(x1,y1)` as the control point
at the beginning of the curve and `(x2,y2)` as the control point at the end of the curve.
Coordinates are absolute.

#### scurveto: [a: SvgNum] a -> a -> a -> a -> PathData -> PathData;

Shorthand/smooth version of `curveto`.

#### quadto: [a: SvgNum] a -> a -> a -> a -> PathData -> PathData;

`pathdata.quadto(x1, y1, x, y)` draws a quadratic Bézier curve from the
current point to (x,y) using (x1,y1) as the control point.
Coordinates are absolute.

#### squadto: [a: SvgNum] a -> a -> PathData -> PathData;

Shorthand/smooth version of `quadto`.

#### arcto: [a: SvgNum, b: SvgNum, r: SvgNum] a -> a -> r -> b -> b -> a -> a -> PathData -> PathData;

`pathdata.arcto(rx, ry, x_axis_rotation, large_arc_flag, sweep_flag, x, y)` draws a elliptical arc.
Coordinates are absolute.
For details, see [W3C SVG 1.1: 8.3.8 The elliptical arc curve commands](https://www.w3.org/TR/SVG11/paths.html#PathDataEllipticalArcCommands).

### namespace Svg

#### svg: [a: SvgNum] a -> a -> XmlElement;

`Svg::svg(width, height)` creates a `<svg>` element.

#### attr_num: [a: SvgNum] String -> a -> XmlElement -> XmlElement;

`element.attr_num(name, value)` sets an attribute of specified name to the element.

#### view_box: [a: SvgNum] a -> a -> a -> a -> XmlElement -> XmlElement;

`element.view_box(min_x, min_y, width, height)` sets the `viewBox` attribute to the element.
`element` must be one of `<svg>`, `<marker>`, `<pattern>`, `<symbol>`, `<view>`.

#### stroke: String -> XmlElement -> XmlElement;

`element.stroke(paint)` sets a `stroke` attribute to the element.

#### stroke_width: [a: SvgNum] a -> XmlElement -> XmlElement;

`element.stroke_width(num)` sets a `stroke-width` attribute to the element.

#### fill: String -> XmlElement -> XmlElement;

`element.fill(paint)` sets a `fill` attribute to the element.
NOTE: this function may conflict with `Array::fill`.

#### fill_: String -> XmlElement -> XmlElement;

Synonym for `Svg::fill` to avoid conflicts.

#### font_family: String -> XmlElement -> XmlElement;

`element.font_family()` sets a `font-family` attribute to the element.

#### font_size: [a: SvgNum] a -> XmlElement -> XmlElement;

`element.font_size()` sets a `font-size` attribute to the element.

#### xy: [a: SvgNum] a -> a -> XmlElement -> XmlElement;

`element.xy(x, y)` sets `x` and `y` attributes to the element.

#### group: XmlElement;

`Svg::group` is an empty `<g>` element.

#### rect: [a: SvgNum] a -> a -> a -> a -> XmlElement;

`Svg::rect(x, y, width, height)` creates a `<rect>` element.

#### circle: [a: SvgNum] a -> a -> a -> XmlElement;

`Svg::circle(cx, cy, r)` creates a `<circle>` element.

#### ellipse: [a: SvgNum] a -> a -> a -> a -> XmlElement;

`Svg::ellipse(cx, cy, rx, ry)` creates an `<ellipse>` element.

#### line: [a: SvgNum] a -> a -> a -> a -> XmlElement;

`Svg::line(x1, y1, x2, y2)` creates a `<line>` element.

#### polyline: [a: SvgNum] a -> XmlElement;

`Svg::polyline(points)` creates a `<polyline>` element.
In most cases, `points` is an array of `(x, y)`, for example `[(x1, y1), (x2, y2), ...]`.

#### polygon: [a: SvgNum] a -> XmlElement;

`Svg::polygon(points)` creates a `<polygon>` element.
In most cases, `points` is an array of `(x, y)`, for example `[(x1, y1), (x2, y2), ...]`.

#### path: PathData -> XmlElement;

`Svg::path(pathdata)` creates a `<path>` element from a pathdata.

#### text: String -> XmlElement;

`Svg::text(content)` creates a `<text>` element.

#### write_file: String -> XmlElement -> IOFail ();

`element.write_file(filepath)` writes a SVG file.
`element` must be a `<svg>` element.

