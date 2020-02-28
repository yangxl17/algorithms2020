#pragma once
template <class T>
class Queue
{
private:
	int capicity;
	int head;
	int tail;
	T* array;
public:
	Queue(int capicity);
	~Queue();
	bool Empty();
	bool Full();
	void Enqueue(const T& data);
	T Dequeue();
};

template<class T>
inline Queue<T>::Queue(int capicity)
{
	if (capicity <= 0)
	{
		capicity = 1;
	}
	array = new T[capicity];
	this->capicity = capicity;
	head = 0;
	tail = -1;
}

template<class T>
inline Queue<T>::~Queue()
{
	delete[] array;
}

template<class T>
inline bool Queue<T>::Empty()
{
	return (tail==-1)||(tail==head);
}

template<class T>
inline bool Queue<T>::Full()
{
	return ((head-tail==1)&&tail!=-1)||(tail-head==capicity-1);
}

template<class T>
inline void Queue<T>::Enqueue(const T& data)
{
	if (!Full())
	{
		if (tail == capicity - 1)
		{
			tail = 0;
		}
		else
		{
			tail = tail + 1;
		}
		array[tail] = data;
	}
}

template<class T>
inline T Queue<T>::Dequeue()
{
	int temphead = head;
	if (!Empty())
	{
		if (head == capicity - 1)
		{
			head = 0;
		}
		else
		{
			head = head + 1;
		}
	}
	return array[temphead];
}
