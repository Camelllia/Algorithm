#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	if (n == 1)
	{
		return 0;
	}

	for (int i = 2; i <= n; i++)
	{
		while (n % i == 0)
		{
			cout << i << "\n";
			n = n / i;
		}
	}
}
