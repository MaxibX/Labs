#include "bigint.h"

using namespace std;

BigInt::BigInt(): index(1), sign(false), data(new unsigned int[this->index]) {
    data[0] = 0;
}

BigInt::BigInt(int n): index(1), sign(n < 0), data(new unsigned int[this->index]) {
    data[0] = abs(n);
    if (n < 0) data[0] = (~data[0]) + 1;
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
    for (long long int i = 0; i < index; ++i) {
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

}

BigInt& BigInt::operator*=(const BigInt& number) {

}

BigInt& BigInt::operator-=(const BigInt& number) {

}

BigInt& BigInt::operator/=(const BigInt& number) {

}

BigInt& BigInt::operator^=(const BigInt& number) {

}

BigInt& BigInt::operator%=(const BigInt& number) {

}

BigInt& BigInt::operator&=(const BigInt& number) {

}

BigInt& BigInt::operator|=(const BigInt& number) {

}

int main() {
    return 0;
}
