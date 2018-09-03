#include <iostream>
#include <vector>


using namespace std;

vector<long> * chain;

long collatz(long n) {
    return n % 2 ? 3*n + 1 : n/2;
}

void print_chain(vector<long> * c) {
    cout << "Chain = [";
    int i = 0;
    for (i = 0; i < c->size() - 1; i++) {
        cout << c->at(i) << ", ";
    }
    cout << c->at(i) << "]" << endl;
}

int main() {
    bool stop = false, odd = false;
    long value = 1;
    cout << "starting value: " << endl;
    cin >> value;
    chain = new vector<long>();
    chain->push_back(value);
    while (value > 1) {
        value = collatz(value);
        chain->push_back(value);
    }

    cout << "Final chain" << endl;
    print_chain(chain);

    delete chain;
}
