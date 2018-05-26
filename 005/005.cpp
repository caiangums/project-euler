#include <iostream>
#include <math.h>
#include <list>

using namespace std;

bool equal_one(int v) {
    return v == 1;
}

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
    for(int i = 3; i < n; i += 2) {
        double result = (double) n / (double) i;
        if (is_integer(result)) {
            return false;
        }
    }
    return true;
}

int next_prime(list<int>* primes) {
    int v = primes->front();
    primes->pop_front();
    return v;
}

bool are_equal(list<int> first, list<int> second) {
    if (first.size() != second.size()) {
        return false;
    }
    list<int>::iterator f;
    list<int>::iterator s;
    for(f = first.begin(), s = second.begin(); f != first.end(); f++, s++) {
        if (f != s) {
            return false;
        }
    }
    return true;
}

int solve() {
    // numbers list, prime list
    list<int> nl, pl;
    for (int i = 1; i <= 20; i++) {
        nl.push_back(i);
        if (is_prime(i)) {
            pl.push_back(i);
        }
    }

    int prime = next_prime(&pl);
    bool stopped;
    int result = 1;
    while (nl.size() != 0) {
        // new numbers list
        list<int> nnl;
        stopped = true;
        nl.remove_if(equal_one);
        for (int val : nl) {
            if (val % prime != 0) {
                nnl.push_back(val);
            } else {
                nnl.push_back(val/prime);
                stopped = false;
            }
        }
        nnl.remove_if(equal_one);
        if (!stopped && !are_equal(nl, nnl)) {
            result = result * prime;
        } else {
            prime = next_prime(&pl);
        }
        nl = nnl;
    }
    return result;
}

int main(int argc, char** argv) {
    int result = solve();
    cout << "The smallest number that can be divided by all numbers in 1 - 20 is " << result << endl;
    return 0;
}
