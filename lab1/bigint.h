#include<iostream>
#include<string>
#include<limits.h>
using namespace std;

class BigInt {
public:
    BigInt();
    BigInt(int);
    BigInt(string);
    BigInt(const BigInt&);
    ~BigInt();

    BigInt& operator=(const BigInt&);

    BigInt operator~() const;

    BigInt& operator++();
    const BigInt operator++(int);
    BigInt& operator--();
    const BigInt operator--(int);

    BigInt& operator+=(const BigInt&);
    BigInt& operator*=(const BigInt&);
    BigInt& operator-=(const BigInt&);
    BigInt& operator/=(const BigInt&);
    BigInt& operator^=(const BigInt&);
    BigInt& operator%=(const BigInt&);
    BigInt& operator&=(const BigInt&);
    BigInt& operator|=(const BigInt&);

    BigInt operator+() const;
    BigInt operator-() const;

    bool operator==(const BigInt&) const;
    bool operator!=(const BigInt&) const;
    bool operator<(const BigInt&) const;
    bool operator>(const BigInt&) const;
    bool operator<=(const BigInt&) const;
    bool operator>=(const BigInt&) const;

    operator int() const;
    operator string() const;

    size_t size() const;
    void realloc(long long int size);
    size_t index;
    bool sign;
    unsigned int *data;
};
