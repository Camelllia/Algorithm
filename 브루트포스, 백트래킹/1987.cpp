#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int result = 0;
char board[21][21];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
bool isused[26];

void func(int x, int y, int cnt)
{
	result = max(result, cnt);

	for (int dir = 0; dir < 4; dir++)
	{
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (nx < 0 || nx >= n || ny < 0 || ny >= m)
		{
			continue;
		}

		if (!isused[board[nx][ny] - 'A'])
		{
			isused[board[nx][ny] - 'A'] = true;
			func(nx, ny, cnt + 1);
			isused[board[nx][ny] - 'A'] = false;
		}
	}
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
			cin >> board[i][j];
		}
	}

	isused[board[0][0] - 'A'] = true;
	func(0, 0, 0);

	cout << result + 1;
}