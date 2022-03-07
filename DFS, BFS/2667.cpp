#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#define x first
#define y second

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	char board[26][26] = { 0, };
	bool visited[26][26] = { 0, };

	int dx[4] = { 1, 0, -1, 0 };
	int dy[4] = { 0, -1, 0, 1 };

	int cnt = 0;
	vector<int> size;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			char c;
			cin >> c;
			board[i][j] = c;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visited[i][j] || board[i][j] == '0')
			{
				continue;
			}

			cnt++;
			queue<pair<int, int>> q;
			visited[i][j] = 1;
			q.push({ i, j });
			int area = 0;

			while (!q.empty())
			{
				area++;
				pair<int, int> cur = q.front();
				q.pop();

				for (int dir = 0; dir < 4; dir++)
				{
					int nx = cur.x + dx[dir];
					int ny = cur.y + dy[dir];

					if (nx < 0 || nx >= n || ny < 0 || ny >= n)
					{
						continue;
					}
					if (visited[nx][ny] || board[nx][ny] != '1')
					{
						continue;
					}

					visited[nx][ny] = 1;
					q.push({ nx, ny });
				}
			}
			size.push_back(area);
		}
	}

	cout << cnt << "\n";

	sort(size.begin(), size.end());

	for (int i = 0; i < cnt; i++)
	{
		cout << size[i] << "\n";
	}
}


