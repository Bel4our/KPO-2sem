#include <iostream>

using namespace std;

int defaultparm(int a, int b, int c, int d, int e, int n = 1, int m = 2)
{
	return (a + b + c + d + e + n + m) / 7;
}

int main()
{
	int a = defaultparm(1, 2, 3, 4, 5);
	int b = defaultparm(1,2,3,4,5,6,7);
	return 0;
}