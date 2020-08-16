#include <vector>


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

