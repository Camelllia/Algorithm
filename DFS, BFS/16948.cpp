#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#define x first
#define y second

using namespace std;

int dx[6] = { -2,-2,0,0,2,2 };
int dy[6] = { -1,1,-2,2,-1,1 };
int dist[201][201];
queue<pair<int, int>> q;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			dist[i][j] = -1;
		}
	}

	dist[x1][y1] = 0;
	q.push({ x1,y1 });

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		for (int dir = 0; dir < 6; dir++)
		{
			int nx = cur.x + dx[dir];
			int ny = cur.y + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n)
			{
				continue;
			}
			if (dist[nx][ny] >= 0)
			{
				continue;
			}

			dist[nx][ny] = dist[cur.x][cur.y] + 1;
			q.push({ nx, ny });
		}
	}

	cout << dist[x2][y2];

}


