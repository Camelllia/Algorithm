#include <iostream>
#include <queue>
#define x first
#define y second

using namespace std;

int n, m;
int startX, startY;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
int board[1001][1001];
int dist[1001][1001];
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
			if (board[nx][ny] == 0 || dist[nx][ny] != -1)
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
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 1)
			{
				dist[i][j] = -1;
			}
			else
			{
				if (board[i][j] == 2)
				{
					startX = i;
					startY = j;
				}
				dist[i][j] = 0;
			}
		}
	}
}

void printResult()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << dist[i][j] << " ";
		}
		cout << "\n";
	}
}