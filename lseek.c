#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(void) {
	int fd, ret;
	unsigned char wdata[256];
	unsigned char rdata;
	int i;
	fd = open("./lseekFile", O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd == -1) {
		perror("Open");
		exit(-1);
	}
	for (i=0; i<256; i++) {
		wdata[i] = i;
	}
	write(fd, wdata, sizeof(wdata));
	lseek(fd, 0, SEEK_SET);
	read(fd, &rdata, 1);
	printf("0, SEEK_SET: %d\n", rdata);

	lseek(fd, 128, SEEK_SET);
	read(fd, &rdata, 1);
	printf("128, SEEK_SET: %d\n", rdata);

	lseek(fd, -1, SEEK_END);
	ret = read(fd, &rdata, 1); // 1이 나오면 잘읽힌 것
	printf("ret : %d\n", ret);
	printf("0, SEEK_END: %d\n", rdata);

	lseek(fd, 10, SEEK_END);
	write(fd, wdata, sizeof(wdata));

	close(fd);
}
