#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

int puts(const char *str) {
    long len = strlen(str);
    long ret = write(STDOUT_FILENO, str, len);
    const char newline = '\n';

    if (ret < 0)
        return EOF;

    ret = write(STDOUT_FILENO, &newline, 1);

    if (ret < 0)
        return EOF;

    return 0;
}
