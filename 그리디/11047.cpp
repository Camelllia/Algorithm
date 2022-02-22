#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;

	int count = 0;
	int min = k;
	int pivot = 0;

	vector<int> v(n);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		int n = k - v[i];
		if (n >= 0 && n <= min)
		{
			pivot = i;
		}
	}

	while (true)
	{
		int n = k - v[pivot];
		if (n >= 0)
		{
			k -= v[pivot];
			count++;
		}
		else
		{
			fivot -= 1;
		}

		if (k == 0)
		{
			break;
		}
	}

	cout << count;
}
