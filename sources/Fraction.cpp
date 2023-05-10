   
#include <iostream>
#include <limits>
#include "Fraction.hpp"

using namespace std;
namespace ariel{


Fraction::Fraction(float frac)
{
    this->numerator = (int)(frac*1000);
    this->denominator = 1000;
    this->reduce();
}

Fraction::Fraction(int nume, int deno)
{
    if(deno == 0)
    {
        throw invalid_argument("can't divide in zero");
    }
    this->numerator = nume;
    this->denominator = deno;
    this->reduce();
}

Fraction::Fraction(const Fraction &frac):numerator(frac.numerator), denominator(frac.denominator){}

Fraction& Fraction::operator=(const Fraction& frac)
{
    if(this != &frac)
    {
        this->numerator=frac.numerator;
        this->denominator=frac.denominator;
    }
    return *this;
}

Fraction::Fraction(Fraction&& frac) noexcept : numerator(frac.numerator), denominator(frac.denominator){}
Fraction& Fraction::operator=(Fraction&& frac) noexcept
{
    if(this != &frac)
    {
        this->numerator=frac.numerator;
        this->denominator=frac.denominator;
    }
    return *this;
}

int Fraction::getNumerator() const
{
    return this->numerator;
}

int Fraction::getDenominator() const
{
    return this->denominator;
}

void Fraction::setNumerator(int nume)
{
    this->numerator = nume;
}

void Fraction::setDenominator(int deno)
{
    this->denominator = deno;
}

Fraction Fraction::operator+(const Fraction& frac) const
{
    long long nume = (long long) (this->numerator*frac.denominator) + (this->denominator*frac.numerator);
    long long deno = (long long)this->denominator*frac.denominator;

    int max_int = std::numeric_limits<int>::max();
    int min_int = std::numeric_limits<int>::min();
    if(nume > max_int || nume < min_int || deno > max_int || deno < min_int)
        throw overflow_error("overflow +");

    Fraction res((int)nume, (int)deno);
    res.reduce();
    return res;
}

Fraction Fraction::operator-(const Fraction& frac) const
{
    long long nume = (long long) (this->numerator*frac.denominator) - (this->denominator*frac.numerator);
    long long deno = (long long) this->denominator*frac.denominator;

    int max_int = std::numeric_limits<int>::max();
    int min_int = std::numeric_limits<int>::min();
    if(nume > max_int || nume < min_int || deno > max_int || deno < min_int)
        throw overflow_error("overflow -");

    Fraction res((int)nume, (int)deno);
    res.reduce();
    return res;
}

Fraction Fraction::operator*(const Fraction& frac) const
{
    long long nume = (long long) this->numerator*frac.numerator;
    long long deno = (long long) this->denominator*frac.denominator;

    int max_int = std::numeric_limits<int>::max();
    int min_int = std::numeric_limits<int>::min();
    if(nume > max_int || nume < min_int || deno > max_int || deno < min_int)
        throw overflow_error("overflow *");

    Fraction res((int)nume, (int)deno);
    res.reduce();
    return res;
}

Fraction Fraction::operator/(const Fraction& frac) const
{
    if(frac.numerator == 0)
    {
        throw runtime_error("can't divide in zero");
    }
    long long nume = (long long) this->numerator*frac.denominator;
    long long deno = (long long) this->denominator*frac.numerator;

    int max_int = std::numeric_limits<int>::max();
    int min_int = std::numeric_limits<int>::min();
    if(nume > max_int || nume < min_int || deno > max_int || deno < min_int)
        throw overflow_error("overflow *");

    Fraction res((int)nume, (int)deno);
    res.reduce();
    return res;
}

bool Fraction::operator==(const Fraction& frac) const
{
    // if(this->numerator==0 && frac.numerator == 0)return true;
    if(this->numerator==frac.numerator && this->denominator==frac.denominator) return true;
    // else if(this->numerator== -frac.numerator && -this->denominator==frac.denominator) return true;
    // else if(this->numerator==-frac.numerator && this->denominator==-frac.denominator) return true;
    return false;
}

bool Fraction::operator>(const Fraction& frac) const
{
    int nume1 = (this->numerator*frac.denominator);
    int nume2 = (this->denominator*frac.numerator);
    int deno = this->denominator*frac.denominator;
    if(nume1 > nume2) return true;
    return false;
}

bool Fraction::operator<(const Fraction& frac) const
{
    int nume1 = (this->numerator*frac.denominator);
    int nume2 = (this->denominator*frac.numerator);
    int deno = this->denominator*frac.denominator;
    if(nume1 < nume2) return true;
    return false;
}
bool Fraction::operator>=(const Fraction& frac) const
{
    int nume1 = (this->numerator*frac.denominator);
    int nume2 = (this->denominator*frac.numerator);
    int deno = this->denominator*frac.denominator;
    if(nume1 >= nume2) return true;
    return false;
}
bool Fraction::operator<=(const Fraction& frac) const
{
    int nume1 = (this->numerator*frac.denominator);
    int nume2 = (this->denominator*frac.numerator);
    int deno = this->denominator*frac.denominator;
    if(nume1 <= nume2) return true;
    return false;
}
// bool operator!=(const Fraction& b) const{return false;}

Fraction& Fraction::operator++()// ++n
{
    this->numerator += this->denominator;
    this->reduce();
    return *this;
} 
Fraction Fraction::operator++(int num) // n++
{
    Fraction temp_num(this->numerator, this->denominator);
    ++(*this);
    return temp_num;
}
Fraction& Fraction::operator--() // --n
{
    this->numerator -= this->denominator;
    this->reduce();
    return *this;
}
Fraction Fraction::operator--(int num) // n--
{
    Fraction temp_num(this->numerator, this->denominator);
    --(*this);
    return temp_num;
}

std::ostream& operator<<(std::ostream& output, const Fraction& obj)
{
    output << obj.getNumerator() << '/' << obj.getDenominator();
    return output;
}

std::istream& operator>>(std::istream& input, Fraction& obj)
{
    int nume, deno;
    input>>nume>>deno;
    if(input.fail()) throw runtime_error("Input invalid/ failed");
    if(deno == 0)
    {
        throw runtime_error("can't divide in zero");
    }
    obj.setNumerator(nume);
    obj.setDenominator(deno);
    obj.reduce();
    return input;
}

//operators on Fraction and float
Fraction Fraction::operator+(float num) const
{
    Fraction temp_num(num);
    // int nume = (this->numerator*temp_num.denominator) + (this->denominator*temp_num.numerator);
    // int deno = this->denominator*temp_num.denominator;
    // Fraction res(nume, deno);
    // res.reduce();
    return *this+temp_num;
}

Fraction Fraction::operator-(float num) const
{
    Fraction temp_num(num);
    return *this-temp_num;
}

Fraction Fraction::operator*(float num) const
{
    Fraction temp_num(num);
    return *this*temp_num;
}

Fraction Fraction::operator/(float num) const
{
    Fraction temp_num(num);
    return *this/temp_num;
}
bool Fraction::operator==(float num) const
{
    Fraction temp_num(num);
    return *this==temp_num;
}
bool Fraction::operator>(float num) const
{
    Fraction temp_num(num);
    return *this>temp_num;
}
bool Fraction::operator<(float num) const
{
    Fraction temp_num(num);
    return *this<temp_num;
}
bool Fraction::operator>=(float num) const
{
    Fraction temp_num(num);
    return *this>=temp_num;
}
bool Fraction::operator<=(float num) const
{
    Fraction temp_num(num);
    return *this<=temp_num;
}

//operators on float and Fraction
Fraction operator+(float num, const Fraction& obj)
{
    Fraction temp_num(num);
    return temp_num+ obj;
}
Fraction operator-(float num, const Fraction& obj)
{
    Fraction temp_num(num);
    return temp_num- obj;
}

Fraction operator*(float num, const Fraction& obj)
{
    Fraction temp_num(num);
    return temp_num* obj;
}

Fraction operator/(float num, const Fraction& obj)
{
    Fraction temp_num(num);
    return temp_num/ obj;
}
bool operator==(float num, const Fraction& obj)
{
    Fraction temp_num(num);
    return temp_num== obj;
}
bool operator>(float num, const Fraction& obj)
{
    Fraction temp_num(num);
    return temp_num> obj;
}
bool operator<(float num, const Fraction& obj)
{
    Fraction temp_num(num);
    return temp_num< obj;
}
bool operator>=(float num, const Fraction& obj)
{
    Fraction temp_num(num);
    return temp_num>= obj;
}
bool operator<=(float num, const Fraction& obj)
{
    Fraction temp_num(num);
    return temp_num<= obj;
}


void Fraction::reduce()
{
    int num1 = abs(this->numerator);
    int num2 = abs(this->denominator);
    int divider = gcd(num1, num2);
    if(this->numerator == 0)
    {
        this->denominator = 1;
    }
    else if(this->numerator > 0 && this->denominator < 0)
    {
        this->numerator = -this->numerator / divider;
        this->denominator = -this->denominator / divider;
    } 
    else if(this->numerator < 0 && this->denominator < 0)
    {
        this->numerator = -this->numerator / divider;
        this->denominator = -this->denominator / divider;
    }
    else{
        this->numerator /= divider;
        this->denominator /= divider;
    }

}

int Fraction::gcd(int num1, int num2) const
{
    if(num2 == 0) return num1;
    else return gcd(num2, num1 % num2);
}

int abs(int num)
{
    if (num < 0) return -1*num;
    else return num;
}
}