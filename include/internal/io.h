/* SPDX-License-Identifier: BSD-3-Clause */

#ifndef __IO_H__
#define __IO_H__	1

#ifdef __cplusplus
extern "C" {
#endif

#include <internal/types.h>

#define STDIN_FILENO    0
#define STDOUT_FILENO   1
#define STDERR_FILENO   2

ssize_t write(int fd, const void *buf, size_t len);
ssize_t read(int fd, void *buf, size_t len);

#ifdef __cplusplus
}
#endif

#endif
