#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#define x first
#define y second

using namespace std;

char board[1001][1001][2];
int dist[1001][1001][2];
int dx[4] = { 1, 0 , -1 , 0 };
int dy[4] = { 0, 1 , 0 , -1 };
int n, m;
queue<pair<int, int>> q;

//0-이동, 1-벽 -> 벽 1개 부수기 가능 -> 최단거리 

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> board[i][j][0];
		}
	}

	q.push({ 1,1 });
	dist[1][1][0] = 0;
	
	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.x + dx[dir];
			int ny = cur.y + dy[dir];

			if (nx < 0 || nx > n || ny < 0 || ny > m)
			{
				continue;
			}
			

		}
	}
}