# `module Minilib.Collection.TreeMap`

TreeMap is a map that manages keys in sorted order.

# Types and aliases

## `namespace Minilib.Collection.TreeMap::TreeMap`

### `type TreeMap k v = unbox struct { ...fields... }`

`TreeMap` is a structure that stores key-value pairs into a red-black tree.

#### field `root : Minilib.Collection.RBTree::RBNode::RBNode (k, v)`

#### field `key_less_than : k -> k -> Std::Bool`

#### field `entry_less_than : (k, v) -> (k, v) -> Std::Bool`

# Traits and aliases

# Trait implementations

### `impl [k : Minilib.Collection.TreeMap::TreeMap::TreeMapKey, v : Minilib.Collection.TreeMap::TreeMap::TreeMapValue] Minilib.Collection.TreeMap::TreeMap::TreeMap k v : Std::ToString`

# Values

## `namespace Minilib.Collection.TreeMap::TreeMap`

### `_lift_lt : (k -> k -> Std::Bool) -> (k, v) -> (k, v) -> Std::Bool`

Converts key_less_than to entry_less_than.

### `contains_key : [k : Minilib.Collection.TreeMap::TreeMap::TreeMapKey, v : Minilib.Collection.TreeMap::TreeMap::TreeMapValue] k -> Minilib.Collection.TreeMap::TreeMap::TreeMap k v -> Std::Bool`

Checks whether a TreeMap contains a key.

### `erase : [k : Minilib.Collection.TreeMap::TreeMap::TreeMapKey, v : Minilib.Collection.TreeMap::TreeMap::TreeMapValue] k -> Minilib.Collection.TreeMap::TreeMap::TreeMap k v -> Minilib.Collection.TreeMap::TreeMap::TreeMap k v`

Erases an entry from a TreeMap.
For example, `tm.erase(k)` removes an entry `(k,v)` from `tm`.

NOTE: If `tm` contains an entry `(k1,v1)`
where the key `k1` is equivalent to `k`,
ie. `!less_than(k,k1) && !less_than(k1,k)` is true,
then `(k1,v1)` is removed.

### `find : [k : Minilib.Collection.TreeMap::TreeMap::TreeMapKey, v : Minilib.Collection.TreeMap::TreeMap::TreeMapValue] k -> Minilib.Collection.TreeMap::TreeMap::TreeMap k v -> Std::Option v`

Finds an element from a TreeMap.

### `find_range : [k : Minilib.Collection.TreeMap::TreeMap::TreeMapKey, v : Minilib.Collection.TreeMap::TreeMap::TreeMapValue] k -> k -> Minilib.Collection.TreeMap::TreeMap::TreeMap k v -> Std::Iterator (k, v)`

`tm.find_range(begin, end)` finds all entries `(k,v)`
where `!less_than(k, begin) && less_than(k, end)` is true.
In default `LessThan` ordering, that condition is same as `begin <= k && k < end`.

### `find_raw_range : [k : Minilib.Collection.TreeMap::TreeMap::TreeMapKey, v : Minilib.Collection.TreeMap::TreeMap::TreeMapValue] ((k, v) -> Std::Bool) -> ((k, v) -> Std::Bool) -> Minilib.Collection.TreeMap::TreeMap::TreeMap k v -> Std::Iterator (k, v)`

`tm.find_raw_range(lt_begin, lt_end)` finds all entries `(k,v)`
where `!lt_begin((k, v)) && lt_end((k, v))` is true.
NOTE: `lt_begin` and `lt_end` must meet following condition:
for all `(k,v)`, `lt_begin((k,v))` is true then `lt_end((k,v))` must be true.

### `from_iter : [k : Std::LessThan, k : Minilib.Collection.TreeMap::TreeMap::TreeMapKey, v : Minilib.Collection.TreeMap::TreeMap::TreeMapValue] Std::Iterator (k, v) -> Minilib.Collection.TreeMap::TreeMap::TreeMap k v`

Converts an iterator of key-value pairs into a TreeMap using default `LessThan` ordering.

### `from_iter_lt : [k : Minilib.Collection.TreeMap::TreeMap::TreeMapKey, v : Minilib.Collection.TreeMap::TreeMap::TreeMapValue] (k -> k -> Std::Bool) -> Std::Iterator (k, v) -> Minilib.Collection.TreeMap::TreeMap::TreeMap k v`

Converts an iterator of key-value pairs into a TreeMap using specified ordering.

### `get_size : [k : Minilib.Collection.TreeMap::TreeMap::TreeMapKey, v : Minilib.Collection.TreeMap::TreeMap::TreeMapValue] Minilib.Collection.TreeMap::TreeMap::TreeMap k v -> Std::I64`

Gets the number of entries.

### `insert : [k : Minilib.Collection.TreeMap::TreeMap::TreeMapKey, v : Minilib.Collection.TreeMap::TreeMap::TreeMapValue] k -> v -> Minilib.Collection.TreeMap::TreeMap::TreeMap k v -> Minilib.Collection.TreeMap::TreeMap::TreeMap k v`

Inserts an entry into a TreeMap.
For example, `tm.insert(k, v)` inserts an entry `(k,v)` into `tm`.

NOTE: If `tm` already contains an entry `(k1,v1)`
where the key `k1` is equivalent to `k`,
ie. `!less_than(k,k1) && !less_than(k1,k)` is true,
then `(k1,v1)` is replaced with `(k,v)`.

### `is_empty : [k : Minilib.Collection.TreeMap::TreeMap::TreeMapKey, v : Minilib.Collection.TreeMap::TreeMap::TreeMapValue] Minilib.Collection.TreeMap::TreeMap::TreeMap k v -> Std::Bool`

Checks whether a TreeMap is empty.

### `keys : [k : Minilib.Collection.TreeMap::TreeMap::TreeMapKey, v : Minilib.Collection.TreeMap::TreeMap::TreeMapValue] Minilib.Collection.TreeMap::TreeMap::TreeMap k v -> Std::Iterator k`

Returns an iterator of keys in ascending order.

### `make : [k : Std::LessThan, k : Minilib.Collection.TreeMap::TreeMap::TreeMapKey, v : Minilib.Collection.TreeMap::TreeMap::TreeMapValue] () -> Minilib.Collection.TreeMap::TreeMap::TreeMap k v`

`TreeMap::make()` creates an empty `TreeMap` using default `LessThan` ordering.

### `make_lt : [k : Minilib.Collection.TreeMap::TreeMap::TreeMapKey, v : Minilib.Collection.TreeMap::TreeMap::TreeMapValue] (k -> k -> Std::Bool) -> Minilib.Collection.TreeMap::TreeMap::TreeMap k v`

`TreeMap::make_lt(less_than)` creates an empty `TreeMap` using specified ordering.
NOTE: `less_than` function must meet specific conditions. For details, see documentation of
[`RBTree`](./rbtree.md).

### `to_iter : [k : Minilib.Collection.TreeMap::TreeMap::TreeMapKey, v : Minilib.Collection.TreeMap::TreeMap::TreeMapValue] Minilib.Collection.TreeMap::TreeMap::TreeMap k v -> Std::Iterator (k, v)`

Converts a TreeMap into an iterator of key-value pairs in ascending order of keys.

### `upsert : [k : Minilib.Collection.TreeMap::TreeMap::TreeMapKey, v : Minilib.Collection.TreeMap::TreeMap::TreeMapValue] k -> v -> (v -> v) -> Minilib.Collection.TreeMap::TreeMap::TreeMap k v -> Minilib.Collection.TreeMap::TreeMap::TreeMap k v`

Inserts or updates an entry in a TreeMap.
For example, `tm.upsert(k, v, updater)` inserts an entry `(k,v)` into `tm`.

NOTE: If `tm` already contains an entry `(k1,v1)`
where the key `k1` is equivalent to `k`,
ie. `!less_than(k,k1) && !less_than(k1,k)` is true,
then `(k1,v1)` is replaced with `(k, updater(v1))`.

## `namespace Minilib.Collection.TreeMap::TreeMap::TreeMap`

### `@entry_less_than : Minilib.Collection.TreeMap::TreeMap::TreeMap k v -> (k, v) -> (k, v) -> Std::Bool`

Retrieves the field `entry_less_than` from a value of `TreeMap`.

### `@key_less_than : Minilib.Collection.TreeMap::TreeMap::TreeMap k v -> k -> k -> Std::Bool`

Retrieves the field `key_less_than` from a value of `TreeMap`.

### `@root : Minilib.Collection.TreeMap::TreeMap::TreeMap k v -> Minilib.Collection.RBTree::RBNode::RBNode (k, v)`

Retrieves the field `root` from a value of `TreeMap`.

### `act_entry_less_than : [f : Std::Functor] (((k, v) -> (k, v) -> Std::Bool) -> f ((k, v) -> (k, v) -> Std::Bool)) -> Minilib.Collection.TreeMap::TreeMap::TreeMap k v -> f (Minilib.Collection.TreeMap::TreeMap::TreeMap k v)`

Updates a value of `TreeMap` by applying a functorial action to field `entry_less_than`.

### `act_key_less_than : [f : Std::Functor] ((k -> k -> Std::Bool) -> f (k -> k -> Std::Bool)) -> Minilib.Collection.TreeMap::TreeMap::TreeMap k v -> f (Minilib.Collection.TreeMap::TreeMap::TreeMap k v)`

Updates a value of `TreeMap` by applying a functorial action to field `key_less_than`.

### `act_root : [f : Std::Functor] (Minilib.Collection.RBTree::RBNode::RBNode (k, v) -> f (Minilib.Collection.RBTree::RBNode::RBNode (k, v))) -> Minilib.Collection.TreeMap::TreeMap::TreeMap k v -> f (Minilib.Collection.TreeMap::TreeMap::TreeMap k v)`

Updates a value of `TreeMap` by applying a functorial action to field `root`.

### `mod_entry_less_than : (((k, v) -> (k, v) -> Std::Bool) -> (k, v) -> (k, v) -> Std::Bool) -> Minilib.Collection.TreeMap::TreeMap::TreeMap k v -> Minilib.Collection.TreeMap::TreeMap::TreeMap k v`

Updates a value of `TreeMap` by applying a function to field `entry_less_than`.

### `mod_key_less_than : ((k -> k -> Std::Bool) -> k -> k -> Std::Bool) -> Minilib.Collection.TreeMap::TreeMap::TreeMap k v -> Minilib.Collection.TreeMap::TreeMap::TreeMap k v`

Updates a value of `TreeMap` by applying a function to field `key_less_than`.

### `mod_root : (Minilib.Collection.RBTree::RBNode::RBNode (k, v) -> Minilib.Collection.RBTree::RBNode::RBNode (k, v)) -> Minilib.Collection.TreeMap::TreeMap::TreeMap k v -> Minilib.Collection.TreeMap::TreeMap::TreeMap k v`

Updates a value of `TreeMap` by applying a function to field `root`.

### `set_entry_less_than : ((k, v) -> (k, v) -> Std::Bool) -> Minilib.Collection.TreeMap::TreeMap::TreeMap k v -> Minilib.Collection.TreeMap::TreeMap::TreeMap k v`

Updates a value of `TreeMap` by setting field `entry_less_than` to a specified one.

### `set_key_less_than : (k -> k -> Std::Bool) -> Minilib.Collection.TreeMap::TreeMap::TreeMap k v -> Minilib.Collection.TreeMap::TreeMap::TreeMap k v`

Updates a value of `TreeMap` by setting field `key_less_than` to a specified one.

### `set_root : Minilib.Collection.RBTree::RBNode::RBNode (k, v) -> Minilib.Collection.TreeMap::TreeMap::TreeMap k v -> Minilib.Collection.TreeMap::TreeMap::TreeMap k v`

Updates a value of `TreeMap` by setting field `root` to a specified one.