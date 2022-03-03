#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>
#define MOD 1000000000

using namespace std;

long long dp[101][11];
long long sum = 0;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int i = 1; i <= 9; i++)
	{
		dp[1][i] = 1;
	}

	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			if (j == 0)
			{
				dp[i][j] = dp[i - 1][j + 1] % MOD;
			}
			else if (j == 9)
			{
				dp[i][j] = dp[i - 1][j - 1] % MOD;
			}
			else
			{
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
			}
		}
	}

	for (int i = 0; i < 10; i++)
	{
		sum += dp[n][i];
	}

	cout << sum % MOD;
}