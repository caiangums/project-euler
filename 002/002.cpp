#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LIMIT 4000000
typedef long double LD;
typedef unsigned long long ULL;

LD phi = (sqrt(5) + 1) / 2;
LD phi_inverse = phi - 1;

ULL fib(int i) {
    return (ULL) ((pow(phi, i) - pow(-phi_inverse, i)) / sqrt(5));
}

int main(int argc, char** argv) {
    int limit = LIMIT;
    if (argc == 2) {
        limit = atoi(argv[1]);
    }

    ULL result = 0;
    ULL fn = fib(2);
    for (int i = 3; fn < limit; i++) {
        if (!(fn % 2)) {
            result += fn;
        }
        //printf("fn: %llu\n", fn);
        fn = fib(i);
    }

    printf("The result is %llu\n", result);
    return 0;
}
