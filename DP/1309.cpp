#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>

using namespace std;

long long dp[100001];

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;

	dp[1] = 3;
	dp[2] = 7;

	for (int i = 3; i <= n; i++)
	{
		dp[i] = (dp[i - 1] * 2 + dp[i - 2]) % 9901;
	}

	cout << dp[n];
}