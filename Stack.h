#pragma once
template <class T>
class Stack
{
private:
	int capicity;
	int size;
	T* array;
public:
	Stack(int capicity);
	~Stack();
	bool Empty();
	void Push(const T& data);
	T Pop();
};

template<class T>
inline Stack<T>::Stack(int capicity)
{
	this->capicity = capicity;
	size = 0;
	if(capicity<=0)
	{
		capicity = 1;
	}
	array = new T[capicity];
}

template<class T>
inline Stack<T>::~Stack()
{
	delete[] array;
}

template<class T>
inline bool Stack<T>::Empty()
{
	return size;
}

template<class T>
inline void Stack<T>::Push(const T& data)
{
	if (size < capicity)
	{
		size = size + 1;
		array[size - 1] = data;
	}
	else
	{
		T* newarray = new T[2 * capicity + 1];
		for (int i = 0; i <= size - 1; i++)
		{
			newarray[i] = array[i];
		}
		delete[] array;
		capicity = 2 * capicity + 1;
		size = size + 1;
		array = newarray;
		array[size - 1] = data;
	}
}

template<class T>
inline T Stack<T>::Pop()
{
	if (size < capicity / 2)
	{
		T* newarray = new T[capicity/2];
		for (int i = 0; i <= size - 1; i++)
		{
			newarray[i] = array[i];
		}
		delete[] array;
		capicity = capicity / 2;
		array = newarray;
	}
	if (size > 0)
	{
		size = size - 1;
		return array[size];
	}
	else
	{
		return T();
	}
}
