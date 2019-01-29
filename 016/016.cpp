#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>


using namespace std;


vector<short> * lvalue;

void check_list_at(int index) {
    short t = -1;
    try {
        t = lvalue->at(index);
    } catch (const out_of_range& oor) {
        lvalue->push_back((short) 0);
    }
}

void check_carry(int index) {
    short value = lvalue->at(index);
    if (value > 9) {
        check_list_at(index+1);
        lvalue->at(index+1) += (value/10);
        lvalue->at(index) = value % 10;
        check_carry(index+1);
    } 
}

void print_list() {
    cout << "List lvalue:" << endl;
    for (int i = lvalue->size()-1; i >= 0; i--) {
        cout << "lvalue[" << i << "]=" << lvalue->at(i) << endl;
    }
}

long sum_step(string line) {
    string line_sum;
    for (int i = (int) line.length()-1, j = 0; i >= 0; i--) {
        line_sum = line.substr(i, 1);
        check_list_at(j);
        lvalue->at(j) += stol(line_sum);
        check_carry(j);
        j++;
    }

    return 0;
}

string build_number() {
    string rv;
    for (int i = lvalue->size()-1; i >= 0; i--) {
        rv += to_string(lvalue->at(i));
    }
    return rv;
}

long sum_of_digits(vector<short> * l) {
    long rv = 0;
    for(auto & el : *l) {
        rv += el;
    }
    return rv;
}

long solve() {
    lvalue = new vector<short>();
    lvalue->push_back((short) 1);

    string curr;
    //cout << "2^" << 0 << "\t=\t" << sum_of_digits(lvalue) << "\t=\t" << build_number() << endl;
    for(int i = 1; i <= 1000; i++) {
        curr = build_number();
        sum_step(curr);
        //cout << "2^" << i << "\t=\t" << sum_of_digits(lvalue) << "\t=\t" << build_number() << endl;
    }

    return sum_of_digits(lvalue);
}

int main(int argc, char** argv) {
    long rv = solve();
    cout << "Problem 16 = " << rv << endl;
}
