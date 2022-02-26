#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[9];
int selected[9];

void print()
{
	for (int i = 0; i < n; i++)
	{
		if (selected[i])
		{
			cout << arr[i] << " ";
		}
	}
	cout << "\n";
}

void DFS(int idx, int cnt)
{
	if (cnt == m)
	{
		print();
		return;
	}

	for (int i = idx; i < n; i++)
	{
		if (selected[i])
		{
			continue;
		}

		selected[i] = true;
		DFS(i + 1, cnt + 1);
		selected[i] = false;
	}

}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		arr[i] = i + 1;
	}

	DFS(0, 0);
}