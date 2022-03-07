#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#define x first
#define y second

using namespace std;

int dx[8] = { 1, 0, -1, 0, 1, -1, -1, 1 };
int dy[8] = { 0, -1, 0, 1, -1, -1, 1, 1 };

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	while (true)
	{
		int board[51][51] = { 0, };
		bool visited[51][51] = { 0, };
		int n, m;
		int cnt = 0;

		cin >> m >> n;

		if (n == 0 && m == 0)
		{
			break;
			return 0;
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				int a;
				cin >> a;
				board[i][j] = a;
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (visited[i][j] || board[i][j] == 0)
				{
					continue;
				}

				queue<pair<int, int>> q;
				visited[i][j] = 1;
				q.push({ i,j });
				cnt++;

				while (!q.empty())
				{
					pair<int, int> cur = q.front();
					q.pop();

					for (int dir = 0; dir < 8; dir++)
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
			}
		}
		cout << cnt << "\n";
	}
}



