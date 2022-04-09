#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct cmp
{
	bool operator()(int a, int b)
	{
		if (abs(a) > abs(b))
		{
			return true;
		}
		else if (abs(a) == abs(b))
		{
			if (a > b)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		return false;
	}
};

int main()
{

	priority_queue<int, vector<int>, cmp> pq;
	int n;
	cin >> n;

	while (n)
	{
		int a;
		cin >> a;

		if (a == 0)
		{
			if (!pq.empty())
			{
				cout << pq.top() << "\n";
				pq.pop();
			}
			else
			{
				cout << 0 << "\n";
			}
		}
		else
		{
			pq.push(a);
		}
		n--;
	}
}