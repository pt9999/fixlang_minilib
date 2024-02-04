# bigint_prime.fix

## module Minilib.Math.BigIntPrime

Generates probable prime numbers of arbitrary-precision integer.

Use `probable_prime(256, random)` to generate a probable prime number of 256-bit.

Depending on the value of the random number, generating a probable prime number can take quite a while.
For example, generating a 1024-bit probable prime number may take about 90 seconds.


### namespace BigIntPrime

#### probable_prime: I64 -> Random -> (BigInt, Random);

`probable_prime(bit_length, random)` returns a probable prime number with specified bit length.

#### next_probable_prime: BigInt -> Random -> (BigInt, Random);

`next_probable_prime(n, random)` returns a probable prime number greater than or equal to `n`.

#### generate_bigint:  I64 -> Random -> (BigInt, Random);

Generates random BigInt `r` of specified bit length.

#### generate_bigint_range: BigInt -> BigInt -> Random -> (BigInt, Random);

Generates random BigInt `r` such that `begin <= r && r < end`.

#### pow_by_U64: BigInt -> U64 -> BigInt;

Calculates `a^n`.

#### modpow: BigInt -> BigInt -> BigInt -> BigInt;

Calculates `a^n mod m`.

#### gcd: BigInt -> BigInt -> BigInt;

`gcd(m,n)` returns the greatest common divisor of `abs(m)` and `abs(n)`.

#### jacobi_symbol: BigInt -> BigInt -> I64;

Calculates Jacobi symbol `(m/n)`.
see: https://en.wikipedia.org/wiki/Jacobi_symbol

#### check_for_small_primes: BigInt -> Bool;

Performes divisibility check against small primes.

#### fermat_base2: BigInt -> Bool;

Performes base-2 Fermat primality test.
Returns true if `2^(n-1) == 1 mod n`.

#### miller_rabin: BigInt -> Random -> (Bool, Random);

Performs Miller-Rabin primality test.
Returns true if `n` is probably prime.
Probability of false prime is less than or equal to `2^-100`.
see: https://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test

#### solovay_strassen: BigInt -> Random -> (Bool, Random);

Performs Solovay–Strassen primality test.
see: https://en.wikipedia.org/wiki/Solovay%E2%80%93Strassen_primality_test

