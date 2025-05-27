#include <stdlib.h>
#include <signal.h>

int main() {
    int *ptr = NULL;
    *ptr = 1; 

    // abort();

    // kill(getpid(), SIGSEGV);

    return 0;
}