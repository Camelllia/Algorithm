#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int testCase;

	cin >> testCase;

	int* arr = new int[testCase];

	for (int i = 0; i < testCase; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + testCase);

	cout << arr[0] * arr[testCase - 1];
}