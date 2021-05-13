#include <iostream>
#include <vector>
#include <cmath>


const int MAX_M = 50;
const int MAX_N = 70;

using namespace std;

template<class T>
class SingleTypeTuple {
    private:
        T _first, _second;
    public:
        SingleTypeTuple(T first, T second): _first(first), _second(second) {}

        T first() { return _first; }
        T second() { return _second; }
};

// based on is_prime
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

// based on Euler's Rule
double get_p(int m, int n) {
    return (pow(2, n - m) + 1) * pow(2, m) - 1;
}

double get_q(int m, int n) {
    return (pow(2, n - m) + 1) * pow(2, n) - 1;
}

double get_r(int m, int n) {
    return pow((pow(2, n - m) + 1), 2) * pow(2, m + n) - 1;
}

double get_pq_dependant(int n, int p, int q) {
    return pow(2, n) * p * q;
}

double get_r_dependant(int n, int r) {
    return pow(2, n) * r;
}

int solve() {
    vector<SingleTypeTuple<long long> *> * amicable = new vector<SingleTypeTuple<long long> *>();

    for (int i = 1; i <= MAX_M; i++) {
        for (int j = i + 1; j <= MAX_N; j++) {
            int p = (int) get_p(i, j);
            int q = (int) get_q(i, j);
            int r = (int) get_r(i, j);

            if (is_prime(p) && is_prime(q) && is_prime(r)) {
                long long pq_dependant = (long long) get_pq_dependant(j, p, q);
                long long r_dependant = (long long) get_r_dependant(j, r);

                cout << "tuple (n=" << j << ", m=" << i << ")\n";
                cout << "amicable (" << pq_dependant << ", " << r_dependant << ")\n";

                SingleTypeTuple<long long> * t = new SingleTypeTuple<long long>(pq_dependant, r_dependant);

                amicable->push_back(t);
            }
        }
    }

    return 0;
}

int main(int argc, char** argv) {
    int rv = solve();
    cout << "result = " << rv << endl;
}
