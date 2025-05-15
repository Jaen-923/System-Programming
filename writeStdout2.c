#include <stdio.h>
#include <unistd.h>
#include <string.h>

void main(void) {
    const char *str = "Hello!\n";
    write(STDOUT_FILENO, str, strlen(str));
}