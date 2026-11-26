*This project has been created as part of the 42 curriculum by vicarauj.*

# ft_printf

## Description

**ft_printf** is a 42 project whose goal is to recode the C standard library function `printf()`. The result is a static library, `libftprintf.a`, exposing a single function:

```c
int	ft_printf(const char *format, ...);
```

The project is mainly an introduction to **variadic functions** in C (`<stdarg.h>`): functions that accept a variable number of arguments. Like the original, `ft_printf` writes the formatted output to the standard output and returns the number of characters printed.

### Supported conversions

| Specifier | Output | Implemented in |
|---|---|---|
| `%c` | A single character | `printf_char.c` |
| `%s` | A string (`(null)` is printed for a NULL pointer, as glibc does) | `printf_str.c` |
| `%p` | A `void *` pointer in hexadecimal, prefixed with `0x` (`(nil)` for NULL, as glibc does) | `printf_ptr.c` |
| `%d` | A signed decimal (base 10) number | `printf_int.c` |
| `%i` | A signed integer in base 10 | `printf_int.c` |
| `%u` | An unsigned decimal (base 10) number | `printf_dec.c` |
| `%x` | An unsigned number in lowercase hexadecimal | `printf_hex.c` |
| `%X` | An unsigned number in uppercase hexadecimal | `printf_hex.c` |
| `%%` | A percent sign | `ft_printf.c` |

### Technical constraints

- Written in C, following the 42 Norm, compiled with `cc -Wall -Wextra -Werror`.
- Allowed external functions: `malloc`, `free`, `write`, `va_start`, `va_arg`, `va_copy`, `va_end`. This implementation only uses `write`, `va_start`, `va_arg` and `va_end`.
- The buffer management of the original `printf()` is **not** reimplemented.
- The library is built with `ar` (`libtool` is forbidden) and `libftprintf.a` is created at the root of the repository.
- The header is named `ft_printf.h` and contains the prototype of `ft_printf()`.
- The library does not depend on `libft`.

## Instructions

### Compilation

At the root of the repository:

```bash
make        # builds libftprintf.a
make clean  # removes object files
make fclean # removes object files and libftprintf.a
make re     # fclean + all
```

### Usage

```c
#include "ft_printf.h"

int	main(void)
{
	int	len;

	len = ft_printf("Hello %s! %d + %d = %i (0x%x)\n", "42", 2, 3, 5, 255);
	ft_printf("Printed %d characters\n", len);
	return (0);
}
```

```bash
cc -Wall -Wextra -Werror main.c -L. -lftprintf -o test
./test
```

### Testing

The output and the return value of `ft_printf` should be compared with those of the original `printf` for the same format string and arguments, including edge cases such as `INT_MIN`, `UINT_MAX`, `0`, a NULL string and a NULL pointer.

### Repository structure

```
.
├── Makefile
├── ft_printf.h      # prototypes
├── ft_printf.c      # ft_printf() and the conversion dispatcher
├── printf_char.c    # %c (and the low-level write)
├── printf_str.c     # %s
├── printf_ptr.c     # %p
├── printf_int.c     # %d, %i
├── printf_dec.c     # %u
└── printf_hex.c     # %x, %X (and the hex part of %p)
```

## Algorithm and data structure

### Overview

`ft_printf` receives the format string and a `va_list` initialised with `va_start`. The format string is traversed **once, from left to right**, character by character:

1. If the current character is not `%`, it is written as-is with `printf_char` and counted.
2. If it is `%`, the next character is read as the **conversion specifier** and passed to a `handler` function, which picks the right printing function and consumes the matching argument with `va_arg`.
3. Every printing function returns the number of characters it wrote; `ft_printf` accumulates these values in a counter and returns the total at the end.
4. `va_end` is called before returning.

The `va_list` is passed to `handler` **by pointer** (`va_list *`), so that the argument consumed by `va_arg` inside the handler is also consumed for the next call in `ft_printf`.

### Why this approach

- **Single pass over the format string**: linear time, `O(n)` in the length of the format plus the size of the printed values, and no need to pre-compute the output size.
- **Direct output with `write`, no intermediate buffer**: the subject explicitly forbids reimplementing the buffering of the original `printf`. Writing directly also means no `malloc`, hence no risk of memory leaks or allocation failures. The trade-off is one `write` system call per character, which is slower than a buffered implementation but keeps the code simple.
- **One function per conversion**: each specifier is isolated in a small function (`printf_char`, `printf_str`, `printf_ptr`, `printf_int`, `printf_dec`, `printf_hex`). This keeps each file short and Norm-compliant, and makes the code easy to read, to test and to extend with new conversions.
- **Dispatch with an `if / else if` chain**: `handler` maps each specifier to its function. With only nine specifiers, a chain is the simplest option and needs no extra data structure; a lookup table of function pointers would only pay off with many more specifiers.
- **Recursive number printing**: the number is printed digit by digit by recursion: the function first prints `nb / base` (the more significant digits) and then the last digit, so digits come out in the right order without a buffer or reversal.
  - `printf_int` (`%d`, `%i`) copies the `int` into a `long` before negating it. This makes `INT_MIN` work, since `-INT_MIN` does not fit in an `int`.
  - `printf_dec` (`%u`) works directly on an `unsigned int`.
  - `printf_hex` (`%x`, `%X`, and `%p`) is **generic in the digit set**: it receives the base as a string (`"0123456789abcdef"` or `"0123456789ABCDEF"`), so lower and upper case share the same code. It takes an `unsigned long`, which is large enough to hold a pointer value on 64-bit systems.
- **`%p`** prints `0x` followed by the address in hexadecimal, reusing `printf_hex`; a NULL pointer prints `(nil)`, matching glibc.

### Data structures

No custom data structure is needed:

- **`va_list`**: the only structure used, to access the variable arguments.
- **Base strings**: constant strings (`"0123456789abcdef"`, `"0123456789ABCDEF"`) used as lookup tables to convert a digit value into its character.

## Resources

### References

- `man 3 printf` and `man 3 stdarg`.
- [The GNU C Library – Variadic Functions](https://www.gnu.org/software/libc/manual/html_node/Variadic-Functions.html).
- [`printf` – POSIX specification](https://pubs.opengroup.org/onlinepubs/9699919799/functions/printf.html).
- [GNU Make Manual](https://www.gnu.org/software/make/manual/make.html).
- 42 Norm (available on the intranet).

### Use of AI

- This README's structure was drafted with the help of an AI assistant, based on the subject's README requirements, and then reviewed by the author(s).
- Reviewing of the code.
