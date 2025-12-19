/*
 *   Yarkin Makar
 *   st141442@student.spbu.ru
 *   Assignment 5
 */
#include "rational.h"
#include <cmath>

using namespace std;

int Rational::gcd(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b != 0){
        int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

void Rational::reduce() {
    if (z == 0) {
        throw runtime_error("Denominator cannot be zero");
    }

    if (z < 0) {
        c = -c;
        z = -z;
    }

    int g = gcd(c, z);
    if (z != 0 && z != 1){
        c /= g;
        z /= g;
    }
}

Rational::Rational() : c(0), z(1) {}

Rational::Rational(int num) : c(num), z(1) {}

Rational::Rational(int num, int den) : c(num), z(den) {
    reduce();
}

int Rational::getC() const {
    return c;
}

int Rational::getZ() const {
    return z;
}


Rational Rational::operator+(const Rational& other) const {
    return Rational(c*other.z + other.c*z, z*other.z);
}

Rational Rational::operator-(const Rational& other) const {
    return Rational(c*other.z - other.c*z, z*other.z);
}

Rational Rational::operator*(const Rational& other) const {
    return Rational(c*other.c, z*other.z);
}

Rational Rational::operator/(const Rational& other) const {
    if (other.c == 0) {
        throw runtime_error("Division by zero");
    }
    return Rational(c*other.z, z*other.c);
}


Rational& Rational::operator+=(const Rational& other) {
    *this = *this + other;
    return *this;
}

Rational& Rational::operator-=(const Rational& other) {
    *this = *this - other;
    return *this;
}

Rational& Rational::operator*=(const Rational& other) {
    *this = *this * other;
    return *this;
}

Rational& Rational::operator/=(const Rational& other) {
    if (other == 0) {
        throw runtime_error("Division by zero");
    }
    *this = *this / other;
    return *this;
}


Rational Rational::operator+() const {
    return *this;
}

Rational Rational::operator-() const {
    return Rational(-c, z);
}


bool Rational::operator==(const Rational& other) const {
    return c == other.c && z == other.z;
}

bool Rational::operator!=(const Rational& other) const {
    return !(*this == other);
}

bool Rational::operator<(const Rational& other) const {
    return c *  other.z < z * other.c;
}

bool Rational::operator>(const Rational& other) const {
    return other < *this;
}

bool Rational::operator<=(const Rational& other) const {
    return !(*this > other);
}

bool Rational::operator>=(const Rational& other) const {
    return !(*this < other);
}


Rational::operator double() const {
    return static_cast<double>(c) / z;
}

std::ostream& operator<<(std::ostream& os, const Rational& r) {
    if (r.z == 1) {
        os << r.c;
    } else {
        os << r.c << "/" << r.z;
    }
    return os;
}

std::istream& operator>>(std::istream& is, Rational& r) {
    int ch, zn = 1;
    char s;
    is >> ch;
    if (is.peek() == '/') {
        is >> s >> zn;
    }
    r = Rational(ch, zn);
    return is;
}