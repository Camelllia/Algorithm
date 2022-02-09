#include <iostream>
using namespace std;

int main()
{
	int num[3] = { 0, };
	int max = 0;
	int sum = 0;

	while (true)
	{
		for (int i = 0; i < 3; i++)
		{
			cin >> num[i];
			if (num[i] > max)
			{
				max = num[i];
			}
		}

		for (int j = 0; j < 3; j++)
		{
			if (num[j] == max)
			{
				num[j] = 0;
			}
			sum += num[j] * num[j];
		}

		if (max * max == sum && max != 0)
		{
			cout << "right" << " ";
		}
		else if (max * max == 0)
		{
			break;
		}
		else
		{
			cout << "wrong" << " ";
		}
		sum = 0;
		max = 0;
	}
}
