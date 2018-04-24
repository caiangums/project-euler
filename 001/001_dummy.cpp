#include <stdio.h>

#define LIMIT 1000

int main() {
    unsigned long long result = 0;
    for (unsigned long long i = 1; i < LIMIT; i++) {
        if (!(i % 3) || !(i % 5)) {
            result += i;
            //printf("result = %u, i = %u\n", result, i);
        }
    }

    printf("Result is %llu\n", result);
    return 0;
}
