#include <iostream>
#include "Sort.h"
#include "Stack.h"
using namespace std;
int main()
{
	Stack<int> stack(2);
	stack.Push(1);
	stack.Push(-1);
	stack.Push(10);
	stack.Push(100);
	stack.Push(-7);
	stack.Push(9);
	while (stack.Empty())
	{
		cout << stack.Pop() << endl;
	}
}