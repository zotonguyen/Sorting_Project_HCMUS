# include <iostream>
using namespace std;
#include "flashSort.h"
#include "insertionSort.h"
void flashSort(int a[], int n)
{
	int maxIndex = 0;
	int min = a[0];

	for (int i = 1; i < n; i++)
	{
		if (a[i] > a[maxIndex])
			maxIndex = i;

		if (a[i] < min)
			min = a[i];
	}

	int max = a[maxIndex];

	if (max == min)
		return;

	swap(a[0], a[maxIndex]);

	int nBucket = (int)(0.45 * n);
	if (nBucket < 2)
		nBucket = 2;

	int *L = new int[nBucket]();

	for (int i = 0; i < n; i++)
	{
		int k = (nBucket - 1) * ((double)(a[i] - min) / (max - min));
		L[k]++;
	}

	for (int i = 1; i < nBucket; i++)
	{
		L[i] += L[i - 1];
	}
	int move = 0;
	int j = 0;
	int k = nBucket - 1;

	while (move < n - 1)
	{
		while (j >= L[k])
		{
			j++;
			k = (nBucket - 1) * ((double)(a[j] - min) / (max - min));
		}

		int flash = a[j];

		while (j < L[k])
		{
			k = (nBucket - 1) * ((double)(flash - min) / (max - min));

			int pos = --L[k];

			swap(a[pos], flash);

			move++;
		}
	}

	delete[] L;

	insertionSort(a, n);
}
//compare

void flashSort(int a[], int n, long long &comparison)
{
  comparison = 0;
  
	int maxIndex = 0;
	int min = a[0];

	for (int i = 1; ++comparison && i < n; i++)
	{
		if (++comparison && a[i] > a[maxIndex])
			maxIndex = i;

		if (++comparison && a[i] < min)
			min = a[i];
	}

	int max = a[maxIndex];

	if (max == min)
		return;

	swap(a[0], a[maxIndex]);

	int nBucket = (int)(0.45 * n);
	if (++comparison && nBucket < 2)
		nBucket = 2;

	int *L = new int[nBucket]();

	for (int i = 0; ++comparison && i < n; i++)
	{
		int k = (nBucket - 1) * ((double)(a[i] - min) / (max - min));
		L[k]++;
	}

	for (int i = 1; ++comparison && i < nBucket; i++)
	{
		L[i] += L[i - 1];
	}
	int move = 0;
	int j = 0;
	int k = nBucket - 1;

	while (++comparison && move < n - 1)
	{
		while (++comparison && j >= L[k])
		{
			j++;
			k = (nBucket - 1) * ((double)(a[j] - min) / (max - min));
		}

		int flash = a[j];

		while (++comparison && j < L[k])
		{
			k = (nBucket - 1) * ((double)(flash - min) / (max - min));

			int pos = --L[k];

			swap(a[pos], flash);

			move++;
		}
	}

	delete[] L;

	insertionSort(a,n,comparison);
}
