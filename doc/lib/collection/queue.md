# queue.fix

## module Minilib.Collection.Queue

Simple queue (FIFO).

### type Queue

A type that represents a queue.

```
type Queue a = unbox struct {
    iter: Iterator a
};
```
### namespace Queue

#### empty: Queue a;

Creates an empty queue.

#### is_empty: Queue a -> Bool;

Checks whether the queue is empty.

#### push: a -> Queue a -> Queue a;

Pushes an element to the back of the queue.

#### pop: Queue a -> Option (a, Queue a);

Pops an element from the front of the queue. If the queue is empty, `none()` is returned.

