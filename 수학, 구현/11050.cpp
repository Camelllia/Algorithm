#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int Factorial(int x)
{
	if (x == 0 || x == 1)
	{
		return 1;
	}

	return x * Factorial(x - 1);
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, k;

	cin >> n >> k;

	int result = Factorial(n) / (Factorial(k) * Factorial(n - k));
	cout << result;

}