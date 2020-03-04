#include <iostream>
#include <string>
#include "Sort.h"
#include "Stack.h"
#include "Queue.h"
#include "HashTable.h"
#include "RedBlackTree.h"
using namespace std;
int main()
{
	RedBlackTree<string, int> bst;
	for (int i = 0 ; i < 2000; i++)
	{
		bst.Insert(i, "ok");
	}
	for (int j = 0; j < 1000; j = j + 2)
	{
		bst.Remove(j);
	}
	for (int j = 0; j < 2000; j=j+3)
	{
		bst.Remove(j);
	}
	for (int i = 0; i < 2000; i=i+5)
	{
		bst.Insert(i, "ok");
	}
	bst.InorderTreeWalk();
}