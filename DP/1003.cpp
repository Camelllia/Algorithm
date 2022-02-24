#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <utility>

using namespace std;

int DP[41];

int fibonacci(int n)
{
	if (n == 0)
	{
		DP[0] = 0;
		return 0;
	}
	else if (n == 1)
	{
		DP[1] = 1;
		return 1;
	}


	if (DP[n] != 0)
	{
		return DP[n];
	}
	else
	{
		return DP[n] = fibonacci(n - 1) + fibonacci(n - 2);
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++)
	{
		int n;
		cin >> n;

		if (n == 0)
		{
			cout << 1 << " " << 0 << "\n";
		}
		else
		{
			cout << fibonacci(n - 1) << " " << fibonacci(n) << "\n";
		}
	}


}