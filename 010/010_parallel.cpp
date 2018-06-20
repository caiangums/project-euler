#include <iostream>
#include <math.h>
#include <thread>

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

void sum_primes(int from, int to, long* result) {
    int i;
    for (i = from; i <= to; i += 2) {
        if (is_prime(i)) {
            *result += i;
        }
    }
}

long solve() {
    long rv1 = 2, rv2 = 0;
    thread first_section (sum_primes, 1, 1000000, &rv1);
    thread second_section (sum_primes, 1000001, 2000000, &rv2);

    first_section.join();
    second_section.join();
    return rv1 + rv2;
}

int main(int argc, char** argv) {
    long result = solve();
    cout << "The result is " << result << endl;
}
