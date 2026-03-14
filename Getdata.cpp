#include"Getdata.h"
int GetAlgorithmIndex(const char*s){
    if(strcmp(s,"selection-sort") == 0) return 0;
    if(strcmp(s,"insertion-sort") == 0) return 1;
    if(strcmp(s,"shell-sort") == 0) return 2;
    if(strcmp(s,"bubble-sort") == 0) return 3;
    if(strcmp(s,"heap-sort") == 0) return 4;
    if(strcmp(s,"merge-sort") == 0) return 5;
    if(strcmp(s,"quick-sort") == 0) return 6;
    if(strcmp(s,"radix-sort") == 0) return 7;
    if(strcmp(s,"counting-sort") == 0) return 8;
    if(strcmp(s,"binary-insertion-sort") == 0) return 9;
    if(strcmp(s,"shaker-sort") == 0) return 10;
        if(strcmp(s,"flash-sort") == 0) return 11;
    return -1;
}
int GetGenerateData(const char*order){
     if (order == 0) return -1;

    if (strcmp(order, "-sorted") == 0)  return 0;
    if (strcmp(order, "-nsorted") == 0) return 1;
    if (strcmp(order, "-rev") == 0)     return 2;
    if (strcmp(order, "-rand") == 0)    return 3;

    return -1;
}
void RunSortAlgorithm(int algorithmIndex, int a[], int n){
    switch(algorithmIndex){
        case 0: 
        selection_sort(a,n);
        break;
        case 1:
        insertionSort(a,n);
        break;
        case 2:
        shell_sort(a,n);
        break;
        case 3:
        bubbleSort1(a,n);
        break;
        case 4:
        heap_sort(a,n);
        break;
        case 5:
        merge_sort(a,n);
        break;
        case 6:
        quick_sort(a,0,n);
        break;
        case 7:
        radixSort(a,n);
        break;
        case 8:
        //counting
        break;
        case 9:
        binaryInsertion(a,n);
        break;
        case 10:
        shakerSort(a,n);
        break;
        case 11: 
        flashSort(a,n);
        break;
        default: break;
    }
}
void RunSortComparison(int algorithmIndex, int a[], int n,long long& comp){
    switch(algorithmIndex){
        case 0: 
        selection_sort(a,n,comp);
        break;
        case 1:
        insertionSort(a,n,comp);
        break;
        case 2:
        shell_sort(a,n,comp);
        break;
        case 3:
        bubbleSort2(a,n,comp);
        break;
        case 4:
        heap_sort(a,n,comp);
        break;
        case 5:
        merge_sort(a,n,comp);
        break;
        case 6:
        quick_sort(a,0,n,comp);
        break;
        case 7:
        radixSort(a,n,comp);
        break;
        case 8:
        //counting
        break;
        case 9:
        binaryInsertion(a,n,comp);
        break;
        case 10:
        shakerSort(a,n,comp);
        break;
        case 11: 
        flashSort(a,n,comp);
        break;
        default: break;
    }
}
int GetOutputParamIndex(const char* s)
{
    
    if (strcmp(s, "-time") == 0) return 0;
    if (strcmp(s, "-comp") == 0) return 1;
    if (strcmp(s, "-both") == 0) return 2;
    return -1;
}