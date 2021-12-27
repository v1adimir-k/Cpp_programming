#include "math.h"
#include<iostream>
using namespace std;

class Rational
{
public:
	Rational();
	Rational(int);
	Rational(int, int);
	int Nominator() const;
	int Denominator() const;
	explicit operator double()const
	{
		return m_nominator /static_cast<double>(m_denominator);
	}
	Rational operator-() const;
	Rational& operator+=(const Rational&);
	Rational& operator-=(const Rational&);
	Rational& operator*=(const Rational&);
	Rational& operator/=(const Rational&);
	Rational operator+(const Rational&);
	Rational operator-(const Rational&);
	Rational operator*(const Rational&);
	Rational operator/(const Rational&);
	friend std::ostream& operator<<(std::ostream& out, const Rational& Rational);
	friend std::istream& operator>>(std::istream& in, Rational& Rational);
private:
	int m_nominator;
	int m_denominator;
	void Normalize();
};


int FindLeastCommonMultiple(int x, int y);
int FindGreatestCommonDivisior(int x, int y);