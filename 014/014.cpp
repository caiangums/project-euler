#include <iostream>
#include <vector>


using namespace std;

vector<long> * chain;
vector<long> * longest_chain;

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

long solve() {
    long value = 0;
    longest_chain = new vector<long>();
    for (long i = 2; i <= 1000000; i++) {
        value = i;
        chain = new vector<long>();
        chain->push_back(value);
        while (value > 1) {
            value = collatz(value);
            chain->push_back(value);
        }
        if (chain->size() > longest_chain->size()) {
            //cout << "value=" << i << ", chain->size=" << chain->size() << endl;
            //print_chain(chain);
            delete longest_chain;
            longest_chain = new vector<long>(*chain);
        }
        delete chain;
    }
    long rv = longest_chain->at(0);
    delete longest_chain;
    return rv;
}

int main(int argc, char** argv) {
    long result = solve();
    cout << "The result is " << result << endl;
}
