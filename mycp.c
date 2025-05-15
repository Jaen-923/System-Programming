/*
 * 학과: 사이버보안학과
 * 학번: 202510081
 * 성명: 옥재은
 * 작성일: 2025-05-14
 */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>

#define BUF_SIZE 1024

int main(int argc, char* argv[]) {

    int src_fd;
    int dst_fd;
    ssize_t ret;
    ssize_t result = 0;
    char buf[BUF_SIZE];

    // 실행 인자가 2개(입력, 출력 파일)인지 확인
    if (argc != 3) {
        printf("Usage: %s input.txt output.txt\n", argv[0]);
        exit(1);
    }

    // 입력 파일의 정보를 가져옴
    if (stat(argv[1], &src_stat) == -1) {
        perror("stat(src)");
        exit(1);
    }

    // 출력 파일의 정보도 가져옴
    if (stat(argv[2], &dst_stat) == 0) {
        
        // 입력 파일과 출력 파일이 같은지 확인
        if (src_stat.st_ino == dst_stat.st_ino && src_stat.st_dev == dst_stat.st_dev) {
            printf("input and output files are the same.\n");
            exit(1);
        }
    }


    // 입력 파일 열기 (읽기 전용)
    src_fd = open(argv[1], O_RDONLY);
    if (src_fd == -1) {
        perror("open(src)");
        exit(1);
    }

    dst_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dst_fd == -1) {
        perror("open(dst)");
        close(src_fd);
        exit(1);
    }

    // 파일 복사 루프
    while (1) {
        ret = read(src_fd, buf, BUF_SIZE);
        
        if (ret > 0) {
            ssize_t written = 0;

            // 다 쓸 때까지 반복적으로 write 호출
            while (written < ret) {
                ssize_t nr = write(dst_fd, buf + written, ret - written);
                if (nr == -1) {
                    perror("write(dst)");
                    close(src_fd);
                    close(dst_fd);
                    exit(1);
                }
                written += nr;
            }
            result += ret;
        } else if (ret == 0) { 
            break;
        } else {
            if (errno == EINTR || errno == EAGAIN) {
                usleep(10000);
                continue;
            } else {
                perror("read(src)");
                close(src_fd);
                close(dst_fd);
                exit(1);
            }
        }
    }
    
     // 입력 파일 닫기
    if (close(src_fd) == -1) {
        perror("close(src)");
    }

     // 출력 파일 닫기
    if (close(dst_fd) == -1) {
        perror("close(dst)");
    }

    printf("Copy completed: %zd bytes written.\n", result);


    return 0;
}