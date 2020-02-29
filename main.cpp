#include <iostream>
#include "Sort.h"
#include "Stack.h"
#include "Queue.h"
#include "HashTable.h"
using namespace std;
int main()
{
	LinkedListHashTable<int> lh(4, [](const int& k)->int {return MultFunction(k, 2); });
	lh.Insert(5);
	lh.Insert(5);
	lh.Insert(7);
	cout << lh.Search(5) << endl;
	cout << lh.Search(7) << endl;
	lh.Remove(5);
	lh.Remove(7);
	cout << lh.Search(5) << endl;
	cout << lh.Search(7) << endl;
}