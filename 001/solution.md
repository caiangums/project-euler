# How my solution works

At first moment, I like to show the 'brute force' solution and proceed to my approach.
```cpp
#include <stdio.h>

#define LIMIT 1000

int main() {
    unsigned result = 0;
    for (unsigned i = 1; i < LIMIT; i++) {
        if (!(i % 3) || !(i % 5)) {
            result += i;
        }
    }

    printf("Result is %u\n", result);
    return 0;
}
```
So, this is the most common approach and the most common I saw. And it's from it that I took my approach.

### Step 01
I observed that I can jump each 3 numbers and sum all 3-multiple numbers. This reduces the complexity to one-third and that is a great performance enhancement!
**Note:** On this moment I need to start my count with 3.
```cpp
for (unsigned i = 3; i < LIMIT; i += 3)
```

### Step 02
As my second sight, I decided to look about the binary numbers and found a nice correlation:
```
3     -      11
6     -     110
9     -    1001
12    -    1100
15    -    1111
18    -   10010
21    -   10101
...
```
If you look closely, you can find that all the numbers that are 3-multiple and binary equivalent with just a left logical shift can be classified with a 6-jump. See that:
```
- 3 (11), 6 (110), 12 (1100)
- 9 (1001), 18 (10010), 36 (100100)
- 15 (1111), 30 (11110), 60 (111100)
- 21 (10101), 42 (101010), 84 (1010100)
- ...
```
That correlation allows you to jump each 6 numbers, reducing the complexity of the for-loop by half(that was already reduced to one-third), but you must find all the numbers that are multiples of the 'root' number with left logical shifts. That's good because the operation of a left logical shift is a low-cost and efficient in almost all machines because they use binary module.
My code now seems so much efficient than before:
```cpp
for (unsigned i = 3; i < LIMIT; i += 6)
```

### Step 03
So now I know all the numbers below the given number, with 6-jump. How can I know the 5-multiple numbers?
Happens that some numbers are multiples of 3 and 5. I just found them and listed on a 5-multiple numbers to find some correlation:

`0  5  10  [15]  20  25  [30]  35  40  [45]  50  55  [60] ...`

As you may notice, each marked number has just 2 non-multiple number by 3 and 5. You can just sum the number before and after in that list and then you sum all the numbers that are 5-multiple and not 3-multiple, based on the 3,5-multiple number. The only problem with this approach is that the first number(5) is never reached so you need to start with it.

## Result
In order to see the REAL DEAL, I compile my program and run with 'time' command on terminal to compare the 'brute force' solution with my solution. As the number to represent such greater number, I changed the precision to `unsigned long long` and run with the greater number that I can run without overflow. The number is 1000000000

My final code is
```cpp
#include <stdio.h>

#define LIMIT 1000

int main() {
    unsigned long long result = 0;
    for (unsigned long long i = 3; i < LIMIT; i += 6) {
        unsigned long long j = i;
        while (j < LIMIT) {
            result += j;
            if (!(j % 5)) {
                result += (j-5);
                if (j + 5 < LIMIT) {
                    result += (j+5);
                }
            }
            j = j << 1;
        }
    }

    printf("Result is %llu\n", result);
    return 0;
}
```

The output on my terminal when I run with the 1000000000 value was:
```
$ 001: time ./dummy.out
Result is 233333333166666668
./dummy.out  14.94s user 0.06s system 98% cpu 15.268 total
$ 001: time ./a.out
Result is 233333333166666668
./a.out  3.85s user 0.01s system 98% cpu 3.906 total
```

I observed too some properties on the pyramid when constructing the sequence of 3-multiple with 6 step, but I think this is not the place or time to discuss this.
