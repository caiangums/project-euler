#include <stdio.h>
#include <stdlib.h>

#define LIMIT 4000000
typedef unsigned long long ULL;

ULL fib(ULL i) {
    if (i == 0) {
        return 1;
    }
    if (i == 1) {
        return 2;
    }
    return fib(i-1) + fib(i-2);
}


int main(int argc, char** argv) {
    ULL limit = LIMIT;
    if (argc == 2) {
        limit = strtoull(argv[1], NULL, 10);
    }

    ULL result = 0;
    ULL fn = fib(0);;
    for (ULL i = 1; fn < limit; i++) {
        //printf("fn: %llu\n", fn);
        if (!(fn % 2)) {
            result += fn;
        }
        fn = fib(i);
    }

    printf("The result is %llu\n", result);
    return 0;
}
