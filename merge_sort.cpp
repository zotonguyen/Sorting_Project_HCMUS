# include <iostream>
using namespace std;
#include "merge_sort.h"
void Merge (int left[], int na, int right[], int nb, int a[]) {
    a [na + nb];
    int i = 0, j = 0, k = 0;

    while (i < na && j < nb) {
        if (left[i] <= right[j]) {
            a[k++] = left[i++];
        }
        else {
            a[k++] = right[j++];
        }
    }

    while (i < na) {
        a[k++] = left [i++];
    }

    while (j < nb) {
        a[k++] = right[j++];
    }
}

void merge_sort(int a[], int n ) {
    if (n <= 1) return;
    int mid = n/2;
    int left [mid];
    int right [n - mid];

    for (int i = 0; i < mid; i++) {
        left[i] = a[i];
    }

    for (int i = mid; i < n; i++) {
        right [i - mid] = a[i];
    }

    merge_sort (left, mid);
    merge_sort (right, n - mid); 

    Merge (left, mid, right, n - mid, a);
}

void Merge (int left[], int na, int right[], int nb, int a[], long long& comparison) {
    a [na + nb];
    int i = 0, j = 0, k = 0;

    while (++comparison && i < na && j < nb) {
        if (left[i] <= right[j]) {
            a[k++] = left[i++];
        }
        else {
            a[k++] = right[j++];
        }
    }

    while (i < na) {
        a[k++] = left [i++];
    }

    while (j < nb) {
        a[k++] = right[j++];
    }
}

void merge_sort(int a[], int n, long long& comparison ) {
    comparison = 0;
    if (n <= 1) return;
    int mid = n/2;
    int left [mid];
    int right [n - mid];

    for (int i = 0; i < mid; i++) {
        left[i] = a[i];
    }

    for (int i = mid; i < n; i++) {
        right [i - mid] = a[i];
    }

    merge_sort (left, mid, comparison);
    merge_sort (right, n - mid, comparison); 

    Merge (left, mid, right, n - mid, a, comparison);
}
