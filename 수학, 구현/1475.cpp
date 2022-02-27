#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int arr[10] = { 0, };
	int max = 0;
	string s;
	cin >> s;

	for (int i = 0; i < s.length(); i++)
	{
		char a = s[i];
		int num = a - 48;

		if (num == 6 || num == 9)
		{
			max++;
		}
		else
		{
			arr[num]++;
		}
	}

	if (max % 2 == 0)
	{
		max /= 2;
	}
	else
	{
		max += 1;
		max /= 2;
	}

	for (int i = 0; i < 10; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}

	cout << max;

}