#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#define x first
#define y second

using namespace std;

int board[100005];
int dist[100005];
int dx[3] = { 1, -1, 2 };
int n, m;
queue<int> q;

int main()
{
	cin >> n >> m;

	for (int i = 0; i < 100005; i++)
	{
		dist[i] = -1;
	}

	dist[n] = 0;
	q.push(n);

	while (dist[m] == -1)
	{
		int cur = q.front();
		q.pop();

		for (int dir : {cur + 1, cur - 1, cur * 2})
		{
			if (dir < 0 || dir >= 100005)
			{
				continue;
			}
			if (dist[dir] != -1)
			{
				continue;
			}

			dist[dir] = dist[cur] + 1;
			q.push(dir);
		}
	}

	cout << dist[m];
}


