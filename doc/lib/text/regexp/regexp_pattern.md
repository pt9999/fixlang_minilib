# regexp_pattern.fix

## module RegExpPattern

Character class and Pattern parser

### type CharClass

Type of a character class.

```
type CharClass = unbox struct {
    // A label that describes this class (for debugging only)
    label: String,
    // A member function that judges whether a character is contained in this class or not
    f: U8 -> Bool
};
```
### namespace CharClass

#### empty: CharClass;

An empty character class.

#### make: String -> (U8 -> Bool) -> CharClass;

Creates a character class from a label and a member function.

#### contains: U8 -> CharClass -> Bool;

Returns true if the character is a member of the class.

#### singleton: U8 -> CharClass;

Creates a character class whose only member is the specified character.

#### range: U8 -> U8 -> CharClass;

Creates a character class whose members are characters from start to end.

#### consists_of: String -> CharClass;

Creates a character class whose members are characters in the specified string.

#### negate: CharClass -> CharClass;

Negate the member function of a character class.

#### union: CharClass -> CharClass -> CharClass;

Creates union of two character classes.

#### add: U8 -> CharClass -> CharClass;

Adds a character to the character class.

#### to_table: CharClass -> CharClass;

For optimization, creates a lookup table of same members, and returns a character class
using that table.

#### cls_dot: CharClass;

A character class of `.`. (any character except newlines)

#### cls_digit: CharClass;

A character class of `\d`. (digits)

#### cls_non_digit: CharClass;

A character class of `\D`. (non-digits)

#### cls_word_char: CharClass;

A character class of `\w`. (ie. `[A-Za-z0-9_]`)

#### cls_non_word_char: CharClass;

A character class of `\W`. (ie. `[^A-Za-z0-9_]`)

#### cls_whitespace: CharClass;

A character class of `\s`. (whitespaces)

#### cls_non_whitespace: CharClass;

A character class of `\S`. (non-whitespaces)

#### `impl CharClass: ToString`

Converts a character class to a string.

### type PAssertion

Type of an assertion for regular expressions, such as `^`, `$`.

```
type PAssertion = unbox union {
    pa_begin: (),       // beginning of line, ie. '^'
    pa_end: ()          // end of line,       ie. '$'
};
```
#### `impl PAssertion: ToString`

Converts an assertion to a string.

### type Pattern

Type of a parsed regular expression.

```
type Pattern = box union {
    // Character class pattern, eg. `a`, `[a-z]`, `\d` etc.
    pclass: CharClass,
    // Assertion pattern, eg. `^`, `$`
    passert: PAssertion,
    // Sequence of patterns, eg. `XYZ`
    psequence: Array Pattern,
    // Either pattern, eg. `X|Y`
    peither: (Pattern, Pattern),
    // Quantified pattern, eg. `X?`, `X*`, `X+`, `X{n,m}`
    pquant: (Pattern, /*min_count:*/ I64, /*max_count:*/ I64),
    // Grouped pattern, eg. `(X)`
    pgroup: (/* group_number:*/ I64, Pattern)
};
```
#### `impl Pattern: ToString`

Converts a pattern to a string.

### namespace Pattern

#### parse: String -> Result ErrMsg Pattern;

Parses a pattern from specified string.

#### parse_pattern: Parser Pattern;

Parses a pattern from the stream.

