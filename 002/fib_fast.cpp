#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef long double LD;
typedef unsigned long long ULL;

LD phi = (sqrt(5) + 1) / 2;
LD phi_inverse = phi - 1;;

LD fib(int i) {
    return (pow(phi, i) - pow(-phi_inverse, i)) / sqrt(5);
}


int main(int argc, char** argv) {
    LD i = strtold(argv[1], NULL);

    LD result = fib(i);
    ULL rounded_result = (ULL) result;
    printf("The result is %llu\n", rounded_result);
    return 0;
}
