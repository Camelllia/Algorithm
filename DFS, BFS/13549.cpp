#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>
#define MAX 100002
using namespace std;

bool visited[MAX];
queue<pair<int, int>> q;
int minTime = MAX;
bool first = false;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n, k;
	cin >> n >> k;

	memset(visited, false, MAX);

	q.push({ n, 0 });
	visited[n] = 1;

	while (!q.empty())
	{
		int curPos = q.front().first;
		int curSec = q.front().second;
		q.pop();
		visited[curPos] = true;

		if (curPos == k && curSec <= minTime)
		{
			minTime = curSec;
		}

		for (int dir : {curPos + 1, curPos - 1, curPos * 2})
		{
			if (dir >= 0 && dir < 100001 && dir == curPos * 2 && !visited[dir])
			{
				q.push({ dir, curSec });
				continue;
			}
			if (dir >= 0 && dir < 100001 && !visited[dir])
			{
				q.push({ dir, curSec + 1 });
			}
		}
	}

	cout << minTime;
}