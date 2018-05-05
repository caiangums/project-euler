#include <iostream>
#include <cmath>

using namespace std;

bool isInteger(double d) {
    return floor(d) == d;
}

bool isPrime(long n) {
    if (!n || n == 1) {
        return false;
    }
    if (n == 2 || n == 3) {
        return true;
    }
    if (n % 2 == 0) {
        return false;
    }
    for(long double i = 3; i < n; i += 2) {
        double result = (double) n / (double) i;
        if (isInteger(result)) {
            return false;
        }
    }
    return true;
}

int main(int argc, char** argv) {
    long double v = 0;
    if (argc == 2) {
        v = atof(argv[1]);
    }
    // long double v = 600851475143;
    // double v = 13195;
    long double rest = v;
    long double result = v;
    for (long double i = 2; i <= v/2; i++) {
        if (isPrime(i)) {
            long double tmp = rest / i;
            while (isInteger(tmp) && floor(tmp) >= 1) {
                cout << i << " : " << tmp << endl;
                rest = tmp;
                tmp = rest / i;
                result = i;
            }
        }
        if (rest == 1) {
            break;
        }
    }

    cout << "Largest Prime Factor is " << result << endl;

    return 0;
}
