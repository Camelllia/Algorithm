#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	int A, B, V;
	int day = 0;

	cin >> A >> B >> V;

	day = (V - B) / (A - B);
	if (((V - B) % (A - B)) > 0)
	{
		day += 1;
	}

	cout << day;
}
