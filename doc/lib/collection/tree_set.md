# tree_set.fix

## module TreeSet

a set that preserves the order of elements

### namespace TreeSet

### type TreeSet

A type of set that preserves the order of its elements.

```
    type TreeSet a = unbox struct {
        root: RBNode a,
        less_than: a -> a -> Bool
    };
```
#### make: [a: TreeSetElem, a: LessThan] () -> TreeSet a;

`TreeSet::make()` creates an empty `TreeSet` using default `LessThan` ordering.

#### make_lt: [a: TreeSetElem] (a -> a -> Bool) -> TreeSet a;

`TreeSet::make_lt(less_than)` creates an empty `TreeSet` using `less_than` ordering.

#### insert: [a: TreeSetElem] a -> TreeSet a -> TreeSet a;

`ts.insert(x)` inserts `x` to `ts`.
If `ts` already contains an element `y` equivalent to `x`,
ie. `!less_than(x,y) && !less_than(y,x)` is true,
then `y` is replaced with `x`.

#### erase: [a: TreeSetElem] a -> TreeSet a -> TreeSet a;

`ts.erase(x)` removes an element `y` equivalent to `x`,
ie. `!less_than(x,y) && !less_than(y,x)` is true.

#### is_empty: [a: TreeSetElem] TreeSet a -> Bool;

#### contains: [a: TreeSetElem] a -> TreeSet a -> Bool;

#### to_iter: [a: TreeSetElem] TreeSet a -> Iterator a;

#### from_iter_lt: [a: TreeSetElem] (a -> a -> Bool) -> Iterator a -> TreeSet a;

#### from_iter: [a: LessThan, a: TreeSetElem] Iterator a -> TreeSet a;

#### intersect: [a : TreeSetElem] TreeSet k -> TreeSet k -> TreeSet k;

#### merge: [a : TreeSetElem] TreeSet k -> TreeSet k -> TreeSet k;

#### `impl [a: TreeSetElem] TreeSet a: ToString`

