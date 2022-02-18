#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cout << fixed;
	cout.precision(6);

	const double pi = 3.14159265358979;
	float Uc;
	float Taxi;
	int r;

	cin >> r;

	cout << pi * pow(r, 2) << "\n";
	cout << 2 * pow(r, 2) << "\n";
}
