#include<iostream>
#include<algorithm>
#include<queue>
#define x first
#define y second

using namespace std;

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0, 1, 0, -1 };
int n, m;
int board[51][51];
int globalMaxDist = -2;
int password = -2;

void input();
void bfs(int startX, int startY);

int main()
{

	cin.tie(0);
	ios::sync_with_stdio(0);

	input();

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] != 0)
			{
				bfs(i, j);
			}
		}
	}

	cout << password;
}

void input()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}
}

void bfs(int startX, int startY)
{
	queue<pair<int, int>> q;

	int dist[51][51];
	int maxDist = -20;
	int desX = 0;
	int desY = 0;

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			dist[i][j] = -1;
		}
	}

	q.push({ startX, startY });
	dist[startX][startY] = 0;

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		if (dist[cur.x][cur.y] >= globalMaxDist)
		{
			if (dist[cur.x][cur.y] > globalMaxDist)
			{
				password = board[startX][startY] + board[cur.x][cur.y];
			}
			else
			{
				password = max(board[startX][startY] + board[cur.x][cur.y], password);
			}
			globalMaxDist = dist[cur.x][cur.y];
		}

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.x + dx[dir];
			int ny = cur.y + dy[dir];

			if (nx < 0 || nx > n || ny < 0 || ny > m)
			{
				continue;
			}
			if (board[nx][ny] == 0 || dist[nx][ny] >= 0)
			{
				continue;
			}

			q.push({ nx, ny });
			dist[nx][ny] = dist[cur.x][cur.y] + 1;
		}
	}
}

