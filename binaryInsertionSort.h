#ifndef binaryInsertionSort_h
#define binaryInsertionSort_h

int binarySort(int a[], int key, int low, int high);
void binaryInsertion(int a[], int n);

int binarySort(int a[], int key, int low, int high, long long &comparison);
void binaryInsertion(int a[], int n, long long &comparison);



#endif
