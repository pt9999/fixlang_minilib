# Module Minilib.Testing.TestUtilArray (test_util_array.fix)

Array utility functions for testing.

### `shuffle_array: Random -> Array a -> (Random, Array a);`

Shuffles an array.

### `skip_array: I64 -> Array a -> Array a;`

Make a skip array.

### `type Reorder`

How to reorder the elements of an array.

```
type Reorder = unbox union {
    ascending: (),      // don't reorder elements
    descending: (),     // reverse elements
    skip: I64,          // skip elements (argument: skip modulo)
    shuffle: I64        // shuffle elements (argument: random seed)
};
```
### `impl Reorder: ToString`

### `reorder: Reorder -> Array a -> Array a;`

Changes the order of elements in an array.

