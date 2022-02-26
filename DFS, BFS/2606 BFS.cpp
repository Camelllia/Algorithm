#include <iostream>
#include <vector>
#include <queue>
#define max 101

using namespace std;

int n, m;
int map[max][max];
bool visited[max];
int result;
queue<int> q;

void reset()
{
	for (int i = 1; i <= n; i++)
	{
		visited[i] = 0;
	}
}

void BFS(int v)
{
	q.push(v);
	visited[v] = true;
	//result++;

	while (!q.empty())
	{
		v = q.front();
		q.pop();

		for (int i = 1; i <= n; i++)
		{
			if (visited[i] == 0 && map[v][i] == 1)
			{
				visited[i] = true;
				q.push(i);
				result++;
			}
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
	BFS(1);

	cout << result;
}