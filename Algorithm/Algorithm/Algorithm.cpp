#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	int result = 0;
	int count = 0;

	while (count != n)
	{
		result++;
		int temp = result;

		while (temp != 0)
		{
			if (temp % 1000 == 666)
			{
				count++;
				break;
			}
			else
			{
				temp /= 10;
			}
		}
	}

	cout << result;
}