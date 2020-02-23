#include <iostream>
#include "Sort.h"
#include "LinkedList.h"
using namespace std;
int main()
{
	LinkedList<int> list;
	list.insert(1);
	list.insert(0);
	list.insert(10);
	list.insert(-5);
	list.insertsort();
	auto head = list.GetHead();
	while (head != nullptr)
	{
		cout << head->key << endl;
		head = head->next;
	}
}