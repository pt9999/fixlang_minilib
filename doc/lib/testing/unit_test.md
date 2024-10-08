# Module Minilib.Testing.UnitTest (unit_test.fix)

Unit Test Framework

### `type TestCase`

TestCase is a type that counts the number of successful and failed tests.

```
type TestCase = Lazy (IOFail (I64, I64));
```
## `namespace TestCase`

### `empty: TestCase;`

A test case where the number of successes and number of failures are both equal to 0.
Can be used as a placeholder at the end of an array of test cases.

### `run_test_driver: Array TestCase -> IO ();`

Executes all test cases and prints the results (number of passes and number of failures).
Exit with exitcode=1 if any test failed or any error occured, exitcode=0 otherwise.

### `run_tests: Array (TestCase) -> TestCase;`

Executes all test cases and treat the results as one test case.

### `make_test: String -> Lazy (IOFail ()) -> TestCase;`

Creates a named test case from a lazy `IOFail ()`.

### `make_table_test: [a: ToString] String -> Array a -> (a -> IOFail ()) -> TestCase;`

Creates a set of test cases from parameters and a lazy `IOFail ()`.

### `assert_true : String -> Bool -> IOFail ();`

Verifies that the boolean value is true. If the boolean value is false, the test will fail with the specified message.

### `assert_equal : [a: Eq, a: ToString] String -> a -> a -> IOFail ();`

Verifies that two values are equal. If the values are different, the test will fail with the specified message.

### `assert_not_equal : [a: Eq, a: ToString] String -> a -> a -> IOFail ();`

Verifies that two values are not equal. If the values are equal, the test will fail with the specified message.

