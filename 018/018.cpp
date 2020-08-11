#include <iostream>
#include <fstream>
#include <string>
#include <vector>


#define LINE vector<int>
#define PYRAMID vector<LINE*>

using namespace std;

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

LINE * split_and_convert(string str_line) {
    LINE* line = new LINE();
    string token, delimiter = " ", o = str_line;
    int pos = 0;

    while ((pos = o.find(delimiter)) != string::npos) {
        token = o.substr(0, pos);
        line->push_back(stoi(token));
        o.erase(0, pos + delimiter.length());
    }

    if (o.length()) {
        line->push_back(stoi(o));
    }

    return line;
}

int high_between(int a, int b) {
    return a > b ? a : b;
}

int solve() {
    open_file("./in.file");

    LINE * line;
    PYRAMID pyramid;
    string str_line;
    while (getline(file, str_line)) {
        line = split_and_convert(str_line);
        pyramid.push_back(line);
    }
    
    close_file();

    reverse(pyramid.begin(), pyramid.end());

    LINE pastLine;
    LINE actualLine;
    bool isFirstCycle = true;
    int i = 0;
    for (PYRAMID::iterator it = pyramid.begin(); it != pyramid.end(); ++it) {
        actualLine.clear();

        if (!isFirstCycle) {
            line = (LINE *) *it;
            i = 0;
            for (LINE::iterator jt = line->begin(); jt != line->end(); ++jt) {
                int highestValue = high_between(pastLine.at(i), pastLine.at(i+1));

                actualLine.push_back((int) *jt + highestValue);

                i++;
            }
        } else {
            actualLine = (LINE) **it;
            isFirstCycle = false;
        }

        pastLine = actualLine;
    }

    return pastLine.at(0);
}

int main(int argc, char** argv) {
    int rv = solve();
    cout << "result = " << rv << endl;
}
