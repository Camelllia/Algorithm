#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> v(n, 0);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	float middle = 0;
	int sum = 0;

	for (int i = 0; i < n; i++)
	{
		sum += v[i];
	}

	middle = floor(sum / n + 0.5);
	cout << middle << "\n";

	sort(v.begin(), v.end());
	cout << v[n / 2] << "\n";

	vector<int> count(8001, 0);

	for (int i = 0; i < n; i++)
	{
		count[v[i] + 4000]++;
	}

	int count_max = *max_element(count.begin(), count.end());
	bool flag = true;
	int index = -1;

	for (int i = 0; i < 8001; i++)
	{
		if (count[i] == count_max)
		{
			if (flag)
			{
				flag = false;
				index = i;
			}
			else
			{
				index = i;
				break;
			}
		}
	}

	cout << index - 4000 << "\n";

	cout << v[n - 1] - v[0];
}
