#include <iostream>
#include <stdarg.h>
#include "Varparm.h"

int main()
{
	int a = Varparm::ivarparm(1, 2);
	int b = Varparm::ivarparm(2, 1, 2);
	int c = Varparm::ivarparm(3, 1,2,3);
	int d = Varparm::ivarparm(7, 1,2,3,4,5,6,7);

	int a1 = Varparm::svarparm(1, 2);
	int b1 = Varparm::svarparm(2, 1, 2);
	int c1 = Varparm::svarparm(3, 1, 2, 3);
	int d1 = Varparm::svarparm(7, 1, 2, 3, 4, 5, 6, 7);

	double a2 = Varparm::fvarparm(FLT_MAX);
	double b2 = Varparm::fvarparm(2.3, FLT_MAX);
	double c2 = Varparm::fvarparm(3.3, 1.3, FLT_MAX);
	double d2 = Varparm::fvarparm(7.3, 1.7, 2.4, 3.6, 4.3, 5.4, FLT_MAX);

	double a3 = Varparm::dvarparm(DBL_MAX);
	double b3 = Varparm::dvarparm(2.3, DBL_MAX);
	double c3 = Varparm::dvarparm(3.3, 1.3, DBL_MAX);
	double d3 = Varparm::dvarparm(7.3, 1.7, 2.4, 3.6, 4.3, 5.4, DBL_MAX);

	return 0;
}