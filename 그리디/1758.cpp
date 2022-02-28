#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool compare(int a, int b)
{
	return a > b;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	long long money = 0;
	int order = 1;
	cin >> n;
	vector<int> v(n);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < n; i++)
	{
		long long tip = v[i] - (order - 1);
		if (tip < 0)
		{
			tip = 0;
		}

		money += tip;
		order++;
	}

	cout << money;
}