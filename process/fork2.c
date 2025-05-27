#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(void) {

	pid_t pid;

	pid = fork();

	if (pid > 0) {
		printf("I am the parent, My pid=%d!\n", getpid());
		sleep(10);
	} else if (!pid) {
		printf("I am the child, My pid=%d!\n", getpid());
		sleep(10);
	} else if (pid == -1) {
		perror("fork");
	}
	return 1;
}


