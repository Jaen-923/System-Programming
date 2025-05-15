#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int fd;
    const char *str = "Open file!\n";
    fd = open("./testFile", O_WRONLY | O_CREAT, S_IWUSR | S_IRUSR); // Owner has read and write permission
    if (fd == -1) {
        perror("open");
        exit(0);
    }
    write(fd, str,strlen(str));
    close(fd);
}