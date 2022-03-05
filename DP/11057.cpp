#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>
#define MOD 10007

using namespace std;

long long dp[1001][10];
long long result = 0;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int i = 0; i <= 9; i++)
	{
		dp[1][i] = 1;
	}

	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			if (j == 0)
			{
				dp[i][j] = 1;
			}
			else
			{
				dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
			}
		}
	}

	for (int i = 0; i <= 9; i++)
	{
		result += dp[n][i];
	}

	cout << result % MOD;
}