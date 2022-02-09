#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int num = 0;
	int arr[10000] = { 0, };

	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + num);
	for (int i = 0; i < num; i++)
	{
		cout << arr[i] << "\n";
	}
}
