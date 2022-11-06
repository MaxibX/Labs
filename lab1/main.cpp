#include "bigint.h"

using namespace std;

BigInt::BigInt(): index(1), sign(false), data(new unsigned int [this->index]) {
    data[0] = 0;
}

BigInt::BigInt(int n): index(1), sign(n < 0), data(new unsigned int [this->index]) {
    data[0] = abs(n);
    if (n < 0) data[0] = (~data[0]) + 1;
}

BigInt::BigInt(const BigInt &number): index(number.index), sign(number.sign), data(new unsigned int [this->index]) {
    for (long long int i = 0; i < index; ++i) {
        data[i] = number.data[i];
    }
}

BigInt::BigInt(string str): index(1), sign(false), data(new unsigned int [this->index]) {
    this->data[0] = 0;
    size_t str_length = str.size();
    if (str_length < 2) throw invalid_argument("invalid argument");
    bool sign_second;
    if (str[0] == '-') sign_second = true;
    else if (str[0] == '+') sign_second = false;
    else throw invalid_argument("invalid argument");
    for (long long int i = 1; i < str_length; ++i) {
        if (48 <= str[i] && str[i] <= 57) {
            *this *= 10;
            *this += BigInt(str[i] - '0');
        }
        else throw invalid_argument("invalid argument");
    }
    if (sign_second) *this = -*this;
}

void BigInt::realloc(long long int size) {
    if (size > 2) return;
    unsigned int *newdata = new unsigned int [size];
    long long int lesslength = index > size ? size : index;
    for (long long int i = 0; i < lesslength; ++i) newdata[i] = data[i];
    for (long long int i = lesslength; i < size; ++i) newdata[i] = sign ? UINT_MAX : 0;
    delete[] this->data;
    this->data = newdata;
    this->index = size;
}

BigInt::~BigInt() {
    delete[] this->data;
}

BigInt& BigInt::operator=(const BigInt& number) {
    if (this != &number) {
        delete[] this->data;
        this->index = number.index;
        this->data = new unsigned int[this->index];
        for (long long int i = 0; i < index; ++i) this->data[i] = number.data[i];
        this->sign = number.sign;
    }
    return *this;
}

BigInt BigInt::operator~() const {
    BigInt result = *this;
    result.sign = !result.sign;
    for (long long int i = 0; i < this->index; ++i) {
        result.data[i] = ~result.data[i];
    }
    return result;
}

BigInt& BigInt::operator++() {
    return *this += BigInt(1);
}

const BigInt BigInt::operator++(int) {
    const BigInt previous = *this;
    *this += BigInt(1);
    return previous;
}

BigInt& BigInt::operator--() {
    return *this -= BigInt(1);
}

const BigInt BigInt::operator--(int) {
    const BigInt previous = *this;
    *this -= BigInt(1);
    return previous;
}

BigInt& BigInt::operator+=(const BigInt& number) {
    BigInt second(number);
    if (index > second.index) {
        second.realloc(index);
    }//...
}

BigInt& BigInt::operator*=(const BigInt& number) {
    
}

BigInt& BigInt::operator-=(const BigInt& number) {
    return *this += -number;
}

BigInt& BigInt::operator/=(const BigInt& number) {

}

BigInt& BigInt::operator^=(const BigInt& number) {
    BigInt second(number);
    if (this->index > second.index) second.realloc(this->index);
    if (this->index < second.index) this->realloc(second.index);
    for (long long int i = 0; i < this->index; ++i) this->data[i] ^= second.data[i];
    sign ^= number.sign;
    return *this;
}

BigInt& BigInt::operator%=(const BigInt& number) {
    BigInt thismul = this->sign ? -*this : *this;
    BigInt numbermul = number.sign ? -number : number;
    *this = thismul - ((thismul / numbermul) * numbermul);
    return *this;
}

BigInt& BigInt::operator&=(const BigInt& number) {
    BigInt second(number);
    if (this->index > second.index) second.realloc(this->index);
    if (this->index < second.index) this->realloc(second.index);
    for (long long int i = 0; i < this->index; ++i) this->data[i] &= second.data[i];
    sign &= number.sign;
    return *this;
}

BigInt& BigInt::operator|=(const BigInt& number) {
    BigInt second(number);
    if (this->index > second.index) second.realloc(this->index);
    if (this->index < second.index) this->realloc(second.index);
    for (long long int i = 0; i < this->index; ++i) this->data[i] |= second.data[i];
    sign |= number.sign;
    return *this;
}

int main() {
    return 0;
}
