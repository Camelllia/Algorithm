#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#define x first
#define y second

using namespace std;

char board[1001][1001] = { 0, };
int dist1[1001][1001];
int dist2[1001][1001];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int n, m;
int result = 0;
queue<pair<int, int>> q1;
queue<pair<int, int>> q2;

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			dist1[i][j] = -1;
			dist2[i][j] = -1;
			cin >> board[i][j];
			if (board[i][j] == 'J')
			{
				q2.push({ i,j });
				dist2[i][j] = 0;
			}
			if (board[i][j] == 'F')
			{
				q1.push({ i,j });
				dist1[i][j] = 0;
			}
		}
	}

	while (!q1.empty())
	{
		pair<int, int> cur = q1.front();
		q1.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.x + dx[dir];
			int ny = cur.y + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
			{
				continue;
			}
			if (dist1[nx][ny] >= 0 || board[nx][ny] == '#')
			{
				continue;
			}

			dist1[nx][ny] = dist1[cur.x][cur.y] + 1;
			q1.push({ nx, ny });
		}
	}

	while (!q2.empty())
	{
		pair<int, int> cur = q2.front();
		q2.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.x + dx[dir];
			int ny = cur.y + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
			{
				cout << dist2[cur.x][cur.y] + 1;
				return 0;
			}
			if (dist2[nx][ny] >= 0 || board[nx][ny] == '#')
			{
				continue;
			}
			if (dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.x][cur.y] + 1)
			{
				continue;
			}

			dist2[nx][ny] = dist2[cur.x][cur.y] + 1;
			q2.push({ nx, ny });
		}
	}

	cout << "IMPOSSIBLE";
}


