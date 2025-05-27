#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int fd;
    const char *str = "Hello World!\n";
    size_t count;
    ssize_t nr;

    fd = open("./appendWriteFile", O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd == -1) {
        perror("Open");
        exit(0);
    }
    count = strlen(str);
    nr = write(fd, str, strlen(str));
    if (nr == -1) {
        perror("Write");
    }
    close(fd);
}