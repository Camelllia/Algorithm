#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#define x first
#define y second

using namespace std;

int board[1001][1001];
bool visited[1001];
int n, m, cnt;

void dfs(int x)
{
	visited[x] = true;

	for (int i = 1; i <= n; i++)
	{
		if (!visited[i] && board[x][i])
		{
			dfs(i);
		}
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		board[u][v] = 1;
		board[v][u] = 1;
	}

	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
			cnt++;
			dfs(i);
		}
	}

	cout << cnt;
}


