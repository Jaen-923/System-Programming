#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int fd;
    const char *str = "Open file!\n";
    fd = open("./testFile", O_WRONLY);
    printf("fd: %d\n", fd);
    write(fd, str, strlen(str));
    close(fd);
}