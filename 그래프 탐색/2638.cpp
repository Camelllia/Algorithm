#include <iostream>
#include <algorithm>
#include <queue>
#define x first
#define y second

using namespace std;

int n, m;
int cnt = 0;
int board[101][101];
bool visited[101][101];
int checkBoard[101][101];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

bool canMelt()
{
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			if (board[i][j] == 1)
			{
				return true;
			}
		}
	}
	return false;
}

void reset()
{
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			visited[i][j] = false;
			checkBoard[i][j] = 0;
		}
	}
}

void bfs()
{
	queue<pair<int, int>> q;

	q.push({ 0,0 });
	visited[0][0] = true;

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
			if (visited[nx][ny])
			{
				continue;
			}

			if (board[nx][ny] == 1 && checkBoard[nx][ny] == 0)
			{
				checkBoard[nx][ny]++;
				continue;
			}
			if (board[nx][ny] == 1 && checkBoard[nx][ny] == 1)
			{
				board[nx][ny] = 0;
				visited[nx][ny] = true;
				continue;
			}

			visited[nx][ny] = true;
			q.push({ nx, ny });
		}
	}
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
		reset();
		cnt++;
		bfs();

		if (!canMelt())
		{
			cout << cnt;
			return 0;
		}
	}
}


