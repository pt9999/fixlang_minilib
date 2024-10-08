# Module Minilib.Trait.Semigroup (semigroup.fix)

Semigroup trait and its several implementations (Array, Iterator, String etc).

Semigroup has an associative binary operation, namely `sappend`.
It may or may not have an identity.

For details, see [Wikipedia: Semigroup](https://en.wikipedia.org/wiki/Semigroup).

### `trait Semigroup`

A trait that represents a semigroup.

```
trait a: Semigroup {
    // `a.sappend(b)` appends `b` after `a`.
    sappend: a -> a -> a;
}
```
### `impl Array a: Semigroup`

For arrays, `sappend` appends two arrays.

### `impl Iterator a: Semigroup`

For iterators, `sappend` appends two iterators.

### `impl String: Semigroup`

For strings, `sappend` concats two strings.

### `impl (): Semigroup`

`()` does not change with `sappend`.

### `impl [a: Semigroup] Option a: Semigroup`

For options, `sappand` appends two values if both is some.

### `impl HashSet k v: Semigroup`

