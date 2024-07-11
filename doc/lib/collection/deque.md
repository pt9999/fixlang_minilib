# Module Minilib.Collection.Deque (deque.fix)

Deque (double-ended queue).
Deque can be used as a FIFO such as a message queue.
When used as a FIFO, the amortized costs of `push_back()` and
`pop_front()` are `O(1)`.

### `type Deque`

A type that represents a double-ended queue.

```
type Deque a = unbox struct {
    front: Array a,     // reversed array
    back: Array a
};
```
## `namespace Deque`

### `empty: I64 -> Deque a;`

Creates an empty double-ended queue.

### `get_size: Deque a -> I64;`

Gets the size of the queue.

### `is_empty: Deque a -> Bool;`

Returns true iff the queue is empty.

### `get_front: Deque a -> Option a;`

Gets the front element of the queue.

### `get_back: Deque a -> Option a;`

Gets the back element of the queue.

### `push_front: a -> Deque a -> Deque a;`

Pushes an element to the front of the queue.

### `push_back: a -> Deque a -> Deque a;`

Pushes an element to the back of the queue.

### `pop_front: Deque a -> Deque a;`

Pops an element from the front of the queue. If the queue is empty, it does nothing.

### `pop_back: Deque a -> Deque a;`

Pops an element from the back of the queue. If the queue is empty, it does nothing.

### `to_iter: Deque a -> Iterator a;`

Returns an iterator of elements.

