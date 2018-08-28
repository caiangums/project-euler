#include <iostream>
#include <cmath>

using namespace std;


long triangle(long count, int value) {
    return  value + count;
}

int divisors(long value) {
    int d = 0;
    for (int i = 1; i <= sqrt(value); i++) {
        if (value % i == 0) {
            d += value/i != i ? 2 : 1;
        }
    }
    return d;
}

int solve() {
    long long v = 0;
    int d = 0;
    for (int i = 1; d < 500 && v >= 0; i++) {
        v = triangle(v, i);
        d = divisors(v);
    }
    return v;
}

int main(int argc, char** argv) {
    long result = solve();
    cout << "The result is " << result << endl;
}
