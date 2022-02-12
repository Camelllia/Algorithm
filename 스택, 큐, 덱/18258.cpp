#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int main()
{

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	queue<int> q;
	int testCase;

	cin >> testCase;

	for (int i = 0; i < testCase; i++)
	{
		string s;
		cin >> s;

		if (s == "push")
		{
			int a;
			cin >> a;

			q.push(a);
		}
		else if (s == "pop")
		{
			if (q.empty() == 0)
			{
				cout << q.front() << "\n";
				q.pop();
			}
			else
			{
				cout << -1 << "\n";
			}
		}
		else if (s == "size")
		{
			cout << size(q) << "\n";
		}
		else if (s == "front")
		{
			if (q.empty() == 0)
			{
				cout << q.front() << "\n";
			}
			else
			{
				cout << -1 << "\n";
			}
		}
		else if (s == "back")
		{
			if (q.empty() == 0)
			{
				cout << q.back() << "\n";
			}
			else
			{
				cout << -1 << "\n";
			}
		}
		else if (s == "empty")
		{
			if (q.empty() == 0)
			{
				cout << 0 << "\n";
			}
			else
			{
				cout << 1 << "\n";
			}
		}

	}

}
