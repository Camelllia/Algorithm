#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>

using namespace std;

int dp[10001];
int coin[101];

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> coin[i];
	}

	for (int i = 0; i <= k; i++)
	{
		dp[i] = 10002;
	}

	dp[0] = 0;

	for (int i = 1; i <= k; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i - coin[j] >= 0)
			{
				dp[i] = min(dp[i], dp[i - coin[j]] + 1);
			}	
		}
	}

	if (dp[k] == 10002)
	{
		cout << -1;
	}
	else
	{
		cout << dp[k];
	}
}


