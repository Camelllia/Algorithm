#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

vector<int> lotto;
bool isused[14];

void reset()
{
	memset(isused, false, sizeof(isused));
	lotto.clear();
}

void func(int idx, int cnt)
{
	if (cnt == 6)
	{
		for (int i = 0; i < lotto.size(); i++)
		{
			if (isused[i])
			{
				cout << lotto[i] << " ";
			}
		}
		cout << "\n";
		return;
	}

	for (int i = idx; i < lotto.size(); i++)
	{
		if (!isused[i])
		{
			isused[i] = true;
			func(i + 1, cnt + 1);
			isused[i] = false;
		}
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	while (true)
	{
		int size;
		cin >> size;

		if (size == 0)
		{
			return 0;
		}

		for (int i = 0; i < size; i++)
		{
			int a;
			cin >> a;
			lotto.push_back(a);
		}

		func(0, 0);
		cout << "\n";

		reset();
	}
}