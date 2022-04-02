#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int maxi = -10001;
int arr[9];
vector<int> v;
bool isused[9];
int n;

void calc()
{
	int sum = 0;

	for (int i = 0; i < n - 1; i++)
	{
		sum += abs(arr[i] - arr[i + 1]);
	}

	maxi = max(maxi, sum);
}

void func(int k)
{
	if (k == n)
	{
		calc();
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (!isused[i])
		{
			isused[i] = true;
			arr[k] = v[i];
			func(k + 1);
			isused[i] = false;
		}
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}

	func(0);

	cout << maxi;
}