#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>


using namespace std;

#define NAMES vector<string>

ifstream file;

void open_file(const char * file_name) {
    file.open(file_name);
    if (!file) {
        cerr << "Error on reading file" << endl;
        exit(1);
    }
}

void close_file() {
    file.close();
}

NAMES * split_and_sort(string str_line) {
    NAMES * names = new NAMES();

    string token, delimiter = ",", o = str_line;
    int pos = 0;

    while ((pos = o.find(delimiter)) != string::npos) {
        token = o.substr(0, pos);
        names->push_back(token);
        o.erase(0, pos + delimiter.length());
    }

    if (o.length()) {
        names->push_back(o);
    }

    sort(names->begin(), names->end());

    return names;
}

long long get_name_value(string name) {
    long long result = 0;
    for (int i = 1; i < name.length() - 1; i++) {
        result += (static_cast<long long>(name[i]) - 64);
    }

    return result;
}

long long solve() {
    open_file("./names.txt");

    string str_line;
    getline(file, str_line);
    close_file();

    NAMES * names = split_and_sort(str_line);

    long long result = 0;
    int i = 1;
    for (NAMES::iterator it = names->begin(); it != names->end(); ++it) {
        long long name_value = get_name_value(*it) * i;
        result = result + name_value;
        i++;
    }

    return result;
}

int main(int argc, char** argv) {
    long long rv = solve();
    cout << "result = " << rv << endl;
}

