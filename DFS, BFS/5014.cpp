#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>

using namespace std;

int f, s, g, u, d;
int dist[1000001] = { -1, };
queue<int> q;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> f >> s >> g >> u >> d;

	for (int i = 0; i <= f; i++)
	{
		dist[i] = -1;
	}

	q.push(s);
	dist[s] = 0;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int dir : { cur + u, cur - d })
		{
			if (dir > 1000000 || dir <= 0)
			{
				continue;
			}
			if (dist[dir] >= 0)
			{
				continue;
			}

			dist[dir] = dist[cur] + 1;
			q.push(dir);
		}
	}

	if (dist[g] == -1)
	{
		cout << "use the stairs";
	}
	else
	{
		cout << dist[g];
	}
}


