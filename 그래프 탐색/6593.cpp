#include<iostream>
#include<queue>
#include<tuple>

using namespace std;

const int dx[6] = { -1, 1, 0, 0, 0, 0 };
const int dy[6] = { 0, 0, -1, 1, 0, 0 };
const int dz[6] = { 0, 0, 0, 0, -1, 1 };

void bfs(int board[31][31][31], int dist[31][31][31], int startX, int startY, int startZ, int l, int n, int m)
{
	// BFS
	queue<tuple<int, int, int>> q;
	q.push({ startX, startY, startZ });
	dist[startX][startY][startZ] = 0;


	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		for (int dir = 0; dir < 6; dir++)
		{
			int nx = get<0>(cur) + dx[dir];
			int ny = get<1>(cur) + dy[dir];
			int nz = get<2>(cur) + dz[dir];

			if (nx < 0 || nx > n || ny < 0 || ny > m || nz < 0 || nz > l)
			{
				continue;
			}
			if (dist[nx][ny][nz] >= 0 || board[nx][ny][nz] == 0)
			{
				continue;
			}

			q.push({ nx, ny, nz });
			dist[nx][ny][nz] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;

			if (board[nx][ny][nz] == 7)
			{
				cout << "Escaped in " << dist[nx][ny][nz] << " minute(s)." << "\n";
				return;
			}
		}
	}

	cout << "Trapped!" << "\n";
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	while (true)
	{
		int l, n, m;
		int startX = 0;
		int startY = 0;
		int startZ = 0;
		int board[31][31][31];
		int dist[31][31][31];

		cin >> l >> n >> m;

		if (l == 0 && n == 0 && m == 0)
		{
			break;
		}

		for (int k = 0; k < l; k++)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					char c;
					cin >> c;
					if (c == '.')
					{
						board[i][j][k] = 1;
					}
					else if (c == '#')
					{
						board[i][j][k] = 0;
					}
					else if (c == 'S')
					{
						board[i][j][k] = 0;
						startX = i;
						startY = j;
						startZ = k;
					}
					else if (c == 'E')
					{
						board[i][j][k] = 7;
					}
					dist[i][j][k] = -1;
				}
			}
		}

		bfs(board, dist, startX, startY, startZ, l, n, m);
	}
}
