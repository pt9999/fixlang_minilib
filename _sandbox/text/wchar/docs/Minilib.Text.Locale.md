# Minilib.Text.Locale

Defined in sandbox-text-wchar@0.1.0

## Values

### namespace Minilib.Text.Locale

#### get_locale

Type: `Std::String -> Std::IO::IOFail Std::String`

Queries the program's current locale.

This function is implemented by passing NULL pointer to the second argument of `setlocale(3)`.

For details, see Linux manual page for [setlocale(3)](https://man7.org/linux/man-pages/man3/setlocale.3.html).

##### Parameters

- `category_name`: The name of the category. (For example, "LC_ALL", "LC_COLLATE", "LC_CTYPE", "LC_MESSAGES", "LC_MONETARY", "LC_NUMERIC", "LC_TIME")

#### init_locale

Type: `Std::IO ()`

Initialize the program's current locale.

This function is equal to `setlocale("LC_ALL", "")`.

#### set_locale

Type: `Std::String -> Std::String -> Std::IO::IOFail Std::String`

Sets the program's current locale.

For details, see Linux manual page for [setlocale(3)](https://man7.org/linux/man-pages/man3/setlocale.3.html).

##### Parameters

- `category_name`: The name of the category. (For example, "LC_ALL", "LC_COLLATE", "LC_CTYPE", "LC_MESSAGES", "LC_MONETARY", "LC_NUMERIC", "LC_TIME")
- `locale`: The locale to be set. (For example, "", "C", "en_US.UTF-8", "ja_JP.UTF-8")

## Types and aliases

## Traits and aliases

## Trait implementations