#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>

using namespace std;

int t[1500001];
int p[1500001];
long long dp[1500001];
long long result;

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
		if (i + t[i] <= n + 1)
		{
			dp[i] = max(dp[i + 1], dp[i + t[i]] + p[i]);
		}
		else
		{
			dp[i] = dp[i + 1];
		}
	}

	cout << dp[1];
}