#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		stack<char> st;
		string s;
		bool flag = false;

		cin >> s;
		int len = (int)s.length();

		for (int j = 0; j < len; j++)
		{
			char c = s[j];
			if (c == '(')
			{
				st.push(c);
			}
			else
			{
				if (st.empty() == false)
				{
					st.pop();
				}
				else
				{
					flag = true;
					break;
				}
			}
		}

		if (st.empty() == true && flag == false)
		{
			cout << "YES" << "\n";
		}
		else
		{
			cout << "NO" << "\n";
		}
	}
}