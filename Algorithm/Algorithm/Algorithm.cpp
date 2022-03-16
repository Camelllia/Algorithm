#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#define x first
#define y second

using namespace std;

int origin[1001][1001];
int temp[1001][1001];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m;
int result = 0;
vector<pair<int, int>> virus;

int bfs()
{
	queue<pair<int, int>> q;
	int size = 0;

	for (int i = 0; i < virus.size(); i++)
	{
		q.push({ virus[i].x, virus[i].y });
	}

	while (!q.empty())
	{
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
			if (temp[nx][ny] == 0)
			{
				temp[nx][ny] = 2;
				q.push({ nx, ny });
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (temp[i][j] == 0)
			{
				size++;
			}
		}
	}

	result = max(result, size);
	return result;
}

int comb(int cnt)
{
	if (cnt == 3)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				temp[i][j] = origin[i][j];
			}
		}

		return bfs();
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (origin[i][j] == 0)
			{
				origin[i][j] = 1;
				comb(cnt + 1);
				origin[i][j] = 0;
			}
		}
	}

	return cnt + 1;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> origin[i][j];
			if (origin[i][j] == 2)
			{
				virus.push_back({ i,j });
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (origin[i][j] == 0)
			{
				origin[i][j] = 1;
				comb(1);
				origin[i][j] = 0;
			}
		}
	}

	cout << result;

	return 0;
}


