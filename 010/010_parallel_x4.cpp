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
    long rv1 = 2, rv2 = 0, rv3 = 0, rv4 = 0;;
    thread section_1 (sum_primes, 1, 500000, &rv1);
    thread section_2 (sum_primes, 500001, 1000000, &rv2);
    thread section_3 (sum_primes, 1000001, 1500000, &rv3);
    thread section_4 (sum_primes, 1500001, 2000000, &rv4);

    section_1.join();
    section_2.join();
    section_3.join();
    section_4.join();
    return rv1 + rv2 + rv3 + rv4;
}

int main(int argc, char** argv) {
    long result = solve();
    cout << "The result is " << result << endl;
}
