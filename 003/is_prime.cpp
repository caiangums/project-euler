#include <iostream>
#include <math.h>

using namespace std;

bool isInteger(double d) {
    return floor(d) == d;
}

bool isPrime(int n) {
    if (n == 2 || n == 3) {
        return true;
    }
    if (!n || n == 1 || n % 2 == 0) {
        return false;
    }
    for(int i = 3; i < n; i += 2) {
        double result = (double) n / (double) i;
        if (isInteger(result)) {
            return false;
        }
    }
    return true;
}

int main(int argc, char** argv) {
    int n = 0;
    if (argc == 2) {
        n = atoi(argv[1]);
    }

    if (isPrime(n)) {
        cout << n << " is prime!" << endl;
    } else {
        cout << n << " is NOT prime!" << endl;
    }

    return 0;
}
