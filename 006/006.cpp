#include <iostream>

using namespace std;


int sum_numbers_until(int n) {
    return (n*(n+1))/2;
}

int young_gauss_sum_squares(int n) {
    return (n*(n+1)*((2*n)+1))/6;
}

int solve() {
    int limit = 100;
    int sum_of_squares = young_gauss_sum_squares(limit);
    int sum = sum_numbers_until(limit);
    return (sum*sum) - sum_of_squares;
}

int main(int argc, char** argv) {
    int result = solve();
    cout << "The difference is " << result << endl;
    return 0;
}
