#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int sugar;
	cin >> sugar;
	int b5, r;

	b5 = sugar / 5;
	r = sugar % 5;

	if (r == 0)
	{
		cout << sugar / 5;
	}
	else if (r == 1 && b5 >= 1)
	{
		cout << b5 + 1;
	}
	else if (r == 2 && b5 >= 2)
	{
		cout << b5 + 2;
	}
	else if (r == 3)
	{
		cout << b5 + 1;
	}
	else if (r == 4 && b5 >= 1)
	{
		cout << b5 + 2;
	}
	else
	{
		cout << -1;
	}
}