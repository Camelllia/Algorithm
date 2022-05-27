#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

queue<pair<int, int>> q;
bool visited[100002];
int cnt;
int minTime;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n, k;
	cin >> n >> k;

	q.push({ n,0 });
	visited[n] = true;

	while (!q.empty())
	{
		int curPos = q.front().first;
		int curSec = q.front().second;
		q.pop();
		visited[curPos] = true;

		if (cnt == 0 && curPos == k)
		{
			minTime = curSec;
			cnt++;
		}
		if (cnt > 0 && curPos == k && curSec == minTime)
		{
			cnt++;
		}

		for (int dir : {curPos + 1, curPos - 1, curPos * 2})
		{
			if (dir < 0 || dir > 100001)
			{
				continue;
			}
			if (!visited[dir])
			{
				q.push({ dir, curSec + 1 });
			}
		}
	}

	cout << minTime << "\n" << cnt - 1;
}


