#include "stdafx.h"

using namespace std;

bool leapyear(int year, bool isLeap)
{
	if (year % 4 == 0)
	{
		cout << "��� ����������" << endl;
		return true;
	}
	else
	{
		cout << "��� �� ����������" << endl;
		return false;
	}
	
}