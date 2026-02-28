*This project has been created as part of the 42 curriculum by assempas.*

# ft_printf

## Description

This project consists of re-implementing the standard C `printf()` function.

The goal is to reproduce the behavior of the original `printf` from the C standard library, supporting a limited set of mandatory conversions, while respecting the 42 Norm and project constraints.

This implementation does not replicate the internal buffer management of the original `printf`, but instead writes directly to standard output using the `write()` system call.

Supported conversions:

* `%c` – Character
* `%s` – String
* `%p` – Pointer (hexadecimal format)
* `%d` – Signed decimal
* `%i` – Signed integer
* `%u` – Unsigned decimal
* `%x` – Hexadecimal (lowercase)
* `%X` – Hexadecimal (uppercase)
* `%%` – Literal percent sign

---

## Architecture

The project is divided into small, clearly separated modules:

* **ft_printf.c**
  Handles format string parsing, variadic argument initialization, counting of printed characters, and global error handling.

* **ft_dispatch.c**
  Routes each conversion specifier to the correct handler function and extracts arguments using `va_arg`.

* **ft_print_str_char.c**
  Implements `%c`, `%s`, and `%%`.

* **ft_print_nbr.c**
  Implements `%d`, `%i`, and `%u`.

* **ft_print_hex_ptr.c**
  Implements `%x`, `%X`, and `%p`.

Each file has a single responsibility to ensure clarity, modularity, and compliance with the 42 Norm.

---

## Algorithm & Design Choices

### 1. Direct Output Strategy

Unlike the original `printf`, this implementation does not use internal buffering.
Each character is written directly using `write(1, ...)`.

This simplifies the logic and avoids complex buffer management.

---

### 2. Centralized Counting

Each helper function returns:

* The number of characters printed
* `-1` if an error occurs

The main function (`ft_printf`) accumulates the total count and immediately stops if any write error occurs.

This ensures consistent error propagation across all modules.

---

### 3. Recursive Number Printing

Both decimal and hexadecimal printing use recursive algorithms.

Algorithm principle:

* If the number is greater than or equal to the base:

  * Print higher digits first (`n / base`)
  * Then print the last digit (`n % base`)

This avoids temporary buffers and keeps the implementation simple and clean.

---

### 4. Safe Handling of Edge Cases

* `NULL` strings are printed as `(null)`
* `NULL` pointers are printed as `(nil)`
* Signed integers are safely converted to `long` before negation to avoid overflow on `INT_MIN`
* If the format string ends with `%`, the function avoids undefined behavior and does not crash

---

### 5. Separation of Responsibilities

* Parsing logic is separated from conversion logic.
* Conversion routing is isolated in a dispatcher.
* Each group of conversions has its own dedicated file.

This makes the code:

* Easier to read
* Easier to debug
* Easier to extend
* Easy to defend during evaluation

---

## Instructions

### Compilation

```bash
make
```

This generates:

```
libftprintf.a
```

### Cleaning

```bash
make clean
make fclean
make re
```

### Usage Example

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s, number: %d\n", "World", 42);
    return (0);
}
```

Compile with:

```bash
cc main.c libftprintf.a
```

---

## Resources

* `man 3 printf`
* `man 2 write`
* `man 3 stdarg`
* The C Programming Language – Kernighan & Ritchie

---

## AI Usage Disclosure

AI was used as a conceptual assistant to:

* Clarify variadic function behavior
* Discuss architectural design decisions
* Review edge-case handling
* Improve code structure and modularization

All implementation logic was written, tested, and understood independently.

The objective of this project was to fully understand variadic functions, recursion, modular architecture, and low-level output handling without relying on automatic code generation.
