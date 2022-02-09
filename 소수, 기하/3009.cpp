#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int x[1001] = { 0, };
	int y[1001] = { 0, };

	int resultX = 0;
	int resultY = 0;

	int get = 0;
	int set = 0;

	for (int i = 0; i < 3; i++)
	{
		cin >> resultX;
		cin >> resultY;

		x[resultX]++;
		y[resultY]++;
	}

	for (int i = 0; i < 1000; i++)
	{
		if (x[i] == 1)
		{
			set = i;
		}
		if (y[i] == 1)
		{
			get = i;
		}
	}

	cout << set << " " << get;
}
