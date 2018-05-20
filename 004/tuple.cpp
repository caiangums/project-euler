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


int main(int argc, char** argv) {
    long x = 6, y = 9;
    double z = 13.2;
    SingleTypeTuple<long> t(x, y);
    Tuple<long, double> r(x, z);
    cout << "Your single type tuple is [" << t.first() << ", " << t.second() << "]" << endl;
    cout << "Your different type tuple is [" << r.first() << ", " << r.second() << "]" << endl;
}
