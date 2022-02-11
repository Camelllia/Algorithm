#include <iostream>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;

int main()
{
	int testCase;
	stack<int> s;
	int sum = 0;

	cin >> testCase;

	for (int i = 0; i < testCase; i++)
	{
		int a;
		cin >> a;

		if (a == 0)
		{
			s.pop();
		}
		else
		{
			s.push(a);
		}	
	}

	while (!s.empty())
	{
		sum += s.top();
		s.pop();
	}

	cout << sum;
}
