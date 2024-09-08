#include "stdafx.h"

using namespace std;
int monthsnoleap[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

int dateNumber(int day, int month, bool isLeap)
{
	int countday = 0, birthday = 175, value;

	for (int i = 0;i < month - 1;i++)
	{
		countday += monthsnoleap[i];
	}
	countday = countday + day;
	if (countday == 175)
	{
		value = 0;
	}
	else {
		if (countday < 175)
		{
			value = 175 - countday;
		}
		else
		{
			value = 365 - (countday - 175);
		}
		if (isLeap && month >= 2)
		{
			value++;
		}
		if (isLeap && month > 2)
		{
			countday++;
		}
	}

	cout << "Порядковый номер дня: " << countday << endl;
	cout << "До ближайшего дня рождения: " << value;
	return 0;
}
