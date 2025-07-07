#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  // provides access to portal operating system interface (POSIX)
                     // operating system API

int main(int argc, char *argv[]) {
    printf("hello (pid: %d)\n", (int)getpid());

    // after fork() system, a child(new) process is created. Both
    // the parent and child have an rc values. The rc value of the
    // parent is the child's pid, while the child's rc = 0.
    // At fork(), the parent and the child share the same physical
    // memory pages. The child gets a copy (not a real, physical copy - read only copy)
    // of parent's memory: heap,stack, data and code segment.
    // However, due to copy-on-write (COW) optimization, the memory isn't
    // copied immediately. If either process modifies a shared page (eg: heap)
    // a private copy is made for that process.
    int rc = fork();

    // the order of execution of the if blocks is determined
    // by the scheduler. The scheduler determines which process
    // has access to the CPU first for execution
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(EXIT_SUCCESS);
    } else if (rc == 0) {
        // child process
        printf("child (pid: %d)\n", (int)getpid());
    } else {
        // executed for the parent process. rc - child's pid
        // getpid() - returns the parent's pid.
        printf("parent of %d (pid: %d)\n", rc, (int)getpid());
    }
    return 0;
}