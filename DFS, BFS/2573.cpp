#include <iostream>
#include <algorithm>
#include <queue>
#define x first
#define y second

using namespace std;

int n, m;
int year = 0;
int area = 0;
int board[301][301];
bool visited[301][301];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int bfs()
{
	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (visited[i][j] || board[i][j] > 0)
			{
				continue;
			}

			q.push({ i,j });
			visited[i][j] = true;

			while (!q.empty())
			{
				auto cur = q.front();
				q.pop();

				for (int dir = 0; dir < 4; dir++)
				{
					int nx = cur.x + dx[dir];
					int ny = cur.y + dy[dir];

					if (nx < 0 || nx >= n || ny < 0 || ny >= m)
					{
						continue;
					}
					else
					{
						if (board[nx][ny] == 0 && !visited[nx][ny])
						{
							q.push({ nx,ny });
							visited[nx][ny] = true;
						}
						if (board[nx][ny] > 0)
						{
							board[nx][ny] -= 1;
							if (board[nx][ny] == 0)
							{
								visited[nx][ny] = true;
							}
						}
					}
				}
			}
		}
	}

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			visited[i][j] = false;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (visited[i][j] || board[i][j] == 0)
			{
				continue;
			}

			area++;
			q.push({ i,j });
			visited[i][j] = true;

			while (!q.empty())
			{
				auto cur = q.front();
				q.pop();

				for (int dir = 0; dir < 4; dir++)
				{
					int nx = cur.x + dx[dir];
					int ny = cur.y + dy[dir];

					if (nx < 0 || nx >= n || ny < 0 || ny >= m)
					{
						continue;
					}
					if (visited[nx][ny] || board[nx][ny] == 0)
					{
						continue;
					}

					q.push({ nx, ny });
					visited[nx][ny] = true;
				}
			}
		}
	}

	return area;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}

	while (true)
	{
		area = 0;
		bool canMelt = false;
		for (int i = 0; i <= n; i++)
		{
			for (int j = 0; j <= m; j++)
			{
				visited[i][j] = false;
			}
		}

		year++;
		if (bfs() >= 2)
		{
			cout << year;
			break;
		}
		else
		{
			for (int i = 0; i <= n; i++)
			{
				for (int j = 0; j <= m; j++)
				{
					if (board[i][j] > 0)
					{
						canMelt = true;
					}
				}
			}

			if (canMelt)
			{
				continue;
			}
			else
			{
				cout << 0;
				return 0;
			}
		}
	}
}


