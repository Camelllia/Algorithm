#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int Fibonarchi(int N)
{
	if (N == 0)
	{
		return 0;
	}
	else if (N == 1)
	{
		return 1;
	}
	else
	{
		return Fibonarchi(N - 1) + Fibonarchi(N - 2);
	}
}

int main()
{
	int input;

	cin >> input;

	cout << Fibonarchi(input);
}