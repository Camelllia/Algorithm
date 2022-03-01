#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

long long dp[100001];

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;

	int n;
	cin >> n;

	for (int i = 4; i <= n; i++)
	{
		dp[i] = i;
		for (int j = 1; j * j <= i; j++)
		{
			dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
	}

	cout << dp[n];
}