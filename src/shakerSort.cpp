# include <iostream>
using namespace std;
#include "shakerSort.h"

void shakerSort(int a[], int n)
{
	int left = 0;
	int right = n - 1;
	while (left < right)
	{
		for (int i = left; i < right; i++)
		{
			if (a[i] > a[i + 1])
			{
				swap(a[i], a[i + 1]);
			}
		}
		right--;
		for (int i = right; i > left; i--)
		{
			if (a[i] < a[i - 1])
			{
				swap(a[i], a[i - 1]);
			}
		}
		left++;
	}
}

void shakerSort(int a[], int n, long long &comparison)
{
  comparison = 0;
  
	int left = 0;
	int right = n - 1;
	while (++comparison && left < right)
	{
		for (int i = left; ++comparison && i < right; i++)
		{
			if (++comparison && a[i] > a[i + 1])
			{
				swap(a[i], a[i + 1]);
			}
		}
		right--;
		for (int i = right; ++comparison && i > left; i--)
		{
			if (++comparison && a[i] < a[i - 1])
			{
				swap(a[i], a[i - 1]);
			}
		}
		left++;
	}
}
