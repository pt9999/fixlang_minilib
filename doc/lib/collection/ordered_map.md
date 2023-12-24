## ordered_map.fix

Ordered map.
This is similar to HashMap except it preserves the order of entries.

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

Check whether an OrderedMap contains a key.

#### empty: I64 -> OrderedMap k v;

Create an empty OrderedMap which is reserved so that it will not rehash until size exceeds the spacified value.

#### erase: [k : HashKey] k -> OrderedMap k v -> OrderedMap k v;

Erase an element from an OrderedMap.

#### find: [k : HashKey] k -> OrderedMap k v -> Option v;

Find an element from an OrderedMap.

#### find_or: [k : HashKey] k -> v -> OrderedMap k v -> v;

Find an element from an OrderedMap. If the map doesn't contain the key, it returns the given default value.

#### get_capacity: OrderedMap k v -> I64;

Get capacity of an OrderedMap.

#### get_size: OrderedMap k v -> I64;

Get size (number of elements) in an OrderedMap.

#### insert: [k : HashKey] k -> v -> OrderedMap k v -> OrderedMap k v;

Insert an element into an OrderedMap.

#### reserve : [k : HashKey] I64 -> OrderedMap k v -> OrderedMap k v;

Reserve an OrderedMap so that it will not rehash until size exceeds the spacified value.

#### to_iter : OrderedMap k v -> Iterator (k, v);

Convert an OrderedMap into an iterator. The order of the elements is the same as
when they were inserted into the map.

#### `impl [k: HashKey, k: ToString, v: ToString] OrderedMap k v: Eq`

#### `impl [k: HashKey, k: ToString, v: ToString] OrderedMap k v : ToString`

