#include "stdafx.h"

using namespace std;

bool leapyear(int year, bool isLeap)
{
	if (year % 4 == 0)
	{
		cout << "Год високосный" << endl;
		return true;
	}
	else
	{
		cout << "Год не високосный" << endl;
		return false;
	}
	
}