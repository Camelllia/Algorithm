#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[9];
int select[9] = { 0, };

void dfs(int idx, int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << select[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = idx; i < n; i++)
	{
		select[cnt] = arr[i];
		dfs(i, cnt + 1);
	}

}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		arr[i] = i + 1;
	}

	dfs(0, 0);

}