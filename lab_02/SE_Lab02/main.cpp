#include <iostream>
#include <Windows.h>

using namespace std;

int sum(int x, int y) { return x + y; };
int sub(int x, int y) { return x - y; };

int(*f)(int, int);

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	int n=10;
	int X = 9 + n, Y = 10 + n, Z = 11 + n;
	float S = 1.0 + n;

	bool f1 = false;
	bool f2 = true;

	char surname1 = 'e'; 
	char surname2 = 'å';

	wchar_t e1 = 's';
	wchar_t e2 = 'ñ';

	short a = X;
	short b = -X;

	short c = 0x7FFF;
	short c1 = 0xFF8000;
	
	unsigned short p12 = 0xFFFF;
	unsigned short p12_2 =0x0000;

	int newY = Y;
	int newMinY = -Y;

	int sizeInt = 0x7FFFFFFF;
	int sizeIntMin = 0xFFFFFFFF80000000;

	unsigned int unInt = 0xFFFFFFFF;
	unsigned int unIntMin = 0x0000;

	long p15 = Z;
	long p15_2 = -Z;

	long p16 = 0x7FFFFFFF;
	long p16_2 = 0xFFFFFFFF80000000;

	unsigned long p17 = 0xFFFFFFFF;
	unsigned long p17_2 = 0x0000;

	float p18 = S;
	float p18_2 = -S;

	float f_1 = S / 0;
	float f_2 = -S / 0;
	float f_3 = acos(1.5);

	char p20 = 'f';
	wchar_t p20_2 = 'a';
	short p20_3 = 20;
	int p20_4 = 32301;
	float p20_5 = 587.4546;
	double p20_6 = 23.46347;

	char* p20p = &p20;
	wchar_t* p20_2p = &p20_2;
	short* p20_3p = &p20_3;
	int* p20_4p = &p20_4;
	float* p20_5p = &p20_5;
	double* p20_6p = &p20_6;

	char* p20p1 = p20p+3;
	wchar_t* p20_2p1 = p20_2p+3;
	short* p20_3p1 = p20_3p+3;
	int* p20_4p1 = p20_4p+3;
	float* p20_5p1 = p20_5p+3;
	double* p20_6p1 = p20_6p+3;
	
	f = sum;
	int x = f(2, 3);
	f = sub;
	int y = f(2, 3);

	return 0;
}

