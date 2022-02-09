#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int arr[10001] = { 0, };
	int num;
	int a = 0;

	cin >> num;

	for (int i = 0; i < num; i++)
	{
		cin >> a;
		arr[a]++;
	}

	for (int i = 0; i < 10001; i++)
	{
		for (int j = 0; j < arr[i]; j++)
		{
			cout << i << "\n";
		}
	}
}
