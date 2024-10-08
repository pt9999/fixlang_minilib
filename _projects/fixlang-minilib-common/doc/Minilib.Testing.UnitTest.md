# `module Minilib.Testing.UnitTest`

Unit Test Framework

# Types and aliases

## `namespace Minilib.Testing.UnitTest`

### `type TestCase = Std::Lazy (Std::IO::IOFail (Std::I64, Std::I64))`

TestCase is a type that counts the number of successful and failed tests.

# Traits and aliases

# Trait implementations

# Values

## `namespace Minilib.Testing.UnitTest`

### `_TEST_VERBOSE : Std::Bool`

If _TEST_VERBOSE is false, only failed testcases will be reported.
If the environment variable `TEST_VERBOSE` is set to non-empty string, _TEST_VERBOSE becomes true.

### `assert_equal : [a : Std::Eq, a : Std::ToString] Std::String -> a -> a -> Std::IO::IOFail ()`

Verifies that two values are equal. If the values are different, the test will fail with the specified message.

### `assert_not_equal : [a : Std::Eq, a : Std::ToString] Std::String -> a -> a -> Std::IO::IOFail ()`

Verifies that two values are not equal. If the values are equal, the test will fail with the specified message.

### `assert_true : Std::String -> Std::Bool -> Std::IO::IOFail ()`

Verifies that the boolean value is true. If the boolean value is false, the test will fail with the specified message.

### `make_table_test : [a : Std::ToString] Std::String -> Std::Array a -> (a -> Std::IO::IOFail ()) -> () -> Std::IO::IOFail (Std::I64, Std::I64)`

Creates a set of test cases from parameters and a lazy `IOFail ()`.

### `make_test : Std::String -> (() -> Std::IO::IOFail ()) -> () -> Std::IO::IOFail (Std::I64, Std::I64)`

Creates a named test case from a lazy `IOFail ()`.

### `run_test_driver : Std::Array (() -> Std::IO::IOFail (Std::I64, Std::I64)) -> Std::IO ()`

Executes all test cases and prints the results (number of passes and number of failures).
Exit with exitcode=1 if any test failed or any error occured, exitcode=0 otherwise.

### `run_tests : Std::Array (() -> Std::IO::IOFail (Std::I64, Std::I64)) -> () -> Std::IO::IOFail (Std::I64, Std::I64)`

Executes all test cases and treat the results as one test case.

## `namespace Minilib.Testing.UnitTest::TestCase`

### `empty : () -> Std::IO::IOFail (Std::I64, Std::I64)`

A test case where the number of successes and number of failures are both equal to 0.
Can be used as a placeholder at the end of an array of test cases.