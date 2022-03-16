#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int dp[16];
int t[16];
int p[16];

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> t[i] >> p[i];
	}

	for (int i = n; i > 0; i--)
	{
		int totalDate = i + t[i];

		if (totalDate > n + 1)
		{
			dp[i] = dp[i + 1];
		}
		else
		{
			dp[i] = max(dp[i + 1], dp[totalDate] + p[i]);
		}
	}

	cout << dp[1];
}


