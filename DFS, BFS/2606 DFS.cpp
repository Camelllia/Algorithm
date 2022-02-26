#include <iostream>
#include <vector>
#include <queue>
#define max 101

using namespace std;

int n, m;
int map[max][max];
bool visited[max];
int result;

void reset()
{
	for (int i = 1; i <= n; i++)
	{
		visited[i] = 0;
	}
}

void DFS(int v)
{
	visited[v] = true;

	for (int i = 1; i <= n; i++)
	{
		if (visited[i] == 0 && map[v][i] == 1)
		{
			DFS(i);
			result++;
		}
	}
}

int main()
{
	cin >> n >> m;

	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;

		map[a][b] = 1;
		map[b][a] = 1;
	}

	reset();
	DFS(1);
	cout << result;
}