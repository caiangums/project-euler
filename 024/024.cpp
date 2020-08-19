#include <iostream>
#include <string>
#include <algorithm>


using namespace std;

const int EQUAL_STRINGS = 0;

string perm = "0123456789";

string solve() {
    string reversed = perm;
    reverse(reversed.begin(), reversed.end());
    string o = perm;

    int k = 1;
    while (o.compare(reversed) != EQUAL_STRINGS && ++k <= 1000000) {
        next_permutation(o.begin(), o.end());
    }

    return o;
}

int main(int argc, char** argv) {
    string rv = solve();
    cout << "result = " << rv << endl;
}

