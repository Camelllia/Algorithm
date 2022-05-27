#include <iostream>
#include <stdio.h>
#include <queue>
#include <algorithm>
#include <string>
#define x first
#define y second

using namespace std;

int n, m;
int startX, startY;
int resultDist = 9000001;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
int board[3001][3001];
int dist[3001][3001];
queue<pair<int, int>> q;

void initialValueSet();
void bfs();
void printResult();

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	initialValueSet();
	bfs();
	printResult();
}

void bfs()
{
	q.push({ startX, startY });
	dist[startX][startY] = 0;

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		if (board[cur.x][cur.y] == 3 || board[cur.x][cur.y] == 4 || board[cur.x][cur.y] == 5)
		{
			resultDist = min(resultDist, dist[cur.x][cur.y]);
		}

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.x + dx[dir];
			int ny = cur.y + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
			{
				continue;
			}
			if (board[nx][ny] == 1 || dist[nx][ny] != -1)
			{
				continue;
			}

			q.push({ nx, ny });
			dist[nx][ny] = dist[cur.x][cur.y] + 1;
		}
	}
}

void initialValueSet()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string line;
		cin >> line;
		for (int j = 0; j < m; j++)
		{
			board[i][j] = line[j] - '0';
			if (board[i][j] == 2)
			{
				startX = i;
				startY = j;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			dist[i][j] = -1;
		}
	}
}

void printResult()
{
	if (resultDist != 9000001)
	{
		cout << "TAK" << "\n" << resultDist;
	}
	else
	{
		cout << "NIE";
	}
}

