#include <iostream>
#include <string>

using namespace std;

typedef unsigned char numb[50];
typedef unsigned char own[50];
typedef unsigned char tar[50];
typedef unsigned int network;
typedef unsigned int minut;

struct moboperator 
{
	numb number;
	own owner;
	tar tariff;
	network internet;
	minut minutes;
};

bool operator==(const moboperator& fval, const moboperator& sval)
{
	return fval.tariff == sval.tariff;
}
bool operator>(const moboperator& fval, const moboperator& sval)
{
	return fval.minutes>sval.minutes;
}

int main()
{
	setlocale(LC_ALL, "rus");
	moboperator firstoper = { "+375291234567", "Иванов", "Абсолют", 200, 100};
	moboperator secondoper = { "+375297654321", "Семёнов", "Безлимитище+", 200, 200 };
	cout << "Первый пользователь" << endl;
	cout << "Номер: " << firstoper.number << endl;
	cout << "Владелец: " << firstoper.owner << endl;
	cout << "Тарифный план: " << firstoper.tariff << endl;
	cout << "Интернет: " << firstoper.internet << endl;
	cout << "Минуты во все сети: " << firstoper.minutes << endl;
	cout << endl;
	cout << "Второй пользователь" << endl;
	cout << "Номер: " << secondoper.number << endl;
	cout << "Владелец: " << secondoper.owner << endl;
	cout << "Тарифный план: " << secondoper.tariff << endl;
	cout << "Интернет: " << secondoper.internet << endl;
	cout << "Минуты во все сети: " << secondoper.minutes << endl;
	cout << endl;
	if (firstoper == secondoper)
	{
		cout << "Тарифные планы одинаковые"<<endl;
	}
	else 
	{
		cout << "Тарфиные планы различаются"<<endl;
	}
	cout << endl;
	if (firstoper > secondoper)
	{
		cout <<"Минут больше у первого оператора";
	}
	else
	{
		cout << "Минут больше у второго оператора";
	}
	cout << endl;
	return 0;
}