#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++)
	{
		int n, m;
		cin >> n >> m;

		queue<pair<int, int>> q;
		priority_queue<int> pq;

		int count = 0;

		for (int i = 0; i < n; i++)
		{
			int a;
			cin >> a;

			q.push(make_pair(i, a));
			pq.push(a);
		}

		while (true)
		{
			int index = q.front().first;
			int imp = q.front().second;

			if (pq.top() > imp)
			{
				q.push(q.front());
				q.pop();
			}
			else
			{
				q.pop();
				pq.pop();
				count++;

				if (index == m)
				{
					cout << count << "\n";
					break;
				}
			}
		}
	}
}