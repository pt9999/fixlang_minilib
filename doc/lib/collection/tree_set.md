# tree_set.fix

## module TreeSet

TreeSet is a set that manages elements in sorted order.

### namespace TreeSet

### type TreeSet

A type of set that manages elements in sorted order.

```
    type TreeSet a = unbox struct {
        root: RBNode a,
        less_than: a -> a -> Bool
    };
```
#### make: [a: TreeSetElem, a: LessThan] () -> TreeSet a;

`TreeSet::make()` creates an empty `TreeSet` using default `LessThan` ordering.

#### make_lt: [a: TreeSetElem] (a -> a -> Bool) -> TreeSet a;

`TreeSet::make_lt(less_than)` creates an empty `TreeSet` using specified ordering.

#### insert: [a: TreeSetElem] a -> TreeSet a -> TreeSet a;

Inserts an element into a TreeSet.
For example, `ts.insert(x)` inserts `x` into `ts`.

NOTE: If `ts` already contains an element `y` equivalent to `x`,
ie. `!less_than(x,y) && !less_than(y,x)` is true,
then `y` is replaced with `x`.

#### erase: [a: TreeSetElem] a -> TreeSet a -> TreeSet a;

Erases an element from a TreeSet.
For example, `ts.erase(x)` removes `x` from `ts`.

NOTE: If `ts` contains an element `y` equivalent to `x`,
ie. `!less_than(x,y) && !less_than(y,x)` is true,
then `y` is removed.

#### is_empty: [a: TreeSetElem] TreeSet a -> Bool;

Checks whether a TreeSet is empty.

#### get_size: TreeSet a -> I64;

Gets the number of elements.

#### contains: [a: TreeSetElem] a -> TreeSet a -> Bool;

Checks whether a TreeSet contains an element.

#### find_range: [a: TreeSetElem] a -> a -> TreeSet a -> Iterator a;

`ts.find_range(begin, end)` finds all elements `x`
where `!less_than(x, begin) && less_than(x, end)` is true.
In default `LessThan` ordering, that condition is same as `begin <= x && x < end`.

#### find_raw_range: [a: TreeSetElem] (a -> Bool) -> (a -> Bool) -> TreeSet a -> Iterator a;

`ts.find_raw_range(lt_begin, lt_end)` finds all elements `x`
where `!lt_begin(x) && lt_end(x)` is true.
NOTE: `lt_begin` and `lt_end` must meet following condition:
for all `x`, `x.lt_begin` is true then `x.lt_end` must be true.

#### to_iter: [a: TreeSetElem] TreeSet a -> Iterator a;

Converts a TreeSet into an iterator in sorted order.

#### from_iter_lt: [a: TreeSetElem] (a -> a -> Bool) -> Iterator a -> TreeSet a;

Converts an iterator into a TreeSet using specified ordering.

#### from_iter: [a: LessThan, a: TreeSetElem] Iterator a -> TreeSet a;

Converts an iterator into a TreeSet using default `LessThan` ordering.

#### intersect: [a : TreeSetElem] TreeSet k -> TreeSet k -> TreeSet k;

Calculates intersection of two TreeSets.

#### merge: [a : TreeSetElem] TreeSet k -> TreeSet k -> TreeSet k;

Calculates union of two TreeSets.

#### `impl [a: TreeSetElem] TreeSet a: ToString`

Converts a TreeSet into a String.

