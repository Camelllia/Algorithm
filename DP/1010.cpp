#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long DP[1001][1001];

long long bino(int n, int r)
{
	if (r > n)
	{
		return 0;
	}

	if (r == 0 || n == r)
	{
		return 1;
	}

	if (DP[n][r] != 0)
	{
		return DP[n][r];
	}
	else
	{
		return DP[n][r] = bino(n - 1, r) + bino(n - 1, r - 1);
	}

}


int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++)
	{
		int n, r;
		cin >> r >> n;
		cout << bino(n, r) << "\n";
	}
}