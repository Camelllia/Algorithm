#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	stack<char> st;
	int cnt = 0;
	string s;
	cin >> s;

	for (int i = 0; i < s.length(); i++)
	{
		char c = s[i];

		if (c == '(')
		{
			st.push(c);
		}
		else
		{
			st.pop();
			if (s[i - 1] == '(')
			{
				cnt += st.size();
			}
			else if (s[i - 1] == ')')
			{
				cnt += 1;
			}
		}
	}

	cout << cnt;
}