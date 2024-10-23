# `module Minilib.Collection.RBTree`

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

# Types and aliases

## `namespace Minilib.Collection.RBTree::RBNode`

### `type RBNode a = box union { ...variants... }`

A type of red-black tree node.

#### variant `empty : ()`

#### variant `red : (Minilib.Collection.RBTree::RBNode::RBNode a, a, Minilib.Collection.RBTree::RBNode::RBNode a)`

#### variant `black : (Minilib.Collection.RBTree::RBNode::RBNode a, a, Minilib.Collection.RBTree::RBNode::RBNode a)`

# Traits and aliases

# Trait implementations

### `impl [a : Minilib.Collection.RBTree::RBNode::RBNodeElem, a : Std::ToString] Minilib.Collection.RBTree::RBNode::RBNode a : Std::ToString`

# Values

## `namespace Minilib.Collection.RBTree::RBNode`

### `_Debug : Std::Bool`

Debug flag. If set to true, a lot of debug messages will be printed and various validations will be done.

### `_balance : Minilib.Collection.RBTree::RBNode::RBNode a -> Minilib.Collection.RBTree::RBNode::RBNode a`

### `_debug_assert_level_diff : [a : Minilib.Collection.RBTree::RBNode::RBNodeElem] Std::String -> Std::String -> Minilib.Collection.RBTree::RBNode::RBNode a -> Std::String -> Minilib.Collection.RBTree::RBNode::RBNode a -> Std::I64 -> (() -> b) -> b`

### `_debug_eprintln_lazy : (() -> Std::String) -> ()`

Prints to stderr if the debug flag is set.

### `_fast_append : Std::Iterator a -> Std::Iterator a -> Std::Iterator a`

Same as `Iterator::append` but a little fast.

### `_less_than : [a : Std::LessThan, a : Minilib.Collection.RBTree::RBNode::RBNodeElem] a -> a -> Std::Bool`

Default less_than function using `LessThan` trait.

### `_remove_fix_left : [a : Minilib.Collection.RBTree::RBNode::RBNodeElem] (Std::Bool, Minilib.Collection.RBTree::RBNode::RBNode a) -> (Std::Bool, Minilib.Collection.RBTree::RBNode::RBNode a)`

Called when `node.left.level == node.right.level - 1`.
Returns `(active, fixed)` where `fixed` is the fixed node,
and `active` is true iff `fixed.level = node.level - 1`.

### `_remove_fix_left_inner : [a : Minilib.Collection.RBTree::RBNode::RBNodeElem] (Std::Bool, Minilib.Collection.RBTree::RBNode::RBNode a) -> (Std::Bool, Minilib.Collection.RBTree::RBNode::RBNode a)`

### `_remove_fix_right : [a : Minilib.Collection.RBTree::RBNode::RBNodeElem] (Std::Bool, Minilib.Collection.RBTree::RBNode::RBNode a) -> (Std::Bool, Minilib.Collection.RBTree::RBNode::RBNode a)`

Called when `node.right.level == node.level.level - 1`.
Returns `(active, fixed)` where `fixed` is the fixed node,
and `active` is true iff `fixed.level = node.level - 1`.

### `_remove_fix_right_inner : [a : Minilib.Collection.RBTree::RBNode::RBNodeElem] (Std::Bool, Minilib.Collection.RBTree::RBNode::RBNode a) -> (Std::Bool, Minilib.Collection.RBTree::RBNode::RBNode a)`

### `_remove_max : [a : Minilib.Collection.RBTree::RBNode::RBNodeElem] Minilib.Collection.RBTree::RBNode::RBNode a -> (Std::Bool, Minilib.Collection.RBTree::RBNode::RBNode a, a)`

`node._remove_max` removes an maximum element.
Returns `(active, removed, max)` where `removed` is the node after removal,
`max` is the maximum element,
and `active` is true iff `removed.level == node.level - 1`.

### `_remove_min : [a : Minilib.Collection.RBTree::RBNode::RBNodeElem] Minilib.Collection.RBTree::RBNode::RBNode a -> (Std::Bool, Minilib.Collection.RBTree::RBNode::RBNode a, a)`

`node._remove_min` removes an minimum element.
Returns `(active, removed, min)` where `removed` is the node after removal,
`min` is the minimum element,
and `active` is true iff `removed.level == node.level - 1`.

### `_try_remove_range : [a : Minilib.Collection.RBTree::RBNode::RBNodeElem] (a -> Std::Bool) -> (a -> Std::Bool) -> Minilib.Collection.RBTree::RBNode::RBNode a -> Std::Option (Std::Bool, Minilib.Collection.RBTree::RBNode::RBNode a)`

`node._try_remove_range(lt_begin, lt_end)` tries to remove single element `elem`
where `!elem.lt_begin && elem.lt_end` is true.
Even if there are several elements that holds the condition, only one of them
are removed.
Returns `some((active, removed))` if removal is succeeded
where `removed` is the node after removal,
and `active` is true iff `removed.level == node.level - 1`.
Returns `none()` if removal is failed.

### `_try_remove_range_inner : [a : Minilib.Collection.RBTree::RBNode::RBNodeElem] (a -> Std::Bool) -> (a -> Std::Bool) -> Minilib.Collection.RBTree::RBNode::RBNode a -> Std::Option (Std::Bool, Minilib.Collection.RBTree::RBNode::RBNode a)`

### `_upsert_inner : a -> (a -> a) -> (a -> a -> Std::Bool) -> Minilib.Collection.RBTree::RBNode::RBNode a -> Minilib.Collection.RBTree::RBNode::RBNode a`

### `find : a -> (a -> a -> Std::Bool) -> Minilib.Collection.RBTree::RBNode::RBNode a -> Std::Option a`

`node.find(x, less_than)` finds an element `elem` that is equivalent to `x`,
ie. `!less_than(elem, x) && !less_than(x, elem)` is true.

### `find_range : (a -> Std::Bool) -> (a -> Std::Bool) -> Minilib.Collection.RBTree::RBNode::RBNode a -> Std::Iterator a`

`node.find_range(lt_begin, lt_end)` finds all elements `elem`
such that `!elem.lt_begin && elem.lt_end` is true.
NOTE: `lt_begin` and `lt_end` must meet following condition:
for all `x`, `x.lt_begin` is true then `x.lt_end` must be true.

### `find_range_descending : (a -> Std::Bool) -> (a -> Std::Bool) -> Minilib.Collection.RBTree::RBNode::RBNode a -> Std::Iterator a`

`node.find_range(lt_begin, lt_end)` finds all elements `elem`
such that `!elem.lt_begin && elem.lt_end` is true, in descending order.
NOTE: `lt_begin` and `lt_end` must meet following condition:
for all `x`, `x.lt_begin` is true then `x.lt_end` must be true.

### `from_iter : [a : Std::LessThan, a : Minilib.Collection.RBTree::RBNode::RBNodeElem] Std::Iterator a -> Minilib.Collection.RBTree::RBNode::RBNode a`

### `from_iter_lt : [a : Minilib.Collection.RBTree::RBNode::RBNodeElem] (a -> a -> Std::Bool) -> Std::Iterator a -> Minilib.Collection.RBTree::RBNode::RBNode a`

### `get_color : Minilib.Collection.RBTree::RBNode::RBNode a -> (Minilib.Collection.RBTree::RBNode::RBNode a, a, Minilib.Collection.RBTree::RBNode::RBNode a) -> Minilib.Collection.RBTree::RBNode::RBNode a`

### `get_first : Minilib.Collection.RBTree::RBNode::RBNode a -> Std::Option a`

Gets the first element (that is, the smallest element) of the tree.

### `get_last : Minilib.Collection.RBTree::RBNode::RBNode a -> Std::Option a`

Gets the last element (that is, the largest element) of the tree.

### `get_left : Minilib.Collection.RBTree::RBNode::RBNode a -> Minilib.Collection.RBTree::RBNode::RBNode a`

### `get_right : Minilib.Collection.RBTree::RBNode::RBNode a -> Minilib.Collection.RBTree::RBNode::RBNode a`

### `get_size : Minilib.Collection.RBTree::RBNode::RBNode a -> Std::I64`

Gets the number of elements.

### `get_triplet : Minilib.Collection.RBTree::RBNode::RBNode a -> (Minilib.Collection.RBTree::RBNode::RBNode a, a, Minilib.Collection.RBTree::RBNode::RBNode a)`

If the node is black or red, `node.get_triplet` returns a triplet `(left, elem, right)`.
If the node is empty, it will abort.

### `insert : [a : Std::LessThan, a : Minilib.Collection.RBTree::RBNode::RBNodeElem] a -> Minilib.Collection.RBTree::RBNode::RBNode a -> Minilib.Collection.RBTree::RBNode::RBNode a`

`node.insert(x)` inserts an element `x` using default `LessThan` ordering.
If `node` already contains an element `y` equivalent to `x`,
ie. `!(x < y) && !(y < x)` is true,
then `y` is replaced with `x`.

### `insert_lt : [a : Minilib.Collection.RBTree::RBNode::RBNodeElem] a -> (a -> a -> Std::Bool) -> Minilib.Collection.RBTree::RBNode::RBNode a -> Minilib.Collection.RBTree::RBNode::RBNode a`

`node.insert_lt(x, less_than)` inserts an element `x` using `less_than` ordering.
If `node` already contains an element `y` equivalent to `x`,
ie. `!less_than(x,y) && !less_than(y,x)` is true,
then `y` is replaced with `x`.

### `level : [a : Minilib.Collection.RBTree::RBNode::RBNodeElem] Minilib.Collection.RBTree::RBNode::RBNode a -> Std::I64`

Returns the level of this node (ie. the number of black nodes from this node to any leaf).
Panicks when the left and right nodes have different black count.

### `level_nonvalidate : [a : Minilib.Collection.RBTree::RBNode::RBNodeElem] Minilib.Collection.RBTree::RBNode::RBNode a -> Std::I64`

Returns the level of this node (ie. the number of black nodes from this node to any leaf).
This function does not validate, so an unbalanced node can be specified.

### `remove : [a : Std::LessThan, a : Minilib.Collection.RBTree::RBNode::RBNodeElem] a -> Minilib.Collection.RBTree::RBNode::RBNode a -> Minilib.Collection.RBTree::RBNode::RBNode a`

`node.remove(x)` removes any element `y` equivalent to `x`,
ie. `!(x < y) && !(y < x)` is true.

### `remove_lt : [a : Minilib.Collection.RBTree::RBNode::RBNodeElem] a -> (a -> a -> Std::Bool) -> Minilib.Collection.RBTree::RBNode::RBNode a -> Minilib.Collection.RBTree::RBNode::RBNode a`

`node.remove_lt(x, less_than)` removes any element `y` equivalent to `x`,
ie. ie. `!less_than(x,y) && !less_than(y,x)` is true.

### `remove_range : [a : Minilib.Collection.RBTree::RBNode::RBNodeElem] (a -> Std::Bool) -> (a -> Std::Bool) -> Minilib.Collection.RBTree::RBNode::RBNode a -> Minilib.Collection.RBTree::RBNode::RBNode a`

`node.remove_range(lt_begin, lt_end)` removes all elements `elem`
where `!elem.lt_begin && elem.lt_end` is true.
NOTE: `lt_begin` and `lt_end` must meet following condition:
for all `x`, `x.lt_begin` is true then `x.lt_end` must be true.

### `set_color : ((Minilib.Collection.RBTree::RBNode::RBNode a, a, Minilib.Collection.RBTree::RBNode::RBNode a) -> Minilib.Collection.RBTree::RBNode::RBNode a) -> Minilib.Collection.RBTree::RBNode::RBNode a -> Minilib.Collection.RBTree::RBNode::RBNode a`

### `set_triplet : (Minilib.Collection.RBTree::RBNode::RBNode a, a, Minilib.Collection.RBTree::RBNode::RBNode a) -> Minilib.Collection.RBTree::RBNode::RBNode a -> Minilib.Collection.RBTree::RBNode::RBNode a`

### `to_iter : [a : Minilib.Collection.RBTree::RBNode::RBNodeElem] Minilib.Collection.RBTree::RBNode::RBNode a -> Std::Iterator a`

### `upsert : [a : Std::LessThan, a : Minilib.Collection.RBTree::RBNode::RBNodeElem] a -> (a -> a) -> Minilib.Collection.RBTree::RBNode::RBNode a -> Minilib.Collection.RBTree::RBNode::RBNode a`

`node.upsert(x, updater)` inserts or updates using default `LessThan` ordering.
If `node` does not contain an element equivalent to `x`, `x` is inserted.
If `node` already contains an element `y` equivalent to `x`,
ie. `!(x < y) && !(y < x)` is true,
then `y` is updated with `updater(y)`.

### `upsert_lt : [a : Minilib.Collection.RBTree::RBNode::RBNodeElem] a -> (a -> a) -> (a -> a -> Std::Bool) -> Minilib.Collection.RBTree::RBNode::RBNode a -> Minilib.Collection.RBTree::RBNode::RBNode a`

`node.upsert_lt(x, less_than)` inserts or updates using `less_than` ordering.
If `node` does not contain an element equivalent to `x`, `x` is inserted.
If `node` already contains an element `y` equivalent to `x`,
ie. `!less_than(x,y) && !less_than(y,x)` is true,
then `y` is updated with `updater(y)`.

### `validate : [a : Minilib.Collection.RBTree::RBNode::RBNodeElem] (a -> a -> Std::Bool) -> Minilib.Collection.RBTree::RBNode::RBNode a -> (Std::I64, Std::Option a, Std::Option a)`

Validates that:
- the left and right nodes have same black count
- children of a red node is not red
- max of left node < elem
- elem < min of right node
Returns `(level, min, max)`.
Panicks if validation failed.

## `namespace Minilib.Collection.RBTree::RBNode::RBNode`

### `as_black : Minilib.Collection.RBTree::RBNode::RBNode a -> (Minilib.Collection.RBTree::RBNode::RBNode a, a, Minilib.Collection.RBTree::RBNode::RBNode a)`

Unwraps a union value of `RBNode` as the variant `black`.
If the value is not the variant `black`, this function aborts the program.

### `as_empty : Minilib.Collection.RBTree::RBNode::RBNode a -> ()`

Unwraps a union value of `RBNode` as the variant `empty`.
If the value is not the variant `empty`, this function aborts the program.

### `as_red : Minilib.Collection.RBTree::RBNode::RBNode a -> (Minilib.Collection.RBTree::RBNode::RBNode a, a, Minilib.Collection.RBTree::RBNode::RBNode a)`

Unwraps a union value of `RBNode` as the variant `red`.
If the value is not the variant `red`, this function aborts the program.

### `black : (Minilib.Collection.RBTree::RBNode::RBNode a, a, Minilib.Collection.RBTree::RBNode::RBNode a) -> Minilib.Collection.RBTree::RBNode::RBNode a`

Constructs a value of union `RBNode` taking the variant `black`.

### `empty : () -> Minilib.Collection.RBTree::RBNode::RBNode a`

Constructs a value of union `RBNode` taking the variant `empty`.

### `is_black : Minilib.Collection.RBTree::RBNode::RBNode a -> Std::Bool`

Checks if a union value of `RBNode` is the variant `black`.

### `is_empty : Minilib.Collection.RBTree::RBNode::RBNode a -> Std::Bool`

Checks if a union value of `RBNode` is the variant `empty`.

### `is_red : Minilib.Collection.RBTree::RBNode::RBNode a -> Std::Bool`

Checks if a union value of `RBNode` is the variant `red`.

### `mod_black : ((Minilib.Collection.RBTree::RBNode::RBNode a, a, Minilib.Collection.RBTree::RBNode::RBNode a) -> (Minilib.Collection.RBTree::RBNode::RBNode a, a, Minilib.Collection.RBTree::RBNode::RBNode a)) -> Minilib.Collection.RBTree::RBNode::RBNode a -> Minilib.Collection.RBTree::RBNode::RBNode a`

Updates a value of union `RBNode` by applying a function if it is the variant `black`, or doing nothing otherwise.

### `mod_empty : (() -> ()) -> Minilib.Collection.RBTree::RBNode::RBNode a -> Minilib.Collection.RBTree::RBNode::RBNode a`

Updates a value of union `RBNode` by applying a function if it is the variant `empty`, or doing nothing otherwise.

### `mod_red : ((Minilib.Collection.RBTree::RBNode::RBNode a, a, Minilib.Collection.RBTree::RBNode::RBNode a) -> (Minilib.Collection.RBTree::RBNode::RBNode a, a, Minilib.Collection.RBTree::RBNode::RBNode a)) -> Minilib.Collection.RBTree::RBNode::RBNode a -> Minilib.Collection.RBTree::RBNode::RBNode a`

Updates a value of union `RBNode` by applying a function if it is the variant `red`, or doing nothing otherwise.

### `red : (Minilib.Collection.RBTree::RBNode::RBNode a, a, Minilib.Collection.RBTree::RBNode::RBNode a) -> Minilib.Collection.RBTree::RBNode::RBNode a`

Constructs a value of union `RBNode` taking the variant `red`.