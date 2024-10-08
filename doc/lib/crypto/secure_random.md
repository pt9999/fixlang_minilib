# Module Minilib.Crypto.SecureRandom (secure_random.fix)

Secure random number generator.

Currently only Linux is supported, because it uses `/dev/urandom` as a secure random source.

### `type SecureRandom`

```
type SecureRandom = unbox struct {
    data: Destructor IOHandle
};
```
## `namespace SecureRandom`

### `make: IOFail SecureRandom;`

Creates a SecureRandom instance.

### `generate_bytes: I64 -> SecureRandom -> IOFail (SecureRandom, Array U8);`

Generates a random byte array with specified size.

