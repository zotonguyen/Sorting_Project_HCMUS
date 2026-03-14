#include <iostream>
#include <chrono>
#include <functional>
using namespace std;
using SortF = function<void(int*, int)>;
double benchmark(SortF func, int arr[],int n ) {
    auto start = chrono::high_resolution_clock::now();
    func(arr,n);
    auto end = chrono::high_resolution_clock::now();
    return chrono::duration<double,std::milli>(end - start).count();
}
