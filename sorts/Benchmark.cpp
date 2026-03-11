#include <iostream>
#include <chrono>
#include <functional>
using namespace std;
using SortF = function<void(int*, int, long long&)>;
double benchmark(SortF func, int arr[],int n, long long &cmp) {
    auto start = chrono::high_resolution_clock::now();
    func(arr,n,cmp);
    auto end = chrono::high_resolution_clock::now();
    return chrono::duration<double,std::milli>(end - start).count();
}
