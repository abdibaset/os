#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  // provides access to portal operating system interface (POSIX)
                     // operating system API

int main(int argc, char *argv[]) {
    int status;
    int options;
    printf("hello (pid: %d)\n", (int)getpid());

    // after fork() system, a child(new) process is created. Both
    // the parent and child have an rc values. The rc value of the
    // parent is the child's pid, while the child's rc = 0.
    // The child process created clones the parent's heap,
    // stack, data and code segment
    int rc = fork();

    // the order of execution of the if blocks is determined
    // by the scheduler. The scheduler determines which process
    // has access to the CPU first for execution
    // the child gets a private copy of the heap of the parent.
    // if the heap is modified, a modified copy of the heap is generated
    // and they are private to their respective process (parent or child)
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(EXIT_SUCCESS);
    } else if (rc == 0) {
        // child process
        printf("child (pid: %d)\n", (int)getpid());
    } else {
        // await for child to complete
        // int rc_wait = wait(NULL);
        int rc_wait = waitpid(rc, &status, options = 0);
        // executed for the parent process. rc - child's pid
        // getpid() - returns the parent's pid.
        printf("parent of %d (rc_wait: %d) (pid: %d)\n", rc, rc_wait, (int)getpid());
    }
    return 0;
}