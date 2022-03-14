#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

long long dp[1001];
long long result = 0;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;

	vector<int> v(n);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		dp[i] = v[i];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (v[i] > v[j] && dp[i] < dp[j] + v[i])
			{
				dp[i] = dp[j] + v[i];
			}
		}
		result = max(result, dp[i]);
	}

	cout << result;
}


