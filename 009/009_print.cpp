#include <iostream>
#include <math.h>
#include <string>

using namespace std;


template<class T>
class PythagoreanTriple {
    private:
        T _a, _b, _c;
    public:
        PythagoreanTriple(T a, T b, T c): _a(a), _b(b), _c(c) {}

        T a() const { return _a; }
        T b() const { return _b; }
        T c() const { return _c; }
        T sum() const { return _a + _b + _c; }
        T product() const { return _a * _b * _c; }
};


PythagoreanTriple<int>* find(int m, int n) {
    if (m < n) {
        return find(n, m);
    }
    int a = pow(m, 2) + pow(n, 2);
    int b = 2*m*n;
    int c = pow(m, 2) - pow(n, 2);

    PythagoreanTriple<int>* t = new PythagoreanTriple<int>(a, b, c);
    return t;
}

void printTriple(PythagoreanTriple<int>* t, string str) {
    cout << "Triple: " << str << endl;
    cout << "a: " << t->a() << endl;
    cout << "b: " << t->b() << endl;
    cout << "c: " << t->c() << endl;
    cout << "a+b+c = " << t->sum() << endl;
    cout << "abc = " << t->product() << endl;
}

long solve() {
    PythagoreanTriple<int>* t = new PythagoreanTriple<int>(1, 2, 3);

    int i, j, rv = 0, sum = 0;
    for (i = 2; sum != 1000 && i <= 50; i++) {
        for (j = 1; sum != 1000 && j < i; j++) {
            delete t;
            t = find(j, i);
            sum = t->sum();
        }
    }

    string s = "" + to_string(j) + ", " + to_string(i);
    printTriple(t, s);
    rv = t->product();
    delete t;
    return rv;
}

int main(int argc, char** argv) {
    long result = solve();
    cout << "The result is " << result << endl;
}
