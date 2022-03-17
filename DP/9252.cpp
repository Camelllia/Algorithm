#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>

using namespace std;

int dp[1001][1001];
int cnt;
string result;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	string s1, s2;

	cin >> s1 >> s2;

	for (int i = 0; i <= s1.length(); i++)
	{
		for (int j = 0; j <= s2.length(); j++)
		{
			if (i == 0 || j == 0)
			{
				dp[i][j] = 0;
				continue;
			}

			if (s1[i - 1] == s2[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
			cnt = max(cnt, dp[i][j]);
		}
	}

	cout << cnt << "\n";

	int i = s1.length();
	int j = s2.length();
	stack<int> st;

	while (dp[i][j] != 0)
	{
		if (dp[i][j] == dp[i - 1][j])
		{
			i--;
		}
		else if (dp[i][j] == dp[i][j - 1])
		{
			j--;
		}
		else
		{
			st.push(i);
			i--;
			j--;
		}
	}

	while (!st.empty())
	{
		cout << s1[st.top() - 1];
		st.pop();
	}
}


