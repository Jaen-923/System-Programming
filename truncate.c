#include <unistd.h>
#include <stdio.h>

int main(void) {

	int ret;
	ret = truncate("./truncateFile", 10);
	if (ret == -1) {
		perror("truncate");
		return -1;
	}
	return 0;
}

