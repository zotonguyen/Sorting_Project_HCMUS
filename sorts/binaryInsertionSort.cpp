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

int binarySort(int a[], int key, int low, int high, long long &comparison)
{
    if (++comparison && high <= low)
    {
        return (++comparison && a[low] > key) ? low : low + 1;
    }
    int mid = (low + high) / 2;

    if (++comparison && a[mid] == key)
    {
        return mid + 1;
    }
    if (++comparison && a[mid] > key)
    {
        return binarySort(a, key, low, mid - 1, comparison);
    }
    return binarySort(a, key, mid + 1, high, comparison);
}

void binaryInsertion(int a[], int n, long long &comparison)
{
    comparison = 0;
    for (int i = 1; ++comparison && i < n; i++)
    {
        int j = i - 1;
        int key = a[i];
        int loc = binarySort(a, key, 0, j, comparison);
        while (++comparison && j >= loc)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

