#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#define x first
#define y second

using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int board[101][101][2];
bool visited[101][101][2];
long long result[2];

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n, m;
	cin >> m >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char c;
			cin >> c;
			if (c == 'W')
			{
				board[i][j][0] = 1;
			}
			if (c == 'B')
			{
				board[i][j][1] = 1;
			}
		}
	}

	for (int tc = 0; tc < 2; tc++)
	{
		queue<pair<int, int>> q;
		result[tc] = 0;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (visited[i][j][tc] || board[i][j][tc] == 0)
				{
					continue;
				}

				visited[i][j][tc] = 1;
				q.push({ i,j });
				int area = 0;

				while (!q.empty())
				{
					auto cur = q.front();
					area++;
					q.pop();

					for (int dir = 0; dir < 4; dir++)
					{
						int nx = cur.x + dx[dir];
						int ny = cur.y + dy[dir];

						if (nx < 0 || nx >= n || ny < 0 || ny >= m)
						{
							continue;
						}
						if (visited[nx][ny][tc] || board[nx][ny][tc] != 1)
						{
							continue;
						}

						visited[nx][ny][tc] = 1;
						q.push({ nx, ny });
					}
				}
				result[tc] += pow(area, 2);
			}
		}
	}

	cout << result[0] << " " << result[1];

}