#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ULL;

ULL fib(ULL i) {
    if (i == 0) {
        return 0;
    }
    if (i < 3) {
        return 1;
    }
    return fib(i-1) + fib(i-2);
}


int main(int argc, char** argv) {
    ULL i = strtoull(argv[1], NULL, 10);

    ULL result = fib(i);
    printf("The result is %llu\n", result);
    return 0;
}
