#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#define x first
#define y second

using namespace std;

int dx[8] = { 1, 0, -1, 0 };
int dy[8] = { 0, -1, 0, 1 };
int board[1002][1002];
int dist[1002][1002];
int n, m;
int result = 0;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	queue<pair<int, int>> q;

	cin >> m >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 1)
			{
				q.push({ i, j });
			}
			if (board[i][j] == 0)
			{
				dist[i][j] = -1;
			}
		}
	}

	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.x + dx[dir];
			int ny = cur.y + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
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

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (dist[i][j] == -1)
			{
				cout << -1;
				return 0;
			}
			result = max(result, dist[i][j]);
		}
	}

	cout << result;
}



