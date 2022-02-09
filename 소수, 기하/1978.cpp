#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

bool isPrime(int x)
{
	int end = (int)sqrt(x);

	if (x < 2)
	{
		return false;
	}

	for (int i = 2; i <= end; i++)
	{
		if (x % i == 0)
		{
			return false;
		}
	}

	return true;
}

int main()
{
	int testCase = 0;
	int count = 0;

	cin >> testCase;

	for (int i = 0; i < testCase; i++)
	{
		int n;
		cin >> n;

		if (isPrime(n) == 1)
		{
			count++;
		}
	}

	cout << count;
}
