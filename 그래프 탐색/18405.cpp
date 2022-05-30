#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
#define x first
#define y second

using namespace std;

class cmp {
public: bool operator() (tuple<int, int, int> a, tuple<int, int, int> b) {
	return get<2>(a) > get<2>(b);
}
};

int n, k, s;
int targetX, targetY;
int board[201][201];
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0, 1, 0 ,-1 };
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, cmp> pq;
vector<tuple<int, int, int>> vec;

void initialValueSet();
int BFS();

int main()
{
	initialValueSet();
	cout << BFS();
}

int BFS()
{
	for (int time = 0; time < s; time++)
	{
		for (int i = 0; i < vec.size(); i++)
		{
			pq.push(vec[i]);
		}
		vec.clear();
		int size = pq.size();

		while (size--)
		{
			auto cur = pq.top();
			pq.pop();

			for (int dir = 0; dir < 4; dir++)
			{
				int nx = get<0>(cur) + dx[dir];
				int ny = get<1>(cur) + dy[dir];

				if (nx < 0 || nx >= n || ny < 0 || ny >= n)
				{
					continue;
				}
				if (board[nx][ny] != 0)
				{
					continue;
				}

				board[nx][ny] = get<2>(cur);
				vec.push_back({ nx, ny, board[nx][ny] });
			}
		}
	}

	return board[targetX - 1][targetY - 1];
}

void initialValueSet()
{
	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
			if (board[i][j] != 0)
			{
				pq.push({ i, j, board[i][j] });
			}
		}
	}

	cin >> s >> targetX >> targetY;
}

