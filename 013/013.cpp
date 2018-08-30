#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <vector>


using namespace std;

ifstream file;
vector<long> * lsum;

void open_file() {
    file.open("./013.in");
    if (!file) {
        cerr << "Error on reading file" << endl;
        exit(1);
    }
}

void close_file() {
    file.close();
}

void check_list_at(int index) {
    long t = -1;
    try {
        t = lsum->at(index);
    } catch (const out_of_range& oor) {
        lsum->push_back((long) 0);
    }
}

void check_carry(int index) {
    long value = lsum->at(index);
    if (value > 999999999) {
        check_list_at(index+1);
        lsum->at(index+1) += (value/10000000000);
        lsum->at(index) = value % 10000000000;
        check_carry(index+1);
    } 
}

void print_list() {
    cout << "List lsum:" << endl;
    for (int i = lsum->size()-1; i >= 0; i--) {
        cout << "lsum[" << i << "]=" << lsum->at(i) << endl;
    }
}

long sum_step(string line) {
    string line_sum;
    for (int i = 4, j = 0; i >= 0; i--) {
        line_sum = line.substr(i*10, 10);
        check_list_at(j);
        lsum->at(j) += stol(line_sum);
        check_carry(j);
        j++;
    }

    return 0;
}

string build_number() {
    string rv;
    for (int i = lsum->size()-1; i >= 0; i--) {
        rv += to_string(lsum->at(i));
    }
    return rv;
}

long solve() {
    open_file();

    lsum = new vector<long>();

    string line;
    while (file >> line) {
        sum_step(line);
    }
    close_file();

    string result = build_number();
    long rv = stol(result.substr(0, 10));
    //print_list();

    delete lsum;
    return rv;
}

int main(int argc, char** argv) {
    long result = solve();
    cout << "The result is " << result << endl;
}
