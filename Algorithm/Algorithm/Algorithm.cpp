#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#define x first
#define y second

using namespace std;

long long n, m;
long long cnt = 0;
queue < pair<long long, long long>> q;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> m;

	q.push({n, 1});
	
	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		if (cur.x == m)
		{
			cout << cur.y;
			return 0;
		}
		
		if (cur.x < m)
		{
			q.push({ cur.x * 10 + 1, cur.y + 1 });
		}
		if (cur.x < m)
		{
			q.push({ cur.x * 2, cur.y + 1 });
		}

	}

	cout << -1;
}


