#include <stdio.h>
#include <unistd.h>
#include <string.h>
#define BUFFER 256

void main(void) {
    char str[BUFFER];
    read(STDIN_FILENO, str, BUFFER);
    write(STDOUT_FILENO, str, strlen(str));
}