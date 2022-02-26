#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define max 1001

int n, m, v;
int map[max][max];
bool visited[max];
queue<int> q;

void reset()
{
	for (int i = 1; i <= n; i++)
	{
		visited[i] = 0;
	}
}

void DFS(int start)
{
	visited[start] = true;
	cout << start << " ";

	for (int i = 1; i <= n; i++)
	{
		if (map[start][i] == 1 && visited[i] == 0)
		{
			DFS(i);
		}
	}
}

void BFS(int start)
{
	q.push(start);
	visited[start] = true;
	cout << start << " ";

	while (!q.empty())
	{
		start = q.front();
		q.pop();

		for (int i = 1; i <= n; i++)
		{
			if (map[start][i] == 1 && visited[i] == 0)
			{
				q.push(i);
				visited[i] = true;
				cout << i << " ";
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m >> v;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}

	reset();
	DFS(v);

	cout << "\n";

	reset();
	BFS(v);
}