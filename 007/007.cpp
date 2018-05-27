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
    int limit = sqrt(n);
    for(int i = 3; i <= limit; i += 2) {
        double result = (double) n / (double) i;
        if (is_integer(result)) {
            return false;
        }
    }
    return true;
}


int solve() {
    int count = 0, i = 1;
    while (true) {
        if (is_prime(i)) {
            count++;
            if (count == 10001) {
                cout << count << endl;
                return i;
            }
        }
        i++;
    }

    return 0;
}

int main(int argc, char** argv) {
    int result = solve();
    cout << "The 10 001th prime is " << result << endl;
    return 0;
}
