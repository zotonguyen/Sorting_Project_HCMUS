#include "bubble_sort.h"
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void bubbleSort1(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool swaped = false;
        for (int j = n - 1; j > i; j--)
        {
            if (a[j - 1] > a[j])
            {
                swap(a[j - 1], a[j]);
                swaped = true;
            }
        }
        if (!swaped)
            break;
    }
}
void bubbleSort2(int a[], int n, long long &comparision)
{
    comparision = 0;
    for (int i = 0;++comparision&& i < n - 1; i++)
    {
        bool swaped = false;
        for (int j = n - 1; ++comparision&&j > i; j--)
        {
            if (++comparision && a[j - 1] > a[j])
            {
                swap(a[j - 1], a[j]);
                swaped = true;
            }
        }
        if (!swaped)
            break;
    }
}
