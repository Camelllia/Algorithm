#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <cmath>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int testCase;
	cin >> testCase;

	int fivot;
	cin >> fivot;

	int card[100];

	int min = fivot;
	int sum;

	for (int i = 0; i < testCase; i++)
	{
		cin >> card[i];
	}

	for (int i = 0; i < testCase; i++)
	{
		for (int j = i + 1; j < testCase; j++)
		{
			for (int k = j + 1; k < testCase; k++)
			{
				sum = card[i] + card[j] + card[k];
				if (sum <= fivot)
				{
					int gap = fivot - sum;
					if (gap < min)
					{
						min = gap;
					}
				}
			}
		}
	}

	cout << fivot - min;
}
