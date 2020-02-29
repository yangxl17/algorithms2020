#pragma once
#include<iostream>
template <class P, class T=int>
struct BSTnode
{
	BSTnode* parent = nullptr;
	BSTnode* leftchild = nullptr;
	BSTnode* rightchild = nullptr;
	T key;
	P data;
};
template <class P, class T=int>
class BST
{
private:
	BSTnode<P,T>* root;
	BSTnode<P,T>* Minimum(BSTnode<P,T>* x);
	BSTnode<P,T>* Maxmum(BSTnode<P,T>* x);
	BSTnode<P,T>* Successor(BSTnode<P,T>* x);
	void DeleteTree(BSTnode<P, T>* x);
	void TransPlant(BSTnode<P, T>* u, BSTnode<P, T>* v);
public:
	BST();
	~BST();
	void InorderTreeWalk();
	void InorderTreeWalk(BSTnode<P,T>* x);
	void Insert(const T& key, const P& data);
	BSTnode<P,T>* Search(const T& k);
	void Remove(const T& k);
	P& operator[](const T& k);
};

template<class P, class T>
inline BSTnode<P, T>* BST<P, T>::Minimum(BSTnode<P, T>* x)
{
	if (x == nullptr)
	{
		return nullptr;
	}
	else
	{
		while (x->leftchild != nullptr)
		{
			x = x->leftchild;
		}
		return x;
	}
}

template<class P, class T>
inline BSTnode<P, T>* BST<P, T>::Maxmum(BSTnode<P, T>* x)
{
	if (x == nullptr)
	{
		return nullptr;
	}
	else
	{
		while (x->rightchild != nullptr)
		{
			x = x->rightchild;
		}
		return x;
	}
}

template<class P, class T>
inline BSTnode<P, T>* BST<P, T>::Successor(BSTnode<P, T>* x)
{
	const auto y = x;
	if (x != nullptr)
	{
		if (x->rightchild != nullptr)
		{
			return Minimum(x->rightchild);
		}
		else
		{
			while (x->parent!=nullptr&&x->parent->rightchild==x)
			{
				x = x->parent;
			}
			return x->parent;
		}
	}
	return nullptr;
}

template<class P, class T>
inline void BST<P, T>::DeleteTree(BSTnode<P, T>* x)
{
	if (x == nullptr)
	{
		DeleteTree(x->leftchild);
		DeleteTree(x->rightchild);
		delete x;
	}
}

template<class P, class T>
inline void BST<P, T>::TransPlant(BSTnode<P, T>* u, BSTnode<P, T>* v)
{
	if (u == root)
	{
		root = v;
	}
	else
	{
		if (u->parent->leftchild == u)
		{
			u->parent->leftchild = v;
		}
		else
		{
			u->parent->rightchild = v;
		}
	}
	if (v != nullptr)
	{
		v->parent = u->parent;
	}
}

template<class P, class T>
inline BST<P, T>::BST()
{
	root = nullptr;
}

template<class P, class T>
inline BST<P, T>::~BST()
{
	DeleteTree(root);
}

template<class P, class T>
inline void BST<P, T>::InorderTreeWalk()
{
	InorderTreeWalk(root);
}

template<class P, class T>
inline void BST<P, T>::InorderTreeWalk(BSTnode<P, T>* x)
{
	if (x != nullptr)
	{
		InorderTreeWalk(x->leftchild);
		std::cout << x->key << ":" << x->data << std::endl;
		InorderTreeWalk(x->rightchild);
	}
}

template<class P, class T>
inline void BST<P, T>::Insert(const T& key, const P& data)
{
	BSTnode<P, T>* x = root;
	BSTnode<P, T>* node = new BSTnode<P, T>;
	node->key = key;
	node->data = data;
	if (x == nullptr)
	{
		root = node;
	}
	else
	{
		while (x != nullptr)
		{
			if (x->key > key)
			{
				if (x->leftchild != nullptr)
				{
					x = x->leftchild;
				}
				else
				{
					x->leftchild = node;
					node->parent = x;
					break;
				}
			}
			else
			{
				if (x->rightchild != nullptr)
				{
					x = x->rightchild;
				}
				else
				{
					x->rightchild = node;
					node->parent = x;
					break;
				}
			}
		}
	}
}

template<class P, class T>
inline BSTnode<P, T>* BST<P, T>::Search(const T& k)
{
	BSTnode<P, T>* x = root;
	while (x != nullptr && x->key != k)
	{
		if (x->key > k)
		{
			x = x->leftchild;
		}
		else
		{
			x = x->rightchild;
		}
	}
	return x;
}

template<class P, class T>
inline void BST<P, T>::Remove(const T& k)
{
	BSTnode<P, T>* x = Search(k);
	if (x != nullptr)
	{
		if (x->leftchild == nullptr)
		{
			TransPlant(x, x->rightchild);
		}
		else if (x->rightchild == nullptr)
		{
			TransPlant(x, x->leftchild);
		}
		else
		{
			BSTnode<P, T>* y = Successor(x);
			if (y->parent == x)
			{
				TransPlant(x, y);
				y->leftchild = x->leftchild;
				y->leftchild->parent = y;
			}
			else
			{
				TransPlant(y, y->rightchild);
				TransPlant(x, y);
				y->rightchild = x->rightchild;
				y->rightchild->parent = y;
				y->leftchild = x->leftchild;
				y->leftchild->parent = y;
			}
		}
		delete x;
	}
}

template<class P, class T>
inline P& BST<P, T>::operator[](const T& k)
{
	BSTnode<P, T>* x = Search(k);
	return x->data;
}
