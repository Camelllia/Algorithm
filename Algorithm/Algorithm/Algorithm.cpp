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

	while (true)
	{
		int n;
		int count = 0;
		cin >> n;
		int fivot = n * 2;

		if (n == 0)
		{
			break;
		}

		while (n < fivot)
		{
			n += 1;
			if (isPrime(n) == 1)
			{
				count++;
			}
		}

		cout << count << "\n";
	}
}
