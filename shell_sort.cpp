# include <iostream>
using namespace std;
#include "shell_sort.h" 

void shell_sort (int a[], int n) {
    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int tmp = a[i];
            int j = i;

            while (j >= gap && a[j - gap] > tmp) {
                a[j] = a[j - gap];
                j -= gap;
            }
            a[j] = tmp;
        }
    }
}

void shell_sort (int a[], int n, long long& comparison) {
    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int tmp = a[i];
            int j = i;

            while (++ comparison && j >= gap && a[j - gap] > tmp) {
                a[j] = a[j - gap];
                j -= gap;
            }
            a[j] = tmp;
        }
    }
}

