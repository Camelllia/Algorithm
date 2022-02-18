#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

void hanoi(int n, int start, int end, int middle)
{
	if (n == 1)
	{
		cout << start << " " << end << "\n";
		return;
	}
	hanoi(n - 1, start, middle, end);
	cout << start << " " << end << "\n";
	hanoi(n - 1, middle, end, start);
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	cout << (int)pow(2, n) - 1 << "\n";
	hanoi(n, 1, 3, 2);

}