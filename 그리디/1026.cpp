#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool compare(int a, int b)
{
	return b < a;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int size;
	int s = 0;
	int gap = 0;
	cin >> size;

	vector<int> a(size);
	vector<int> b(size);

	for (int i = 0; i < size; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < size; i++)
	{
		cin >> b[i];
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), compare);

	for (int i = 0; i < size; i++)
	{
		s += a[i] * b[i];
	}

	cout << s;
}