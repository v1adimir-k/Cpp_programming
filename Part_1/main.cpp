#include<iostream>
#include "math.h"
#include "Header.h"

using namespace std;

Rational y1(Rational& x)
{
	Rational res = (x * 2) + (Rational(1.3) / x);
	return res;
}

double y2(double x)
{
	return (x * 2) + (1.3 / x);
}

int main() 
{
	setlocale(LC_ALL, "RUS");
	Rational a, res; 
	double x, resx;
	cout << "¬ведите рациональное число" << endl;
	cin >> a;
	res = y1(a);
	cout << res << endl;
	cout << "¬ведите x" << endl;
	cin >> x;
	resx = y2(x);
	cout << resx;
}

