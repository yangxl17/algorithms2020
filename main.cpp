#include <iostream>
#include "Sort.h"
using namespace std;
int main()
{
	int A[] = { 9,3,7,5,2,5,6,1 ,6};
	Sort<int>::RadixSort(A,3,3);
	for (int i = 0; i < 9; i++)
	{
		cout << A[i] << ' ';
	}
}