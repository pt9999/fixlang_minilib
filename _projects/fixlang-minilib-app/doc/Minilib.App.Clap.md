# `module Minilib.App.Clap`

Command line argument parser.
Inspired by [`clap` crate of Rust](https://docs.rs/clap/3.2.0/clap/index.html).

# Types and aliases

## `namespace Minilib.App.Clap`

### `type Arg = unbox struct { ...fields... }`

A structure that defines arguments.
Arguments can be either optional or positional arguments.
If either `short` or `long` is set, it becomes an optional argument.
Otherwise, it is a positional argument.

#### field `id : Std::String`

#### field `short : Std::U8`

#### field `long : Std::String`

#### field `required : Std::Bool`

#### field `takes_value : Std::Bool`

#### field `multiple_values : Std::Bool`

#### field `default_value : Std::Option Std::String`

#### field `value_name : Std::String`

#### field `help : Std::String`

#### field `action : Minilib.App.Clap::ArgAction::ArgAction`

### `type ArgMatches = box struct { ...fields... }`

A structure representing the result of parsing command line arguments.

#### field `subcommand : Std::Option (Std::String, Minilib.App.Clap::ArgMatches)`

#### field `map : HashMap::HashMap Std::String (Std::Array Std::String)`

### `type Command = box struct { ...fields... }`

A structure representing a command (ie. application).

#### field `name : Std::String`

#### field `bin_name : Std::String`

#### field `display_name : Std::String`

#### field `subcommand_path : Std::String`

#### field `version : Std::String`

#### field `author : Std::String`

#### field `about : Std::String`

#### field `subcommands : Std::Array Minilib.App.Clap::Command`

#### field `args : Std::Array Minilib.App.Clap::Arg`

#### field `help_template : Minilib.App.Clap::HelpTemplate`

#### field `version_template : Minilib.App.Clap::HelpTemplate`

### `type HelpTemplate = unbox struct { ...fields... }`

#### field `data : Std::String`

## `namespace Minilib.App.Clap::ArgAction`

### `type ArgAction = unbox union { ...variants... }`

The action taken when the argument is parsed.

#### variant `set : ()`

#### variant `append : ()`

#### variant `set_true : ()`

#### variant `set_false : ()`

#### variant `increment : ()`

#### variant `help : ()`

#### variant `version : ()`

## `namespace Minilib.App.Clap::ArgParser`

### `type ArgParser = unbox struct { ...fields... }`

#### field `command : Minilib.App.Clap::Command`

#### field `remaining_args : Std::Iterator Minilib.App.Clap::Arg`

#### field `matches : Minilib.App.Clap::ArgMatches`

#### field `inputs : Std::Iterator Std::String`

#### field `positional_only : Std::Bool`

# Traits and aliases

# Trait implementations

### `impl Minilib.App.Clap::Arg : Std::ToString`

# Values

## `namespace Minilib.App.Clap::Arg`

### `@action : Minilib.App.Clap::Arg -> Minilib.App.Clap::ArgAction::ArgAction`

Retrieves the field `action` from a value of `Arg`.

### `@default_value : Minilib.App.Clap::Arg -> Std::Option Std::String`

Retrieves the field `default_value` from a value of `Arg`.

### `@help : Minilib.App.Clap::Arg -> Std::String`

Retrieves the field `help` from a value of `Arg`.

### `@id : Minilib.App.Clap::Arg -> Std::String`

Retrieves the field `id` from a value of `Arg`.

### `@long : Minilib.App.Clap::Arg -> Std::String`

Retrieves the field `long` from a value of `Arg`.

### `@multiple_values : Minilib.App.Clap::Arg -> Std::Bool`

Retrieves the field `multiple_values` from a value of `Arg`.

### `@required : Minilib.App.Clap::Arg -> Std::Bool`

Retrieves the field `required` from a value of `Arg`.

### `@short : Minilib.App.Clap::Arg -> Std::U8`

Retrieves the field `short` from a value of `Arg`.

### `@takes_value : Minilib.App.Clap::Arg -> Std::Bool`

Retrieves the field `takes_value` from a value of `Arg`.

### `@value_name : Minilib.App.Clap::Arg -> Std::String`

Retrieves the field `value_name` from a value of `Arg`.

### `_is_option : Minilib.App.Clap::Arg -> Std::Bool`

### `_is_positional : Minilib.App.Clap::Arg -> Std::Bool`

### `_long_to_string : Minilib.App.Clap::Arg -> Std::String`

### `_option_matches : Std::String -> Minilib.App.Clap::Arg -> Std::Bool`

### `_positional_to_string : Minilib.App.Clap::Arg -> Std::String`

### `_short_to_string : Minilib.App.Clap::Arg -> Std::String`

### `act_action : [f : Std::Functor] (Minilib.App.Clap::ArgAction::ArgAction -> f Minilib.App.Clap::ArgAction::ArgAction) -> Minilib.App.Clap::Arg -> f Minilib.App.Clap::Arg`

Updates a value of `Arg` by applying a functorial action to field `action`.

### `act_default_value : [f : Std::Functor] (Std::Option Std::String -> f (Std::Option Std::String)) -> Minilib.App.Clap::Arg -> f Minilib.App.Clap::Arg`

Updates a value of `Arg` by applying a functorial action to field `default_value`.

### `act_help : [f : Std::Functor] (Std::String -> f Std::String) -> Minilib.App.Clap::Arg -> f Minilib.App.Clap::Arg`

Updates a value of `Arg` by applying a functorial action to field `help`.

### `act_id : [f : Std::Functor] (Std::String -> f Std::String) -> Minilib.App.Clap::Arg -> f Minilib.App.Clap::Arg`

Updates a value of `Arg` by applying a functorial action to field `id`.

### `act_long : [f : Std::Functor] (Std::String -> f Std::String) -> Minilib.App.Clap::Arg -> f Minilib.App.Clap::Arg`

Updates a value of `Arg` by applying a functorial action to field `long`.

### `act_multiple_values : [f : Std::Functor] (Std::Bool -> f Std::Bool) -> Minilib.App.Clap::Arg -> f Minilib.App.Clap::Arg`

Updates a value of `Arg` by applying a functorial action to field `multiple_values`.

### `act_required : [f : Std::Functor] (Std::Bool -> f Std::Bool) -> Minilib.App.Clap::Arg -> f Minilib.App.Clap::Arg`

Updates a value of `Arg` by applying a functorial action to field `required`.

### `act_short : [f : Std::Functor] (Std::U8 -> f Std::U8) -> Minilib.App.Clap::Arg -> f Minilib.App.Clap::Arg`

Updates a value of `Arg` by applying a functorial action to field `short`.

### `act_takes_value : [f : Std::Functor] (Std::Bool -> f Std::Bool) -> Minilib.App.Clap::Arg -> f Minilib.App.Clap::Arg`

Updates a value of `Arg` by applying a functorial action to field `takes_value`.

### `act_value_name : [f : Std::Functor] (Std::String -> f Std::String) -> Minilib.App.Clap::Arg -> f Minilib.App.Clap::Arg`

Updates a value of `Arg` by applying a functorial action to field `value_name`.

### `default_value : Std::String -> Minilib.App.Clap::Arg -> Minilib.App.Clap::Arg`

Sets `@default_value`.

### `help : Std::String -> Minilib.App.Clap::Arg -> Minilib.App.Clap::Arg`

Sets `@help`.

### `long : Std::String -> Minilib.App.Clap::Arg -> Minilib.App.Clap::Arg`

Sets `@long`.

### `mod_action : (Minilib.App.Clap::ArgAction::ArgAction -> Minilib.App.Clap::ArgAction::ArgAction) -> Minilib.App.Clap::Arg -> Minilib.App.Clap::Arg`

Updates a value of `Arg` by applying a function to field `action`.

### `mod_default_value : (Std::Option Std::String -> Std::Option Std::String) -> Minilib.App.Clap::Arg -> Minilib.App.Clap::Arg`

Updates a value of `Arg` by applying a function to field `default_value`.

### `mod_help : (Std::String -> Std::String) -> Minilib.App.Clap::Arg -> Minilib.App.Clap::Arg`

Updates a value of `Arg` by applying a function to field `help`.

### `mod_id : (Std::String -> Std::String) -> Minilib.App.Clap::Arg -> Minilib.App.Clap::Arg`

Updates a value of `Arg` by applying a function to field `id`.

### `mod_long : (Std::String -> Std::String) -> Minilib.App.Clap::Arg -> Minilib.App.Clap::Arg`

Updates a value of `Arg` by applying a function to field `long`.

### `mod_multiple_values : (Std::Bool -> Std::Bool) -> Minilib.App.Clap::Arg -> Minilib.App.Clap::Arg`

Updates a value of `Arg` by applying a function to field `multiple_values`.

### `mod_required : (Std::Bool -> Std::Bool) -> Minilib.App.Clap::Arg -> Minilib.App.Clap::Arg`

Updates a value of `Arg` by applying a function to field `required`.

### `mod_short : (Std::U8 -> Std::U8) -> Minilib.App.Clap::Arg -> Minilib.App.Clap::Arg`

Updates a value of `Arg` by applying a function to field `short`.

### `mod_takes_value : (Std::Bool -> Std::Bool) -> Minilib.App.Clap::Arg -> Minilib.App.Clap::Arg`

Updates a value of `Arg` by applying a function to field `takes_value`.

### `mod_value_name : (Std::String -> Std::String) -> Minilib.App.Clap::Arg -> Minilib.App.Clap::Arg`

Updates a value of `Arg` by applying a function to field `value_name`.

### `new : Std::String -> Minilib.App.Clap::Arg`

Creates new argument.

### `required : Minilib.App.Clap::Arg -> Minilib.App.Clap::Arg`

Sets `@required` to true.

### `set_action : Minilib.App.Clap::ArgAction::ArgAction -> Minilib.App.Clap::Arg -> Minilib.App.Clap::Arg`

Updates a value of `Arg` by setting field `action` to a specified one.

### `set_default_value : Std::Option Std::String -> Minilib.App.Clap::Arg -> Minilib.App.Clap::Arg`

Updates a value of `Arg` by setting field `default_value` to a specified one.

### `set_help : Std::String -> Minilib.App.Clap::Arg -> Minilib.App.Clap::Arg`

Updates a value of `Arg` by setting field `help` to a specified one.

### `set_id : Std::String -> Minilib.App.Clap::Arg -> Minilib.App.Clap::Arg`

Updates a value of `Arg` by setting field `id` to a specified one.

### `set_long : Std::String -> Minilib.App.Clap::Arg -> Minilib.App.Clap::Arg`

Updates a value of `Arg` by setting field `long` to a specified one.

### `set_multiple_values : Std::Bool -> Minilib.App.Clap::Arg -> Minilib.App.Clap::Arg`

Updates a value of `Arg` by setting field `multiple_values` to a specified one.

### `set_required : Std::Bool -> Minilib.App.Clap::Arg -> Minilib.App.Clap::Arg`

Updates a value of `Arg` by setting field `required` to a specified one.

### `set_short : Std::U8 -> Minilib.App.Clap::Arg -> Minilib.App.Clap::Arg`

Updates a value of `Arg` by setting field `short` to a specified one.

### `set_takes_value : Std::Bool -> Minilib.App.Clap::Arg -> Minilib.App.Clap::Arg`

Updates a value of `Arg` by setting field `takes_value` to a specified one.

### `set_value_name : Std::String -> Minilib.App.Clap::Arg -> Minilib.App.Clap::Arg`

Updates a value of `Arg` by setting field `value_name` to a specified one.

### `short : Std::U8 -> Minilib.App.Clap::Arg -> Minilib.App.Clap::Arg`

Sets `@short`.

### `takes_multiple_values : Minilib.App.Clap::Arg -> Minilib.App.Clap::Arg`

Sets `@takes_value` to true, `@multiple_values` to true, and `@action` to `append()`.

### `takes_value : Minilib.App.Clap::Arg -> Minilib.App.Clap::Arg`

Sets `@takes_value` to true, and `@action` to `set()`.

### `value_name : Std::String -> Minilib.App.Clap::Arg -> Minilib.App.Clap::Arg`

Sets `@value_name`.

## `namespace Minilib.App.Clap::ArgAction::ArgAction`

### `append : () -> Minilib.App.Clap::ArgAction::ArgAction`

Constructs a value of union `ArgAction` taking the variant `append`.

### `as_append : Minilib.App.Clap::ArgAction::ArgAction -> ()`

Unwraps a union value of `ArgAction` as the variant `append`.
If the value is not the variant `append`, this function aborts the program.

### `as_help : Minilib.App.Clap::ArgAction::ArgAction -> ()`

Unwraps a union value of `ArgAction` as the variant `help`.
If the value is not the variant `help`, this function aborts the program.

### `as_increment : Minilib.App.Clap::ArgAction::ArgAction -> ()`

Unwraps a union value of `ArgAction` as the variant `increment`.
If the value is not the variant `increment`, this function aborts the program.

### `as_set : Minilib.App.Clap::ArgAction::ArgAction -> ()`

Unwraps a union value of `ArgAction` as the variant `set`.
If the value is not the variant `set`, this function aborts the program.

### `as_set_false : Minilib.App.Clap::ArgAction::ArgAction -> ()`

Unwraps a union value of `ArgAction` as the variant `set_false`.
If the value is not the variant `set_false`, this function aborts the program.

### `as_set_true : Minilib.App.Clap::ArgAction::ArgAction -> ()`

Unwraps a union value of `ArgAction` as the variant `set_true`.
If the value is not the variant `set_true`, this function aborts the program.

### `as_version : Minilib.App.Clap::ArgAction::ArgAction -> ()`

Unwraps a union value of `ArgAction` as the variant `version`.
If the value is not the variant `version`, this function aborts the program.

### `help : () -> Minilib.App.Clap::ArgAction::ArgAction`

Constructs a value of union `ArgAction` taking the variant `help`.

### `increment : () -> Minilib.App.Clap::ArgAction::ArgAction`

Constructs a value of union `ArgAction` taking the variant `increment`.

### `is_append : Minilib.App.Clap::ArgAction::ArgAction -> Std::Bool`

Checks if a union value of `ArgAction` is the variant `append`.

### `is_help : Minilib.App.Clap::ArgAction::ArgAction -> Std::Bool`

Checks if a union value of `ArgAction` is the variant `help`.

### `is_increment : Minilib.App.Clap::ArgAction::ArgAction -> Std::Bool`

Checks if a union value of `ArgAction` is the variant `increment`.

### `is_set : Minilib.App.Clap::ArgAction::ArgAction -> Std::Bool`

Checks if a union value of `ArgAction` is the variant `set`.

### `is_set_false : Minilib.App.Clap::ArgAction::ArgAction -> Std::Bool`

Checks if a union value of `ArgAction` is the variant `set_false`.

### `is_set_true : Minilib.App.Clap::ArgAction::ArgAction -> Std::Bool`

Checks if a union value of `ArgAction` is the variant `set_true`.

### `is_version : Minilib.App.Clap::ArgAction::ArgAction -> Std::Bool`

Checks if a union value of `ArgAction` is the variant `version`.

### `mod_append : (() -> ()) -> Minilib.App.Clap::ArgAction::ArgAction -> Minilib.App.Clap::ArgAction::ArgAction`

Updates a value of union `ArgAction` by applying a function if it is the variant `append`, or doing nothing otherwise.

### `mod_help : (() -> ()) -> Minilib.App.Clap::ArgAction::ArgAction -> Minilib.App.Clap::ArgAction::ArgAction`

Updates a value of union `ArgAction` by applying a function if it is the variant `help`, or doing nothing otherwise.

### `mod_increment : (() -> ()) -> Minilib.App.Clap::ArgAction::ArgAction -> Minilib.App.Clap::ArgAction::ArgAction`

Updates a value of union `ArgAction` by applying a function if it is the variant `increment`, or doing nothing otherwise.

### `mod_set : (() -> ()) -> Minilib.App.Clap::ArgAction::ArgAction -> Minilib.App.Clap::ArgAction::ArgAction`

Updates a value of union `ArgAction` by applying a function if it is the variant `set`, or doing nothing otherwise.

### `mod_set_false : (() -> ()) -> Minilib.App.Clap::ArgAction::ArgAction -> Minilib.App.Clap::ArgAction::ArgAction`

Updates a value of union `ArgAction` by applying a function if it is the variant `set_false`, or doing nothing otherwise.

### `mod_set_true : (() -> ()) -> Minilib.App.Clap::ArgAction::ArgAction -> Minilib.App.Clap::ArgAction::ArgAction`

Updates a value of union `ArgAction` by applying a function if it is the variant `set_true`, or doing nothing otherwise.

### `mod_version : (() -> ()) -> Minilib.App.Clap::ArgAction::ArgAction -> Minilib.App.Clap::ArgAction::ArgAction`

Updates a value of union `ArgAction` by applying a function if it is the variant `version`, or doing nothing otherwise.

### `set : () -> Minilib.App.Clap::ArgAction::ArgAction`

Constructs a value of union `ArgAction` taking the variant `set`.

### `set_false : () -> Minilib.App.Clap::ArgAction::ArgAction`

Constructs a value of union `ArgAction` taking the variant `set_false`.

### `set_true : () -> Minilib.App.Clap::ArgAction::ArgAction`

Constructs a value of union `ArgAction` taking the variant `set_true`.

### `version : () -> Minilib.App.Clap::ArgAction::ArgAction`

Constructs a value of union `ArgAction` taking the variant `version`.

## `namespace Minilib.App.Clap::ArgMatches`

### `@map : Minilib.App.Clap::ArgMatches -> HashMap::HashMap Std::String (Std::Array Std::String)`

Retrieves the field `map` from a value of `ArgMatches`.

### `@subcommand : Minilib.App.Clap::ArgMatches -> Std::Option (Std::String, Minilib.App.Clap::ArgMatches)`

Retrieves the field `subcommand` from a value of `ArgMatches`.

### `_mod_values : Std::String -> (Std::Array Std::String -> Std::Array Std::String) -> Minilib.App.Clap::ArgMatches -> Minilib.App.Clap::ArgMatches`

### `_set_values : Std::String -> Std::Array Std::String -> Minilib.App.Clap::ArgMatches -> Minilib.App.Clap::ArgMatches`

### `act_map : [f : Std::Functor] (HashMap::HashMap Std::String (Std::Array Std::String) -> f (HashMap::HashMap Std::String (Std::Array Std::String))) -> Minilib.App.Clap::ArgMatches -> f Minilib.App.Clap::ArgMatches`

Updates a value of `ArgMatches` by applying a functorial action to field `map`.

### `act_subcommand : [f : Std::Functor] (Std::Option (Std::String, Minilib.App.Clap::ArgMatches) -> f (Std::Option (Std::String, Minilib.App.Clap::ArgMatches))) -> Minilib.App.Clap::ArgMatches -> f Minilib.App.Clap::ArgMatches`

Updates a value of `ArgMatches` by applying a functorial action to field `subcommand`.

### `empty : Minilib.App.Clap::ArgMatches`

An empty `ArgMatches` structure.

### `get_many : Std::String -> Minilib.App.Clap::ArgMatches -> Std::Option (Std::Array Std::String)`

Gets the array of argument values with the specified ID.

### `get_one : Std::String -> Minilib.App.Clap::ArgMatches -> Std::Option Std::String`

Gets the value of the argument with the specified ID.

### `mod_map : (HashMap::HashMap Std::String (Std::Array Std::String) -> HashMap::HashMap Std::String (Std::Array Std::String)) -> Minilib.App.Clap::ArgMatches -> Minilib.App.Clap::ArgMatches`

Updates a value of `ArgMatches` by applying a function to field `map`.

### `mod_subcommand : (Std::Option (Std::String, Minilib.App.Clap::ArgMatches) -> Std::Option (Std::String, Minilib.App.Clap::ArgMatches)) -> Minilib.App.Clap::ArgMatches -> Minilib.App.Clap::ArgMatches`

Updates a value of `ArgMatches` by applying a function to field `subcommand`.

### `set_map : HashMap::HashMap Std::String (Std::Array Std::String) -> Minilib.App.Clap::ArgMatches -> Minilib.App.Clap::ArgMatches`

Updates a value of `ArgMatches` by setting field `map` to a specified one.

### `set_subcommand : Std::Option (Std::String, Minilib.App.Clap::ArgMatches) -> Minilib.App.Clap::ArgMatches -> Minilib.App.Clap::ArgMatches`

Updates a value of `ArgMatches` by setting field `subcommand` to a specified one.

### `subcommand : Minilib.App.Clap::ArgMatches -> Std::Option (Std::String, Minilib.App.Clap::ArgMatches)`

## `namespace Minilib.App.Clap::ArgParser`

### `_increment_value : Minilib.App.Clap::Arg -> Minilib.App.Clap::ArgParser::ArgParser -> Std::Result Std::String Minilib.App.Clap::ArgParser::ArgParser`

Increments the value as an integer.

### `_perform_action : Minilib.App.Clap::Arg -> Minilib.App.Clap::ArgParser::ArgParser -> Std::Result Std::String Minilib.App.Clap::ArgParser::ArgParser`

Performs the action set in `arg`.

### `_process_option_arg : Minilib.App.Clap::ArgParser::ArgParser -> Std::Result Std::String Minilib.App.Clap::ArgParser::ArgParser`

Treats the current input as an optional argument.

### `_process_positional_arg : Minilib.App.Clap::ArgParser::ArgParser -> Std::Result Std::String Minilib.App.Clap::ArgParser::ArgParser`

Treats the current input as a positional argument.

### `_remove_arg : Minilib.App.Clap::Arg -> Minilib.App.Clap::ArgParser::ArgParser -> Minilib.App.Clap::ArgParser::ArgParser`

Remove `arg` from the remaining args.

### `_set_or_append_value : Minilib.App.Clap::Arg -> Minilib.App.Clap::ArgParser::ArgParser -> Std::Result Std::String Minilib.App.Clap::ArgParser::ArgParser`

Takes the current input as a value and performs a `set` or `append` action.

### `advance : Minilib.App.Clap::ArgParser::ArgParser -> Std::Result Std::String (Std::String, Minilib.App.Clap::ArgParser::ArgParser)`

Proceed to next input.

### `append_value : Minilib.App.Clap::Arg -> Std::String -> Minilib.App.Clap::ArgParser::ArgParser -> Minilib.App.Clap::ArgParser::ArgParser`

Adds a value to the array of values in `arg`.

### `check_required_args_present : Minilib.App.Clap::ArgParser::ArgParser -> Std::Result Std::String Minilib.App.Clap::ArgParser::ArgParser`

Check whether the required argument values are set. Reports an error if the value is not set.

### `get_input : Minilib.App.Clap::ArgParser::ArgParser -> Std::Result Std::String Std::String`

Get the current input.

### `make : Std::Array Std::String -> Minilib.App.Clap::Command -> Minilib.App.Clap::ArgParser::ArgParser`

Creates an `ArgParser` based on the input array and command.

### `no_inputs : Minilib.App.Clap::ArgParser::ArgParser -> Std::Bool`

Returns True if there are no more inputs. Returns False if there is more input.

### `parse_args : Minilib.App.Clap::ArgParser::ArgParser -> Std::Result Std::String Minilib.App.Clap::ArgParser::ArgParser`

Parse the actual command line argument array and set the value of `Arg`.

### `set_default_if_not_present : Minilib.App.Clap::ArgParser::ArgParser -> Std::Result Std::String Minilib.App.Clap::ArgParser::ArgParser`

If no value is set for the argument, set the default value.

### `set_value : Minilib.App.Clap::Arg -> Std::String -> Minilib.App.Clap::ArgParser::ArgParser -> Minilib.App.Clap::ArgParser::ArgParser`

Set the value to `arg`.

## `namespace Minilib.App.Clap::ArgParser::ArgParser`

### `@command : Minilib.App.Clap::ArgParser::ArgParser -> Minilib.App.Clap::Command`

Retrieves the field `command` from a value of `ArgParser`.

### `@inputs : Minilib.App.Clap::ArgParser::ArgParser -> Std::Iterator Std::String`

Retrieves the field `inputs` from a value of `ArgParser`.

### `@matches : Minilib.App.Clap::ArgParser::ArgParser -> Minilib.App.Clap::ArgMatches`

Retrieves the field `matches` from a value of `ArgParser`.

### `@positional_only : Minilib.App.Clap::ArgParser::ArgParser -> Std::Bool`

Retrieves the field `positional_only` from a value of `ArgParser`.

### `@remaining_args : Minilib.App.Clap::ArgParser::ArgParser -> Std::Iterator Minilib.App.Clap::Arg`

Retrieves the field `remaining_args` from a value of `ArgParser`.

### `act_command : [f : Std::Functor] (Minilib.App.Clap::Command -> f Minilib.App.Clap::Command) -> Minilib.App.Clap::ArgParser::ArgParser -> f Minilib.App.Clap::ArgParser::ArgParser`

Updates a value of `ArgParser` by applying a functorial action to field `command`.

### `act_inputs : [f : Std::Functor] (Std::Iterator Std::String -> f (Std::Iterator Std::String)) -> Minilib.App.Clap::ArgParser::ArgParser -> f Minilib.App.Clap::ArgParser::ArgParser`

Updates a value of `ArgParser` by applying a functorial action to field `inputs`.

### `act_matches : [f : Std::Functor] (Minilib.App.Clap::ArgMatches -> f Minilib.App.Clap::ArgMatches) -> Minilib.App.Clap::ArgParser::ArgParser -> f Minilib.App.Clap::ArgParser::ArgParser`

Updates a value of `ArgParser` by applying a functorial action to field `matches`.

### `act_positional_only : [f : Std::Functor] (Std::Bool -> f Std::Bool) -> Minilib.App.Clap::ArgParser::ArgParser -> f Minilib.App.Clap::ArgParser::ArgParser`

Updates a value of `ArgParser` by applying a functorial action to field `positional_only`.

### `act_remaining_args : [f : Std::Functor] (Std::Iterator Minilib.App.Clap::Arg -> f (Std::Iterator Minilib.App.Clap::Arg)) -> Minilib.App.Clap::ArgParser::ArgParser -> f Minilib.App.Clap::ArgParser::ArgParser`

Updates a value of `ArgParser` by applying a functorial action to field `remaining_args`.

### `mod_command : (Minilib.App.Clap::Command -> Minilib.App.Clap::Command) -> Minilib.App.Clap::ArgParser::ArgParser -> Minilib.App.Clap::ArgParser::ArgParser`

Updates a value of `ArgParser` by applying a function to field `command`.

### `mod_inputs : (Std::Iterator Std::String -> Std::Iterator Std::String) -> Minilib.App.Clap::ArgParser::ArgParser -> Minilib.App.Clap::ArgParser::ArgParser`

Updates a value of `ArgParser` by applying a function to field `inputs`.

### `mod_matches : (Minilib.App.Clap::ArgMatches -> Minilib.App.Clap::ArgMatches) -> Minilib.App.Clap::ArgParser::ArgParser -> Minilib.App.Clap::ArgParser::ArgParser`

Updates a value of `ArgParser` by applying a function to field `matches`.

### `mod_positional_only : (Std::Bool -> Std::Bool) -> Minilib.App.Clap::ArgParser::ArgParser -> Minilib.App.Clap::ArgParser::ArgParser`

Updates a value of `ArgParser` by applying a function to field `positional_only`.

### `mod_remaining_args : (Std::Iterator Minilib.App.Clap::Arg -> Std::Iterator Minilib.App.Clap::Arg) -> Minilib.App.Clap::ArgParser::ArgParser -> Minilib.App.Clap::ArgParser::ArgParser`

Updates a value of `ArgParser` by applying a function to field `remaining_args`.

### `set_command : Minilib.App.Clap::Command -> Minilib.App.Clap::ArgParser::ArgParser -> Minilib.App.Clap::ArgParser::ArgParser`

Updates a value of `ArgParser` by setting field `command` to a specified one.

### `set_inputs : Std::Iterator Std::String -> Minilib.App.Clap::ArgParser::ArgParser -> Minilib.App.Clap::ArgParser::ArgParser`

Updates a value of `ArgParser` by setting field `inputs` to a specified one.

### `set_matches : Minilib.App.Clap::ArgMatches -> Minilib.App.Clap::ArgParser::ArgParser -> Minilib.App.Clap::ArgParser::ArgParser`

Updates a value of `ArgParser` by setting field `matches` to a specified one.

### `set_positional_only : Std::Bool -> Minilib.App.Clap::ArgParser::ArgParser -> Minilib.App.Clap::ArgParser::ArgParser`

Updates a value of `ArgParser` by setting field `positional_only` to a specified one.

### `set_remaining_args : Std::Iterator Minilib.App.Clap::Arg -> Minilib.App.Clap::ArgParser::ArgParser -> Minilib.App.Clap::ArgParser::ArgParser`

Updates a value of `ArgParser` by setting field `remaining_args` to a specified one.

## `namespace Minilib.App.Clap::Command`

### `@about : Minilib.App.Clap::Command -> Std::String`

Retrieves the field `about` from a value of `Command`.

### `@args : Minilib.App.Clap::Command -> Std::Array Minilib.App.Clap::Arg`

Retrieves the field `args` from a value of `Command`.

### `@author : Minilib.App.Clap::Command -> Std::String`

Retrieves the field `author` from a value of `Command`.

### `@bin_name : Minilib.App.Clap::Command -> Std::String`

Retrieves the field `bin_name` from a value of `Command`.

### `@display_name : Minilib.App.Clap::Command -> Std::String`

Retrieves the field `display_name` from a value of `Command`.

### `@help_template : Minilib.App.Clap::Command -> Minilib.App.Clap::HelpTemplate`

Retrieves the field `help_template` from a value of `Command`.

### `@name : Minilib.App.Clap::Command -> Std::String`

Retrieves the field `name` from a value of `Command`.

### `@subcommand_path : Minilib.App.Clap::Command -> Std::String`

Retrieves the field `subcommand_path` from a value of `Command`.

### `@subcommands : Minilib.App.Clap::Command -> Std::Array Minilib.App.Clap::Command`

Retrieves the field `subcommands` from a value of `Command`.

### `@version : Minilib.App.Clap::Command -> Std::String`

Retrieves the field `version` from a value of `Command`.

### `@version_template : Minilib.App.Clap::Command -> Minilib.App.Clap::HelpTemplate`

Retrieves the field `version_template` from a value of `Command`.

### `_default_args : Std::Array Minilib.App.Clap::Arg`

### `_get_submatches_from : Std::Array Std::String -> Minilib.App.Clap::Command -> Std::Result Std::String (Std::String, Minilib.App.Clap::ArgMatches)`

### `about : Std::String -> Minilib.App.Clap::Command -> Minilib.App.Clap::Command`

Sets the description about the command.

### `act_about : [f : Std::Functor] (Std::String -> f Std::String) -> Minilib.App.Clap::Command -> f Minilib.App.Clap::Command`

Updates a value of `Command` by applying a functorial action to field `about`.

### `act_args : [f : Std::Functor] (Std::Array Minilib.App.Clap::Arg -> f (Std::Array Minilib.App.Clap::Arg)) -> Minilib.App.Clap::Command -> f Minilib.App.Clap::Command`

Updates a value of `Command` by applying a functorial action to field `args`.

### `act_author : [f : Std::Functor] (Std::String -> f Std::String) -> Minilib.App.Clap::Command -> f Minilib.App.Clap::Command`

Updates a value of `Command` by applying a functorial action to field `author`.

### `act_bin_name : [f : Std::Functor] (Std::String -> f Std::String) -> Minilib.App.Clap::Command -> f Minilib.App.Clap::Command`

Updates a value of `Command` by applying a functorial action to field `bin_name`.

### `act_display_name : [f : Std::Functor] (Std::String -> f Std::String) -> Minilib.App.Clap::Command -> f Minilib.App.Clap::Command`

Updates a value of `Command` by applying a functorial action to field `display_name`.

### `act_help_template : [f : Std::Functor] (Minilib.App.Clap::HelpTemplate -> f Minilib.App.Clap::HelpTemplate) -> Minilib.App.Clap::Command -> f Minilib.App.Clap::Command`

Updates a value of `Command` by applying a functorial action to field `help_template`.

### `act_name : [f : Std::Functor] (Std::String -> f Std::String) -> Minilib.App.Clap::Command -> f Minilib.App.Clap::Command`

Updates a value of `Command` by applying a functorial action to field `name`.

### `act_subcommand_path : [f : Std::Functor] (Std::String -> f Std::String) -> Minilib.App.Clap::Command -> f Minilib.App.Clap::Command`

Updates a value of `Command` by applying a functorial action to field `subcommand_path`.

### `act_subcommands : [f : Std::Functor] (Std::Array Minilib.App.Clap::Command -> f (Std::Array Minilib.App.Clap::Command)) -> Minilib.App.Clap::Command -> f Minilib.App.Clap::Command`

Updates a value of `Command` by applying a functorial action to field `subcommands`.

### `act_version : [f : Std::Functor] (Std::String -> f Std::String) -> Minilib.App.Clap::Command -> f Minilib.App.Clap::Command`

Updates a value of `Command` by applying a functorial action to field `version`.

### `act_version_template : [f : Std::Functor] (Minilib.App.Clap::HelpTemplate -> f Minilib.App.Clap::HelpTemplate) -> Minilib.App.Clap::Command -> f Minilib.App.Clap::Command`

Updates a value of `Command` by applying a functorial action to field `version_template`.

### `arg : Minilib.App.Clap::Arg -> Minilib.App.Clap::Command -> Minilib.App.Clap::Command`

Add an argument definition to the command.

### `author : Std::String -> Minilib.App.Clap::Command -> Minilib.App.Clap::Command`

Sets the author of the command.

### `bin_name : Std::String -> Minilib.App.Clap::Command -> Minilib.App.Clap::Command`

Sets the name of the executable binary of the command.

### `display_name : Std::String -> Minilib.App.Clap::Command -> Minilib.App.Clap::Command`

Sets the display name of the command.

### `get_matches : Minilib.App.Clap::Command -> Std::IO::IOFail Minilib.App.Clap::ArgMatches`

Parse command line arguments based on `IO::get_args`.
If `--help` or `--version` is specified, the help string or version string will be returned as `throw`.

### `get_matches_from : Std::Array Std::String -> Minilib.App.Clap::Command -> Std::Result Std::String Minilib.App.Clap::ArgMatches`

Parses command line arguments based on the specified input array.
If `--help` or `--version` is specified, the help string or version string will be returned as the error message.

### `mod_about : (Std::String -> Std::String) -> Minilib.App.Clap::Command -> Minilib.App.Clap::Command`

Updates a value of `Command` by applying a function to field `about`.

### `mod_args : (Std::Array Minilib.App.Clap::Arg -> Std::Array Minilib.App.Clap::Arg) -> Minilib.App.Clap::Command -> Minilib.App.Clap::Command`

Updates a value of `Command` by applying a function to field `args`.

### `mod_author : (Std::String -> Std::String) -> Minilib.App.Clap::Command -> Minilib.App.Clap::Command`

Updates a value of `Command` by applying a function to field `author`.

### `mod_bin_name : (Std::String -> Std::String) -> Minilib.App.Clap::Command -> Minilib.App.Clap::Command`

Updates a value of `Command` by applying a function to field `bin_name`.

### `mod_display_name : (Std::String -> Std::String) -> Minilib.App.Clap::Command -> Minilib.App.Clap::Command`

Updates a value of `Command` by applying a function to field `display_name`.

### `mod_help_template : (Minilib.App.Clap::HelpTemplate -> Minilib.App.Clap::HelpTemplate) -> Minilib.App.Clap::Command -> Minilib.App.Clap::Command`

Updates a value of `Command` by applying a function to field `help_template`.

### `mod_name : (Std::String -> Std::String) -> Minilib.App.Clap::Command -> Minilib.App.Clap::Command`

Updates a value of `Command` by applying a function to field `name`.

### `mod_subcommand_path : (Std::String -> Std::String) -> Minilib.App.Clap::Command -> Minilib.App.Clap::Command`

Updates a value of `Command` by applying a function to field `subcommand_path`.

### `mod_subcommands : (Std::Array Minilib.App.Clap::Command -> Std::Array Minilib.App.Clap::Command) -> Minilib.App.Clap::Command -> Minilib.App.Clap::Command`

Updates a value of `Command` by applying a function to field `subcommands`.

### `mod_version : (Std::String -> Std::String) -> Minilib.App.Clap::Command -> Minilib.App.Clap::Command`

Updates a value of `Command` by applying a function to field `version`.

### `mod_version_template : (Minilib.App.Clap::HelpTemplate -> Minilib.App.Clap::HelpTemplate) -> Minilib.App.Clap::Command -> Minilib.App.Clap::Command`

Updates a value of `Command` by applying a function to field `version_template`.

### `name : Std::String -> Minilib.App.Clap::Command -> Minilib.App.Clap::Command`

Sets the name of the command.

### `new : Std::String -> Minilib.App.Clap::Command`

Creates a command structure by specifying the command name.

### `render_help : Minilib.App.Clap::Command -> Std::String`

Generates a help string based on the help template.

### `render_version : Minilib.App.Clap::Command -> Std::String`

Generates a version string based on the version template.

### `set_about : Std::String -> Minilib.App.Clap::Command -> Minilib.App.Clap::Command`

Updates a value of `Command` by setting field `about` to a specified one.

### `set_args : Std::Array Minilib.App.Clap::Arg -> Minilib.App.Clap::Command -> Minilib.App.Clap::Command`

Updates a value of `Command` by setting field `args` to a specified one.

### `set_author : Std::String -> Minilib.App.Clap::Command -> Minilib.App.Clap::Command`

Updates a value of `Command` by setting field `author` to a specified one.

### `set_bin_name : Std::String -> Minilib.App.Clap::Command -> Minilib.App.Clap::Command`

Updates a value of `Command` by setting field `bin_name` to a specified one.

### `set_display_name : Std::String -> Minilib.App.Clap::Command -> Minilib.App.Clap::Command`

Updates a value of `Command` by setting field `display_name` to a specified one.

### `set_help_template : Minilib.App.Clap::HelpTemplate -> Minilib.App.Clap::Command -> Minilib.App.Clap::Command`

Updates a value of `Command` by setting field `help_template` to a specified one.

### `set_name : Std::String -> Minilib.App.Clap::Command -> Minilib.App.Clap::Command`

Updates a value of `Command` by setting field `name` to a specified one.

### `set_subcommand_path : Std::String -> Minilib.App.Clap::Command -> Minilib.App.Clap::Command`

Updates a value of `Command` by setting field `subcommand_path` to a specified one.

### `set_subcommands : Std::Array Minilib.App.Clap::Command -> Minilib.App.Clap::Command -> Minilib.App.Clap::Command`

Updates a value of `Command` by setting field `subcommands` to a specified one.

### `set_version : Std::String -> Minilib.App.Clap::Command -> Minilib.App.Clap::Command`

Updates a value of `Command` by setting field `version` to a specified one.

### `set_version_template : Minilib.App.Clap::HelpTemplate -> Minilib.App.Clap::Command -> Minilib.App.Clap::Command`

Updates a value of `Command` by setting field `version_template` to a specified one.

### `subcommand : Minilib.App.Clap::Command -> Minilib.App.Clap::Command -> Minilib.App.Clap::Command`

Add a subcommand to the command.

### `version : Std::String -> Minilib.App.Clap::Command -> Minilib.App.Clap::Command`

Sets the version of the command.

## `namespace Minilib.App.Clap::HelpTemplate`

### `@data : Minilib.App.Clap::HelpTemplate -> Std::String`

Retrieves the field `data` from a value of `HelpTemplate`.

### `_default_help : Minilib.App.Clap::HelpTemplate`

### `_default_version : Minilib.App.Clap::HelpTemplate`

### `_format_all_args : Minilib.App.Clap::Command -> Minilib.App.Clap::HelpTemplate -> Std::String`

### `_format_arg : Minilib.App.Clap::Arg -> Std::String`

### `_format_option : Minilib.App.Clap::Arg -> Std::String`

### `_format_subcommand : Minilib.App.Clap::Command -> Std::String`

### `_format_usage : Minilib.App.Clap::Command -> Minilib.App.Clap::HelpTemplate -> Std::String`

### `act_data : [f : Std::Functor] (Std::String -> f Std::String) -> Minilib.App.Clap::HelpTemplate -> f Minilib.App.Clap::HelpTemplate`

Updates a value of `HelpTemplate` by applying a functorial action to field `data`.

### `format : Minilib.App.Clap::Command -> Minilib.App.Clap::HelpTemplate -> Std::String`

### `mod_data : (Std::String -> Std::String) -> Minilib.App.Clap::HelpTemplate -> Minilib.App.Clap::HelpTemplate`

Updates a value of `HelpTemplate` by applying a function to field `data`.

### `new : Std::String -> Minilib.App.Clap::HelpTemplate`

### `set_data : Std::String -> Minilib.App.Clap::HelpTemplate -> Minilib.App.Clap::HelpTemplate`

Updates a value of `HelpTemplate` by setting field `data` to a specified one.