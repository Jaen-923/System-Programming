#include <errno.h>
#include <stdio.h>
#include <unistd.h>

int main(void) {
    int fd;
    errno = 0;
    if(fsync(fd)==-1)
        perror("fsync");
    printf("%d\n", errno);
}