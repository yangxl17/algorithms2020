#pragma once
#include "Heap.h"
template <class T>
class Sort
{
public:
	static void InsertSort(T* A,int Length);
	static void MergeSort(T* A, int p, int r);
	static void HeapSort(T* A, int size)
	{
		Heap<T>::HeapSort(A,size);
	}
	static void QuickSort(T* A, int p, int r);
private:
	static void Merge(T* A, int p, int q, int r);
	static int Partition(T* A, int p, int r);
};
template <class T>
void Sort<T>::InsertSort(T* A, int Length)
{
	for (int i = 0; i <= Length - 1; i++)
		for (int j = i - 1; j >= 0; j--)
		{
			if (A[j] > A[j + 1])
			{
				T temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp;
			}
			else
				break;
		}
}
template<class T>
inline void Sort<T>::QuickSort(T* A, int p, int r)
{
	if (r > p)
	{
		int q = Partition(A, p, r);
		QuickSort(A, p, q - 1);
		QuickSort(A, q + 1, r);
	}
}
template <class T>
void Sort<T>::Merge(T* A, int p, int q, int r)
{
	int length1 = q - p + 1;
	int length2 = r - q;
	T* B1 = new T[length1];
	T* B2 = new T[length2];
	for (int i = p; i <= q; i++)
	{
		B1[i - p] = A[i];
	}
	for (int j = q + 1; j <= r; j++)
	{
		B2[j - q - 1] = A[j];
	}
	int j = 0;
	int k = 0;
	for (int i = p; i <= r; i++)
	{
		if (j < length1 && k < length2)
		{
			if (B1[j] < B2[k])
			{
				A[i] = B1[j];
				j = j + 1;
			}
			else
			{
				A[i] = B2[k];
				k = k + 1;
			}
		}
		else if (j == length1)
		{
			A[i] = B2[k];
			k = k + 1;
		}
		else
		{
			A[i] = B1[j];
			j = j + 1;
		}
	}
}
template<class T>
inline int Sort<T>::Partition(T* A, int p, int r)
{
	int i = p - 1;
	int tag = A[r];
	for (int j = p; j < r; j++)
	{
		if (A[j] < tag)
		{
			T temp = A[j];
			A[j] = A[i + 1];
			A[i + 1] = temp;
			i = i + 1;
		}
	}
	A[r] = A[i + 1];
	A[i + 1] = tag;
	return i + 1;
}
template <class T>
void Sort<T>::MergeSort(T* A, int p, int r)
{
	int q = (r - p) / 2 + p;
	if (r>p)
	{
		MergeSort(A, p, q);
		MergeSort(A, q + 1, r);
		Merge(A, p, q, r);
	}
}
