#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[9];
bool visited[9];

void dfs(int v)
{
	if (v == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		visited[i] = true;
		arr[v] = i;
		dfs(v + 1);
		visited[i] = false;
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	dfs(0);
}