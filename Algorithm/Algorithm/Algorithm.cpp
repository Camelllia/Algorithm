#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int main()
{

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	queue<int> q;
	int testCase;
	
	cin >> testCase;

	if (testCase == 1)
	{
		cout << 1;
		return 0;
	}

	for (int i = 1; i <= testCase; i++)
	{
		q.push(i);
	}

	while (true)
	{
		q.pop();
		int a = q.front();
		q.pop();
		q.push(a);

		if (size(q) == 1)
		{
			break;
		}
	}

	cout << q.front();
}
