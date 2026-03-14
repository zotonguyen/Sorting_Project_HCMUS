#include "heap_sort.h"

void heapify(int a[], int n, int i)
{
    int L = 2 * i + 1;
    int R = 2 * i + 2;
    int largest = i;
    if (L < n && a[largest] < a[L])
        largest = L;
    if (R < n && a[largest] < a[R])
        largest = R;

    if (i != largest)
    {
        swap(a[i], a[largest]);

        heapify(a, n, largest);
    }
}
void heap_sort(int a[], int n)
{
    // Building max-heap
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(a, n, i);
    }
    // Sort
    for (int i = n - 1; i >= 0; i--)
    {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}
void heapify(int a[], int n, int i, long long &comparison)
{
    int L = 2 * i + 1;
    int R = 2 * i + 2;
    int largest = i;
    if (++comparison && L < n && ++comparison && a[largest] < a[L])
        largest = L;
    if (++comparison && R < n && ++comparison && a[largest] < a[R])
        largest = R;

    if (++comparison && i != largest)
    {
        swap(a[i], a[largest]);

        heapify(a, n, largest, comparison);
    }
}
void heap_sort(int a[], int n, long long &comparison)
{
    comparison = 0;
    // Building max-heap
    for (int i = n / 2 - 1; ++comparison && i >= 0; i--)
    {
        heapify(a, n, i, comparison);
    }
    // Sort
    for (int i = n - 1; ++comparison && i > 0; i--)
    {
        swap(a[0], a[i]);
        heapify(a, i, 0, comparison);
    }
}