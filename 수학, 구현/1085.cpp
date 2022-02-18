#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int x, y, w, h;
	int distance = 0;
	int arr[4] = { 0, };

	cin >> x >> y >> w >> h;

	for (int i = 0; i < 4; i++)
	{
		if (i == 0)
		{
			arr[i] = x;
		}
		else if (i == 1)
		{
			arr[i] = y;
		}
		else if (i == 2)
		{
			arr[i] = w - x;
		}
		else
		{
			arr[i] = h - y;
		}
	}

	sort(arr, arr + 4);
	cout << arr[0];

}
