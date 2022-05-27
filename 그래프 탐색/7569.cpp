#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <tuple>
#define x first
#define y second

using namespace std;

int dx[6] = { 0,0,1,-1,0,0 };
int dy[6] = { 1,-1,0,0,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };

int board[102][102][102];
int dist[102][102][102];
int n, m, h;
int result = 0;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	queue<tuple<int, int, int>> q;

	cin >> m >> n >> h;

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				cin >> board[j][k][i];
				if (board[j][k][i] == 1)
				{
					q.push({ j, k, i });
				}
				if (board[j][k][i] == 0)
				{
					dist[j][k][i] = -1;
				}
			}
		}
	}

	while (!q.empty())
	{
		tuple<int, int, int> cur = q.front();
		q.pop();

		for (int dir = 0; dir < 6; dir++)
		{
			int nx = get<0>(cur) + dx[dir];
			int ny = get<1>(cur) + dy[dir];
			int nz = get<2>(cur) + dz[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h)
			{
				continue;
			}
			if (dist[nx][ny][nz] >= 0)
			{
				continue;
			}

			dist[nx][ny][nz] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
			q.push({ nx, ny, nz });
		}
	}

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				if (dist[j][k][i] == -1)
				{
					cout << -1;
					return 0;
				}
				result = max(result, dist[j][k][i]);
			}
		}
	}

	cout << result;
}



