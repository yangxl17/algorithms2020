#include <iostream>
#include "Sort.h"
using namespace std;
int main()
{
	int A[] = { 9,3,7,5,2,0,10,1 };
	int B[8];
	Sort<int>::CountingSort(A,B,8,10);
	for (int i = 0; i < 8; i++)
	{
		cout << B[i] << ' ';
	}
}