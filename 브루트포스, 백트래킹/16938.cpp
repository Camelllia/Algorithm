#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n, l, r, x;
int result = 0;
vector<int> level;
vector<int> problems;
bool isused[16];

bool check()
{
	int sum = 0;

	for (int i = 0; i < problems.size(); i++)
	{
		sum += problems[i];
	}

	sort(problems.begin(), problems.end());

	if (sum >= l && sum <= r && (problems.back() - problems.front()) >= x)
	{
		return true;
	}
	return false;
}

void func(int k, int cnt, int pivot)
{
	if (k == pivot)
	{
		for (int i = 0; i < level.size(); i++)
		{
			if (isused[i])
			{
				problems.push_back(level[i]);
			}
		}
		if (check())
		{
			result++;
		}
		problems.clear();
		return;
	}

	for (int i = cnt; i < level.size(); i++)
	{
		if (!isused[i])
		{
			isused[i] = true;
			func(k + 1, i + 1, pivot);
			isused[i] = false;
		}
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> l >> r >> x;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		level.push_back(a);
	}

	for (int i = 2; i < level.size() + 1; i++)
	{
		func(0, 0, i);
		memset(isused, false, sizeof(isused));
	}

	cout << result;
}