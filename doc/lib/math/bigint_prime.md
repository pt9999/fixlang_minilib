# bigint_prime.fix

## module Minilib.Math.BigIntPrime

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


### type PrimeGen

Prime generator

```
type PrimeGen = unbox struct {
    rand_var: Var Random,
    task_pool_var: Var TaskPool,
    progress: Bool
};
```
### namespace PrimeGen

#### make: Random -> Bool -> IO PrimeGen;

Creates a prime generator.

#### probable_prime: I64 -> PrimeGen -> IO BigInt;

`prime_gen.probable_prime(bit_length)` returns a probable prime number with specified bit length.

#### next_probable_prime: BigInt -> PrimeGen -> IO BigInt;

Returns a probable prime number greater than or equal to `n`.

#### generate_bigint:  I64 -> PrimeGen -> IO BigInt;

Generates random BigInt `r` of specified bit length.

#### generate_bigint_range: BigInt -> BigInt -> PrimeGen -> IO BigInt;

Generates random BigInt `r` such that `begin <= r && r < end`.

#### pow_by_U64: BigInt -> U64 -> BigInt;

Calculates `a^n`.

#### check_for_small_primes: BigInt -> Bool;

Performes divisibility check against small primes.

#### fermat_base2: BigInt -> Bool;

Performes base-2 Fermat primality test.
Returns true if `2^(n-1) == 1 mod n`.

#### miller_rabin: BigInt -> PrimeGen -> IO Bool;

Performs Miller-Rabin primality test.
Returns true if `n` is probably prime.
Probability of false prime is less than or equal to `2^-100`.
see: https://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test

#### solovay_strassen: BigInt -> PrimeGen -> IO Bool;

Performs Solovay–Strassen primality test.
see: https://en.wikipedia.org/wiki/Solovay%E2%80%93Strassen_primality_test

#### modpow: BigInt -> BigInt -> BigInt -> BigInt;

Calculates `a^n mod m`.

#### gcd: BigInt -> BigInt -> BigInt;

`gcd(m,n)` returns the greatest common divisor of `abs(m)` and `abs(n)`.

#### jacobi_symbol: BigInt -> BigInt -> I64;

Calculates Jacobi symbol `(m/n)`.
see: https://en.wikipedia.org/wiki/Jacobi_symbol

