#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#define MOD 10007

using namespace std;

long long dp[1001];

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;

	dp[1] = 1;
	dp[2] = 3;

	for (int i = 3; i <= n; i++)
	{
		dp[i] = (dp[i - 2] * 2 + dp[i - 1]) % MOD;
	}

	cout << dp[n];

}


