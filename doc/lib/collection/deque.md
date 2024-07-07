# deque.fix

## module Minilib.Collection.Deque

Deque (double-ended queue).
Deque can be used as a FIFO such as a message queue.
When used as a FIFO, the amortized costs of `push_back()` and
`pop_front()` are `O(1)`.

### type Deque

A type that represents a double-ended queue.

```
type Deque a = unbox struct {
    front: Array a,     // reversed array
    back: Array a
};
```
### namespace Deque

#### empty: I64 -> Deque a;

Creates an empty double-ended queue.

#### get_size: Deque a -> I64;

Gets the size of the queue.

#### is_empty: Deque a -> Bool;

Returns true iff the queue is empty.

#### get_front: Deque a -> Option a;

Gets the front element of the queue.

#### get_back: Deque a -> Option a;

Gets the back element of the queue.

#### push_front: a -> Deque a -> Deque a;

Pushes an element to the front of the queue.

#### push_front_many: Array a -> Deque a -> Deque a;

Pushes all elements of an array to the front of the queue.
The order of elements are preserved, ie. the first element of the array becomes the front element of the queue.

#### push_back: a -> Deque a -> Deque a;

Pushes an element to the back of the queue.

#### push_back_many: Array a -> Deque a -> Deque a;

Pushes all elements of an array to the back of the queue.
The order of elements are preserved, ie. the last element of the array becomes the back element of the queue.

#### pop_front: Deque a -> Deque a;

Pops an element from the front of the queue. If the queue is empty, it does nothing.

#### pop_front_many: I64 -> Deque a -> (Deque a, Array a);

`q.pop_front_many(max_count)` pops elements at most `max_count` times from the front of the queue.
The order of returned elements are preserved, ie. the first element was at the front of the queue before this function is called.

#### pop_back: Deque a -> Deque a;

Pops an element from the back of the queue. If the queue is empty, it does nothing.

#### pop_back_many: I64 -> Deque a -> (Deque a, Array a);

`q.pop_back_many(max_count)` pops elements at most `max_count` times from the back of the queue.
The order of returned elements are preserved, ie. the last element was at the back of the queue before this function is called.

#### to_iter: Deque a -> Iterator a;

Returns an iterator of elements.

