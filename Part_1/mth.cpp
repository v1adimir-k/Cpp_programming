#include<iostream>
using namespace std;
int FindGreatestCommonDivisior(int x, int y)
{
	int g = std::abs(y);
	int a = max(std::abs(x), std::abs(y));
	int b = min(std::abs(x), std::abs(y));

	while (b !=0)
	{
		int r = a % b;
		a = b;
		b = r;

	}
	return a;
}


int FindLeastCommonMultiple(int x, int y)
{
	return abs(x * y) / FindGreatestCommonDivisior(x, y);
}