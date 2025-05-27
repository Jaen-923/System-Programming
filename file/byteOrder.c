#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int fd;
    unsigned int word = 1720;
    size_t count;
    ssize_t nr;

    fd = open("./testFile", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd == -1) {
        perror("open");
        exit(0);
    }
    count = sizeof(word);
    nr = write(fd, &word, count);
    if (nr == -1) {
        perror("write");
    }
    else if (nr != count) {
        printf("Partial Write!\n");
    }
    close(fd);
}