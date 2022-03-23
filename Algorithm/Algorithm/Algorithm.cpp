#include <iostream>
#include <algorithm>
#include <queue>
#define x first
#define y second

using namespace std;

int n, m, waterCnt;
char board[51][51];
int distWater[51][51];
int distBeaver[51][51];
bool visited[51][51];
int caveX, caveY;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
queue<pair<int, int>> waterQ;
queue<pair<int, int>> beaverQ;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> m;

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			distWater[i][j] = -1;
			distBeaver[i][j] = -1;
			visited[i][j] = false;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char c;
			cin >> c;
			board[i][j] = c;

			if (c == '*')
			{
				waterQ.push({ i,j });
				distWater[i][j] = 0;
				visited[i][j] = true;
			}
			if (c == 'S')
			{
				beaverQ.push({ i,j });
				distBeaver[i][j] = 0;
			}
			if (c == 'D')
			{
				caveX = i;
				caveY = j;
			}
		}
	}

	while (!waterQ.empty())
	{
		auto cur = waterQ.front();
		waterQ.pop();
		
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.x + dx[dir];
			int ny = cur.y + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
			{
				continue;
			}
			else
			{
				if (board[nx][ny] != 'X' && distWater[nx][ny] == -1 && board[nx][ny] != 'D' && board[nx][ny] != '*')
				{
					distWater[nx][ny] = distWater[cur.x][cur.y] + 1;
					waterQ.push({ nx, ny });
					visited[nx][ny] = true;
				}
			}
		}
	}

	while (!beaverQ.empty())
	{
		auto cur = beaverQ.front();
		beaverQ.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.x + dx[dir];
			int ny = cur.y + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
			{
				continue;
			}
			else
			{
				if (board[nx][ny] == 'D')
				{
					distBeaver[nx][ny] = distBeaver[cur.x][cur.y] + 1;
					cout << distBeaver[nx][ny];
					return 0;
				}
				if (visited[nx][ny] == false && distBeaver[nx][ny] == -1 && board[nx][ny] != 'X')
				{
					distBeaver[nx][ny] = distBeaver[cur.x][cur.y] + 1;
					beaverQ.push({ nx, ny });
					continue;
				}
				if (board[nx][ny] != 'X' && distBeaver[nx][ny] == -1 && distBeaver[cur.x][cur.y] + 1 < distWater[nx][ny])
				{
					distBeaver[nx][ny] = distBeaver[cur.x][cur.y] + 1;
					beaverQ.push({ nx, ny });
				}
			}

		}
	}

	cout << "KAKTUS";
}


