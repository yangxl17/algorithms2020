#include <iostream>
#include "Sort.h"
#include "Stack.h"
#include "Queue.h"
using namespace std;
int main()
{
	Queue<int> queue(3);
	queue.Enqueue(1);
	queue.Enqueue(2);
	queue.Enqueue(3);
	cout << queue.Dequeue()<<endl;
	cout << queue.Dequeue() << endl;
	queue.Enqueue(4);
	queue.Enqueue(5);
	cout << queue.Dequeue() << endl;
	cout << queue.Dequeue() << endl;
	cout << queue.Dequeue() << endl;
}