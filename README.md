Binary Insertion Sort is not included in the line graph and bar chart because its overall time complexity remains O(n^2), similar to standard Insertion Sort. Although it uses binary search to reduce the number of comparisons, the dominant cost of shifting elements still results in nearly identical running time. Therefore, including it would not provide significant additional insight and could lead to redundant visualization.

# Sorting Project

## Introduction
This project implements and benchmarks multiple sorting algorithms for the Sorting Project assignment.  
The program supports both **algorithm mode** and **comparison mode** through command-line instructions.

## Implemented Algorithms
- Selection Sort
- Insertion Sort
- Shell Sort
- Bubble Sort
- Heap Sort
- Merge Sort
- Quick Sort
- Radix Sort
- Counting Sort
- Binary Insertion Sort
- Shaker Sort
- Flash Sort

## Compile
```bash
g++ src/*.cpp -std=c++14 -o groupid.exe
