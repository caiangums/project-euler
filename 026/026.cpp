#include <iostream>
#include <vector>
#include <map>
#include <string>


using namespace std;

typedef map<int, int> map_remainders;

string find_recurring_sequence(int n) {
    map_remainders rem_map;

    int remainder = 1%n;

    return to_string(remainder);
}

int solve() {
    for (int i = 1; i <= 10; i++) {
        cout << "seq(1/" << i << ")\t= " << find_recurring_sequence(i) << endl;
    }


    return 0;
}

int main(int argc, char** argv) {
    int rv = solve();
    cout << "result = " << rv << endl;
}
