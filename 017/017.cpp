#include <iostream>

using namespace std;


int numeral(int n) {
    switch (n) {
        case 1: // one
        case 2: // two
        case 6: // six
            return 3;
        case 4: // four
        case 5: // five
        case 9: // nine
            return 4;
        case 3: // three
        case 7: // seven
        case 8: // eight
            return 5;
        default:
            return 0;
    }
}

int decimal_below_twenty(int n) {
    switch (n) {
        case 10: // ten
            return 3;
        case 11: // eleven
        case 12: // twelve
            return 6;
        case 16: // sixteen
        case 15: // fifteen
            return 7;
        case 13: // thirteen
        case 14: // fourteen
        case 18: // eighteen
        case 19: // nineteen
            return 8;
        case 17: // seventeen
            return 9;
        default:
            return 0;
    }
}

int decimal(int n) {
    if (n > 9 && n < 20) {
        return decimal_below_twenty(n);
    }
    int d = (int) n/10;
    switch (d) {
        case 0: // (no value)
            return numeral(n);
        case 5: // fifty
        case 6: // sixty
        case 4: // forty
            return 5 + numeral(n % 10);
        case 2: // twenty
        case 3: // thirty
        case 8: // eighty
        case 9: // ninety
            return 6 + numeral(n % 10);
        case 7: // seventy
            return 7 + numeral(n % 10);
        default:
            return 0;
    }
}

int centesimal(int n) {
    int c = (int) n/100;
    int d = n - (c*100);
    if (c > 0) {
        if (d == 0) {
            // $c hundred
            return numeral(c) + 7 + decimal(d);
        }
        // $c hundred and $d
        return numeral(c) + 10 + decimal(d);
    }
    // $d
    return decimal(d);
}

long solve() {
    int sum = 11; // one thousand
    for (int i = 1; i < 1000; i++) {
        sum += centesimal(i);;
    }
    return sum;
}

int main(int argc, char** argv) {
    int rv = solve();
    cout << "Problem 17 - result = " << rv << endl;
}
