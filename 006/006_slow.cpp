#include <iostream>

using namespace std;


int solve() {
    int i, sum = 0, sum_of_squares = 0;
    for (i = 1; i <= 100; i++) {
        sum += i;
        sum_of_squares += i*i;
    }
    return (sum*sum) - sum_of_squares;
}

int main(int argc, char** argv) {
    int result = solve();
    cout << "The difference is " << result << endl;
    return 0;
}
