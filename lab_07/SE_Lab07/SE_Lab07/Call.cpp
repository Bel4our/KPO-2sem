#include <iostream>

using namespace std;

namespace Call
{

	int _cdecl cdecll(int a, int b, int c)
	{
		return a + b + c;
	}

	int _stdcall cstd(int& a, int b, int c)
	{
		return a * b * c;
	}

	int _fastcall cfst(int a, int b, int c, int d)
	{
		return a + b + c + d;
	}
}

int main()
{
	setlocale(LC_ALL, "rus");

	int a = 1;
	int b = 2;
	int c = 3;
	int d = 4;

	int value = Call::cdecll(a,b,c);
	int value2 = Call::cstd(a, b, c);
	int value3 = Call::cfst(a, b, c, d);

	return 0;
}