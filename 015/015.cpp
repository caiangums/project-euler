#include <iostream>


using namespace std;

double fact(int n) {
    return n > 1 ? n * fact(n-1) : 1;
}

double fact_stop(int n, int s) {
    return n > s ? n * fact_stop(n-1, s) : 1;
}

double lattice_paths(int n) {
    double t = fact_stop(2*n, n);
    cout << "t=" << t << ", ";
    double d = fact(n);
    cout << "d=" << d << endl;;
    return (double) t/d;
}

double solve() {
    cout << "Insert a size" << endl;
    int size;
    cin >> size;
    return lattice_paths(size);
}

int main(int argc, char** argv) {
    double result = solve();
    cout << "The result is " << result << endl;
}
