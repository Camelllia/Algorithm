#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int Factorial(int N)
{
	if (N == 1 || N == 0)
	{
		return 1;
	}
	return N * Factorial(N - 1);
}

int main()
{
	int input;

	cin >> input;

	cout << Factorial(input);
}