*This project has been created as part of the 42 curriculum by rimayer.*

# ft_printf

## Description

`ft_printf` is my implementation of a simplified version of the standard C `printf` function.

The goal of the project is to learn how formatted output works in C, with a particular focus on variadic functions, format parsing, type handling, number-base conversion, and static libraries.

The function has the following prototype:

```c
int	ft_printf(const char *format, ...);
```

It writes formatted output to the standard output and returns the number of characters written.

The following conversions are supported:

| Specifier | Description |
|-----------|-------------|
| `%c` | Prints a character |
| `%s` | Prints a string |
| `%p` | Prints a pointer address in hexadecimal |
| `%d` | Prints a signed decimal integer |
| `%i` | Prints a signed integer |
| `%u` | Prints an unsigned decimal integer |
| `%x` | Prints an unsigned integer in lowercase hexadecimal |
| `%X` | Prints an unsigned integer in uppercase hexadecimal |
| `%%` | Prints a percent sign |

## How It Works

`ft_printf` starts by initializing a variadic argument list with `va_start`.

The format string is then processed one character at a time. Normal characters are written directly to the standard output.

When a `%` is encountered, the following character is checked to determine whether it is a supported format specifier. Valid specifiers are passed to a dispatcher function, which retrieves the next variadic argument with `va_arg` using the appropriate type and calls the corresponding printing function.

For example:

```text
%c  -> int
%s  -> char *
%d  -> int
%u  -> unsigned int
%x  -> unsigned int
%p  -> void *
```

Each printing function returns the number of characters it writes. These values are accumulated so that `ft_printf` can return the total number of characters printed.

After the complete format string has been processed, `va_end` is called to clean up the variadic argument list.

### Number conversion

Decimal and hexadecimal numbers are printed recursively.

For hexadecimal conversion, the number is repeatedly divided by 16. The remainder is used as an index into either:

```text
0123456789abcdef
```

or:

```text
0123456789ABCDEF
```

depending on whether `%x` or `%X` was requested.

Pointer addresses use the same hexadecimal principle after the pointer is retrieved as a `void *` and converted to an integer representation suitable for the conversion used in this implementation. The `0x` prefix is added separately.

## Building

Clone the repository:

```bash
git clone https://github.com/Reyamdev/42_ft_printf.git
cd 42_ft_printf
```

Build the library:

```bash
make
```

This creates:

```text
libftprintf.a
```

The Makefile also provides:

```bash
make clean
```

to remove object files,

```bash
make fclean
```

to remove object files and `libftprintf.a`, and:

```bash
make re
```

to completely rebuild the library.

## Usage

Include the header:

```c
#include "ft_printf.h"
```

Example:

```c
int	main(void)
{
	ft_printf("Hello %s! Number: %d, Hex: %x\n", "42", 42, 42);
	return (0);
}
```

Compile your program with the library:

```bash
cc main.c libftprintf.a -o program
```

Then run:

```bash
./program
```

## Resources

The following resources were useful while learning the concepts required for this project:

- GeeksforGeeks — Variadic Functions in C
  https://www.geeksforgeeks.org/c/variadic-functions-in-c/

- The `printf(3)` and `stdarg(3)` manual pages for understanding formatted output and variadic argument handling.

### AI usage

AI was used as a learning aid during the project. It was used to explain concepts such as variadic arguments, unsigned integer behavior.

The implementation was written and tested while working through these concepts and without relying on generated solutions.
