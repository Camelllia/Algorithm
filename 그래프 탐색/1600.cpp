#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int k, n, m;
int moveCnt = 0;
int board[201][201];
//�ּ� ����Ƚ�� ���� �迭
int dist[201][201][31];
int dx[12] = { 1,0,-1,0,-2,-1,1,2,2,1,-1,-2 };
int dy[12] = { 0,1,0,-1,-1,-2,-2,-1,1,2,2,1 };
bool canGo;
//tuple -> x��ǥ, y��ǥ, ��ó�� �̵��� Ƚ��
queue<tuple<int, int, int>> q;

void reset()
{
	for (int k = 0; k < 31; k++)
	{
		for (int i = 0; i <= n; i++)
		{
			for (int j = 0; j <= m; j++)
			{
				dist[i][j][k] = -1;
			}
		}
	}
}

void bfs()
{
	q.push({ 0, 0, 0 });
	dist[0][0][0] = 0;

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();
		int moveCnt = get<2>(cur);

		//������ ������ ����ϰ� ����
		if (get<0>(cur) == n - 1 && get<1>(cur) == m - 1)
		{
			cout << dist[n - 1][m - 1][moveCnt];
			canGo = true;
			return;
		}

		if (moveCnt < k)
		{
			for (int dir = 4; dir < 12; dir++)
			{
				int nx = get<0>(cur) + dx[dir];
				int ny = get<1>(cur) + dy[dir];

				//���� ���� -> out
				if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				{
					continue;
				}
				//��ֹ��� ���� -> out
				if (board[nx][ny] == 1 || dist[nx][ny][moveCnt + 1] != -1)
				{
					continue;
				}

				q.push({ nx, ny, moveCnt + 1 });
				dist[nx][ny][moveCnt + 1] = dist[get<0>(cur)][get<1>(cur)][moveCnt] + 1;
			}
		}

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = get<0>(cur) + dx[dir];
			int ny = get<1>(cur) + dy[dir];

			//���� ���� -> out
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
			{
				continue;
			}
			//��ֹ��� ���� -> out
			if (board[nx][ny] == 1 || dist[nx][ny][moveCnt] != -1)
			{
				continue;
			}

			q.push({ nx, ny, moveCnt });
			dist[nx][ny][moveCnt] = dist[get<0>(cur)][get<1>(cur)][moveCnt] + 1;
		}
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> k >> m >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}

	//����Ƚ�� ���� �迭 �ʱ�ȭ
	reset();

	bfs();

	if (!canGo)
	{
		cout << -1;
	}
}