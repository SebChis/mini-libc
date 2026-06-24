# mini-libc: A Minimalist C Standard Library for Linux

A lightweight, freestanding implementation of the C standard library for Linux x86_64 systems. This project demonstrates low-level system programming by reimplementing core libc functionality directly on top of Linux syscalls, without relying on external libraries.

## Overview

**mini-libc** is an educational implementation of a minimal C standard library that replaces critical glibc functions. It provides essential string manipulation, memory management, file I/O, and process control operations—all implemented directly using Linux system calls.

### Key Features

-  **String Operations** – `strcpy`, `strcat`, `strlen`, `strncpy`, `strncat`, `strcmp`, `strncmp`, `strstr`, `strrstr`, `memcpy`, `memmove`, `memset`, `memcmp`
-  **File I/O** – `open`, `close`, `read`, `write`, `lseek`, `truncate`, `ftruncate`
-  **File Metadata** – `stat`, `fstat`, `fstatat`
-  **Memory Management** – `malloc`, `free`, `calloc`, `realloc`, `mmap`, `mremap`, `munmap`
-  **Process Control** – `sleep`, `nanosleep`, `exit`
-  **Output** – `puts` with file descriptor support
-  **Error Handling** – `errno` variable management

##  Project Structure

```text
/
├── string/          # String manipulation functions
│   └── string.c
├── io/              # File I/O operations
│   ├── open.c
│   ├── close.c
│   ├── read_write.c
│   ├── lseek.c
│   ├── truncate.c
│   ├── ftruncate.c
│   └── puts.c
├── mm/              # Memory management
│   ├── malloc.c
│   ├── mmap.c
│   └── mem_list.c
├── stat/            # File metadata
│   ├── stat.c
│   ├── fstat.c
│   └── fstatat.c
├── process/         # Process operations
│   ├── exit.c
│   └── time.c
├── crt/             # C runtime initialization
│   ├── __libc_start_main.c
│   └── start.asm
├── errno.c          # Error handling
└── syscall.c        # Syscall interface layer
```

##  Building

```bash
make
```

##  Implementation Details

### String Manipulation (`string/`)

Implements all essential POSIX string functions with proper memory handling:

- Safe length-limited variants (`strncpy`, `strncat`, `strncmp`)
- Pattern matching (`strstr`, `strrstr`)
- Memory operations (`memcpy`, `memmove`, `memset`, `memcmp`)

### File I/O (`io/`)

Direct syscall-based file operations:

- File descriptor management (`open`, `close`)
- Sequential reading/writing (`read`, `write`)
- File positioning (`lseek`)
- File size control (`truncate`, `ftruncate`)
- Standard output support (`puts`)

### Memory Management (`mm/`)

Custom memory allocator with metadata tracking:

- Dynamic allocation (`malloc`, `calloc`, `realloc`)
- Memory mapping (`mmap`, `mremap`, `munmap`)
- Internal linked list for allocation tracking

### File Metadata (`stat/`)

File information retrieval:

- `stat`, `fstat` for file statistics
- `fstatat` for relative path operations

### Process Control (`process/`)

Process-level operations:

- Program termination (`exit`)
- Sleep operations (`sleep`, `nanosleep`)

##  Architecture

- **Freestanding:** No external library dependencies; all functionality built from Linux syscalls.
- **x86_64 Target:** Assembly syscall interface for Linux.
- **Syscall Layer:** Unified `syscall()` function with architecture-specific implementation.
- **Error Handling:** `errno`-based error reporting per POSIX standards.

##  Usage Example

```c
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    // String operations
    char buffer[256];
    strcpy(buffer, "Hello");
    strcat(buffer, " World");
    puts(buffer);

    // File I/O
    int fd = open("data.txt", O_WRONLY | O_CREAT, 0644);
    write(fd, "mini-libc", 9);
    close(fd);

    // Memory management
    int *data = malloc(10 * sizeof(int));
    memset(data, 0, 10 * sizeof(int));
    free(data);

    return 0;
}
```

##  Learning Outcomes

This project demonstrates:

- Linux system call interface and conventions
- Low-level memory management techniques
- String and binary data manipulation
- File descriptor-based I/O
- Error handling patterns in systems programming
- Assembly language for syscall invocation

##  Notes

- **Architecture:** x86_64 Linux only (ARM64/AArch64 users should use a virtual machine).
- **Minimalist Design:** Focuses on essential functionality, not performance optimization.
- **Educational Purpose:** Designed to teach bare-metal systems programming concepts.

##  License

This is an educational assignment project.

- **Platform:** Linux x86_64
- **Language:** C with x86_64 Assembly
