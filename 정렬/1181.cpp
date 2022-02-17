#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <cmath>
#include <vector>
using namespace std;

bool compare(const string& a, const string& b)
{
	if (a.length() != b.length())
	{
		return a.length() < b.length();
	}
	else
	{
		return a < b;
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int testCase;
	cin >> testCase;

	vector<string> v(testCase);

	for (int i = 0; i < testCase; i++)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end(), compare);

	cout << v[0] << "\n";

	for (int i = 1; i < testCase; i++)
	{
		if (v[i - 1] == v[i])
		{
			continue;
		}
		cout << v[i] << "\n";
	}
}