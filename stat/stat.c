// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <fcntl.h>
#include <errno.h>

int stat(const char *restrict path, struct stat *restrict buf)
{
	/* TODO: Implement stat(). */
	long ret = syscall(__NR_newfstatat, AT_FDCWD, path, buf, 0);

	if (ret < 0) {
		errno = -(int)ret;
		return -1;
	}

	return 0;
}
