#include "stdafx.h"

using namespace std;
bool isLeap = false;

string mont(int month)
{
	string monthsess[] = {"������","�������","����","������","���","����","����","������","��������","�������","������","�������"};
	return monthsess[month-1];
}

void holiday(int ind, bool isLeap, int year)
{
	int month, day;
	bool f = true;
	int monthses[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int i = 1;
	int nowmon = monthses[0];
	if (isLeap)
	{
		monthses[1] = 29;
	}
	while (f)
	{
		if (ind > nowmon)
		{
			nowmon += monthses[i];
			i++;
			continue;
		}
		day = ind - (nowmon - monthses[i-1]);
		month = i;
		f = false;
	}
	cout << day << "." << month << "." << year << endl;
	if ((day == 13 && month == 9 && !isLeap) || (day == 12 && month == 9 && isLeap))
	{
		cout << "���� ������������!!!!" << endl << endl;
	}

	if (day == 9 && month == 5)
	{
		cout << "���� ������!!!!" << endl << endl;
	}

	if (day == 1 && month == 1)
	{
		cout << "����� ���!!!!" << endl << endl;
	}

}

int secondDayNumber(int day, int month, int year, bool isLeap)
{
	int countday=0;
	int monthsnoleap[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (isLeap && month > 2)
	{
		monthsnoleap[1] = 29;
	}
	for (int i = 0;i < month - 1;i++)
	{
		countday += monthsnoleap[i];
	}
	countday = countday + day;
	countday += (year-1) * 365 + ((year-1) / 4);
	return countday;
}

int calculateHourDiff(int countday1, int coutday2, int hours)
{
	int diff;
	diff = abs((countday1 * 24 + hours) - coutday2*24);
	return diff;
}

int main()
{
	setlocale(LC_ALL, "rus");
	int date, day, month, year, ind, countday1, countday2;
	cout << "������� ���� � ������� ��������: "; cin >> date;

	day = date / 1000000;
	month = (date - (day * 1000000)) / 10000;
	year = date % 10000;
	if (day > 31 || month > 12 || year < 1000 || year>9999 || (!isLeap && month == 2 && day == 29))
	{
		cout << "�� ����� ������������ ��������!";
	}
	else
	{
		cout << "����: " << day << endl;
		cout << "�����: " << month << " - " << mont(month) << endl;
		cout << "���: " << year << endl;

		isLeap = leapyear(year, isLeap);
		cout << endl;

		countday1 = dateNumber(day, month, year, isLeap);

		cout << endl << "������� ���������� �����: "; cin >> ind;
		if ((isLeap && ind > 366) || (!isLeap && ind > 365) || ind < 1)
		{
			cout << "�� ����� ������������ ��������!" << endl;

		}
		else
		{
			holiday(ind, isLeap, year);
			cout << "������� 2 ���� � ������� ��������: "; cin >> date;
			day = date / 1000000;
			month = (date - (day * 1000000)) / 10000;
			year = date % 10000;
			if (day > 31 || month > 12 || year < 1000 || year>9999||(!isLeap && month == 2 && day == 29))
			{
				cout << "�� ����� ������������ ��������!";
			}
			else
			{
				countday2 = secondDayNumber(day, month, year, isLeap);
				int difference = abs(countday1 - countday2);
				cout << "������� ����� ������: " << difference << endl;
				time_t currentTime = time(nullptr);
				tm* localTime = localtime(&currentTime);
				int hours = localTime->tm_hour;
				cout << "������� �����: " << hours << " �����" << endl;
				difference = calculateHourDiff(countday1, countday2, hours);
				cout << "������� � �����: " << difference << endl;
			}
		}
	}
	return 0;
}
