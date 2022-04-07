#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#define x first
#define y second

using namespace std;

int n;
int idx = 0;
int result = 1000;
int board[101][101];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void setNumber()
{
	queue<pair<int, int>> q;
	bool visited[101][101];
	memset(visited, false, sizeof(visited));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visited[i][j] || board[i][j] == 0)
			{
				continue;
			}

			idx++;
			q.push({ i, j });
			visited[i][j] = true;
			board[i][j] = idx;

			while (!q.empty())
			{
				auto cur = q.front();
				q.pop();

				for (int dir = 0; dir < 4; dir++)
				{
					int nx = cur.x + dx[dir];
					int ny = cur.y + dy[dir];

					if (nx < 0 || nx >= n || ny < 0 || ny >= n)
					{
						continue;
					}
					if (visited[nx][ny] || board[nx][ny] == 0)
					{
						continue;
					}

					q.push({ nx, ny });
					visited[nx][ny] = true;
					board[nx][ny] = idx;
				}
			}
		}
	}
}

int makeBridge(int num)
{
	queue<pair<int, int>> q;
	bool visited[101][101];
	int leng = 0;

	memset(visited, false, sizeof(visited));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == num)
			{
				visited[i][j] = true;
				q.push({ i,j });
			}
		}
	}

	while (!q.empty())
	{
		int s = q.size();

		for (int i = 0; i < s; i++)
		{
			auto cur = q.front();
			q.pop();

			for (int dir = 0; dir < 4; dir++)
			{
				int nx = cur.x + dx[dir];
				int ny = cur.y + dy[dir];

				if (nx < 0 || nx >= n || ny < 0 || ny >= n)
				{
					continue;
				}

				if (board[nx][ny] == 0 && !visited[nx][ny])
				{
					visited[nx][ny] = true;
					q.push({ nx, ny });
				}
				else if (board[nx][ny] != 0 && board[nx][ny] != num)
				{
					return leng;
				}
			}
		}
		leng++;
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 1)
			{
				board[i][j] = -1;
			}
		}
	}

	setNumber();

	for (int i = 0; i < idx; i++)
	{
		result = min(result, makeBridge(i + 1));
	}

	cout << result;
}