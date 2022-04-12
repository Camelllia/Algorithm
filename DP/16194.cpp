#include <iostream>
#include <algorithm>

using namespace std;

int n;
int dp[1001];
int arr[1001];

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		dp[i] = arr[i];
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			dp[i] = min(dp[i], dp[i - j] + arr[j]);
		}
	}

	cout << dp[n];
}