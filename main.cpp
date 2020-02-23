#include <iostream>
#include "Sort.h"
using namespace std;
int main()
{
	float A[] = { 0.5,0.61,0.9,0.3,0.4,0.5,0.11 };
	Sort<float>::BucketSort(A, 7);
	for (int i = 0; i <= 6; i++)
	{
		cout << A[i] << endl;
	}
}