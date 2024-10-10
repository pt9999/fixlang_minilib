# `module Minilib.Trait.Semigroup`

Semigroup trait and its several implementations (Array, Iterator, String etc).

Semigroup has an associative binary operation, namely `sappend`.
It may or may not have an identity.

For details, see [Wikipedia: Semigroup](https://en.wikipedia.org/wiki/Semigroup).

# Types and aliases

# Traits and aliases

## `namespace Minilib.Trait.Semigroup`

### `trait a : Semigroup`

A trait that represents a semigroup.

#### method `sappend : a -> a -> a`

`a.sappend(b)` appends `b` after `a`.

# Trait implementations

### `impl () : Minilib.Trait.Semigroup::Semigroup`

`()` does not change with `sappend`.

### `impl Std::Array a : Minilib.Trait.Semigroup::Semigroup`

For arrays, `sappend` appends two arrays.

### `impl Std::Iterator a : Minilib.Trait.Semigroup::Semigroup`

For iterators, `sappend` appends two iterators.

### `impl [a : Minilib.Trait.Semigroup::Semigroup] Std::Option a : Minilib.Trait.Semigroup::Semigroup`

For options, `sappand` appends two values if both is some.

### `impl Std::String : Minilib.Trait.Semigroup::Semigroup`

For strings, `sappend` concats two strings.

# Values

## `namespace Minilib.Trait.Semigroup::Semigroup`

### `sappend : [a : Minilib.Trait.Semigroup::Semigroup] a -> a -> a`

`a.sappend(b)` appends `b` after `a`.