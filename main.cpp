#include <iostream>
#include <string>
#include "Sort.h"
#include "Stack.h"
#include "Queue.h"
#include "HashTable.h"
#include "BST.h"
using namespace std;
int main()
{
	BST<string, int> bst;
	bst.Insert(5, "I ");
	bst.Insert(2, "love ");
	bst.Insert(0, "you!");
	bst.Insert(1, "I");
	bst.Insert(3, "want");
	bst.Insert(1, "a");
	bst.Insert(4, "girlfriend!");
	bst.InorderTreeWalk();
	bst.Remove(5);
	bst.Remove(2);
	bst.Remove(0);
	bst.InorderTreeWalk();
	cout << bst[4]<<endl;
	bst[4] = "girlfriends!";
	cout << bst[4] << endl;
}