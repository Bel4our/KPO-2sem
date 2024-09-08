#include <iostream>

using namespace std;

typedef unsigned char day;
typedef unsigned char month;
typedef unsigned char year;

struct Date 
{
	day dd;
	month mm;
	year yyyy;
};

bool operator<(const Date& fval, const Date& lval)
{
	return (fval.yyyy < lval.yyyy) || (fval.yyyy == lval.yyyy && fval.mm < lval.mm) || (fval.yyyy == lval.yyyy && fval.mm == lval.mm && fval.dd < lval.dd);
}

bool operator>(const Date& fval, const Date& lval)
{
	return (fval.yyyy > lval.yyyy)||(fval.yyyy == lval.yyyy && fval.mm>lval.mm)||(fval.yyyy == lval.yyyy && fval.mm == lval.mm && fval.dd > lval.dd);
}

bool operator==(const Date& fval, const Date& lval)
{
	return fval.dd == lval.dd && fval.mm == lval.mm && fval.yyyy == lval.yyyy;
}

int main()
{
	setlocale(LC_ALL, "rus");


	Date date1 = { 7,1,1980 };
	Date date2 = { 7,2,1993 };
	Date date3 = { 7,1,1980 };

	if (date1 < date2) cout << "истина" << endl;
	else cout << "ложь" << endl;

	if (date1 > date2) cout << "истина" << endl;
	else cout << "ложь" << endl;

	if (date1 == date2) cout << "истина" << endl;
	else cout << "ложь" << endl;

	if (date1 == date3) cout << "истина" << endl;
	else cout << "ложь" << endl;

	return 0;
}