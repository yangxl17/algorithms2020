#include <iostream>
#include "Sort.h"
using namespace std;
int main()
{
	int A[] = { 9,3,7,5,2,0,-1,1 };
	Sort<int>::HeapSort(A,8);
	for (int i = 0; i < 8; i++)
	{
		cout << A[i] << ' ';
	}
}