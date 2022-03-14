#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

long long dp[100001];
long long arr[100001];
long long result = -1001;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		dp[i] = arr[i];
	}

	dp[0] = result;

	for (int i = 1; i <= n; i++)
	{
		dp[i] = max(dp[i], dp[i - 1] + arr[i]);
		result = max(dp[i], result);
	}

	cout << result;
}


