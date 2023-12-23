## ordered_map.fix

### type OrderedMap

Similar to HashMap, but `to_iter()` returns entries in the same order as they were inserted.

```
type OrderedMap k v = unbox struct {
    map: HashMap k (I64, v),
    serial: I64
};
```
### namespace OrderedMap

#### contains_key: [k : HashKey] k -> OrderedMap k v -> Bool;

#### empty: I64 -> OrderedMap k v;

#### erase: [k : HashKey] k -> OrderedMap k v -> OrderedMap k v;

#### find: [k : HashKey] k -> OrderedMap k v -> Option v;

#### find_or: [k : HashKey] k -> v -> OrderedMap k v -> v;

#### get_capacity: OrderedMap k v -> I64;

#### get_size: OrderedMap k v -> I64;

#### insert: [k : HashKey] k -> v -> OrderedMap k v -> OrderedMap k v;

#### reserve : [k : HashKey] I64 -> OrderedMap k v -> OrderedMap k v;

#### to_iter : OrderedMap k v -> Iterator (k, v);

