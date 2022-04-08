#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n;
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n;

	while (n)
	{
		int a;
		cin >> a;

		if (a == 0)
		{
			if (pq.empty())
			{
				cout << 0 << "\n";
			}
			else
			{
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else
		{
			pq.push(a);
		}

		n--;
	}
}