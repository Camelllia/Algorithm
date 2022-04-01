#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n;
vector<int> result;
char arr[12];
bool isused[12];
int sequence[12];
queue<char> oper;
vector<char> v;

void calc()
{
	int temp = 0;
	int idx = 2;
	bool init = true;

	while (!oper.empty())
	{
		char cur = oper.front();

		if (init)
		{
			if (cur == 'a')
			{
				temp = sequence[0] + sequence[1];
			}
			else if (cur == 's')
			{
				temp = sequence[0] - sequence[1];
			}
			else if (cur == 'm')
			{
				temp = sequence[0] * sequence[1];
			}
			else if (cur == 'd')
			{
				temp = sequence[0] / sequence[1];
			}

			init = false;
		}
		else
		{
			if (cur == 'a')
			{
				temp += sequence[idx];
			}
			else if (cur == 's')
			{
				temp -= sequence[idx];
			}
			else if (cur == 'm')
			{
				temp *= sequence[idx];
			}
			else if (cur == 'd')
			{
				temp /= sequence[idx];
			}

			idx++;
		}
		oper.pop();
	}

	result.push_back(temp);
}

void func(int k)
{
	if (k == n - 1)
	{
		for (int i = 0; i < v.size(); i++)
		{
			oper.push(arr[i]);
		}
		calc();
		return;
	}

	for (int i = 0; i < v.size(); i++)
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

void makeVec()
{
	int a = 0; int s = 0; int m = 0; int d = 0;
	cin >> a >> s >> m >> d;

	for (int i = 0; i < a; i++)
	{
		v.push_back('a');
	}
	for (int i = 0; i < s; i++)
	{
		v.push_back('s');
	}
	for (int i = 0; i < m; i++)
	{
		v.push_back('m');
	}
	for (int i = 0; i < d; i++)
	{
		v.push_back('d');
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> sequence[i];
	}

	makeVec();

	func(0);

	sort(result.begin(), result.end());

	cout << result[result.size() - 1] << "\n" << result[0];
}