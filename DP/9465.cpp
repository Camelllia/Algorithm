#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 100001

using namespace std;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int tc;
	cin >> tc;

	while (tc)
	{
		int board[MAX][2] = { 0, };
		int dp[MAX][2] = { 0, };

		int n;
		cin >> n;

		for (int j = 0; j < 2; j++)
		{
			for (int i = 1; i <= n; i++)
			{
				cin >> board[i][j];
			}
		}

		dp[0][0] = 0;
		dp[0][1] = 0;

		for (int i = 2; i <= n; i++)
		{
			dp[i][0] = max(dp[i - 1][1], dp[i - 2][1]) + board[i][0];
			dp[i][1] = max(dp[i - 1][0], dp[i - 2][0]) + board[i][1];
		}

		int result = max(dp[n][0], dp[n][1]);
		cout << result << "\n";

		tc--;
	}
}


