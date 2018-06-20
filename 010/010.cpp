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

long solve() {
    int i;
    long rv = 0;
    for (i = 1; i < 2000000; i++) {
        if (is_prime(i)) {
            rv += i;
        }
    }
    return rv;
}

int main(int argc, char** argv) {
    long result = solve();
    cout << "The result is " << result << endl;
}
