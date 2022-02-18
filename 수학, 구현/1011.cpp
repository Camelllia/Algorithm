#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	int testCase;
	int x = 0;
	int y = 0;
	double a = 0;
	double b = 0;
	int distance = 0;

	cin >> testCase;

	for (int i = 0; i < testCase; i++)
	{
		cin >> x >> y;

		distance = y - x;
		a = sqrt(distance);
		b = round(a);

		if (a <= b)
		{
			cout << b * 2 - 1 << "\n";
		}
		else
		{
			cout << b * 2 << "\n";
		}
	}
}