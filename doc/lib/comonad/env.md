# Module Minilib.Comonad.Env (env.fix)

Env comonad. (a.k.a CoReader comonad)

For details, see [blog post: The Reader and Writer Monads and Comonads](https://www.olivierverdier.com/posts/2014/12/31/reader-writer-monad-comonad/).

### `type EnvT`

Env comonad wraps a pair of an environment and a value.
`e` is a type of an environment.
`w` is a type of an underlyind comonad.
`a` is a type of a value.

```
type [w: * -> *] EnvT e w a = unbox struct {
    env: e,
    value: w a
};
```
### `type Env`

```
type Env e a = EnvT e IdentityC a;
```
## `namespace Env`

### `env_t: [w: Comonad] e -> w a -> EnvT e w a;`

Creates a generic env comonad from an enviroment and a value.

### `env: e -> a -> Env e a;`

Creates an env comonad from an enviroment and a value.

### `get_env: [w: Comonad] EnvT e w a -> e;`

Gets the envirionment from an env comonad.

### `get_value: [w: Comonad] EnvT e w a -> a;`

Gets the value from an env comonad.

### `to_tuple: [w: Comonad] EnvT e w a -> (e, a);`

Converts a env comonad to a pair of an enviroment and a value.

### `impl [w: Comonad] EnvT e w: Functor`

### `impl [w: Comonad] EnvT e w: Comonad`

