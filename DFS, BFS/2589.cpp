#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#define x first
#define y second

using namespace std;

int board[51][51] = { 0, };
int dist[51][51];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int n, m;
int result = 0;

void reset()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			dist[i][j] = -1;
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	reset();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char c;
			cin >> c;
			if (c == 'W')
			{
				board[i][j] = 0;
			}
			if (c == 'L')
			{
				board[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 0)
			{
				continue;
			}
			queue<pair<int, int>> q;
			q.push({ i, j });
			dist[i][j] = 0;

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
					if (dist[nx][ny] >= 0 || board[nx][ny] != 1)
					{
						continue;
					}

					dist[nx][ny] = dist[cur.x][cur.y] + 1;
					q.push({ nx, ny });
					result = max(result, dist[nx][ny]);
				}
			}
			reset();
		}
	}
	cout << result;
}


