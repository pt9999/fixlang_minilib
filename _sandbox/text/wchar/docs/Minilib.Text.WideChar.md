# Minilib.Text.WideChar

Defined in sandbox-text-wchar@0.1.0

Wide-character definition and classification.

The type of wide character is `WideChar`.

You can check if a wide character has a specific character property by using
a classification function such as `WideChar::is_alpha`.

## NOTE

- The result of the classification functions are affected by the `LC_TYPE` locale.

## Values

### namespace Minilib.Text.WideChar::WideChar

#### is_alnum

Type: `Minilib.Text.WideChar::WideChar -> Std::Bool`

#### is_alpha

Type: `Minilib.Text.WideChar::WideChar -> Std::Bool`

#### is_blank

Type: `Minilib.Text.WideChar::WideChar -> Std::Bool`

#### is_cntrl

Type: `Minilib.Text.WideChar::WideChar -> Std::Bool`

#### is_digit

Type: `Minilib.Text.WideChar::WideChar -> Std::Bool`

#### is_graph

Type: `Minilib.Text.WideChar::WideChar -> Std::Bool`

#### is_lower

Type: `Minilib.Text.WideChar::WideChar -> Std::Bool`

#### is_print

Type: `Minilib.Text.WideChar::WideChar -> Std::Bool`

#### is_punct

Type: `Minilib.Text.WideChar::WideChar -> Std::Bool`

#### is_space

Type: `Minilib.Text.WideChar::WideChar -> Std::Bool`

#### is_upper

Type: `Minilib.Text.WideChar::WideChar -> Std::Bool`

#### is_xdigit

Type: `Minilib.Text.WideChar::WideChar -> Std::Bool`

## Types and aliases

### namespace Minilib.Text.WideChar

#### WideChar

Defined as: `type WideChar = Std::U32`

The type of wide character.

This is equal to `wchar_t` in Linux and MacOS.

##### NOTE

- Currently Windows is not supported yet, but in Windows, `wchar_t` is 16-bit.

## Traits and aliases

## Trait implementations