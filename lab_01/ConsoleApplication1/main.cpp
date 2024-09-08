#include "stdafx.h"

using namespace std;

bool isLeap = false;
int main()
{
	setlocale(LC_ALL, "rus");
	int date, day, month, year;
	cout << "Введите дату в формате ДДММГГГГ: "; cin >> date;
	day = date / 1000000;
	month = (date - (day * 1000000)) / 10000;
	year = date % 10000;
	if (day > 31 || month > 12 || year < 1000 || year>9999)
	{
		cout << "Вы ввели неправильное значение!";
	}
	else {
		cout << "День: " << day << endl;
		cout << "Месяц: " << month << endl;
		cout << "Год: " << year << endl;
		isLeap = leapyear(year, isLeap);

		dateNumber(day, month, isLeap);
	}
	return 0;
}
