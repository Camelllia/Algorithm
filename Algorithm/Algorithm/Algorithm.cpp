#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int arr[10001] = { 0, };

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
	int x, y;
	int sum = 0;
	int min = 10001;

	cin >> x >> y;

	if (x == y)
	{
		if (isPrime(x) == 1)
		{
			cout << x << "\n";
			cout << x;
			return 0;
		}
		else
		{
			cout << -1;
			return 0;
		}
	}

	while (x < y)
	{
		if (isPrime(x) == true)
		{
			arr[x] = 1;
		}
		x++;
		if (x == y)
		{
			if (isPrime(x) == true)
			{
				arr[x] = 1;
			}
			break;
		}
	}

	for (int i = 0; i < 10001; i++)
	{
		if (arr[i] == 1)
		{
			sum += i;
			if (i < min)
			{
				min = i;
			}
		}
	}

	if (sum == 0)
	{
		cout << -1;
	}
	else
	{
		cout << sum << "\n";
		cout << min;
	}

}
