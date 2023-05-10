
# pragma once
#include <iostream>

namespace ariel{
    
class Fraction
{
private:
    int numerator; //a
    int denominator; //b

    int gcd(int num1, int num2) const;
    

public:
    Fraction(): numerator(0), denominator(1){}
    Fraction(int nume, int deno);
    Fraction(float frac);
    Fraction(const Fraction &frac);
    ~Fraction(){};

    Fraction& operator=(const Fraction& frac);

    Fraction(Fraction&& frac) noexcept;
    Fraction& operator=(Fraction&& frac) noexcept;

    int getNumerator() const;
    int getDenominator() const;
    void setNumerator(int nume);
    void setDenominator(int deno);


    //operators on Fraction objects
    Fraction operator+(const Fraction& frac) const;
    Fraction operator-(const Fraction& frac) const;
    Fraction operator*(const Fraction& frac) const;
    Fraction operator/(const Fraction& frac) const;
    bool operator==(const Fraction& frac) const;
    bool operator>(const Fraction& frac) const;
    bool operator<(const Fraction& frac) const;
    bool operator>=(const Fraction& frac) const;
    bool operator<=(const Fraction& frac) const;
    // bool operator!=(const Fraction& b) const{return false;}

    Fraction& operator++(); // ++n
    Fraction operator++(int num); // n++
    Fraction& operator--(); // --n
    Fraction operator--(int num); // n--

    friend std::ostream& operator<<(std::ostream& output, const Fraction& obj);
    friend std::istream& operator>>(std::istream& input, Fraction& obj);


    //operators on Fraction and float
    Fraction operator+(float num) const;
    Fraction operator-(float num) const;
    Fraction operator*(float num) const;
    Fraction operator/(float num) const;
    bool operator==(float num) const;
    bool operator>(float num) const;
    bool operator<(float num) const;
    bool operator>=(float num) const;
    bool operator<=(float num) const;
    // bool operator!=(float b) const{return false;}

    //operators on float and Fraction
    friend Fraction operator+(float num, const Fraction& obj);
    friend Fraction operator-(float num, const Fraction& obj);
    friend Fraction operator*(float num, const Fraction& obj);
    friend Fraction operator/(float num, const Fraction& obj);
    friend bool operator==(float num, const Fraction& obj);
    friend bool operator>(float num, const Fraction& obj);
    friend bool operator<(float num, const Fraction& obj);
    friend bool operator>=(float num, const Fraction& obj);
    friend bool operator<=(float num, const Fraction& obj);
    // friend bool operator!=(float b, const Fraction& obj){return false;}

    void reduce();
};
};