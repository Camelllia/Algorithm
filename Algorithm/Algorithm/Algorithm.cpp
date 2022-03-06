#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>

using namespace std;

long long card[1001];
long long dp[1001];
long long result;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int num;
	cin >> num;

	for (int i = 1; i <= num; i++)
	{
		cin >> card[i];
	}

	dp[1] = card[1];

	for (int i = 2; i <= num; i++)
	{
		dp[i] = card[i];

		for (int j = 1; j <= i; j++)
		{
			dp[i] = max(dp[i], dp[i - j] + card[j]);
		}
	}

	cout << dp[num];
}