#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	int cnt = 0;
	cin >> n;

	vector<int> v(n);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	int max = v[n - 1];

	for (int i = n - 1; i > 0; i--)
	{
		if (v[i] <= v[i - 1])
		{
			while (v[i] <= v[i - 1])
			{
				v[i - 1]--;
				cnt++;
			}
		}
	}

	cout << cnt;
}