#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	string s;

	cin >> s;

	sort(s.rbegin(), s.rend());

	cout << s;
}