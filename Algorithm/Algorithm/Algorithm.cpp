#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>

using namespace std;

long long dp[501][501];
long long tree[501][501];
long long result = 0;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cin >> tree[i][j];
		}
	}

	dp[1][1] = tree[1][1];


	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (j == 1)
			{
				dp[i][j] = dp[i - 1][j] + tree[i][j];
			}
			else if (j == i)
			{
				dp[i][j] = dp[i - 1][j - 1] + tree[i][j];
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + tree[i][j];
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (dp[n][i] > result)
		{
			result = dp[n][i];
		}
	}

	cout << result;
}