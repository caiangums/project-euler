#include <stdio.h>

int main() {
    unsigned result = 0;
    bool correct = true;
    for (unsigned i = 3; i < 1000; i += 6) {
        unsigned j = i;
        while (j <= 1000) {
            result += j;
            j = j << 2;
            correct = correct && !(j % 3);
        }
    }

    if (correct) {
        printf("Is correct!\n");
    }

    printf("Result from 3 is: %u!\n", result);
    return 0;
}
