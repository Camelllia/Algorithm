#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	int sum = 0;

	for (int i = 5; i <= n; i *= 5)
	{
		sum += n / i;
	}

	cout << sum;
}