#include <stdio.h>
#include <unistd.h>
#include <string.h>

void main(void) {
	const char *str = "Hello!\n";
	write(1, str, strlen(str));
}

