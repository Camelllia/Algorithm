#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
int v[9];
int arr[10001];
bool isused[10001];

void func(int k)
{
	if (k == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		if (!isused[v[i]])
		{
			isused[v[i]] = true;
			arr[k] = v[i];
			func(k + 1);
			isused[v[i]] = false;
		}
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
	}

	sort(v, v + n + 1);

	func(0);
}