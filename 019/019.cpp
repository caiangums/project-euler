#include <iostream>


const int START_YEAR = 1900;
const int START_COUNT_YEAR = 1901;
const int END_YEAR = 2000;
const int MONTHS = 12;
const int WEEK_DAYS = 7;

using namespace std;

bool is_leap_year(int year) {
    if (year % 100 == 0) {
        return year % 400 == 0;
    }

    return year % 4 == 0;
}

int get_days_of_month(int month, bool leap_year) {
    if (month > 7) {
        return month % 2 == 0 ? 31 : 30;
    }

    if (month % 2 == 1) {
        return 31;
    }

    if (month == 2) {
        return leap_year ? 29 : 28;
    }

    return 30;
}

int solve() {
    int count_sunday = 0;
    int week_day = 1; // 1900 starts with Monday

    for (int y = START_YEAR; y <= END_YEAR; y++) {
        bool is_leap = is_leap_year(y);

        for (int m = 1; m <= MONTHS; m++) {
            int days_of_month = get_days_of_month(m, is_leap);

            for (int d = 0; d < days_of_month; d++) {
                if (y >= START_COUNT_YEAR && d == 0 && week_day == 0) {
                    count_sunday++;
                }

                week_day = (week_day + 1) % WEEK_DAYS;
            }
        }
    }

    return count_sunday;
}

int main(int argc, char** argv) {
    int rv = solve();
    cout << "result = " << rv << endl;
}
