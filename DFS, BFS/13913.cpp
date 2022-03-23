#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

const int MAX = 100005;
int visited[MAX];
int parent[MAX];
int n, k;
queue<pair<int, int>> q;
stack<int> st;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> k;

	q.push({ n, 0 });
	visited[n] = 1;

	while (!q.empty())
	{
		int pos = q.front().first;
		int sec = q.front().second;
		q.pop();

		if (pos == k)
		{
			cout << sec << "\n";
			int now = k;
			while (now != n)
			{
				st.push(now);
				now = parent[now];
			}
			st.push(n);
		}

		for (int dir : {pos + 1, pos - 1, pos * 2})
		{
			if (dir < 0 || dir >= MAX)
			{
				continue;
			}
			else
			{
				if (!visited[dir])
				{
					visited[dir] = 1;
					parent[dir] = pos;
					q.push({ dir, sec + 1 });
				}

			}
		}
	}

	while (!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
}


