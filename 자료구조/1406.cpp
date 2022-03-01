#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	list<char> li;

	string s;
	cin >> s;

	for (int i = 0; i < s.length(); i++)
	{
		li.push_back(s.at(i));
	}

	auto cursor = li.end();

	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++)
	{
		char c;
		cin >> c;

		if (c == 'L')
		{
			if (cursor != li.begin())
			{
				cursor--;
			}
		}
		else if (c == 'D')
		{
			if (cursor != li.end())
			{
				cursor++;
			}
		}
		else if (c == 'B')
		{
			if (cursor != li.begin())
			{
				cursor = li.erase(--cursor);
			}
		}
		else if (c == 'P')
		{
			char ch;
			cin >> ch;

			li.insert(cursor, ch);
		}
	}

	for (auto c : li)
	{
		cout << c;
	}
}