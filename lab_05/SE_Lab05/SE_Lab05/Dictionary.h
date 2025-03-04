#include <cstring>
#define DICTINAMEMAXSIZE 20
#define DICTIMAXSIZE 100
#define ENTRYMAXSIZE 30
#define THROW01 "Create: �������� ������ ����� �������"
#define THROW02 "Create: �������� ������ ������������ ������� �������"
#define THROW03 "AddEntry: ������������ �������"
#define THROW04 "AddEntry: ������������ ��������������"
#define THROW05 "GetEntry: �� ������ �������"
#define THROW06 "DelEntry: �� ������ �������"
#define THROW07 "UpdEntry: �� ������ �������"
#define THROW08 "UpdEntry: ������������ ��������������0"


namespace Dictionary
{
	struct Entry
	{
		int id;
		char name[ENTRYMAXSIZE];
	};
	struct Instance
	{
		char name[DICTINAMEMAXSIZE];
		int maxsize;
		int size;
		Entry* dictionary;
	};
	Instance Create(
		const char name[DICTINAMEMAXSIZE],
		int size
	);
	void AddEntry(
		Instance& inst,
		Entry ed
	);

	void DelEntry(
		Instance& inst,
		int id
	);
	void UpdEntry(
		Instance& inst,
		int id,
		Entry new_ed
	);
	Entry GetEntry(
		Instance inst,
		int id
	);
	void Print(Instance d);
	void Delete(Instance& d);
};