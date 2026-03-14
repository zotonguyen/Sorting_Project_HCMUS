#pragma once
#include<iostream>
#include<algorithm>
using namespace std;

void heapify(int a[],int n,int i);
void heap_sort(int a[],int n);
void heapify(int a[],int n,int i , long long &comparison);
void heap_sort(int a[],int n,long long &comparison);