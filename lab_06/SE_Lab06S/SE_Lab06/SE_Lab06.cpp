#include <iostream>
#include "stdafx.h"
#include "C:\лабы\Наркевич\КПО\lab_06\SE_Lab06S\SE_Lab06L\Dictionary.h"
#pragma comment(lib,"C:\\лабы\\Наркевич\\КПО\\lab_06\\SE_Lab06S\\Debug\\SE_Lab06L.lib")

int main()
{
	setlocale(LC_ALL, "rus");
	try
	{
		//#if (defined(TEST_CREATE_01) + defined(TEST_CREATE_02) + defined(TEST_ADDENTRY_03) + defined(TEST_ADDENTRY_04) + defined(TEST_GETENTRY_05) + defined(TEST_DELENTRY_06) + defined(TEST_UPDENTRY_07) + defined(TEST_UPDENTRY_08)>1)
		//#error Превышенное количество макросов
		//#endif
#ifdef TEST_DICTIONARY
		Dictionary::Instance d1;

#ifdef TEST_CREATE_01
		d1 = Dictionary::Create("Преподhyhyyhyyhnunyhаватели", 5);
#endif
#ifdef TEST_CREATE_02
		d1 = Dictionary::Create("Преподаватели", 535);
#endif
		d1 = Dictionary::Create("Преподаватели", 5);

		Dictionary::Entry e1 = { 1, "Гладкий" }, e2 = { 2, "Веялкин" },
			e3 = { 3,"Смелов" }, e4 = { 4, "Урбанович" }, e5 = { 5, "Пацей" }, e6 = { 1, "Поломка" }, e7 = { 7, "2поломка" };
		Dictionary::AddEntry(d1, e1);
#ifdef TEST_ADDENTRY_04
		Dictionary::AddEntry(d1, e6);
#endif
		Dictionary::AddEntry(d1, e2);
		Dictionary::AddEntry(d1, e3);
		Dictionary::AddEntry(d1, e4);
		Dictionary::AddEntry(d1, e5);
#ifdef TEST_ADDENTRY_03
		Dictionary::AddEntry(d1, e7);
#endif
		Dictionary::Entry ex2;
#ifdef TEST_GETENTRY_05
		ex2 = Dictionary::GetEntry(d1, 8);
#endif
		ex2 = Dictionary::GetEntry(d1, 4);
#ifdef TEST_DELENTRY_06
		Dictionary::DelEntry(d1, 6);
#endif
		Dictionary::DelEntry(d1, 2);
		Dictionary::Entry newentry1 = { 6, "Гурин" }, newentry2{ 1, "3ошибка" };
#ifdef TEST_UPDENTRY_07
		Dictionary::UpdEntry(d1, 6, newentry1);
#endif
#ifdef TEST_UPDENTRY_08
		Dictionary::UpdEntry(d1, 3, newentry2);
#else
		Dictionary::UpdEntry(d1, 3, newentry1);
#endif
		Dictionary::Print(d1);
		Dictionary::Instance d2 = Dictionary::Create("Студенты", 5);
		Dictionary::Entry s1 = { 1, "Иванов" }, s2 = { 2, "Петров" },
			s3 = { 3, "Сидоров" };
		Dictionary::AddEntry(d2, s1);
		Dictionary::AddEntry(d2, s2);
		Dictionary::AddEntry(d2, s3);
		Dictionary::Entry newentry3 = { 4, "Николаев" };
		Dictionary::UpdEntry(d2, 3, newentry3);
		Dictionary::Print(d2);
		Delete(d1);
		Delete(d2);
#else
		Dictionary::Instance d1;

#ifdef TEST_CREATE_01
		d1 = Dictionary::Create("Преподhyhyyhyyhnunyhаватели", 5);
#endif
#ifdef TEST_CREATE_02
		d1 = Dictionary::Create("Преподаватели", 535);
#endif
		d1 = Dictionary::Create("Преподаватели", 5);

		Dictionary::Entry e1 = { 1, "Гладкий" }, e2 = { 2, "Веялкин" },
			e3 = { 3,"Смелов" }, e4 = { 4, "Урбанович" }, e5 = { 5, "Пацей" }, e6 = { 1, "Поломка" }, e7 = { 7, "2поломка" };
		Dictionary::AddEntry(d1, e1);
#ifdef TEST_ADDENTRY_04
		Dictionary::AddEntry(d1, e6);
#endif
		Dictionary::AddEntry(d1, e2);
		Dictionary::AddEntry(d1, e3);
		Dictionary::AddEntry(d1, e4);
#ifdef TEST_ADDENTRY_03
		Dictionary::AddEntry(d1, e7);
#endif
		Dictionary::Entry ex2;
#ifdef TEST_GETENTRY_05
		ex2 = Dictionary::GetEntry(d1, 8);
#endif
		ex2 = Dictionary::GetEntry(d1, 4);
#ifdef TEST_DELENTRY_06
		Dictionary::DelEntry(d1, 6);
#endif
		Dictionary::DelEntry(d1, 2);
		Dictionary::Entry newentry1 = { 6, "Гурин" }, newentry2{ 1, "3ошибка" };
#ifdef TEST_UPDENTRY_07
		Dictionary::UpdEntry(d1, 6, newentry1);
#endif
#ifdef TEST_UPDENTRY_08
		Dictionary::UpdEntry(d1, 3, newentry2);
#else
		Dictionary::UpdEntry(d1, 3, newentry1);
#endif
		Dictionary::Print(d1);
		Dictionary::Instance d2 = Dictionary::Create("Студенты", 5);
		Dictionary::Entry s1 = { 1, "Иванов" }, s2 = { 2, "Петров" },
			s3 = { 3, "Сидоров" };
		Dictionary::AddEntry(d2, s1);
		Dictionary::AddEntry(d2, s2);
		Dictionary::AddEntry(d2, s3);
		Dictionary::Entry newentry3 = { 4, "Николаев" };
		Dictionary::UpdEntry(d2, 3, newentry3);
		Dictionary::Print(d2);
		Delete(d1);
		Delete(d2);
#endif
	}
	catch (const char* e)
	{
		std::cout << e << std::endl;
	};
	return 0;
}