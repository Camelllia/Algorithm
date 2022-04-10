#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
int arr[9];
int res[9];
bool isused[9];

void func(int k)
{
	int tmp = 0;

	if (k == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << res[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (!isused[i] && arr[i] != tmp)
		{
			res[k] = arr[i];
			tmp = res[k];
			isused[i] = true;
			func(k + 1);
			isused[i] = false;
		}
	}
}


int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + n);

	func(0);
}