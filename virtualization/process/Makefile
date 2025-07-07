cc_flags=-Wall -pedantic -Wno-strict-prototypes -Wno-format-pedantic -Wno-newline-eof -std=c99

all: fork_test_1 fork_test_2 exec_test

fork_test_1: fork_test_1.c
	gcc $(cc_flags) -o fork_test_1 fork_test_1.c -lpthread

fork_test_2: fork_test_2.c
	gcc $(cc_flags) -o fork_test_2 fork_test_2.c -lpthread

exec_test: exec_test.c
	gcc $(cc_flags) -o exec_test exec_test.c 

clean:
	rm -f fork_test_1 fork_test_2 exec_test *.o