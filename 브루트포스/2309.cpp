#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <utility>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int arr[9];
	int sum = 0;
	bool flag = false;

	for (int i = 0; i < 9; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}

	for (int i = 0; i < 9; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			int tmp = arr[i] + arr[j];

			if (sum - tmp == 100)
			{
				arr[i] = 100;
				arr[j] = 100;
				flag = true;
			}
		}

		if (flag == true)
		{
			break;
		}
	}

	sort(arr, arr + 9);

	for (int i = 0; i < 7; i++)
	{
		cout << arr[i] << "\n";
	}
}