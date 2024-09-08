#include <iostream>
#include "Dictionary.h"
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