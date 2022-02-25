#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int DP[102][102][102];

int w(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0)
	{
		return 1;
	}

	if (DP[a + 50][b + 50][c + 50] != 0)
	{
		return DP[a + 50][b + 50][c + 50];
	}
	else
	{
		if(a > 20 || b > 20 || c > 20)
		{
			return  DP[a + 50][b + 50][c + 50] = w(20, 20, 20);
		}
		else if (a < b && b < c)
		{
			return DP[a + 50][b + 50][c + 50] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
		}
		else
		{
			return DP[a + 50][b + 50][c + 50] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	while (true)
	{
		int a, b, c;
		cin >> a >> b >> c;

		if (a == -1 && b == -1 && c == -1)
		{
			break;
		}

		cout << "w(" << a << ", " << b << ", " << c << ") " << "= " << w(a, b, c) << "\n";
	}
}