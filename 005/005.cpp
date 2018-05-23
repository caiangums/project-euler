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

void fill_prime_list(list<int>* primes) {
    for (int i = 2; i < 20; i++) {
        if (is_prime(i)) {
            primes->push_back(i);
        }
    }
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
    for(f = first.begin(), s = second.begin(); f != first.end() && s != second.end(); f++, s++) {
        if (f != s) {
            return false;
        }
    }
    return true;
}

int solve() {
    // fill numbers
    list<int> l;
    for (int i = 1; i <= 20; i++) {
        l.push_back(i);
    }

    // fill prime list
    list<int> primes;
    fill_prime_list(&primes);

    // get prime
    int prime = next_prime(&primes);
    bool run = true, stopped;
    int result = 1;
    while (run) {
        list<int> m;
        stopped = true;
        l.remove_if(equal_one);
        for (int v : l) {
            if (v % prime != 0) {
                m.push_back(v);
            } else {
                m.push_back(v/prime);
                stopped = false;
            }
        }
        m.remove_if(equal_one);
        if (!stopped && !are_equal(l, m)) {
            result = result * prime;
        } else {
            prime = next_prime(&primes);
        }
        l = m;
        if (l.size() == 0) {
            run = false;
        }
    }
    return result;
}

int main(int argc, char** argv) {
    int result = solve();
    cout << "The smallest number that can be divided by all numbers in 1 - 20 is " << result << endl;
    return 0;
}
