#include <sys/types.h>
#include <unistd.h>
#include <stdint.h>
#include <stdio.h>

int main(void) {

    printf("My pid = %jd\n", (intmax_t)getpid());
    printf("Parent's pid = %jd\n", (intmax_t)getppid());
    return 1;
    
}