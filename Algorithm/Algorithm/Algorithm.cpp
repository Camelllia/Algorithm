#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
int num[10];
int arr[10001];
bool isused[10001];

void dfs(int cnt, int k)
{
	if (k == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = cnt; i <= n; i++)
	{
		if (!isused[num[i]])
		{
			isused[num[i]] = 1;
			arr[k] = num[i];
			dfs(i + 1, k + 1);
			isused[num[i]] = 0;
		}
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		cin >> num[i];
	}

	sort(num, num + n + 1);

	dfs(1, 0);
}