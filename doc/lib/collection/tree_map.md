# tree_map.fix

## module Minilib.Collection.TreeMap

TreeMap is a map that manages keys in sorted order.

### namespace TreeMap

### trait TreeMapKey = ToString;

A trait of the key. Currently `ToString` is required.

### trait TreeMapValue = ToString;

A trait of the value. Currently `ToString` is required.

### type TreeMap

`TreeMap` is a structure that stores key-value pairs into a red-black tree.

```
    type TreeMap k v = unbox struct {
        root: RBNode (k, v),
        key_less_than: k -> k -> Bool,
        entry_less_than: (k, v) -> (k, v) -> Bool
    };
```
#### make: [k: LessThan, k: TreeMapKey, v: TreeMapValue] () -> TreeMap k v;

`TreeMap::make()` creates an empty `TreeMap` using default `LessThan` ordering.

#### make_lt: [k: TreeMapKey, v: TreeMapValue] (k -> k -> Bool) -> TreeMap k v;

`TreeMap::make_lt(less_than)` creates an empty `TreeMap` using specified ordering.
NOTE: `less_than` function must meet specific conditions. For details, see documentation of
[`RBTree`](./rbtree.md).

#### insert: [k: TreeMapKey, v: TreeMapValue] k -> v -> TreeMap k v -> TreeMap k v;

Inserts an entry into a TreeMap.
For example, `tm.insert(k, v)` inserts an entry `(k,v)` into `tm`.

NOTE: If `tm` already contains an entry `(k1,v1)`
where the key `k1` is equivalent to `k`,
ie. `!less_than(k,k1) && !less_than(k1,k)` is true,
then `(k1,v1)` is replaced with `(k,v)`.

#### upsert: [k: TreeMapKey, v: TreeMapValue] k -> v -> (v -> v) -> TreeMap k v -> TreeMap k v;

Inserts or updates an entry in a TreeMap.
For example, `tm.upsert(k, v, updater)` inserts an entry `(k,v)` into `tm`.

NOTE: If `tm` already contains an entry `(k1,v1)`
where the key `k1` is equivalent to `k`,
ie. `!less_than(k,k1) && !less_than(k1,k)` is true,
then `(k1,v1)` is replaced with `(k, updater(v1))`.

#### erase: [k: TreeMapKey, v: TreeMapValue] k -> TreeMap k v -> TreeMap k v;

Erases an entry from a TreeMap.
For example, `tm.erase(k)` removes an entry `(k,v)` from `tm`.

NOTE: If `tm` contains an entry `(k1,v1)`
where the key `k1` is equivalent to `k`,
ie. `!less_than(k,k1) && !less_than(k1,k)` is true,
then `(k1,v1)` is removed.

#### is_empty: [k: TreeMapKey, v: TreeMapValue] TreeMap k v -> Bool;

Checks whether a TreeMap is empty.

#### get_size: [k: TreeMapKey, v: TreeMapValue] TreeMap k v -> I64;

Gets the number of entries.

#### contains_key: [k: TreeMapKey, v: TreeMapValue] k -> TreeMap k v -> Bool;

Checks whether a TreeMap contains a key.

#### keys: [k: TreeMapKey, v: TreeMapValue] TreeMap k v -> Iterator k;

Returns an iterator of keys in ascending order.

#### find: [k: TreeMapKey, v: TreeMapValue] k -> TreeMap k v -> Option v;

Finds an element from a TreeMap.

#### find_range: [k: TreeMapKey, v: TreeMapValue] k -> k -> TreeMap k v -> Iterator (k, v);

`tm.find_range(begin, end)` finds all entries `(k,v)`
where `!less_than(k, begin) && less_than(k, end)` is true.
In default `LessThan` ordering, that condition is same as `begin <= k && k < end`.

#### find_raw_range: [k: TreeMapKey, v: TreeMapValue] ((k,v) -> Bool) -> ((k,v) -> Bool) -> TreeMap k v -> Iterator (k, v);

`tm.find_raw_range(lt_begin, lt_end)` finds all entries `(k,v)`
where `!lt_begin((k, v)) && lt_end((k, v))` is true.
NOTE: `lt_begin` and `lt_end` must meet following condition:
for all `(k,v)`, `lt_begin((k,v))` is true then `lt_end((k,v))` must be true.

#### to_iter: [k: TreeMapKey, v: TreeMapValue] TreeMap k v -> Iterator (k, v);

Converts a TreeMap into an iterator of key-value pairs in ascending order of keys.

#### from_iter_lt: [k: TreeMapKey, v: TreeMapValue] (k -> k -> Bool) -> Iterator (k, v) -> TreeMap k v;

Converts an iterator of key-value pairs into a TreeMap using specified ordering.

#### from_iter: [k: LessThan, k: TreeMapKey, v: TreeMapValue] Iterator (k, v) -> TreeMap k v;

Converts an iterator of key-value pairs into a TreeMap using default `LessThan` ordering.

#### `impl [k: TreeMapKey, v: TreeMapValue] TreeMap k v: ToString`

