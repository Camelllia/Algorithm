#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int g_Arr[2][3];

int(*func(int arg))[2][3]
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			g_Arr[i][j] = arg;
		}
	}
	return &g_Arr;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cout << (*func(7))[0][0] << endl;
	cout << (*func(7))[1][2] << endl;

	return 0;
}


