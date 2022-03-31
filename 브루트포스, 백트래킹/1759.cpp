#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int L, C;
char arr[16];
vector<char> password;
bool isused[16];

bool canPassword()
{
	int vowel = 0;
	int consonant = 0;

	for (int i = 0; i < password.size(); i++)
	{
		if (password[i] == 'a' || password[i] == 'e' || password[i] == 'i' || password[i] == 'o' || password[i] == 'u')
		{
			vowel++;
		}
		else
		{
			consonant++;
		}
	}

	if (vowel >= 1 && consonant >= 2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void func(int idx, int cnt)
{
	if (cnt == L)
	{
		for (int i = 0; i < C; i++)
		{
			if (isused[i])
			{
				password.push_back(arr[i]);
			}
		}
		if (canPassword())
		{
			for (int j = 0; j < password.size(); j++)
			{
				cout << password[j];
			}
			cout << "\n";
			password.clear();
			return;
		}
		else
		{
			password.clear();
			return;
		}
	}

	for (int i = idx; i < C; i++)
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

	cin >> L >> C;

	for (int i = 0; i < C; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + C);

	func(0, 0);
}