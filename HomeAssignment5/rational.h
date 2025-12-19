/*
 *   Yarkin Makar
 *   st141442@student.spbu.ru
 *   Assignment 5
 */
#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <stdexcept>

class Rational {
private:
    int c;
    int z;

    
    static int gcd(int a, int b);
    
    
    void reduce();

public:
    
    Rational();
    Rational(int num);
    Rational(int num, int den);
    
    
    int getC() const;
    int getZ() const;

    
    Rational operator+(const Rational& other) const;
    Rational operator-(const Rational& other) const;
    Rational operator*(const Rational& other) const;
    Rational operator/(const Rational& other) const;
    
    
    Rational& operator+=(const Rational& other);
    Rational& operator-=(const Rational& other);
    Rational& operator*=(const Rational& other);
    Rational& operator/=(const Rational& other);
    
    
    Rational operator+() const;
    Rational operator-() const;
    
    
    bool operator==(const Rational& other) const;
    bool operator!=(const Rational& other) const;
    bool operator<(const Rational& other) const;
    bool operator>(const Rational& other) const;
    bool operator<=(const Rational& other) const;
    bool operator>=(const Rational& other) const;
    
    
    explicit operator double() const;
    

    friend std::ostream& operator<<(std::ostream& os, const Rational& r);
    friend std::istream& operator>>(std::istream& is, Rational& r);
};

#endif