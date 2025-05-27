#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(void) {
	int ret;

	ret = execl("/bin/ls", "ls", "-l", NULL);
	if (ret == -1) {
		perror("execl");
	}

	return 1;
}

