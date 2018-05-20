#include <iostream>

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


template<class S, class R>
class Tuple {
    private:
        S _first;
        R _second;
    public:
        Tuple(S first, R second): _first(first), _second(second) {}

        S first() { return _first; }
        R second() { return _second; }
};

int reverse(int n) {
    int v = n, rv = 0;
    do {
        rv = (rv*10) + (v%10);
        v = v/10;
    } while (v > 0);
    return rv;
}

Tuple<int, SingleTypeTuple<int> > solve() {
    int v = 0;
    for (int i = 999; i > 99; i--) {
        for (int j = 999; j > i-100; j--) {
            v = i*j;
            if (v == reverse(v)) {
                SingleTypeTuple<int> stt(i, j);
                Tuple<int, SingleTypeTuple<int> > t(v, stt);
                return t;
            }
        }
    }
    SingleTypeTuple<int> stt(0, 0);
    Tuple<int, SingleTypeTuple<int> > t(0, stt);
    return t;
}

int main(int argc, char** argv) {
    Tuple<int, SingleTypeTuple<int> > result = solve();
    cout << "Largest Palindromic Number is " << result.first()
        << " = " << result.second().first()
        << " * " << result.second().second()
        << endl;
}
