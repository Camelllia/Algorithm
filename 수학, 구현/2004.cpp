#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

long long n, r;
long long temp;
long long five;
long long two;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> r;

	temp = n - r;

	if (n == r || r == 0)
	{
		cout << 0;
		return 0;
	}

	for (long long i = 5; i <= n; i *= 5)
	{
		five += n / i;
		five -= r / i;
		five -= temp / i;
	}

	for (long long i = 2; i <= n; i *= 2)
	{
		two += n / i;
		two -= r / i;
		two -= temp / i;
	}

	cout << min(two, five);
}