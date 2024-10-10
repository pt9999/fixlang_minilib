# `module Minilib.Collection.OrderedMap`

Ordered map.
This is similar to HashMap except it preserves the order of entries.

# Types and aliases

## `namespace Minilib.Collection.OrderedMap`

### `type OrderedMap k v = unbox struct { ...fields... }`

Similar to HashMap, but `to_iter()` returns entries in the same order as they were inserted.

#### field `map : HashMap::HashMap k (Std::I64, v)`

#### field `serial : Std::I64`

# Traits and aliases

# Trait implementations

### `impl [k : Hash::HashKey, v : Std::Eq] Minilib.Collection.OrderedMap::OrderedMap k v : Std::Eq`

### `impl [k : Hash::HashKey, k : Std::ToString, v : Std::ToString] Minilib.Collection.OrderedMap::OrderedMap k v : Std::ToString`

# Values

## `namespace Minilib.Collection.OrderedMap::OrderedMap`

### `@map : Minilib.Collection.OrderedMap::OrderedMap k v -> HashMap::HashMap k (Std::I64, v)`

Retrieves the field `map` from a value of `OrderedMap`.

### `@serial : Minilib.Collection.OrderedMap::OrderedMap k v -> Std::I64`

Retrieves the field `serial` from a value of `OrderedMap`.

### `act_map : [f : Std::Functor] (HashMap::HashMap k (Std::I64, v) -> f (HashMap::HashMap k (Std::I64, v))) -> Minilib.Collection.OrderedMap::OrderedMap k v -> f (Minilib.Collection.OrderedMap::OrderedMap k v)`

Updates a value of `OrderedMap` by applying a functorial action to field `map`.

### `act_serial : [f : Std::Functor] (Std::I64 -> f Std::I64) -> Minilib.Collection.OrderedMap::OrderedMap k v -> f (Minilib.Collection.OrderedMap::OrderedMap k v)`

Updates a value of `OrderedMap` by applying a functorial action to field `serial`.

### `contains_key : [k : Hash::HashKey] k -> Minilib.Collection.OrderedMap::OrderedMap k v -> Std::Bool`

Check whether an OrderedMap contains a key.

### `empty : Std::I64 -> Minilib.Collection.OrderedMap::OrderedMap k v`

Create an empty OrderedMap which is reserved so that it will not rehash until size exceeds the spacified value.

### `erase : [k : Hash::HashKey] k -> Minilib.Collection.OrderedMap::OrderedMap k v -> Minilib.Collection.OrderedMap::OrderedMap k v`

Erase an element from an OrderedMap.

### `find : [k : Hash::HashKey] k -> Minilib.Collection.OrderedMap::OrderedMap k v -> Std::Option v`

Find an element from an OrderedMap.

### `find_or : [k : Hash::HashKey] k -> v -> Minilib.Collection.OrderedMap::OrderedMap k v -> v`

Find an element from an OrderedMap. If the map doesn't contain the key, it returns the given default value.

### `get_capacity : Minilib.Collection.OrderedMap::OrderedMap k v -> Std::I64`

Get capacity of an OrderedMap.

### `get_size : Minilib.Collection.OrderedMap::OrderedMap k v -> Std::I64`

Get size (number of elements) in an OrderedMap.

### `insert : [k : Hash::HashKey] k -> v -> Minilib.Collection.OrderedMap::OrderedMap k v -> Minilib.Collection.OrderedMap::OrderedMap k v`

Insert an element into an OrderedMap.

### `mod_map : (HashMap::HashMap k (Std::I64, v) -> HashMap::HashMap k (Std::I64, v)) -> Minilib.Collection.OrderedMap::OrderedMap k v -> Minilib.Collection.OrderedMap::OrderedMap k v`

Updates a value of `OrderedMap` by applying a function to field `map`.

### `mod_serial : (Std::I64 -> Std::I64) -> Minilib.Collection.OrderedMap::OrderedMap k v -> Minilib.Collection.OrderedMap::OrderedMap k v`

Updates a value of `OrderedMap` by applying a function to field `serial`.

### `reserve : [k : Hash::HashKey] Std::I64 -> Minilib.Collection.OrderedMap::OrderedMap k v -> Minilib.Collection.OrderedMap::OrderedMap k v`

Reserve an OrderedMap so that it will not rehash until size exceeds the spacified value.

### `set_map : HashMap::HashMap k (Std::I64, v) -> Minilib.Collection.OrderedMap::OrderedMap k v -> Minilib.Collection.OrderedMap::OrderedMap k v`

Updates a value of `OrderedMap` by setting field `map` to a specified one.

### `set_serial : Std::I64 -> Minilib.Collection.OrderedMap::OrderedMap k v -> Minilib.Collection.OrderedMap::OrderedMap k v`

Updates a value of `OrderedMap` by setting field `serial` to a specified one.

### `to_iter : Minilib.Collection.OrderedMap::OrderedMap k v -> Std::Iterator (k, v)`

Convert an OrderedMap into an iterator. The order of the elements is the same as
when they were inserted into the map.