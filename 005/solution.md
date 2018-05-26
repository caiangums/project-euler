All the code discussed and presented here can be seen in my [personal repository](https://github.com/caian-gums/project-euler/).

# How the solution works

My solution consists in create a list with all numbers from `1 - 20` and findind a list of primes that makes that list end up with the number `1` in all positions.

In order to make this approach, I used the `std::list` from `C++` and a feature from `C++11` named `remove_if()`.

### Prime List

For a prime list, I've used my prime searcher funcions from last problems

```cpp
// Check if the number is integer
bool is_integer(double d) {
    return floor(d) == d;
}

// Check if the number is prime
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
```

And with that, I can fill a prime list with all the primes until the number I want to search (in problem case, the number is `20`)

### List - std::list

For the List Object, I've used the `std::list`. Some functions was implemented to help the code readability and abstractions.

```cpp
// Check if the number is equal one. This is a callback function for remove_if()
bool equal_one(int v) {
    return v == 1;
}

// Pop the next number of the prime list
int next_prime(list<int>* primes) {
    int v = primes->front();
    primes->pop_front();
    return v;
}

// Check if the both lists are equal
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
```

## Result

The final code is

```cpp
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
```

# Performance

The output on my terminal was:
```
$ 005: time ./a.out
The smallest number that can be divided by all numbers in 1 - 20 is 232792560
./a.out  0.00s user 0.00s system 62% cpu 0.005 total
```
