#include "DataGenerator.h"
using namespace std;

template <class T>
void Swap(T &a, T &b)
{
	T x = a;
	a = b;
	b = x;
}

//-------------------------------------------------

// Function to generate an array with random data
void GenerateRandomData(int a[], int n)
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < n; i++)
	{
		a[i] = rand()%n;
	}
}

// Function to generate an array with ascending order data
void GenerateSortedData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
}

// Function to generate an array with descending order data
void GenerateReverseData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = n - 1 - i;
	}
}

// Function to generate an array with nearly sorted data
void GenerateNearlySortedData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
	srand((unsigned int) time(NULL));
	for (int i = 0; i < 10; i ++)
	{
		int r1 = rand()%n;
		int r2 = rand()%n;
		Swap(a[r1], a[r2]);
	}
}

void GenerateData(int a[], int n, int dataType)
{
	switch (dataType)
	{
	case 0:	// random
		GenerateRandomData(a, n);
		break;
	case 1:	// sorted
		GenerateSortedData(a, n);
		break;
	case 2:	// reverse sorted
		GenerateReverseData(a, n);
		break;
	case 3:	// nearly sorted
		GenerateNearlySortedData(a, n);
		break;
	default:
		printf("Error: unknown data type!\n");
	}
}
