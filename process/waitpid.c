#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {

	int status;
	pid_t pid, pid2;

	pid = fork();

	if (!pid) return 1;
	pid2 = waitpid(pid, &status, 0);

	if (pid2 == -1) {
		perror("waitpid");
	} else {
		printf("pid=%d\n", pid2);
		if (WIFEXITED(status)) {
			printf("Normal termination with exit status=%d\n", WEXITSTATUS(status));
		}
		if (WIFSIGNALED(status)) {
			printf("Killed by signal=%d%s\n", WTERMSIG(status), WCOREDUMP(status) ? " (dumped core)" : "");
		}
	}
}
