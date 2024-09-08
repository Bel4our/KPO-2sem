#include "stdafx.h"

using namespace std;
bool isLeap = false;

string mont(int month)
{
	string monthsess[] = {"Январь","Февраль","Март","Апрель","Май","Июнь","Июль","Август","Сентябрь","Октябрь","Ноябрь","Декабрь"};
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
		cout << "ДЕНЬ ПРОГРАММИСТА!!!!" << endl << endl;
	}

	if (day == 9 && month == 5)
	{
		cout << "ДЕНЬ ПОБЕДЫ!!!!" << endl << endl;
	}

	if (day == 1 && month == 1)
	{
		cout << "НОВЫЙ ГОД!!!!" << endl << endl;
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
	cout << "Введите дату в формате ДДММГГГГ: "; cin >> date;

	day = date / 1000000;
	month = (date - (day * 1000000)) / 10000;
	year = date % 10000;
	if (day > 31 || month > 12 || year < 1000 || year>9999 || (!isLeap && month == 2 && day == 29))
	{
		cout << "Вы ввели неправильное значение!";
	}
	else
	{
		cout << "День: " << day << endl;
		cout << "Месяц: " << month << " - " << mont(month) << endl;
		cout << "Год: " << year << endl;

		isLeap = leapyear(year, isLeap);
		cout << endl;

		countday1 = dateNumber(day, month, year, isLeap);

		cout << endl << "Введите порядковый номер: "; cin >> ind;
		if ((isLeap && ind > 366) || (!isLeap && ind > 365) || ind < 1)
		{
			cout << "Вы ввели неправильное значение!" << endl;

		}
		else
		{
			holiday(ind, isLeap, year);
			cout << "Введите 2 дату в формате ДДММГГГГ: "; cin >> date;
			day = date / 1000000;
			month = (date - (day * 1000000)) / 10000;
			year = date % 10000;
			if (day > 31 || month > 12 || year < 1000 || year>9999||(!isLeap && month == 2 && day == 29))
			{
				cout << "Вы ввели неправильное значение!";
			}
			else
			{
				countday2 = secondDayNumber(day, month, year, isLeap);
				int difference = abs(countday1 - countday2);
				cout << "Разница между датами: " << difference << endl;
				time_t currentTime = time(nullptr);
				tm* localTime = localtime(&currentTime);
				int hours = localTime->tm_hour;
				cout << "Текущее время: " << hours << " часов" << endl;
				difference = calculateHourDiff(countday1, countday2, hours);
				cout << "Разница в часах: " << difference << endl;
			}
		}
	}
	return 0;
}
