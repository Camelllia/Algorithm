#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(pair<int, int>a, pair<int, int>b)
{
	if (a.second == b.second)
	{
		return a.first < b.first;
	}
	else
	{
		return a.second < b.second;
	}

}

int main()
{
	vector<pair<int, int>> v;
	int testCase;
	int x, y;

	cin >> testCase;

	for (int i = 0; i < testCase; i++)
	{
		cin >> x >> y;
		v.push_back(pair<int, int>(x, y));
	}

	sort(v.begin(), v.end(), compare);

	for (int j = 0; j < testCase; j++)
	{
		cout << v[j].first << " " << v[j].second << "\n";
	}
}