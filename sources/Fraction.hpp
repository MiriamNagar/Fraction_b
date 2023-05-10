
# pragma once
#include <iostream>

namespace ariel{
    
class Fraction
{
private:
    int numerator; //a
    int denominator; //b

    //  functions to help reduce the fractions  //
    int gcd(int num1, int num2) const;
    void reduce();

public:
    //  constructors  //
    Fraction(): numerator(0), denominator(1){}
    Fraction(int nume, int deno);
    Fraction(float frac);
    Fraction(const Fraction &frac);
    ~Fraction(){};

    Fraction& operator=(const Fraction& frac);

    Fraction(Fraction&& frac) noexcept;
    Fraction& operator=(Fraction&& frac) noexcept;

    //  getters and setters  //
    int getNumerator() const;
    int getDenominator() const;
    void setNumerator(int nume);
    void setDenominator(int deno);


    //  Arithmetic operators between Fractions  //
    Fraction operator+(const Fraction& frac) const;
    Fraction operator-(const Fraction& frac) const;
    Fraction operator*(const Fraction& frac) const;
    Fraction operator/(const Fraction& frac) const;

    //  Comparison operators between Fractions  //
    bool operator==(const Fraction& frac) const;
    bool operator>(const Fraction& frac) const;
    bool operator<(const Fraction& frac) const;
    bool operator>=(const Fraction& frac) const;
    bool operator<=(const Fraction& frac) const;

    //  prefix & postfix operators - addition and submition  //
    Fraction& operator++(); // ++n
    Fraction operator++(int num); // n++
    Fraction& operator--(); // --n
    Fraction operator--(int num); // n--


    //  Insertion extraction operators  //
    friend std::ostream& operator<<(std::ostream& output, const Fraction& obj);
    friend std::istream& operator>>(std::istream& input, Fraction& obj);


    //  Arithmetic operators on Fraction and float  //
    Fraction operator+(float num) const;
    Fraction operator-(float num) const;
    Fraction operator*(float num) const;
    Fraction operator/(float num) const;

    //  Comparison operators on Fraction and float  //
    bool operator==(float num) const;
    bool operator>(float num) const;
    bool operator<(float num) const;
    bool operator>=(float num) const;
    bool operator<=(float num) const;


    //  Arithmetic operators on float and Fraction  //
    friend Fraction operator+(float num, const Fraction& obj);
    friend Fraction operator-(float num, const Fraction& obj);
    friend Fraction operator*(float num, const Fraction& obj);
    friend Fraction operator/(float num, const Fraction& obj);

    //  Comparison operators on float and Fraction  //
    friend bool operator==(float num, const Fraction& obj);
    friend bool operator>(float num, const Fraction& obj);
    friend bool operator<(float num, const Fraction& obj);
    friend bool operator>=(float num, const Fraction& obj);
    friend bool operator<=(float num, const Fraction& obj);

};
};