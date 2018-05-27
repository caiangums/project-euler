#include <iostream>
#include <math.h>

using namespace std;

bool is_integer(double d) {
    return floor(d) == d;
}

bool is_prime(int n) {
    if (n == 2 || n == 3) {
        return true;
    }
    if (!n || n == 1 || n % 2 == 0) {
        return false;
    }
    for(int i = 3; i <= sqrt(n); i += 2) {
        double result = (double) n / (double) i;
        if (is_integer(result)) {
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

    if (is_prime(n)) {
        cout << n << " is prime!" << endl;
    } else {
        cout << n << " is NOT prime!" << endl;
    }

    return 0;
}
