#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <queue>
using namespace std;

int num = 10000;
int arr[10001];

int piece[10001];

void sieve()
{
	int n; // 12
	cin >> n;
	int div = n / 2; // 6

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

	if (arr[div] != 0)
	{
		cout << div << " " << div << "\n";
	}
	else
	{
		int a = 0;

		while (true)
		{
			a++;
			if (arr[div - a] + arr[div + a] == n)
			{
				cout << arr[div - a] << " " << arr[div + a] << "\n";
				break;
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int testCase = 0;
	cin >> testCase;

	for (int i = 0; i < testCase; i++)
	{
		sieve();
	}
}
