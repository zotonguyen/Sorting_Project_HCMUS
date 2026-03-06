#include "selection_sort.h"


void selection_sort(int a[], int n,long long &comparison){
    comparison = 0;
    for(int i = 0 ;++comparison&&i<n-1;i++){
        int minIndex = i;
        for(int j = i+1;++comparison&&j<n;j++){
            if(++comparison&&a[minIndex] > a[j]) minIndex = j;
        }
        if(++comparison&& minIndex != i)
        swap( a[minIndex],a[i]);
    }
}
void selection_sort(int a[], int n){
    
    for(int i = 0 ;i<n-1;i++){
        int minIndex = i;
        for(int j = i+1;j<n;j++){
            if(a[minIndex] > a[j]) minIndex = j;
        }
        swap(a[minIndex],a[i]);
    }
}

