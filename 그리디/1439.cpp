#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <utility>

using namespace std;

int ToZero(string s)
{
	int ZeroCnt = 0;
	bool flag = false;
	char tmp = s[s.length() - 1];

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '1')
		{
			s[i] = '0';
			if (flag == true)
			{
				ZeroCnt++;
				flag = false;
			}
		}
		else
		{
			flag = true;
		}
	}

	if (flag == true)
	{
		ZeroCnt++;
	}

	return ZeroCnt;
}

int ToOne(string s)
{
	int OneCnt = 0;
	bool flag = false;
	char tmp = s[s.length() - 1];

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '0')
		{
			s[i] = '1';
			if (flag == true)
			{
				OneCnt++;
				flag = false;
			}
		}
		else
		{
			flag = true;
		}
	}

	if (flag == true)
	{
		OneCnt++;
	}

	return OneCnt;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string s;
	cin >> s;

	cout << min(ToZero(s), ToOne(s));
}