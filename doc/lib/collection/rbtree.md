# Module Minilib.Collection.RBTree (rbtree.fix)

Red-Black Tree.
(This is an internal module of `TreeMap` and `TreeSet`.)

Ported from Japanese translation of the book below:

"Purely functional data structures" by Chris Okasaki, Cambridge University Press, 1998, ISBN 0-521-66350-4

And for removal algorithm, ported from web site below.
http://wwwa.pikara.ne.jp/okojisan/rb-tree/index.html#Delete

NOTE: `less_than()` function must meet following conditions.
- Irreflexivity: for all `x`, `less_than(x,x)` must be false.
- Asymmetry:     for all `x, y`, if `less_than(x,y)` is true, then `less_than(y,x)` must be false.
- Transitivity:  for all `x, y, z`, if `less_than(x,y)` is true and `less_than(y,z)` is true,
then `less_than(x,z)` must be true.


## `namespace RBNode`

### `trait RBNodeElem = ToString;`

A trait of the element. Currently `ToString` is required.

### `type RBNode`

A type of red-black tree node.

```
    type RBNode a = box union {
        empty: (),
        red:  (RBNode a, a, RBNode a),
        black: (RBNode a, a, RBNode a)
    };
```
### `level_nonvalidate: [a: RBNodeElem] RBNode a -> I64;`

Returns the level of this node (ie. the number of black nodes from this node to any leaf).
This function does not validate, so an unbalanced node can be specified.

### `level: [a: RBNodeElem] RBNode a -> I64;`

Returns the level of this node (ie. the number of black nodes from this node to any leaf).
Panicks when the left and right nodes have different black count.

### `validate: [a: RBNodeElem] (a -> a -> Bool) -> RBNode a -> (I64, Option a, Option a);`

Validates that:
- the left and right nodes have same black count
- children of a red node is not red
- max of left node < elem
- elem < min of right node
Returns `(level, min, max)`.
Panicks if validation failed.

### `get_size: RBNode a -> I64;`

Gets the number of elements.

### `get_triplet: RBNode a -> (RBNode a, a, RBNode a);`

If the node is black or red, `node.get_triplet` returns a triplet `(left, elem, right)`.
If the node is empty, it will abort.

### `set_triplet: (RBNode a, a, RBNode a) -> RBNode a -> RBNode a;`

### `get_color: RBNode a -> ((RBNode a, a, RBNode a) -> RBNode a);`

### `set_color: ((RBNode a, a, RBNode a) -> RBNode a) -> RBNode a -> RBNode a;`

### `get_left: RBNode a -> RBNode a;`

### `get_right: RBNode a -> RBNode a;`

### `find: a -> (a -> a -> Bool) -> RBNode a -> Option a;`

`node.find(x, less_than)` finds an element `elem` that is equivalent to `x`,
ie. `!less_than(elem, x) && !less_than(x, elem)` is true.

### `find_range: (a -> Bool) -> (a -> Bool) -> RBNode a -> Iterator a;`

`node.find_range(lt_begin, lt_end)` finds all elements `elem`
such that `!elem.lt_begin && elem.lt_end` is true.
NOTE: `lt_begin` and `lt_end` must meet following condition:
for all `x`, `x.lt_begin` is true then `x.lt_end` must be true.

### `find_range_descending: (a -> Bool) -> (a -> Bool) -> RBNode a -> Iterator a;`

`node.find_range(lt_begin, lt_end)` finds all elements `elem`
such that `!elem.lt_begin && elem.lt_end` is true, in descending order.
NOTE: `lt_begin` and `lt_end` must meet following condition:
for all `x`, `x.lt_begin` is true then `x.lt_end` must be true.

### `get_first: RBNode a -> Option a;`

Gets the first element (that is, the smallest element) of the tree.

### `get_last: RBNode a -> Option a;`

Gets the last element (that is, the largest element) of the tree.

### `upsert_lt: [a: RBNodeElem] a -> (a -> a) -> (a -> a -> Bool) -> RBNode a -> RBNode a;`

`node.upsert_lt(x, less_than)` inserts or updates using `less_than` ordering.
If `node` does not contain an element equivalent to `x`, `x` is inserted.
If `node` already contains an element `y` equivalent to `x`,
ie. `!less_than(x,y) && !less_than(y,x)` is true,
then `y` is updated with `updater(y)`.

### `upsert: [a: LessThan, a: RBNodeElem] a -> (a -> a) -> RBNode a -> RBNode a;`

`node.upsert(x, updater)` inserts or updates using default `LessThan` ordering.
If `node` does not contain an element equivalent to `x`, `x` is inserted.
If `node` already contains an element `y` equivalent to `x`,
ie. `!(x < y) && !(y < x)` is true,
then `y` is updated with `updater(y)`.

### `insert_lt: [a: RBNodeElem] a -> (a -> a -> Bool) -> RBNode a -> RBNode a;`

`node.insert_lt(x, less_than)` inserts an element `x` using `less_than` ordering.
If `node` already contains an element `y` equivalent to `x`,
ie. `!less_than(x,y) && !less_than(y,x)` is true,
then `y` is replaced with `x`.

### `insert: [a: LessThan, a: RBNodeElem] a -> RBNode a -> RBNode a;`

`node.insert(x)` inserts an element `x` using default `LessThan` ordering.
If `node` already contains an element `y` equivalent to `x`,
ie. `!(x < y) && !(y < x)` is true,
then `y` is replaced with `x`.

### `remove: [a: LessThan, a: RBNodeElem] a -> RBNode a -> RBNode a;`

`node.remove(x)` removes any element `y` equivalent to `x`,
ie. `!(x < y) && !(y < x)` is true.

### `remove_lt: [a: RBNodeElem] a -> (a -> a -> Bool) -> RBNode a -> RBNode a;`

`node.remove_lt(x, less_than)` removes any element `y` equivalent to `x`,
ie. ie. `!less_than(x,y) && !less_than(y,x)` is true.

### `remove_range: [a: RBNodeElem] (a -> Bool) -> (a -> Bool) -> RBNode a -> RBNode a;`

`node.remove_range(lt_begin, lt_end)` removes all elements `elem`
where `!elem.lt_begin && elem.lt_end` is true.
NOTE: `lt_begin` and `lt_end` must meet following condition:
for all `x`, `x.lt_begin` is true then `x.lt_end` must be true.

### `to_iter: [a: RBNodeElem] RBNode a -> Iterator a;`

### `from_iter_lt: [a: RBNodeElem] (a -> a -> Bool) -> Iterator a -> RBNode a;`

### `from_iter: [a: LessThan, a: RBNodeElem] Iterator a -> RBNode a;`

### `impl [a: RBNodeElem, a: ToString] RBNode a: ToString`

