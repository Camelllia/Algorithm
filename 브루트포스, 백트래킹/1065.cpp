#include <iostream>
using namespace std;

int main()
{
	int num;
	cin >> num;
	int count = 0;

	while (num > 0)
	{
		if (num == 1000)
		{

		}
		else if (num >= 100)
		{
			int a = num / 100;
			int b = (num - (a * 100)) / 10;
			int c = (num - ((a * 100) + (b * 10))) / 1;
			if (a + c == b * 2)
			{
				count++;
			}
		}
		else if (num >= 10)
		{
			count++;
		}
		else
		{
			count++;
		}
		num--;
	}
	cout << count;
}
