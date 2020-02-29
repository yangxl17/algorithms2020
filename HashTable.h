#pragma once
#include "LinkedList.h"
unsigned int MultFunction(unsigned int k, unsigned int p);
template <class T>
class LinkedListHashTable
{
private:
	LinkedList<T>* array;
	int length;
	int (*hashfunc)(const T&);
public:
	LinkedListHashTable(int length, int (*hashfunc)(const T&));
	~LinkedListHashTable();
	void Insert(const T& data);
	T Search(const T& data);
	void Remove(const T& data);
};

template<class T>
inline LinkedListHashTable<T>::LinkedListHashTable(int length, int(*hashfunc)(const T&))
{
	this->length = length;
	array = new LinkedList<T>[length]();
	this->hashfunc = hashfunc;
}

template<class T>
inline LinkedListHashTable<T>::~LinkedListHashTable()
{
	delete[] array;
}

template<class T>
inline void LinkedListHashTable<T>::Insert(const T& data)
{
	array[hashfunc(data)].insert(data);
}

template<class T>
inline T LinkedListHashTable<T>::Search(const T& data)
{
	int index = hashfunc(data);
	auto ptr = array[index].GetHead();
	while (ptr != nullptr)
	{
		if (data == ptr->key)
		{
			return ptr->key;
		}
		ptr = ptr->next;
	}
	return T();
}

template<class T>
inline void LinkedListHashTable<T>::Remove(const T& data)
{
	int index = hashfunc(data);
	auto ptr = array[index].GetHead();
	while (ptr != nullptr)
	{
		if (data == ptr->key)
		{
			array[index].remove(ptr);
			break;
		}
		ptr = ptr->next;
	}
}

