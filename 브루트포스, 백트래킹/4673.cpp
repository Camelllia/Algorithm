#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	long long arr[30000] = { 0, };
	int num = 10000;

	while (num >= 1)
	{
		if (num == 10000)
		{
			arr[1] = 0;
		}
		else if (num >= 1000)
		{
			arr[num + (num / 1000) + ((num / 100) % 10) + ((num / 10) % 10) + (num % 10)] = 1;
		}
		else if (num >= 100)
		{
			arr[num + (num / 100) + ((num / 10) % 10) + (num % 10)] = 1;
		}
		else if (num >= 10)
		{
			arr[num + (num / 10) + (num % 10)] = 1;
		}
		else
		{
			arr[num + num] = 1;
		}
		num--;
	}

	for (int i = 1; i < 10000; i++)
	{
		if (arr[i] == 0)
		{
			cout << i << "\n";
		}
	}

}
