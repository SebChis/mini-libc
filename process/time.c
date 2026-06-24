#include <time.h>
#include <internal/syscall.h>
#include <errno.h>
#include <unistd.h>

int nanosleep(const struct timespec *req, struct timespec *rem) {
    long ret = syscall(__NR_nanosleep, req, rem);

    if (ret < 0) {
        errno = (int)-ret;
        return -1;
    }

    return 0;
}

unsigned int sleep(unsigned int seconds) {
    struct timespec req;
    struct timespec rem;
    int ret;

    req.tv_sec = seconds;
    req.tv_nsec = 0;

    ret = nanosleep(&req, &rem);

    if (ret == -1) {
        if (errno == EINTR)
            return (unsigned int)rem.tv_sec;
        return 0;
    }

    return 0;
}
