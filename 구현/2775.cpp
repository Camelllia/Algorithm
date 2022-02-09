#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int testCase;
	int k = 0;
	int n = 0;
	int apart[15][15] = { 0, };

	cin >> testCase;

	while (testCase > 0)
	{
		for (int i = 0; i < 15; i++)
		{
			for (int j = 0; j < 15; j++)
			{
				if (i == 0)
				{
					apart[0][j] = j;
				}
				else if (j == 1)
				{
					apart[i][1] = 1;
				}
				else
				{
					apart[i][j] = apart[i - 1][j] + apart[i][j - 1];
				}
			}
		}

		cin >> k >> n;
		cout << apart[k][n] << "\n";
		testCase--;
	}
}