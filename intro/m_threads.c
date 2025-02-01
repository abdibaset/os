#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "common_threads.h"

volatile int counter = 0; // shared global variable
int loops; // determines number of times each thread increments the counter

void *worker(void *arg) {

    // what happens
    // load value of counter into a register
    // increment counter
    // store value of counter back to memory
    for (int i = 0; i <loops; i++){
        counter++; // update the volatile counter
    }
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "usage: threads <values>\n");
        exit(EXIT_FAILURE);
    }

    // get the number of loops from the command line
    loops = atoi(argv[1]);
    pthread_t p1, p2;
    printf("Initial counter value: %d\n", counter);

    Pthread_create(&p1, NULL, worker, NULL);
    Pthread_create(&p2, NULL, worker, NULL);

    Pthread_join(p1, NULL);
    Pthread_join(p2, NULL);

    // print the final counter value
    printf("Final counter value: %d\n", counter);
    return 0;
}