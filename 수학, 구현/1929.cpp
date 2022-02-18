#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int num = 1000001;
int arr[1000001];

void Sieve()
{
	int m, n;

	cin >> m >> n;

	for (int i = 2; i <= num; i++)
	{
		arr[i] = i;
	}

	for (int i = 2; i <= num; i++)
	{
		if (arr[i] == 0)
		{
			continue;
		}

		for (int j = i + i; j <= num; j += i)
		{
			arr[j] = 0;
		}
	}

	for (int i = m; i <= n; i++)
	{
		if (arr[i] != 0)
		{
			cout << arr[i] << "\n";
		}
	}
}

int main()
{
	Sieve();
}
