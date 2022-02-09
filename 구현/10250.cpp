#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int testCase;
	int H = 0;
	int W = 0;
	int N = 0;
	int X = 0;
	int Y = 0;

	cin >> testCase;

	for (int i = 0; i < testCase; i++)
	{
		cin >> H >> W >> N;
		Y = N % H;
		X = N / H + 1;

		if (Y == 0)
		{
			Y = H;
			X--;
		}

		cout << Y * 100 + X << "\n";
	}
}