# Minilib.Collection.PatTree3

Defined in sandbox-container-pattree@0.1.0

Simple map using Patricia Tree.
The type of key is U64, and the type of value is any type.

This module was inspired by Haskell's `Data.IntMap` package.
https://hackage-content.haskell.org/package/containers-0.8/docs/Data-IntMap.html

In particular, I used the following papers mentioned in the `Data.IntMap` package's documentation:

Chris Okasaki and Andy Gill, "Fast Mergeable Integer Maps", Workshop on ML, September 1998, pages 77-86,
https://web.archive.org/web/20150417234429/https://ittc.ku.edu/~andygill/papers/IntMap98.pdf

## Values

### namespace Minilib.Collection.PatTree3::Combine

#### append

Type: `[a : Std::Add] Minilib.Collection.PatTree3::Combine a`

A combining function that appends the new value after the old value.

#### overwrite

Type: `Minilib.Collection.PatTree3::Combine a`

A combining function that replaces the old value into the new value.

### namespace Minilib.Collection.PatTree3::PNodeIndex

#### empty

Type: `Minilib.Collection.PatTree3::PNodeIndex`

A special index which represents an empty node.

### namespace Minilib.Collection.PatTree3::PTree

#### empty

Type: `Minilib.Collection.PatTree3::PTree a`

An empty Patricia Tree.

#### erase

Type: `Minilib.Collection.PatTree3::Key -> Minilib.Collection.PatTree3::PTree a -> Minilib.Collection.PatTree3::PTree a`

Erases a key-value pair from a Patricia Tree.
If there is no key-value pair which matches the specified key, this function does nothing.

##### Parameters

* `key` - The key to erase.
* `tree` - A Patricia Tree.

#### find

Type: `Minilib.Collection.PatTree3::Key -> Minilib.Collection.PatTree3::PTree a -> Std::Option a`

Finds the value which is associated with the key.

##### Parameters

* `key` - The key to find.
* `tree` - A Patricia Tree.

#### get_size

Type: `Minilib.Collection.PatTree3::PTree a -> Std::I64`

Gets size (number of key-value pairs) of a Patricia Tree.

#### insert

Type: `Minilib.Collection.PatTree3::Key -> a -> Minilib.Collection.PatTree3::PTree a -> Minilib.Collection.PatTree3::PTree a`

Inserts a key-value pair into a Patricia Tree.

##### Parameters

* `new_key` - The key to insert.
* `new_value` - The value to insert.
* `tree` - A Patricia Tree.

#### is_empty

Type: `Minilib.Collection.PatTree3::PTree a -> Std::Bool`

Checks whether the Patricia Tree is empty.

#### to_array

Type: `Minilib.Collection.PatTree3::PTree a -> Std::Array (Minilib.Collection.PatTree3::Key, a)`

Converts a Patricia Tree into an array of key-value pairs.
The key-value pairs are sorted in ascending order of keys.

##### Parameters

* `tree` - A Patricia Tree.

## Types and aliases

### namespace Minilib.Collection.PatTree3

#### Combine

Defined as: `type Combine a = a -> a -> a`

The type of combining functions that resolve collisions.
`combine(old_value, new_value)` should return a value combined from `old_value` and `new_value`.

#### Key

Defined as: `type Key = Std::U64`

The key type of Patricia Trees.

#### Mask

Defined as: `type Mask = Std::U64`

The mask type. (used internally)

#### PNode

Defined as: `type PNode a = unbox union { ...variants... }`

The type of tree nodes.

##### variant `empty`

Type: `()`

An empty node.

##### variant `leaf`

Type: `(Minilib.Collection.PatTree3::Key, a)`

A leaf node. (key, data)

##### variant `branch`

Type: `(Minilib.Collection.PatTree3::Prefix, Minilib.Collection.PatTree3::Mask, Minilib.Collection.PatTree3::PNodeIndex, Minilib.Collection.PatTree3::PNodeIndex)`

A branch node. (prefix, mask of the branching bit, left, right)

#### PNodeIndex

Defined as: `type PNodeIndex = Std::I64`

The type of index of the node array.

#### PTree

Defined as: `type PTree a = unbox struct { ...fields... }`

The type of Patricia Trees.

##### field `_root`

Type: `Minilib.Collection.PatTree3::PNodeIndex`

##### field `_size`

Type: `Std::I64`

##### field `_combine`

Type: `Minilib.Collection.PatTree3::Combine a`

##### field `_nodes`

Type: `Std::Array (Minilib.Collection.PatTree3::PNode a)`

##### field `_freelist`

Type: `Std::Array Minilib.Collection.PatTree3::PNodeIndex`

#### Prefix

Defined as: `type Prefix = Std::U64`

The prefix type. (used internally)

## Traits and aliases

## Trait implementations

### impl `[a : Std::ToString] Minilib.Collection.PatTree3::PTree a : Std::ToString`