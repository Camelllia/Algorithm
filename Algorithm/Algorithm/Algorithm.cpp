#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#define x first
#define y second

using namespace std;

int n, L, R;
int moveDay = 0;
int board[51][51];
bool visited[51][51];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
bool canMove = true;

bool check(int x, int y)
{
	for (int dir = 0; dir < 4; dir++)
	{
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (nx < 0 || nx >= n || ny < 0 || ny >= n)
		{
			continue;
		}
		if (L <= abs(board[x][y] - board[nx][ny]) && abs(board[nx][ny] - board[x][y]) <= R)
		{
			return true;
		}
	}
	return false;
}

void BFS(int i, int j)
{
	queue<pair<int, int>> q;
	queue<pair<int, int>> unionSpot;

	q.push({ i,j });
	unionSpot.push({ i,j });
	visited[i][j] = true;
	int unionSum = 0;
	int unionCnt = 0;

	while (!q.empty())
	{
		auto cur = q.front();
		unionSum += board[cur.x][cur.y];
		unionCnt++;
		q.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.x + dx[dir];
			int ny = cur.y + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n)
			{
				continue;
			}
			if (visited[nx][ny])
			{
				continue;
			}

			if (L <= abs(board[cur.x][cur.y] - board[nx][ny]) && abs(board[nx][ny] - board[cur.x][cur.y]) <= R)
			{
				visited[nx][ny] = true;
				q.push({ nx, ny });
				unionSpot.push({ nx, ny });
			}	
		}
	}

	int unionValue = unionSum / unionCnt;
	
	while (!unionSpot.empty())
	{
		auto spot = unionSpot.front();
		board[spot.x][spot.y] = unionValue;
		unionSpot.pop();
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> L >> R;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}
	}
	
	while (canMove)
	{
		canMove = false;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (!visited[i][j] && check(i,j))
				{
					BFS(i, j);
					canMove = true;
				}
			}
		}
		if (canMove)
		{
			moveDay++;
		}
		memset(visited, false, sizeof(visited));
	}

	cout << moveDay;
}