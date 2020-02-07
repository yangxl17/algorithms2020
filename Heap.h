#pragma once
template <class T>
class Heap
{
private:
	static inline int parent(int index)
	{
		return (index + 1) / 2 - 1;
	}
	static inline int left(int index)
	{
		return (index + 1) * 2 - 1;
	}
	static inline int right(int index)
	{
		return (index + 1) * 2;
	}
public:
	static void MaxHeapify(T* array,int index,int size);
	static void BuildMaxHeap(T* array, int size);
	static void HeapSort(T* array, int size);
};

template<class T>
inline void Heap<T>::MaxHeapify(T* array, int index, int size)
{
	if (index < size)
	{
		int largest = index;
		if (left(index) < size && array[left(index)] > array[largest])
		{
			largest = left(index);
		}
		if (right(index)< size && array[right(index)] > array[largest])
		{
			largest = right(index);
		}
		if (largest != index)
		{
			T temp = array[index];
			array[index] = array[largest];
			array[largest] = temp;
			MaxHeapify(array,largest,size);
		}
	}
}

template<class T>
inline void Heap<T>::BuildMaxHeap(T* array, int size)
{
	for (int i = parent(size-1); i >= 0; i--)
	{
		MaxHeapify(array, i, size);
	}
}

template<class T>
inline void Heap<T>::HeapSort(T* array, int size)
{
	BuildMaxHeap(array, size);
	for (int i = size-1; i >= 0; i--)
	{
		T temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		MaxHeapify(array, 0, i);
	}
}

