#include <stdio.h>
#include <unistd.h>

int main() {
    //  printf("printf: hello") - in this case 'write' which is unbuffered appears
    // on stdout first
    // printf("printf: hello\n") - '\n' flushes the buffer to stdout or use fflush(stdout)
    printf("printf: hello");
    // fflush(stdout);
    write(STDOUT_FILENO, "write: hello\n", 13);
    return 0;
}