# clap.fix

## module Minilib.App.Clap

Command line argument parser.
Inspired by [`clap` crate of Rust](https://docs.rs/clap/3.2.0/clap/index.html).

### namespace ArgAction

### type ArgAction

The action taken when the argument is parsed.

```
    type ArgAction = unbox union {
        set: (),        // Sets next input to the single argument value.
        append: (),     // Appends next input to the array of argument values.
        set_true: (),   // Sets "true" as the single argument value.
        set_false: (),  // Sets "false" as the single argument value.
        help: (),       // Displays help for the command.
        version: ()     // Displays the version of the command.
    };
```
### type Arg

A structure that defines arguments.
Arguments can be either optional or positional arguments.
If either `short` or `long` is set, it becomes an optional argument.
Otherwise, it is a positional argument.

```
type Arg = unbox struct {
    id: String,             // A unique ID that identifies the argument.
    short: U8,              // A one-hypen option, eg. `-n`
    long: String,           // A two-hypen option, eg. `--count`
    required: Bool,         // Whether the argument is required or not.
    takes_value: Bool,      // Whether the argument takes some value.
    multiple_values: Bool,  // Whether the argument value(s) is singule or multiple.
    default_value: Option String,   // A default value of the argument.
    value_name: String,     // The name of the argument value which is displayed in help message.
    help: String,           // The help message of the argument.
    action: ArgAction       // The action taken when the argument is parsed.
};
```
### namespace Arg

#### new: String -> Arg;

Creates new argument.

#### short: U8 -> Arg -> Arg;

Sets `@short`.

#### long: String -> Arg -> Arg;

Sets `@long`.

#### required: Arg -> Arg;

Sets `@required` to true.

#### takes_value: Arg -> Arg;

Sets `@takes_value` to true, and `@action` to `set()`.

#### takes_multiple_values: Arg -> Arg;

Sets `@takes_value` to true, `@multiple_values` to true, and `@action` to `append()`.

#### default_value: String -> Arg -> Arg;

Sets `@default_value`.

#### value_name: String -> Arg -> Arg;

Sets `@value_name`.

#### help: String -> Arg -> Arg;

Sets `@help`.

#### `impl Arg: ToString`

### type Command

A structure representing a command (ie. application).

```
type Command = unbox struct {
    name: String,           // The name of the command.
    bin_name: String,       // The name of the executable binary of the command.
    display_name: String,   // The display name of the command.
    version: String,        // The version of the command.
    author: String,         // Author of the command.
    about: String,          // Description about the command.
    args: Array Arg,        // Argument definitions of the command.
    help_template: HelpTemplate,    // A help template of the command.
    version_template: HelpTemplate  // A version template of the command.
};
```
### namespace Command

#### new: String -> Command;

Creates a command structure by specifying the command name.

#### name: String -> Command -> Command;

Sets the name of the command.

#### bin_name: String -> Command -> Command;

Sets the name of the executable binary of the command.

#### display_name: String -> Command -> Command;

Sets the display name of the command.

#### version: String -> Command -> Command;

Sets the version of the command.

#### author: String -> Command -> Command;

Sets the author of the command.

#### about: String -> Command -> Command;

Sets the description about the command.

#### arg: Arg -> Command -> Command;

Add an argument definition to the command.

#### render_help: Command -> String;

Generates a help string based on the help template.

#### render_version: Command -> String;

Generates a version string based on the version template.

#### get_matches: Command -> IOFail ArgMatches;

Parse command line arguments based on `IO::get_args`.
If `--help` or `--version` is specified, the help string or version string will be returned as `throw`.

#### get_matches_from: Array String -> Command -> Result ErrMsg ArgMatches;

Parses command line arguments based on the specified input array.
If `--help` or `--version` is specified, the help string or version string will be returned as the error message.

### namespace ArgParser

---------------------------------
ArgParser
---------------------------------

### type ArgParser

```
    type ArgParser = unbox struct {
        command: Command,
        remaining_args: Iterator Arg,
        matches: ArgMatches,
        inputs: Iterator String,
        positional_only: Bool
    };
```
#### make: Array String -> Command -> ArgParser;

Creates an `ArgParser` based on the input array and command.

#### no_inputs: ArgParser -> Bool;

Returns True if there are no more inputs. Returns False if there is more input.

#### advance: ArgParser -> Result ErrMsg (String, ArgParser);

Proceed to next input.

#### get_input: ArgParser -> Result ErrMsg String;

Get the current input.

#### parse_args : ArgParser -> Result ErrMsg ArgParser;

Parse the actual command line argument array and set the value of `Arg`.

#### set_value: Arg -> String -> ArgParser -> ArgParser;

Set the value to `arg`.

#### append_value: Arg -> String -> ArgParser -> ArgParser;

Adds a value to the array of values in `arg`.

#### check_required_args_present: ArgParser -> Result ErrMsg ArgParser;

Check whether the required argument values are set. Reports an error if the value is not set.

#### set_default_if_not_present: ArgParser -> Result ErrMsg ArgParser;

If no value is set for the argument, set the default value.

### type ArgMatches

A structure representing the result of parsing command line arguments.

```
type ArgMatches = unbox struct {
    map: HashMap String (Array String)
};
```
### namespace ArgMatches

#### empty: ArgMatches;

An empty `ArgMatches` structure.

#### get_many: String -> ArgMatches -> Option (Array String);

Gets the array of argument values with the specified ID.

#### get_one: String -> ArgMatches -> Option String;

Gets the value of the argument with the specified ID.

### type HelpTemplate

```
type HelpTemplate = unbox struct { 
    data: String 
};
```
### namespace HelpTemplate

#### new: String -> HelpTemplate;

#### format: Command -> HelpTemplate -> String;

