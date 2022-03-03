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
	string s;
	int value = 1;
	int result = 0;
	cin >> s;

	for (int i = 0; i < s.length(); i++)
	{
		char c = s[i];

		if (c == '(')
		{
			st.push(c);
			value *= 2;
		}
		else if (c == ')')
		{
			if (st.empty() || st.top() != '(')
			{
				result = 0;
				break;
			}
			else if (s[i - 1] == '(')
			{
				result += value;
			}
			st.pop();
			value /= 2;
		}
		else if (c == '[')
		{
			st.push(c);
			value *= 3;
		}
		else if (c == ']')
		{
			if (st.empty() == true || st.top() != '[')
			{
				result = 0;
				break;
			}
			else if (s[i - 1] == '[')
			{
				result += value;
			}
			st.pop();
			value /= 3;
		}
	}

	if (st.empty())
	{
		cout << result;
	}
	else
	{
		cout << 0;
	}
}