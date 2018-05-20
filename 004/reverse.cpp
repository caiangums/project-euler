#include <iostream>

using namespace std;


long reverse(long n) {
    long v = n, rv = 0;
    do {
        rv = (rv*10) + (v%10);
        v = v/10;
    } while (v > 0);
    return rv;
}

int main(int argc, char** argv) {
    long n = 0;
    if (argc == 2) {
        n = atol(argv[1]);
    }

    long rn = reverse(n);
    cout << "Reverse " << rn << endl;
}
