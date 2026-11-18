_This project has been created as part of the 42 curriculum by alnoukan._

# ft_printf

## Description

`ft_printf` is a reimplementation of the C standard library function `printf()`. The goal of the project is to learn how variadic functions work in C (`va_start`, `va_arg`, `va_end`) and to build a small library that can be reused in later 42 projects.

The project produces a static library, `libftprintf.a`, which contains `ft_printf()` and every function of `libft`.

```c
int ft_printf(const char *format, ...);
```

It returns the number of characters printed, like `printf()`.

### Supported conversions

| Conversion | Prints                                                |
| ---------- | ----------------------------------------------------- |
| `%c`       | a single character                                    |
| `%s`       | a string (`(null)` if the pointer is `NULL`)          |
| `%p`       | a `void *` pointer in hexadecimal, prefixed with `0x` |
| `%d`       | a signed decimal integer                              |
| `%i`       | a signed integer in base 10                           |
| `%u`       | an unsigned decimal integer                           |
| `%x`       | an unsigned integer in lowercase hexadecimal          |
| `%X`       | an unsigned integer in uppercase hexadecimal          |
| `%%`       | a percent sign                                        |

Buffer management, flags, field width and precision are not implemented.

## Instructions

### Build

```sh
make        # builds libft, then libftprintf.a at the repository root
make clean  # removes object files (ft_printf and libft)
make fclean # removes object files and libraries
make re     # rebuilds everything
```

The Makefile first runs `make` in `lib/libft` to build `libft.a`. It then copies `libft.a` to `libftprintf.a` and adds the ft_printf object files to it with `ar`. A program therefore only needs to link against `libftprintf.a`.

### Use

```c
#include "../includes/ft_printf.h"

int main(void)
{
	int len;

	len = ft_printf("Hello %s, you are %d years old\n", "world", 42);
	ft_printf("That line was %d characters long\n", len);
	return (0);
}
```

```sh
cc -Wall -Wextra -Werror -Iincludes -Ilib/libft main.c libftprintf.a -o demo
./demo
```

### Repository layout

```
.
├── Makefile
├── includes/ft_printf.h   # prototypes for ft_printf and its helpers
├── srcs/                  # ft_printf sources
└── lib/libft/             # libft sources, header and Makefile
```

## Algorithm and data structure

### Parsing

`ft_printf()` starts a `va_list` and hands it, along with the format string and a pointer to a counter, to `ft_selector()`.

`ft_selector()` reads the format string once, from left to right:

1. A character that is not `%` is written as is, and the counter goes up by one.
2. On `%`, it reads the next character and calls the matching handler with the next argument from `va_arg`:
   - `c` → `ft_printchar`
   - `s` → `ft_string`
   - `p` → `ft_pointertohex`
   - `d`, `i` → `ft_decimal`
   - `u` → `ft_uint`
   - `x`, `X` → `ft_hex`
   - `%` → prints `%`
3. Each handler returns the number of characters it wrote, and that number is added to the counter.

When the format string ends, `ft_printf()` calls `va_end()` and returns the counter.

### Number conversion

Numbers are printed with recursion. To print `n` in base `b`, the function first prints `n / b`, then the digit for `n % b`. This prints the most significant digit first without storing the digits anywhere. Hexadecimal digits come from the digit value: `0`–`9` map to `'0'`–`'9'`, and 10–15 map to `'a'`–`'f'` or `'A'`–`'F'` depending on whether the conversion is `x` or `X`.

The number of characters printed is computed separately, by counting how many times the value can be divided by its base (`ft_countdigit`, `ft_hexcount`, `ft_ptrlen`). Negative numbers count one extra character for the `-` sign. Counting uses a `long`, so `INT_MIN` is handled without overflow.

`%p` reads the argument as a 64-bit unsigned value, prints `0x`, then prints the address in lowercase hexadecimal.

### Why this design

- **No data structure, no allocation.** The output is written straight to standard output with `write`, one character at a time. Nothing is allocated, so nothing can leak. The subject also forbids reproducing `printf()`'s buffer management.
- **One handler per conversion.** Each conversion lives in its own small file. Adding a conversion means adding one handler and one branch in `ft_selector()`.
- **Recursion for digits.** It is short, easy to explain, and the recursion depth is small: at most 20 calls for a 64-bit value.

## Resources

### References

- [`printf(3)` manual page](https://man7.org/linux/man-pages/man3/printf.3.html): expected behavior of each conversion and the return value.
- [`stdarg(3)` manual page](https://man7.org/linux/man-pages/man3/stdarg.3.html): `va_start`, `va_arg`, `va_copy` and `va_end`.
- [GNU Make manual, "Recursive Use of make"](https://www.gnu.org/software/make/manual/html_node/Recursion.html): calling the libft Makefile from the main Makefile with `$(MAKE) -C`.
- [42 Norm](https://github.com/42School/norminette): the coding style the sources follow.

### Use of AI

An AI assistant (Claude) was used for:

- **Makefile:** explaining how the main Makefile can call the libft Makefile with `$(MAKE) -C`, and how to merge `libft.a` into `libftprintf.a`.
- **Compliance review:** checking the project against the subject, comparing the output with the real `printf()`, and finding an out-of-bounds read when the format string ends with `%`.
- **Documentation:** drafting this README.

The `ft_printf` source code was not written by AI.
