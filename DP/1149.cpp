#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>

using namespace std;

int rgb[3];
int dp[1001][3];
int cost;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	dp[0][0] = 0;
	dp[0][1] = 0;
	dp[0][2] = 0;

	for (int i = 1; i <= n; i++)
	{
		cin >> rgb[0] >> rgb[1] >> rgb[2];

		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + rgb[0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + rgb[1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + rgb[2];
	}

	cout << min(dp[n][0], min(dp[n][1], dp[n][2]));
}