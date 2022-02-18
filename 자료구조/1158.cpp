#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	int count = 0;

	queue<int> q;

	for (int i = 0; i < n; i++)
	{
		q.push(i + 1);
	}

	cout << "<";

	while (true)
	{
		if (count < k - 1)
		{
			q.push(q.front());
			q.pop();
			count++;
		}
		else
		{
			if (q.size() == 1)
			{
				cout << q.front() << ">";
				q.pop();
			}
			else
			{
				cout << q.front() << "," << " ";
				q.pop();
			}
			count = 0;
		}

		if (q.empty() == true)
		{
			break;
		}

	}

}