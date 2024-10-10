# `module Minilib.Trait.Monoid`

Monoid trait and its several implementations (Array, Iterator, String etc).

Monoid is a semigroup with an identity.

For details, see [Wikipedia: Monoid](https://en.wikipedia.org/wiki/Monoid).

# Types and aliases

# Traits and aliases

## `namespace Minilib.Trait.Monoid`

### `trait a : MEmpty`

A trait that represents an identity of a monoid.

#### method `mempty : a`

An identity of a monoid, such as an empty instance.

# Trait implementations

### `impl () : Minilib.Trait.Monoid::MEmpty`

### `impl Std::Array a : Minilib.Trait.Monoid::MEmpty`

### `impl Std::Iterator a : Minilib.Trait.Monoid::MEmpty`

### `impl [a : Minilib.Trait.Semigroup::Semigroup] Std::Option a : Minilib.Trait.Monoid::MEmpty`

### `impl Std::String : Minilib.Trait.Monoid::MEmpty`

# Values

## `namespace Minilib.Trait.Monoid`

### `mconcat : [a : Minilib.Trait.Monoid::Monoid] Std::Iterator a -> a`

Concats an iterator of monoids to a monoid.

## `namespace Minilib.Trait.Monoid::MEmpty`

### `mempty : [a : Minilib.Trait.Monoid::MEmpty] a`

An identity of a monoid, such as an empty instance.