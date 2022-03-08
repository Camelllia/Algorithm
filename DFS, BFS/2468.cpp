#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#define x first
#define y second

using namespace std;

int board[102][102] = { 0, };
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0, -1, 0, 1 };
int n;
int cnt = 0;
int result = 0;
int limit = 0;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
			limit = max(limit, board[i][j]);
		}
	}

	for (int k = 0; k <= limit; k++)
	{
		bool visited[102][102] = { 0, };

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (visited[i][j] || board[i][j] <= k)
				{
					continue;
				}
				queue<pair<int, int>> q;
				cnt++;
				visited[i][j] = 1;
				q.push({ i, j });

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
						if (visited[nx][ny] || board[nx][ny] <= k)
						{
							continue;
						}

						visited[nx][ny] = 1;
						q.push({ nx, ny });
					}
				}
			}
		}
		result = max(result, cnt);
		cnt = 0;
	}
	cout << result;
}



