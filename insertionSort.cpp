# include <iostream>
using namespace std;
#include "insertionSort.h"

void insertionSort(int a[], int n)
{

	for (int i = 0; i < n; i++)
	{
		int key = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > key)
		{

			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = key;
	}
}
void insertionSort(int a[] , int n , long long &comparison)
{
	comparison = 0;
	for (int i = 0; ++comparison && i < n; i++)
	{
		int key = a[i];
		int j = i - 1;
		while (++comparison && j >= 0 && ++comparison && a[j] > key)
		{

			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = key;
	}
}
