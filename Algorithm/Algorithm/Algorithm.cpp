#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long dp[1000001];

long long tile(int n)
{
	if (n <= 1)
	{
		return 1;
	}

	if (dp[n] != 0)
	{
		return dp[n];
	}
	else
	{
		return dp[n] = ((tile(n - 1) + tile(n - 2)) % 15746);
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	cout << tile(n);
}