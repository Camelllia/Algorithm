#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <cmath>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	int sum;
	int div;

	for (int i = 1; i <= n; i++)
	{
		sum = i;
		div = i;

		while (div)
		{
			sum += div % 10;
			div /= 10;
		}

		if (n == sum)
		{
			cout << i << "\n";
			return 0;
		}
	}

	cout << 0 << "\n";
}