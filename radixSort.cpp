#include <iostream>
using namespace std;
#include "radixSort.h"

int Max(int a[], int n)
{
    int maxVal = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > maxVal)
            maxVal = a[i];
    return maxVal;
}

void countingSort(int a[], int n, int d)
{
    const int base = 10;
    int* temp = new int[n];
    int count[base] = {0};

    for (int i = 0; i < n; i++)
    {
        count[(a[i] / d) % 10]++;
    }

    for (int i = 1; i < base; i++)
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

    delete[] temp;
}

void radixSort(int a[], int n)
{
    int maxVal = Max(a, n);

    for (int d = 1; maxVal / d > 0; d *= 10)
    {
        countingSort(a, n, d);
    }
}

int Max(int a[], int n, long long& comparison)
{
    int maxVal = a[0];
    for (int i = 1; ++comparison && i < n; i++)
        if (++comparison && a[i] > maxVal)
            maxVal = a[i];
    return maxVal;
}

void countingSort(int a[], int n, int d, long long& comparison)
{
    const int base = 10;
    int* temp = new int[n];
    int count[base];

    for (int i = 0; ++comparison && i < base; ++i)
    {
        count[i] = 0;
    }

    for (int i = 0; ++comparison && i < n; i++)
    {
        count[(a[i] / d) % 10]++;
    }

    for (int i = 1; ++comparison && i < base; i++)
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

    delete[] temp;
}

void radixSort(int a[], int n, long long& comparison)
{
    comparison = 0;
    int maxVal = Max(a, n, comparison);

    for (int d = 1; ++comparison && maxVal / d > 0; d *= 10)
    {
        countingSort(a, n, d, comparison);
    }
}