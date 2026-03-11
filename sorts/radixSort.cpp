#include <iostream>
using namespace std;
#include "radixSort.h"


int Max(int a[], int n)
{
	int max = a[0];
	for (int i = 1; i < n; i++)
		if (a[i] > max)
			max = a[i];
	return max;
}

void countingSort(int a[], int n, int d)
{
	const int max = 10;
	int temp[n];
	int count[max];

	for (int i = 0; i < max; ++i) 
	{
		count[i] = 0;
	}

	for (int i = 0; i < n; i++)
	{
		count[(a[i] / d) % 10]++;
	}

	for (int i = 1; i < max; i++)
	{
		count[i] += count[i - 1];
	}

	for (int i = n - 1; i >= 0; i--)
	{
		temp[count[(a[i] / d) % 10] - 1] = a[i];
		count[(a[i] / d) % 10]--;
	}

	for (int i = 0; i < n; i++)
	{
		a[i] = temp[i];
	}
}

void radixsort(int a[], int n)
{
	int max = Max(a, n);

	for (int d = 1; max / d > 0; d *= 10)
	{
		countingSort(a, n, d);
	}
}


int Max(int a[], int n, long long &comparison)
{
	int max = a[0]; 
	for (int i = 1; ++comparison && i < n; i++)
		if (++comparison && a[i] > max)
			max = a[i];
	return max;
}

void countingSort(int a[], int n, int d, long long & comparison)
{
	const int max = 10;
	int temp[n];
	int count[max];

	for (int i = 0; ++comparison && i < max; ++i) 
	{
		count[i] = 0;
	}

	for (int i = 0; ++comparison && i < n; i++)
	{
		count[(a[i] / d) % 10]++;
	}

	for (int i = 1; ++comparison && i < max; i++)
	{
		count[i] += count[i - 1];
	}

	for (int i = n - 1; ++comparison && i >= 0; i--)
	{
		temp[count[(a[i] / d) % 10] - 1] = a[i];
		count[(a[i] / d) % 10]--;
	}

	for (int i = 0; ++comparison && i < n; i++)
	{
		a[i] = temp[i];
	}
}

void radixsort(int a[], int n, long long & comparison)
  comparison = 0;
	int max = Max(a, n);

	for (int d = 1; ++comparison && max / d > 0; d *= 10)
	{
		countingSort(a, n, d);
	}
}
