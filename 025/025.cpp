#include <iostream>
#include <vector>
#include <map>


using namespace std;

class BigNum {
    private:
        vector<int> * _value;

    public:
        BigNum(int value) {
            this->_value = new vector<int>();
            int actual = value;

            if (actual == 0) {
                this->_value->push_back(actual);
            } else {
                while (actual > 0) {
                    this->_value->push_back(actual % 10);
                    actual = actual / 10;
                }
            }
        }

        BigNum(vector<int> * value): _value(value) {}

        BigNum * sum(BigNum * with) {
            vector<int> * result = new vector<int>();
            int carry = 0;
            int fullSize = this->size() > with->size() ? this->size() : with->size();

            for (int i = 0; i < fullSize; i++) {
                int actual = this->get_single_value(i) + with->get_single_value(i) + carry;

                carry = 0;
                if (actual > 9) {
                    actual = actual - 10;
                    carry = 1;
                }

                result->push_back(actual);
            }

            if (carry) {
                result->push_back(carry);
            }

            return new BigNum(result);
        }

        BigNum * multiply(BigNum * by) {
            BigNum * final = new BigNum(0);
            vector<int> * result = new vector<int>();

            int carry = 0;

            for (int i = 0; i < this->size(); i++) {
                int iActual = this->get_single_value(i);

                for(int w = 0; w < i; w++) {
                    result->push_back(0);
                }

                for (int j = 0; j < by->size(); j++) {
                    int jActual = by->get_single_value(j);

                    int actualResult = (iActual * jActual) + carry;

                    carry = 0;
                    if (actualResult > 9) {
                        carry = actualResult / 10;
                        actualResult = actualResult % 10;
                    }

                    result->push_back(actualResult);
                }

                if (carry) {
                    result->push_back(carry);
                    carry = 0;
                }

                BigNum * actualBigNum = new BigNum(result);
                final = final->sum(actualBigNum);
                result->clear();
            }

            return final;

        }

        int size() {
            return this->_value->size();
        }

        int get_sum_of_digits() {
            int rv = 0;
            for (int i = 0; i < this->_value->size(); i++) {
                rv += this->_value->at(i);
            }

            return rv;
        }

        string get_value() {
            string result;
            for (int i = 0; i < this->_value->size(); i++) {
                result = to_string(this->_value->at(i)) + result;
            }

            return result;
        }

    private:
        int get_single_value(int index) {
            if (index >= this->_value->size()) {
                return 0;
            }

            return this->_value->at(index);
        }
};

typedef map<int, BigNum*> num_map;

num_map cache;

void init_cache() {
    BigNum * one = new BigNum(1);

    cache[1] = one;
    cache[2] = one;
}

BigNum * fibonacci(int n) {
    num_map::iterator found = cache.find(n);

    if (found != cache.end()) {
        return found->second;
    }

    BigNum * n_1 = fibonacci(n-1);
    BigNum * n_2 = fibonacci(n-2);

    BigNum * value = n_1->sum(n_2);

    cache[n] = value;

    return value;
}

int solve() {
    init_cache();

    int n = 1;
    BigNum * actual = fibonacci(n);

    while (actual->size() < 1000) {
        actual = fibonacci(++n);
    }

    string value = cache.find(n)->second->get_value();

    return n;
}

int main(int argc, char** argv) {
    int rv = solve();
    cout << "result = " << rv << endl;
}
