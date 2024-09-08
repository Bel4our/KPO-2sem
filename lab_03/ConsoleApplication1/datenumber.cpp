#include "stdafx.h"

using namespace std;

int dateNumber(int day, int month, int year, bool isLeap)
{
	int countday = 0, birthday = 175, value;
	int monthsnoleap[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (isLeap)
	{
		monthsnoleap[1] = 29;
	}
	for (int i = 0;i < month - 1;i++)
	{	
		countday += monthsnoleap[i];
	}
	countday = countday + day;
	if (countday == 175)
	{
		value = 0;
		cout << "День рождения!!!" << endl;
	}
	else 
	{
		if (countday < 175)
		{
			value = 175 - countday;
		}
		else
		{
			value = 365 - (countday - 175);
		}
	}
	cout << "Порядковый номер дня: " << countday << endl;

	countday += (year-1) * 365 + ((year-1) / 4);

	cout << "До ближайшего дня рождения: " << value << endl;
	return countday;
}
