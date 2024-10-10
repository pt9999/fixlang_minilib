# `module Minilib.Math.BigIntPrime`

Generates probable prime numbers of arbitrary-precision integer.

Sample code:
```
let random = Random::init_by_seed(123_U64);
let prime_gen = *PrimeGen::make(random, true);
let n = *prime_gen.probable_prime(256);
```

PrimeGen uses a task pool internally, so it can run faster with multi-core CPUs.

Depending on the value of the random number, generating a probable prime number can take some time.
For example, generating a 1024-bit probable prime number takes approximately 15 seconds
with AMD Ryzen 7 2700 (8 cores / 16 threads), or 35 seconds with MediaTek mt8183 (4 cores / 8 threads).

NOTE: Due to multi-threading, the generated prime number is non-deterministic
      even if the random number generator state is the same.

# Types and aliases

## `namespace Minilib.Math.BigIntPrime`

### `type PrimeGen = unbox struct { ...fields... }`

Prime generator

#### field `rand_var : AsyncTask::Var::Var Random::Random`

#### field `task_pool_var : AsyncTask::Var::Var Minilib.Thread.TaskPool::TaskPool`

#### field `progress : Std::Bool`

# Traits and aliases

# Trait implementations

# Values

## `namespace Minilib.Math.BigIntPrime`

### `gcd : Minilib.Math.BigInt::BigInt -> Minilib.Math.BigInt::BigInt -> Minilib.Math.BigInt::BigInt`

`gcd(m,n)` returns the greatest common divisor of `abs(m)` and `abs(n)`.

### `jacobi_symbol : Minilib.Math.BigInt::BigInt -> Minilib.Math.BigInt::BigInt -> Std::I64`

Calculates Jacobi symbol `(m/n)`.
see: https://en.wikipedia.org/wiki/Jacobi_symbol

### `modpow : Minilib.Math.BigInt::BigInt -> Minilib.Math.BigInt::BigInt -> Minilib.Math.BigInt::BigInt -> Minilib.Math.BigInt::BigInt`

Calculates `a^n mod m`.

## `namespace Minilib.Math.BigIntPrime::PrimeGen`

### `@progress : Minilib.Math.BigIntPrime::PrimeGen -> Std::Bool`

Retrieves the field `progress` from a value of `PrimeGen`.

### `@rand_var : Minilib.Math.BigIntPrime::PrimeGen -> AsyncTask::Var::Var Random::Random`

Retrieves the field `rand_var` from a value of `PrimeGen`.

### `@task_pool_var : Minilib.Math.BigIntPrime::PrimeGen -> AsyncTask::Var::Var Minilib.Thread.TaskPool::TaskPool`

Retrieves the field `task_pool_var` from a value of `PrimeGen`.

### `_find_first_or : a -> (a -> Std::Bool) -> Std::Iterator (Std::IO a) -> Minilib.Math.BigIntPrime::PrimeGen -> Std::IO a`

`prime_gen._find_first_or(default, f, iter)` executes each computation in `iter`
in parallel, then finds the first result that meets the specified condition.
Returns the default value if no one meets the condition.
This function uses the task pool for each computation.

### `_generate_u64 : Minilib.Math.BigIntPrime::PrimeGen -> Std::IO Std::U64`

### `_is_weak_probable_prime : Minilib.Math.BigInt::BigInt -> Minilib.Math.BigIntPrime::PrimeGen -> Std::IO (Std::Option Minilib.Math.BigInt::BigInt)`

Returns true iff `n` is a weak probable prime number.

### `_next_weak_probable_prime : Minilib.Math.BigInt::BigInt -> Minilib.Math.BigIntPrime::PrimeGen -> Std::IO Minilib.Math.BigInt::BigInt`

Returns a weak probable prime number greater than or equal to `n`.

### `_progress : Std::String -> Minilib.Math.BigIntPrime::PrimeGen -> Std::IO ()`

Prints a progress message if `@progress` is true.

### `act_progress : [f : Std::Functor] (Std::Bool -> f Std::Bool) -> Minilib.Math.BigIntPrime::PrimeGen -> f Minilib.Math.BigIntPrime::PrimeGen`

Updates a value of `PrimeGen` by applying a functorial action to field `progress`.

### `act_rand_var : [f : Std::Functor] (AsyncTask::Var::Var Random::Random -> f (AsyncTask::Var::Var Random::Random)) -> Minilib.Math.BigIntPrime::PrimeGen -> f Minilib.Math.BigIntPrime::PrimeGen`

Updates a value of `PrimeGen` by applying a functorial action to field `rand_var`.

### `act_task_pool_var : [f : Std::Functor] (AsyncTask::Var::Var Minilib.Thread.TaskPool::TaskPool -> f (AsyncTask::Var::Var Minilib.Thread.TaskPool::TaskPool)) -> Minilib.Math.BigIntPrime::PrimeGen -> f Minilib.Math.BigIntPrime::PrimeGen`

Updates a value of `PrimeGen` by applying a functorial action to field `task_pool_var`.

### `check_for_small_primes : Minilib.Math.BigInt::BigInt -> Std::Bool`

Performes divisibility check against small primes.

### `fermat_base2 : Minilib.Math.BigInt::BigInt -> Std::Bool`

Performes base-2 Fermat primality test.
Returns true if `2^(n-1) == 1 mod n`.

### `generate_bigint : Std::I64 -> Minilib.Math.BigIntPrime::PrimeGen -> Std::IO Minilib.Math.BigInt::BigInt`

Generates random BigInt `r` of specified bit length.

### `generate_bigint_range : Minilib.Math.BigInt::BigInt -> Minilib.Math.BigInt::BigInt -> Minilib.Math.BigIntPrime::PrimeGen -> Std::IO Minilib.Math.BigInt::BigInt`

Generates random BigInt `r` such that `begin <= r && r < end`.

### `make : Random::Random -> Std::Bool -> Std::IO Minilib.Math.BigIntPrime::PrimeGen`

Creates a prime generator.

### `miller_rabin : Minilib.Math.BigInt::BigInt -> Minilib.Math.BigIntPrime::PrimeGen -> Std::IO Std::Bool`

Performs Miller-Rabin primality test.
Returns true if `n` is probably prime.
Probability of false prime is less than or equal to `2^-100`.
see: https://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test

### `mod_progress : (Std::Bool -> Std::Bool) -> Minilib.Math.BigIntPrime::PrimeGen -> Minilib.Math.BigIntPrime::PrimeGen`

Updates a value of `PrimeGen` by applying a function to field `progress`.

### `mod_rand_var : (AsyncTask::Var::Var Random::Random -> AsyncTask::Var::Var Random::Random) -> Minilib.Math.BigIntPrime::PrimeGen -> Minilib.Math.BigIntPrime::PrimeGen`

Updates a value of `PrimeGen` by applying a function to field `rand_var`.

### `mod_task_pool_var : (AsyncTask::Var::Var Minilib.Thread.TaskPool::TaskPool -> AsyncTask::Var::Var Minilib.Thread.TaskPool::TaskPool) -> Minilib.Math.BigIntPrime::PrimeGen -> Minilib.Math.BigIntPrime::PrimeGen`

Updates a value of `PrimeGen` by applying a function to field `task_pool_var`.

### `next_probable_prime : Minilib.Math.BigInt::BigInt -> Minilib.Math.BigIntPrime::PrimeGen -> Std::IO Minilib.Math.BigInt::BigInt`

Returns a probable prime number greater than or equal to `n`.

### `pow_by_U64 : Minilib.Math.BigInt::BigInt -> Std::U64 -> Minilib.Math.BigInt::BigInt`

Calculates `a^n`.

### `probable_prime : Std::I64 -> Minilib.Math.BigIntPrime::PrimeGen -> Std::IO Minilib.Math.BigInt::BigInt`

`prime_gen.probable_prime(bit_length)` returns a probable prime number with specified bit length.

### `set_progress : Std::Bool -> Minilib.Math.BigIntPrime::PrimeGen -> Minilib.Math.BigIntPrime::PrimeGen`

Updates a value of `PrimeGen` by setting field `progress` to a specified one.

### `set_rand_var : AsyncTask::Var::Var Random::Random -> Minilib.Math.BigIntPrime::PrimeGen -> Minilib.Math.BigIntPrime::PrimeGen`

Updates a value of `PrimeGen` by setting field `rand_var` to a specified one.

### `set_task_pool_var : AsyncTask::Var::Var Minilib.Thread.TaskPool::TaskPool -> Minilib.Math.BigIntPrime::PrimeGen -> Minilib.Math.BigIntPrime::PrimeGen`

Updates a value of `PrimeGen` by setting field `task_pool_var` to a specified one.

### `solovay_strassen : Minilib.Math.BigInt::BigInt -> Minilib.Math.BigIntPrime::PrimeGen -> Std::IO Std::Bool`

Performs Solovay–Strassen primality test.
see: https://en.wikipedia.org/wiki/Solovay%E2%80%93Strassen_primality_test