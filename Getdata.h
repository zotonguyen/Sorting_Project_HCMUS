#pragma once 
#include<cstring>
#include"sorts.h"
int GetAlgorithmIndex(const char*s);
int GetGenerateData(const char*s);
void RunSortComparison(int algorithmIndex, int a[], int n, long long& comp);
void RunSortAlgorithm(int algorithmIndex, int a[], int n);
int GetOutputParamIndex(const char* s);
