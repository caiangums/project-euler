# How my solution works

Using some analysis about the problem and lookin in the web for some better solutions as alternatives to 'brute force', I found something to explore a better aproach to Fibonacci numbers: The  _Binet's Formula for the nth Fibonacci Number_. Let's deep dive.

### Step 01 - Brute Force
First things first. Before try to solve the problem, I wrote a fibonacci function as it is well known.

#### Fibonacci nth number Generator - Brute Force Version

```cpp
#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ULL;

ULL fib(ULL i) {
    if (i == 0) {
        return 0;
    }
    if (i < 3) {
        return 1;
    }
    return fib(i-1) + fib(i-2);
}


int main(int argc, char** argv) {
    ULL i = strtoull(argv[1], NULL, 10);

    ULL result = fib(i);
    printf("The result is %llu\n", result);
    return 0;
}
```

As you may notice the first number that this fibonacci implementation output is `0`. This is not my first implementation of the sequence but later I'll discuss why I done this.

The important thing here is: I have my fibonacci implementation that is recursive and have `O(n)`.

#### Problem Solving
I felt that the problem as it is was easy to solve, and probably that's why it is a `5%` difficulty problem.

```cpp
// 002_slow.cpp
#include <stdio.h>
#include <stdlib.h>

#define LIMIT 4000000
typedef unsigned long long ULL;

ULL fib(ULL i) {
    if (i == 0) {
        return 1;
    }
    if (i == 1) {
        return 2;
    }
    return fib(i-1) + fib(i-2);
}


int main(int argc, char** argv) {
    ULL limit = LIMIT;
    if (argc == 2) {
        limit = strtoull(argv[1], NULL, 10);
    }

    ULL result = 0;
    ULL fn = fib(0);;
    for (ULL i = 1; fn < limit; i++) {
        //printf("fn: %llu\n", fn);
        if (!(fn % 2)) {
            result += fn;
        }
        fn = fib(i);
    }

    printf("The result is %llu\n", result);
    return 0;
}
```

Here I changed a little the fibonacci generator function just to act like the real problem description in order to get the feeling of solving the problem. As I said: this is the 'brute force' version and with no further analysis.

This code has a for-loop `O(n)` that has a recursive call to fibonacci function `O(n)`. The moment I look this I searched for some solution or better approach.


### Step 02 - Analyze the Solution

If you read my `solution.md` on previous problem you will get the feeling that I'm doing the same trick here. And that is exactly the thing that I'm doing.

I started to scratch the number and noticed that they have some interesting properties. Based on Mathematic Properties of numbers:
* The sum of two different integer numbers can only be **even** or **odd**.
* If the numbers are both **even** or **odd** the sum is **even**
* If the numbers are different (one **even** and other **odd**) the sum is **odd**

The sequence keeps the order (o - odd, e - even)
```
1  1  2  3  5  8  13  21  34  55  89  ...
o  o  e  o  o  e   o   o   e   o   o  ...
```

So, You just need to jump between 3 numbers to sum all even numbers on fibonacci sequence, and this is the code that runs faster than the 'brute force'. The code is just the for-loop to replace on the original one.
```cpp
// 002_better.cpp
for (ULL i = 1; fn < limit; i += 3)
```

This simple analysis reduce the running time by half with no mathematic otimization.

### Step 03 - The Binet's Formula
You can search on reference section for the link about this. The formula is based on the **Phi** number and it's inverse (**phi**).
The code is
```cpp
fib(n) = (Phi^n - (-(phi)^n)) / sqrt(5);
```

With this formula the fibonacci number can be found in `O(1)`, that reduces even more the processing time spent.

## Result
To see the real function beeing tested, I compiled and tested with a big number, the greater without overflow. The number is 100000000.

The final code is
```cpp
// 002.cpp
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LIMIT 4000000
typedef long double LD;
typedef unsigned long long ULL;

LD phi = (sqrt(5) + 1) / 2;
LD phi_inverse = phi - 1;;

ULL fib(int i) {
    return (ULL) ((pow(phi, i) - pow(-phi_inverse, i)) / sqrt(5));
}

int main(int argc, char** argv) {
    int limit = LIMIT;
    if (argc == 2) {
        limit = atoi(argv[1]);
    }

    ULL result = 0;
    ULL fn = fib(2);
    for (int i = 3; fn < limit; i++) {
        if (!(fn % 2)) {
            result += fn;
        }
        //printf("fn: %llu\n", fn);
        fn = fib(i);
    }

    printf("The result is %llu\n", result);
    return 0;
}
```

The output on my terminal was:
```
$ 002: time ./slow.out 1000000000
The result is 350704366
./slow.out 1000000000  8.88s user 0.01s system 99% cpu 8.904 total
$ 002: time ./better.out 1000000000
The result is 350704366
./better.out 1000000000  4.45s user 0.01s system 99% cpu 4.469 total
$ 002: time ./a.out 1000000000
The result is 350704366
./a.out 1000000000  0.00s user 0.00s system 56% cpu 0.005 total
```

### References

* [Binet's Formula for the nth Fibonacci number](http://www.maths.surrey.ac.uk/hosted-sites/R.Knott/Fibonacci/fibFormula.html)
