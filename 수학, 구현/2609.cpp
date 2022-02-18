#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int A, B;
	int temp = 0;
	int mul = 0;
	int C = 0;
	int D = 0;

	cin >> A >> B;
	mul = A * B;

	if (A > B)
	{
		while (B > 0)
		{
			temp = A % B;
			A = B;
			B = temp;
		}
	}
	else
	{
		C = B;
		D = A;

		while (D > 0)
		{
			temp = C % D;
			C = D;
			D = temp;
		}

		A = C;
	}

	cout << A << "\n";
	cout << mul / A;
}