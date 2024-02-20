# Example programs for fixlang_minilib


## json_cat

Reads JSON from a file (or standard input), and writes it to a file (or standar output).

```
$ ./json_cat.out --help
json_cat.out 1.0
Reads JSON from a file (or standard input), and writes it to a file (or standar output).

USAGE:
    json_cat.out [OPTIONS]

OPTIONS:
    -h, --help                  Print help information
    -V, --version               Print version information
    -i, --input <VALUE>         Input file (default: standard input)
    -o, --output <VALUE>        Output file (default: standard output)
    -p, --plain <VALUE>         Disable pretty printing (default: enable pretty printing)
```

## sample_client

Fetches contents from remote HTTP server.
Currently HTTPS is not supported.

```
$ ./sample_client.out --help
ERROR: sample_client 0.1
Fetches contents from remote HTTP server.

USAGE:
    sample_client [OPTIONS] [URL]

ARGS:
    [URL]      The URL to fetch. NOTE: URL should start with 'http://'.

OPTIONS:
    -h, --help                  Print help information
    -V, --version               Print version information
```

## sample_server

This program implements a chat server.
The chat server listens on `localhost:2525`.

Chat members can connect to the chat server using `nc` (netcat) command.
Chat messages are broadcasted to all chat members.

Prerequisite:

`$ sudo apt install netcat`

Start server:  (Ctrl+c to stop server)

`$ examples/sample_server.out`

Start client:  (Ctrl+c to disconnect)

`$ nc localhost 2525`

```
$ ./sample_server.out --help
sample_server.out 1.0
Sample chat server

USAGE:
    sample_server.out [OPTIONS]

OPTIONS:
    -h, --help                  Print help information
    -V, --version               Print version information
    -h, --host <VALUE>          IP address to liten (default: 127.0.0.1)
    -p, --port <VALUE>          port number to listen (default: 2525)
```

## sample_http_server

Sample HTTP server that serves a chat room.

Start the server and open `http://127.0.0.1:8080/` in your favorite browser.

```
$ ./sample_http_server.out --help
sample_http_server.out 1.0
Sample http server

USAGE:
    sample_http_server.out [OPTIONS]

OPTIONS:
    -h, --help                  Print help information
    -V, --version               Print version information
    -h, --host <VALUE>          IP address to liten (default: 127.0.0.1)
    -p, --port <VALUE>          port number to listen (default: 8080)
```

## grep

Find lines matching a regular expression.

```
$ ./grep.out --help
grep 0.1.0
Find lines matching a regular expression.

USAGE:
    grep [OPTIONS] <PATTERN> [FILES]...

ARGS:
    <PATTERN>  Regular expression pattern
    [FILES]... Input files

OPTIONS:
    -h, --help                  Print help information
    -V, --version               Print version information
```

## calc_pi

Calculates PI (3.1415926...)

```
$ ./calc_pi.out --help
calc_pi 0.1.0
Calculates pi

USAGE:
    calc_pi [OPTIONS]

OPTIONS:
    -h, --help                  Print help information
    -V, --version               Print version information
    -p, --prec <VALUE>          precision of base 10
    -f, --f64                   calculate with F64
```

## fractal_server

An HTTP server that renders Mandelbrot fractal images.

Start the server and open `http://127.0.0.1:8080/` in your favorite browser.

```
$ examples/fractal_server.out --help
fractal_server.out 0.1
An HTTP server that renders Mandelbrot fractal images.

USAGE:
    fractal_server.out [OPTIONS]

OPTIONS:
    -h, --help                  Print help information
    -V, --version               Print version information
    -h, --host <VALUE>          IP address to liten (default: 127.0.0.1)
    -p, --port <VALUE>          port number to listen (default: 8080)
```

## probable_primes

Generates probable primes.
By default, it generates probable primes of 128 bit to 1024 bit.

```
$ examples/probable_primes.out --help
probable_primes 0.1.0
Generates probable primes

USAGE:
    probable_primes [OPTIONS]

OPTIONS:
    -h, --help                  Print help information
    -V, --version               Print version information
    -f, --from <VALUE>          from
    -t, --to <VALUE>            to
    -s, --step <VALUE>          step
        --seed <VALUE>          Seed of the random number generator. Default is current time
```

## spell_checker

This is a sample program for spell checker.

Currently, you can only enter a single word, and if the word is not in the word list,
correction suggestions will be displayed.

Although the spell checker can be used with user-defined word lists,
I recommend that you use predefined word list files.

For Ubuntu 22.04, American English word list file can be installed by the command below.
It is installed to `/usr/share/dict/american-english`.
```
$ sudo apt install wamerican
```

```
$ examples/spell_checker.out --help
spell_checker.out 1.0
Sample spell checker

USAGE:
    spell_checker.out [OPTIONS]

OPTIONS:
    -h, --help                  Print help information
    -V, --version               Print version information
    -w, --word-list <VALUE>     Word list file (default: /usr/share/dict/american-english)
```
