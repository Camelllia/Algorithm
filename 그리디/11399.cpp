#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> v(n);

	int sum = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	for (int i = 1; i < n + 1; i++)
	{
		int n = 0;
		for (int j = 0; j < i; j++)
		{
			n += v[j];
		}

		sum += n;
	}

	cout << sum;
}