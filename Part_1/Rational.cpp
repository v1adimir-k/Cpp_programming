#include "Header.h"

Rational::Rational() :
	m_nominator{ 0 }, m_denominator{ 1 }{}

Rational::Rational(int x) :
	m_nominator{ x }, m_denominator{ 1 }{}

Rational::Rational(int x, int y) :
	m_nominator{ x }, m_denominator{ y }{Normalize();}

int Rational::Nominator() const
{
	return m_nominator;
}

int Rational::Denominator() const
{
	return m_denominator;
}


void Rational::Normalize() 
{
	int devider = FindGreatestCommonDivisior(m_nominator, m_denominator);
	if (m_denominator < 0) { devider = -devider; };
	m_nominator /= devider;
	m_denominator /= devider;
}

Rational& Rational::operator+=(const Rational& right)
{
	int lcm = FindLeastCommonMultiple(m_denominator, right.m_denominator);
	m_nominator = m_nominator * (lcm / m_denominator) + right.m_nominator * (lcm / m_denominator);
	m_denominator = lcm;
	Normalize();
	return *this;
}

Rational& Rational::operator-=(const Rational& right)
{
	int lcm = FindLeastCommonMultiple(m_denominator, right.m_denominator);
	m_nominator = m_nominator * (lcm / m_denominator) - right.m_nominator * (lcm / m_denominator);
	m_denominator = lcm;
	Normalize();
	return *this;
}

Rational& Rational::operator*=(const Rational& right)
{
	m_nominator *= right.m_nominator;
	m_denominator *= right.m_denominator;
	Normalize();
	return *this;
}

Rational& Rational::operator/=(const Rational& right)
{
	m_nominator *= right.m_denominator;
	m_denominator *= right.m_nominator;
	Normalize();
	return *this;
}


Rational Rational::operator+(const Rational& right)
{
	Rational res = *this;
	return res += right;;
}

Rational Rational::operator-(const Rational& right)
{
	Rational res = *this;
	return res -= right;;
}

Rational Rational::operator*(const Rational& right)
{
	Rational res = *this;
	return res *= right;;
}

Rational Rational::operator/(const Rational& right)
{
	Rational res = *this;
	return res /= right;;
}

ostream& operator<<(ostream& out, const Rational& Rational) //операция вывода
{
	out << Rational.m_nominator << "/" << Rational.m_denominator;
	return out;
}
istream& operator>>(istream& in, Rational& Rational) //операция ввода
{
	in >> Rational.m_nominator >> Rational.m_denominator;
	return in;
}