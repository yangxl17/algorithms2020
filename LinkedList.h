#pragma once
template<class T>
struct Node
{
	Node<T>* prev;
	T key;
	Node<T>* next;
};
template<class T>
class LinkedList
{
private:
	Node<T>* head;
public:
	LinkedList();
	~LinkedList();
	void insert(T data);
	void remove(Node<T>* node);
	void insertsort();
	Node<T>* GetHead();
};

template<class T>
inline LinkedList<T>::LinkedList():head(nullptr)
{
}

template<class T>
inline LinkedList<T>::~LinkedList()
{
	Node<T>* pointer = head;
	while (pointer != nullptr)
	{

		auto npointer = pointer;
		pointer = pointer->next;
		delete npointer;
	}
}

template<class T>
inline void LinkedList<T>::insert(T data)
{
	Node<T>* newnode = new Node<T>();
	newnode->key = data;
	newnode->prev = nullptr;
	newnode->next = head;
	if (head != nullptr)
	{
		head->prev = newnode;
	}
	head = newnode;
}

template<class T>
inline void LinkedList<T>::remove(Node<T>* node)
{
	if (node == head)
	{
		head = node->next;
	}
	else
	{
		node->prev->next = node->next;
	}
	delete node;
}

template<class T>
inline void LinkedList<T>::insertsort()
{
	Node<T>* pointer = nullptr;
	if (head != nullptr)
	{
		pointer = head->next;
	}
	while (pointer != nullptr)
	{
		T ndata = pointer->key;
		Node<T>* npointer = pointer->prev;
		while (npointer != nullptr)
		{
			if (npointer->key > ndata)
			{
				npointer->next->key = npointer->key;
				npointer = npointer->prev;
			}
			else
			{
				npointer->next->key = ndata;
				break;
			}
		}
		if (npointer == nullptr)
		{
			head->key = ndata;
		}
		pointer = pointer->next;
	}
}

template<class T>
inline Node<T>* LinkedList<T>::GetHead()
{
	return head;
}
