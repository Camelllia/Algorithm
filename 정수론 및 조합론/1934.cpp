#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int testCase;
	int A = 0;
	int B = 0;
	int C = 0;
	int D = 0;
	int mul = 0;
	int temp = 0;
	int result = 0;

	cin >> testCase;

	for (int i = 0; i < testCase; i++)
	{
		cin >> A >> B;
		mul = A * B;

		if (A > B)
		{
			C = A;
			D = B;
			while (D > 0)
			{
				temp = C % D;
				C = D;
				D = temp;
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
		}
		result = mul / C;
		cout << result << "\n";
	}
}