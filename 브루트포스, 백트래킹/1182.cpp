#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int n, s, cnt;
int arr[30];

void func(int k, long long sum)
{
	if (k == n)
	{
		if (sum == s)
		{
			cnt++;
		}
		return;
	}

	func(k + 1, sum);
	func(k + 1, sum + arr[k]);
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> s;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	func(0, 0);

	if (s == 0)
	{
		cnt--;
	}

	cout << cnt;
}