#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int testCase;
	cin >> testCase;

	int first;
	cin >> first;

	for (int i = 0; i < testCase - 1; i++)
	{
		int n;
		cin >> n;

		if (first % n == 0)
		{
			cout << first / n << "/" << 1 << "\n";
		}
		else
		{
			if (first > n)
			{
				int a = first;
				int b = n;
				int temp;

				while (true)
				{
					temp = a % b;
					a = b;
					b = temp;

					if (b == 0)
					{
						cout << first / a << "/" << n / a << "\n";
						break;
					}
				}
			}
			else
			{
				int a = n;
				int b = first;
				int temp;

				while (true)
				{
					temp = a % b;
					a = b;
					b = temp;

					if (b == 0)
					{
						cout << first / a << "/" << n / a << "\n";
						break;
					}
				}
			}
		}
	}
}
