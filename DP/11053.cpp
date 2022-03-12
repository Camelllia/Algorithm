#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#define MOD 10007

using namespace std;

int dp[1001] = { 0, };
int arr[1001] = { 0, };
int mx = 0;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		dp[i] = 1;
	}

	for (int i = 0; i < n; i++)
	{
		if (i == 0)
		{
			dp[i] = 1;
		}

		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j])
			{
				if (dp[i] < dp[j] + 1)
				{
					dp[i] = dp[j] + 1;
				}
			}
		}

		mx = max(mx, dp[i]);
	}

	cout << mx;
}


