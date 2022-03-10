#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#define x first
#define y second

using namespace std;

int board[101][101];
int visited[101][101];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m, k, cnt;
queue<pair<int, int>> q;
vector<int> v;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> m >> k;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			board[i][j] = 1;
		}
	}
	
	for (int i = 0; i < k; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int j = y1; j < y2; j++)
		{
			for (int h = x1; h < x2; h++)
			{
				board[j][h] = 0;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 0 || visited[i][j])
			{
				continue;
			}

			visited[i][j] = 1;
			q.push({ i,j });
			cnt++;
			int area = 0;

			while (!q.empty())
			{
				area++;
				auto cur = q.front();
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
			v.push_back(area);
		}
	}

	sort(v.begin(), v.end());

	cout << cnt << "\n";

	for (int i = 0; i < cnt; i++)
	{
		cout << v[i] << " ";
	}
}


