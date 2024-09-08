#pragma once
#include <stdarg.h>

namespace Varparm
{
	int ivarparm(int n, ...)
	{
		int proizvedenie = 1;
		va_list a;
		va_start(a, n);
		for (int i = 0;i < n;i++)
		{
			proizvedenie *= va_arg(a, int);
		}
		va_end(a);
		return proizvedenie;
	}

	int svarparm(short n, ...)
	{
		int max = 0;
		va_list a;
		va_start(a, n);
		for (int i = 0;i < n;i++)
		{
			int value = va_arg(a, int);
			if (value > max)
			{
				max = value;
			}
		}
		va_end(a);
		return max;
	}

	double fvarparm(float n, ...)
	{
		double sum = 0;
		va_list a;
		va_start(a, n);
		float value = n;
		while(value != FLT_MAX)
		{
			sum += value;
			value = va_arg(a, double);
		}
		va_end(a);
		return sum;
	}

	double dvarparm(double n, ...)
	{
		double sum = 0;
		va_list a;
		va_start(a, n);
		double value = n;
		while (value != DBL_MAX)
		{
			sum += value;
			value = va_arg(a, double);
		}
		va_end(a);
		return sum;
	}

}