#include <iostream>
#include <algorithm>
#include <cmath>
#include <stack>
#include <string>
using namespace std;

int main()
{
	int testCase;
	string input;
	stack<int> s;

	cin >> testCase;

	for (int i = 0; i < testCase; i++)
	{
		cin >> input;

		if (input == "size")
		{
			cout << size(s) << "\n";
		}
		else if (input == "push")
		{
			int a;
			cin >> a;
			s.push(a);

		}
		else if (input == "pop")
		{
			if (size(s) == 0)
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << s.top() << "\n";
				s.pop();
			}
		}
		else if (input == "top")
		{
			if (s.empty() == 1)
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << s.top() << "\n";
			}
		}
		else if (input == "empty")
		{
			if (s.empty() == 1)
			{
				cout << 1 << "\n";
			}
			else
			{
				cout << 0 << "\n";
			}
		}
	}
}
