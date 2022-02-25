#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long DP[101];

long long Padovan(int n)
{
	if (n == 1 || n == 2 || n == 3)
	{
		return 1;
	}

	if (DP[n] != 0)
	{
		return DP[n];
	}
	else
	{
		return DP[n] = Padovan(n - 2) + Padovan(n - 3);
	}

}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;

	while (tc)
	{
		int n;
		cin >> n;

		cout << Padovan(n) << "\n";
		tc--;
	}
}