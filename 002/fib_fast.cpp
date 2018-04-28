#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef long double LD;
typedef unsigned long long ULL;

LD phi = (sqrt(5) + 1) / 2;
LD phi_inverse = phi - 1;;

ULL fib(int i) {
    return (ULL) ((pow(phi, i) - pow(-phi_inverse, i)) / sqrt(5));
}


int main(int argc, char** argv) {
    int i = strtold(argv[1], NULL);

    ULL result = fib(i);
    printf("The result is %llu\n", result);
    return 0;
}
