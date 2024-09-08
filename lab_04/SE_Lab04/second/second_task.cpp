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
	moboperator firstoper = { "+375291234567", "������", "�������", 200, 100};
	moboperator secondoper = { "+375297654321", "������", "�����������+", 200, 200 };
	cout << "������ ������������" << endl;
	cout << "�����: " << firstoper.number << endl;
	cout << "��������: " << firstoper.owner << endl;
	cout << "�������� ����: " << firstoper.tariff << endl;
	cout << "��������: " << firstoper.internet << endl;
	cout << "������ �� ��� ����: " << firstoper.minutes << endl;
	cout << endl;
	cout << "������ ������������" << endl;
	cout << "�����: " << secondoper.number << endl;
	cout << "��������: " << secondoper.owner << endl;
	cout << "�������� ����: " << secondoper.tariff << endl;
	cout << "��������: " << secondoper.internet << endl;
	cout << "������ �� ��� ����: " << secondoper.minutes << endl;
	cout << endl;
	if (firstoper == secondoper)
	{
		cout << "�������� ����� ����������"<<endl;
	}
	else 
	{
		cout << "�������� ����� �����������"<<endl;
	}
	cout << endl;
	if (firstoper > secondoper)
	{
		cout <<"����� ������ � ������� ���������";
	}
	else
	{
		cout << "����� ������ � ������� ���������";
	}
	cout << endl;
	return 0;
}