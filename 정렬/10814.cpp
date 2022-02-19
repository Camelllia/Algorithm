#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

bool compare(pair<int, string> a, pair<int, string> b)
{
	if (a.first < b.first)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int testCase;
	cin >> testCase;

	vector<pair<int, string>> v;

	int x;
	string y;

	for (int i = 0; i < testCase; i++)
	{
		cin >> x >> y;
		v.push_back(pair<int, string>(x, y));
	}

	stable_sort(v.begin(), v.end(), compare);

	for (int i = 0; i < testCase; i++)
	{
		cout << v[i].first << " " << v[i].second << "\n";
	}
}