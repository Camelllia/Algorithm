#include <iostream>
#include <queue>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

int board[22][22];
int result = 100001;
vector<int> startVec;
vector<int> linkVec;
int arr[21];
bool isused[21];
int n;

void func(int idx, int cnt)
{
	int startSum = 0;
	int linkSum = 0;

	if (cnt == n / 2)
	{
		for (int i = 0; i < n; i++)
		{
			if (isused[i])
			{
				startVec.push_back(i);
			}
			else
			{
				linkVec.push_back(i);
			}
		}
		
		for (int i = 0; i < n / 2; i++)
		{
			for (int j = 0; j < n / 2; j++)
			{
				startSum += board[startVec[i]][startVec[j]];		
				linkSum += board[linkVec[i]][linkVec[j]];
			}
		}
		result = min(result, abs(startSum - linkSum));
		startVec.clear();
		linkVec.clear();
		return;
	}

	for (int i = idx; i < n; i++)
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

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}
	}

	func(0, 0);

	cout << result;
}