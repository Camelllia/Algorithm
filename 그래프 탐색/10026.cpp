#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#define x first
#define y second

using namespace std;

int board[102][102][4] = { 0, };
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0, -1, 0, 1 };
int n;
int cnt[4] = { 0, };

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			char c;
			cin >> c;
			if (c == 'R')
			{
				board[i][j][0] = 1;
			}
			if (c == 'G')
			{
				board[i][j][1] = 1;
			}
			if (c == 'R' || c == 'G')
			{
				board[i][j][2] = 1;
			}
			if (c == 'B')
			{
				board[i][j][3] = 1;
			}
		}
	}

	for (int k = 0; k < 4; k++)
	{
		bool visited[102][102] = { 0, };

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (visited[i][j] || board[i][j][k] == 0)
				{
					continue;
				}

				queue<pair<int, int>> q;
				visited[i][j] = 1;
				q.push({ i,j });
				cnt[k]++;

				while (!q.empty())
				{
					pair<int, int> cur = q.front();
					q.pop();

					for (int dir = 0; dir < 4; dir++)
					{
						int nx = cur.x + dx[dir];
						int ny = cur.y + dy[dir];

						if (nx < 0 || nx >= n || ny < 0 || ny >= n)
						{
							continue;
						}
						if (visited[nx][ny] || board[nx][ny][k] != 1)
						{
							continue;
						}

						visited[nx][ny] = 1;
						q.push({ nx, ny });
					}
				}
			}
		}
	}

	cout << cnt[0] + cnt[1] + cnt[3] << " " << cnt[2] + cnt[3];
}



