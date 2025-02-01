cc_flags=-Wall -pedantic -Wno-strict-prototypes -Wno-format-pedantic -Wno-newline-eof -std=c99

all: mem_alloc

m_threads: m_threads.c common.h common_threads.h
	gcc $(cc_flags) -o m_threads m_threads.c -lpthread

mem_alloc: mem_alloc.c common.h
	gcc $(cc_flags) -o mem_alloc mem_alloc.c

clean:
	rm -f mem_alloc *.o