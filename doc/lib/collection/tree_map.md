# tree_map.fix

## module TreeMap

### namespace TreeMap

### type TreeMap

```
    type TreeMap k v = unbox struct {
        root: RBNode (k, v),
        key_less_than: k -> k -> Bool,
        entry_less_than: (k, v) -> (k, v) -> Bool
    };
```
#### make: [k: LessThan, k: TreeMapKey] () -> TreeMap k v;

#### make_lt: [k: TreeMapKey] (k -> k -> Bool) -> TreeMap k v;

#### insert: [k: TreeMapKey] k -> v -> TreeMap k v -> TreeMap k v;

#### erase: [k: TreeMapKey] k -> TreeMap k v -> TreeMap k v;

#### is_empty: [k: TreeMapKey] TreeMap k v -> Bool;

#### contains_key: [k: TreeMapKey] k -> TreeMap k v -> Bool;

#### keys: [k: TreeMapKey] TreeMap k v -> Iterator k;

#### find: [k: TreeMapKey] k -> TreeMap k v -> Option v;

#### find_range: [k: TreeMapKey] k -> k -> TreeMap k v -> Iterator (k, v);

`ts.find_range(begin, end)` finds all entries `(k,v)`
where `!less_than(k, begin) && less_than(k, end)` is true.
In default `LessThan` ordering, that condition is same as `begin <= k && k < end`.

#### find_raw_range: [k: TreeMapKey] ((k,v) -> Bool) -> ((k,v) -> Bool) -> TreeMap k v -> Iterator (k, v);

`ts.find_raw_range(lt_begin, lt_end)` finds all entries `(k,v)`
where `!lt_begin((k, v)) && lt_end((k, v))` is true.

#### to_iter: [k: TreeMapKey] TreeMap k v -> Iterator (k, v);

#### from_iter_lt: [k: TreeMapKey] (k -> k -> Bool) -> Iterator (k, v) -> TreeMap k v;

#### from_iter: [k: LessThan, k: TreeMapKey] Iterator (k, v) -> TreeMap k v;

#### `impl [k: TreeMapKey, v: ToString] TreeMap k v: ToString`

