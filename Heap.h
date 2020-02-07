#pragma once
template <class T>
class Heap
{
private:
	int size;
	int capacity;
	T* array;
public:
	Heap(int length)
	{
		size = 0;
		capacity = length;
		array = new T[size];
	};
	void MaxHeapify(int index);
};

template<class T>
inline void Heap<T>::MaxHeapify(int index)
{
	if (index < size)
	{

	}
}
