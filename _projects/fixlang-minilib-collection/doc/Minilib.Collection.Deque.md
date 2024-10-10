# `module Minilib.Collection.Deque`

Deque (double-ended queue).
Deque can be used as a FIFO such as a message queue.
When used as a FIFO, the amortized costs of `push_back()` and
`pop_front()` are `O(1)`.

# Types and aliases

## `namespace Minilib.Collection.Deque`

### `type Deque a = unbox struct { ...fields... }`

A type that represents a double-ended queue.

#### field `front : Std::Array a`

#### field `back : Std::Array a`

# Traits and aliases

# Trait implementations

# Values

## `namespace Minilib.Collection.Deque::Deque`

### `@back : Minilib.Collection.Deque::Deque a -> Std::Array a`

Retrieves the field `back` from a value of `Deque`.

### `@front : Minilib.Collection.Deque::Deque a -> Std::Array a`

Retrieves the field `front` from a value of `Deque`.

### `_reverse_array : Std::Array a -> Std::Array a`

Reverses an array.

### `act_back : [f : Std::Functor] (Std::Array a -> f (Std::Array a)) -> Minilib.Collection.Deque::Deque a -> f (Minilib.Collection.Deque::Deque a)`

Updates a value of `Deque` by applying a functorial action to field `back`.

### `act_front : [f : Std::Functor] (Std::Array a -> f (Std::Array a)) -> Minilib.Collection.Deque::Deque a -> f (Minilib.Collection.Deque::Deque a)`

Updates a value of `Deque` by applying a functorial action to field `front`.

### `empty : Std::I64 -> Minilib.Collection.Deque::Deque a`

Creates an empty double-ended queue.

### `get_back : Minilib.Collection.Deque::Deque a -> Std::Option a`

Gets the back element of the queue.

### `get_front : Minilib.Collection.Deque::Deque a -> Std::Option a`

Gets the front element of the queue.

### `get_size : Minilib.Collection.Deque::Deque a -> Std::I64`

Gets the size of the queue.

### `is_empty : Minilib.Collection.Deque::Deque a -> Std::Bool`

Returns true iff the queue is empty.

### `mod_back : (Std::Array a -> Std::Array a) -> Minilib.Collection.Deque::Deque a -> Minilib.Collection.Deque::Deque a`

Updates a value of `Deque` by applying a function to field `back`.

### `mod_front : (Std::Array a -> Std::Array a) -> Minilib.Collection.Deque::Deque a -> Minilib.Collection.Deque::Deque a`

Updates a value of `Deque` by applying a function to field `front`.

### `pop_back : Minilib.Collection.Deque::Deque a -> Minilib.Collection.Deque::Deque a`

Pops an element from the back of the queue. If the queue is empty, it does nothing.

### `pop_front : Minilib.Collection.Deque::Deque a -> Minilib.Collection.Deque::Deque a`

Pops an element from the front of the queue. If the queue is empty, it does nothing.

### `push_back : a -> Minilib.Collection.Deque::Deque a -> Minilib.Collection.Deque::Deque a`

Pushes an element to the back of the queue.

### `push_front : a -> Minilib.Collection.Deque::Deque a -> Minilib.Collection.Deque::Deque a`

Pushes an element to the front of the queue.

### `set_back : Std::Array a -> Minilib.Collection.Deque::Deque a -> Minilib.Collection.Deque::Deque a`

Updates a value of `Deque` by setting field `back` to a specified one.

### `set_front : Std::Array a -> Minilib.Collection.Deque::Deque a -> Minilib.Collection.Deque::Deque a`

Updates a value of `Deque` by setting field `front` to a specified one.

### `to_iter : Minilib.Collection.Deque::Deque a -> Std::Iterator a`

Returns an iterator of elements.