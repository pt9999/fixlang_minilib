# monoid.fix

## module Minilib.Trait.Monoid

Monoid trait and its several implementations (Array, Iterator, String etc).

Monoid is a semigroup with an identity.

For details, see [Wikipedia: Monoid](https://en.wikipedia.org/wiki/Monoid).

### trait MEmpty

A trait that represents an identity of a monoid.

```
trait a: MEmpty {
    // An identity of a monoid, such as an empty instance.
    mempty: a;
}
```
### trait Monoid = Semigroup + MEmpty;

A trait that represents a monoid.

#### mconcat: [a: Monoid] Iterator a -> a;

Concats an iterator of monoids to a monoid.

#### `impl Array a: MEmpty`

#### `impl Iterator a: MEmpty`

#### `impl String: MEmpty`

#### `impl (): MEmpty`

#### `impl [a: Semigroup] Option a: MEmpty`

#### `impl HashSet k v: MEmpty`

