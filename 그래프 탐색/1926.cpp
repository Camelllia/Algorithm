#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#define x first
#define y second

using namespace std;

int n, m;
int board[501][501];
bool visited[501][501];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int cnt = 0;
int maxS = 0;

void BFS()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 0 || visited[i][j])
			{
				continue;
			}

			cnt++;
			queue<pair<int, int>> q;
			visited[i][j] = 1;
			q.push({ i, j });
			int area = 0;

			while (!q.empty())
			{
				area++;
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
					if (visited[nx][ny] || board[nx][ny] != 1)
					{
						continue;
					}

					visited[nx][ny] = 1;
					q.push({ nx, ny });
				}
			}
			maxS = max(maxS, area);
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}

	BFS();

	cout << cnt << "\n";
	cout << maxS;
}