#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int n;
string maxi = "0";
string mini = "999999999";
int arr[10];
bool isused[11];
char oper[10];

bool check()
{
	bool flag = false;
	int idx = 0;

	for (int i = 0; i < n; i++)
	{
		if (oper[i] == '<')
		{
			if (arr[i] < arr[i + 1] == 0)
			{
				return false;
			}
		}
		else if (oper[i] == '>')
		{
			if (arr[i] > arr[i + 1] == 0)
			{
				return false;
			}
		}
	}

	return true;
}

void func(int k)
{
	if (k == n + 1)
	{
		if (check())
		{
			string s = "";
			for (int i = 0; i < n + 1; i++)
			{
				s += to_string(arr[i]);
			}
			maxi = max(maxi, s);
			mini = min(mini, s);
		}
		return;
	}

	for (int i = 0; i < 10; i++)
	{
		if (!isused[i])
		{
			isused[i] = true;
			arr[k] = i;
			func(k + 1);
			isused[i] = false;
		}
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> oper[i];
	}

	func(0);

	cout << maxi << "\n" << mini;
}