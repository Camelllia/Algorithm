#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>

using namespace std;

long long curTime;
long long exTime;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int n;
	cin >> n;

	vector<pair<int, int>> v;

	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		v.push_back(pair<int, int>(a, b));
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++)
	{
		curTime = v[i].first;
		if (exTime > curTime)
		{
			curTime = exTime;
		}
		exTime = curTime + v[i].second;
	}

	cout << exTime;
}