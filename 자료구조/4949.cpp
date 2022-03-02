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

	while (true)
	{
		stack<char> st;
		string s;
		getline(cin, s);
		int a = 0;
		int b = 0;

		if (s == ".")
		{
			break;
			return 0;
		}

		for (int i = 0; i < s.length(); i++)
		{
			char c = s[i];
			if (c == '(')
			{
				st.push(c);
				a++;
			}
			else if (c == ')')
			{
				a--;
				if (st.empty() == false && st.top() == '(')
				{
					st.pop();
				}
			}
			else if (c == '[')
			{
				st.push(c);
				b++;
			}
			else if (c == ']')
			{
				b--;
				if (st.empty() == false && st.top() == '[')
				{
					st.pop();
				}
			}
		}

		if (st.empty() == true && a == 0 && b == 0)
		{
			cout << "yes" << "\n";
		}
		else
		{
			cout << "no" << "\n";
		}
	}
}