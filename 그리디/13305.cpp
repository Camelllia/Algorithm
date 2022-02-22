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

	long long money = 0;

	vector<long long> dis(n - 1);
	vector<long long> oil(n);

	for (int i = 0; i < n - 1; i++)
	{
		cin >> dis[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> oil[i];
	}

	money += dis[0] * oil[0];
	long long min = oil[0];

	for (int i = 1; i < n - 1; i++)
	{
		if (oil[i] < min)
		{
			min = oil[i];
		}
		money += min * dis[i];
	}

	cout << money;
}