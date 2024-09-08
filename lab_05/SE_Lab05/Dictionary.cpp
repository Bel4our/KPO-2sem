#include <iostream>
#include "Dictionary.h"
#include "stdafx.h"
namespace Dictionary
{
	Instance Create(const char name[DICTNAMEMAXSIZE], int size)
	{
		if (strlen(name) > DICTNAMEMAXSIZE)
		{
			throw THROW01;
		}
		if (size > DICTMAXSIZE)
		{
			throw THROW02;
		}
		Instance* instance = new Instance;
		strcpy_s(instance->name, name);
		instance->maxsize = size;
		instance->size = 0;
		instance->dictionary = new Entry[size];
		return *instance;
	};
	void AddEntry(Instance& inst, Entry ed)
	{
		if (inst.size >= inst.maxsize)
		{
			throw THROW03;
		}
		for (int i = 0; i < inst.size; i++)
		{
			if (inst.dictionary[i].id == ed.id)
			{
				throw THROW04;
			}
		}
		inst.dictionary[inst.size] = ed;
		inst.size++;
	};
	void DelEntry(Instance& inst, int id)
	{
		bool flag = 0;
		for (int i = 0; i < inst.size; i++)
		{
			if (inst.dictionary[i].id == id) 
			{
				flag = true;
				for (int j = i; j < inst.maxsize - 1; j++)
				{
					inst.dictionary[j] = inst.dictionary[j + 1];
				}
				inst.size--;
				return;
			}
		}
		if (!flag)
		{
			throw THROW06;
		}
	};

	void UpdEntry(Instance& inst, int id, Entry new_ed)
	{
		bool flag = 0;
		for (int i = 0;i < inst.size; i++)
		{
			if (inst.dictionary[i].id == new_ed.id && inst.dictionary[i].id != id) 
			{ 
				throw THROW08; 
			}
		}
		for (int i = 0; i < inst.size; i++)
		{
			if (inst.dictionary[i].id == id) 
			{
				flag = true;
				inst.dictionary[i] = new_ed;
				return;
			}
		}
		if (!flag)
		{
			throw THROW07;
		}
	};
	
	Entry GetEntry(Instance inst, int id)
	{
		for (int i = 0; i < inst.size; i++)
		{
			if (id == inst.dictionary[i].id) 
			{
				return inst.dictionary[i];
			}
		}
		throw THROW05;
	};
	void Print(Instance d)
	{
		std::cout << "***********************" << d.name << "***********************" << std::endl;
		for (int i = 0; i < d.size; i++)
		{
			std::cout << d.dictionary[i].id << ' ';
			std::cout << d.dictionary[i].name << std::endl;
		}	
	};
	void Delete(Instance& d)
	{
		delete[] d.dictionary;
	};
}

int main()
{
	setlocale(LC_ALL, "rus");
	try
	{
#if (defined(TEST_CREATE_01) + defined(TEST_CREATE_02) + defined(TEST_ADDENTRY_03) + defined(TEST_ADDENTRY_04) + defined(TEST_GETENTRY_05) + defined(TEST_DELENTRY_06) + defined(TEST_UPDENTRY_07) + defined(TEST_UPDENTRY_08)>1)
#error Превышенное количество макросов
#endif
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