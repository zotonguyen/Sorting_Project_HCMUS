#include <iostream>

using namespace std;
#include "binaryInsertionSort.h"


int binarySort(int a[], int key, int low, int high)
{
	if (high <= low)
	{
		return (a[low] > key) ? low : low + 1;
	}
	int mid = (low + high) / 2;

	if (a[mid] == key)
	{
		return mid + 1;
	}
	if (a[mid] > key)
	{
		return binarySort(a, key, low, mid - 1);
	}
	return binarySort(a, key, mid + 1, high);
}

void binaryInsertion(int a[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int j = i - 1;
		int key = a[i];
		int loc = binarySort(a, key, 0, j);
		while (j >= loc)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	}
}
