#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;

char board[1002][1002];
int dist[1002][1002][2];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m;
queue<tuple<int, int, int>> q;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> board[i][j];
		}
	}

	for (int i = 0; i <= n + 1; i++)
	{
		for (int j = 1; j <= m + 1; j++)
		{
			dist[i][j][0] = -1;
			dist[i][j][1] = -1;
		}
	}

	q.push({ 1,1,0 });
	dist[1][1][0] = 0;

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();
		if (get<0>(cur) == n && get<1>(cur) == m)
		{
			cout << dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
			return 0;
		}

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = get<0>(cur) + dx[dir];
			int ny = get<1>(cur) + dy[dir];
			int cnt = get<2>(cur);

			if (nx < 0 || nx > n || ny < 0 || ny > m)
			{
				continue;
			}
			else
			{
				if (cnt == 0 && board[nx][ny] == '1' && dist[nx][ny][cnt] == -1)
				{
					q.push({ nx, ny, cnt + 1 });
					dist[nx][ny][cnt + 1] = dist[get<0>(cur)][get<1>(cur)][cnt] + 1;
				}
				if (board[nx][ny] == '0' && dist[nx][ny][cnt] == -1)
				{
					q.push({ nx, ny, cnt });
					dist[nx][ny][cnt] = dist[get<0>(cur)][get<1>(cur)][cnt] + 1;
				}
			}
		}
	}

	cout << -1;
	return 0;
}


