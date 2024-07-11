# Module Minilib.Math.Complex (complex.fix)

Complex number, for example `1 + 2i`.

### `type Complex`

A type that represents a complex number.
`a` is typically F64 or F32.

```
type Complex a = unbox struct {
    re: a,        // real part
    im: a         // image part
};
```
### `make: a -> a -> Complex a;`

Creates a complex number.

### `complex: a -> a -> Complex a;`

`complex` is synonym for `make`.

### `abs2: [a: Add, a: Mul] Complex a -> a;`

Returns the square of the absolute value of a complex number.

### `abs: Complex F64 -> F64;`

Returns the absolute value of a complex number.

### `arg: Complex F64  -> F64;`

Returns the argument of a complex number, ie.

### `conj: [a: Neg] Complex a -> Complex a;`

Returns the conjugate complex number.

### `impl [a: ToString] Complex a: ToString`

Converts a complex number to a string.

### `impl [a: Eq] Complex a: Eq`

### `impl [a: Zero] Complex a: Zero`

### `impl [a: Neg] Complex a: Neg`

### `impl [a: Add] Complex a: Add`

### `impl [a: Sub] Complex a: Sub`

### `impl [a: Ring] Complex a: Mul`

### `impl [a: Field] Complex a: Div`

