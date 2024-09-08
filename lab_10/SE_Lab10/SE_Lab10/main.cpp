#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	auto lyambdaf{ [](string first, string second) {return first + second;} };
	string fline = "Добрый ";
	string sline = "день";
	cout << lyambdaf(fline, sline);
}