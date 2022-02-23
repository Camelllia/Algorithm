#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int cnt = 0;

	while (true)
	{
		long long l, p, v;
		cin >> l >> p >> v;

		cnt++;

		if (l == 0 && p == 0 && v == 0)
		{
			break;
		}

		long long a = v / p;
		long long b = min(v % p, l);

		cout << "Case " << cnt << ": " << l * a + b << "\n";
	}
}