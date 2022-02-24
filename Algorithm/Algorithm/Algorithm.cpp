#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <utility>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	int count = 0;
	int time = 0;
	cin >> n;
	vector<pair<int, int>> v(n);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i].second >> v[i].first;
	}

	sort(v.begin(), v.end());

	
	for (int i = 0; i < n; i++)
	{
		if (time <= v[i].second)
		{
			time = v[i].first;
			count++;
		}
	}

	cout << count;

}