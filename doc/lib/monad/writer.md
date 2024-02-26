# writer.fix

## module Minilib.Monad.Writer

Writer monad. (a.k.a Env, CoReader comonad)

For details, see [blog post: The Reader and Writer Monads and Comonads](https://www.olivierverdier.com/posts/2014/12/31/reader-writer-monad-comonad/).

### type Writer

Writer monad wraps a pair of an environment and a value.
`e` is a type of an environment.
`a` is a type of a value.

```
type Writer e a = unbox struct {
    data: (e, a)
};
```
### namespace Writer

#### writer: e -> a -> Writer e a;

Creates a writer monad from an enviroment and a value.

#### run_writer: Writer e a -> (e, a);

Runs a writer monad to get an enviroment and a value.

#### write: [e: Monoid] e -> Writer e ();

Creates a writer monad that appends to the environment.

#### get_env: Writer e a -> e;

Gets the envirionment from a writer monad.

#### get_value: Writer e a -> a;

Gets the value from a writer monad.

### type Env

Env comonad. this is same as a writer monad.

```
type Env e a = Writer e a;
```
### namespace Env

#### env: e -> a -> Env e a;

Creates a env comonad from an enviroment and a value.

#### to_tuple: Env e a -> (e, a);

Converts a env comonad to a pair of an enviroment and a value.

#### `impl Writer e: Functor`

#### `impl [e: Monoid] Writer e: Monad`

#### `impl Writer e: Comonad`

